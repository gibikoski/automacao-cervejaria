// artifact_id: <UUID_GERADO_PARA_T3.1_CF>
// Test ID: T3.1 (Controle de Fermentação)
// Function: Controle de Fermentação
// Objective: Testar integração MQTT com Home Assistant
// Setup: Arduino R4 Connect, Home Assistant, broker MQTT
// Details: Configurar sketch MQTT. Publicar temperatura (DS18B20) e estado (SSR-10DA) no broker. Verificar no Home Assistant.

// --- Bibliotecas ---
#include <WiFiS3.h>
#include <PubSubClient.h> // Biblioteca MQTT
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ArduinoJson.h> // Para formatar a mensagem JSON (opcional, mas recomendado)
// -------------------

// --- Configurações de Rede ---
char ssid[] = "SEU_SSID";
char pass[] = "SUA_SENHA";
int wifiStatus = WL_IDLE_STATUS;
// --------------------------

// --- Configurações MQTT ---
const char* mqtt_server = "IP_DO_SEU_BROKER_MQTT"; // Ex: "192.168.1.100"
const int mqtt_port = 1883;
// const char* mqtt_user = "seu_usuario_mqtt"; // Descomente se usar autenticação
// const char* mqtt_password = "sua_senha_mqtt"; // Descomente se usar autenticação
const char* client_id = "arduino_fermentador"; // ID único para este cliente
const char* temperature_topic = "cervejaria/fermentador/temperatura";
const char* ssr_state_topic = "cervejaria/fermentador/ssr_estado";
// const char* ssr_command_topic = "cervejaria/fermentador/ssr/set"; // Opcional: para receber comandos
// ------------------------

// --- Configurações de Hardware ---
#define ONE_WIRE_BUS 2
#define SSR_PIN 3
// -----------------------------

// --- Objetos Globais ---
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress sensorAddress;
unsigned long lastMsgTime = 0;
const long msgInterval = 10000; // Intervalo de publicação MQTT (10 segundos)
// -----------------------

void setup() {
  Serial.begin(9600);
  while (!Serial);

  pinMode(SSR_PIN, OUTPUT);
  digitalWrite(SSR_PIN, LOW); // Garante que SSR comece desligado

  setup_wifi(); // Conecta ao Wi-Fi
  mqttClient.setServer(mqtt_server, mqtt_port);
  // mqttClient.setCallback(callback); // Descomente se for receber mensagens (ex: comando SSR)

  sensors.begin();
  if (sensors.getAddress(sensorAddress, 0)) {
      sensors.setResolution(sensorAddress, 12);
      Serial.println("Sensor DS18B20 encontrado.");
  } else {
      Serial.println("Erro: Sensor DS18B20 não encontrado!");
  }

  Serial.println("Teste T3.1: Integração MQTT com Home Assistant");
  Serial.println("--------------------------------------------------");
  Serial.println("Setup: Arduino R4 conectado ao Wi-Fi, Broker MQTT rodando, Home Assistant configurado para receber dos tópicos MQTT.");
  Serial.println("Ação: Publicar periodicamente a temperatura e o estado do SSR nos tópicos MQTT.");
  Serial.println("Verificação: Observar no Home Assistant (ou cliente MQTT) se os dados estão chegando corretamente.");
  Serial.println("--------------------------------------------------");
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros()); // Para ID do cliente MQTT, se necessário

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

// --- Função callback para receber mensagens MQTT (exemplo) ---
/*
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensagem recebida no tópico: ");
  Serial.println(topic);
  Serial.print("Mensagem: ");
  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.println(message);
  Serial.println("-----------------------");

  // Exemplo: Controlar SSR via MQTT
  if (String(topic) == ssr_command_topic) {
    if (message == "ON") {
      digitalWrite(SSR_PIN, HIGH);
      Serial.println("SSR Ligado via MQTT");
      // Publicar estado atualizado
      mqttClient.publish(ssr_state_topic, "ON", true); // true = reter mensagem
    } else if (message == "OFF") {
      digitalWrite(SSR_PIN, LOW);
       Serial.println("SSR Desligado via MQTT");
      mqttClient.publish(ssr_state_topic, "OFF", true);
    }
  }
}
*/

void reconnect_mqtt() {
  // Loop até reconectar
  while (!mqttClient.connected()) {
    Serial.print("Tentando conexão MQTT...");
    // Tenta conectar
    // bool connected = mqttClient.connect(client_id, mqtt_user, mqtt_password); // Com autenticação
    bool connected = mqttClient.connect(client_id); // Sem autenticação

    if (connected) {
      Serial.println("conectado!");
      // Opcional: Inscrever-se em tópicos após conectar
      // mqttClient.subscribe(ssr_command_topic);
      // Serial.print("Inscrito no tópico: "); Serial.println(ssr_command_topic);
    } else {
      Serial.print("falhou, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" tentando novamente em 5 segundos");
      // Espera 5 segundos antes de tentar novamente
      delay(5000);
    }
  }
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi desconectado. Tentando reconectar...");
    setup_wifi(); // Tenta reconectar o WiFi
    return; // Pula o resto do loop até reconectar
  }

  if (!mqttClient.connected()) {
    reconnect_mqtt(); // Garante que o cliente MQTT esteja conectado
  }
  mqttClient.loop(); // Mantém a conexão MQTT ativa e processa mensagens recebidas

  unsigned long now = millis();
  if (now - lastMsgTime > msgInterval) {
    lastMsgTime = now;

    // 1. Ler Temperatura
    sensors.requestTemperatures();
    float tempC = sensors.getTempC(sensorAddress);

    if (tempC != DEVICE_DISCONNECTED_C) {
      Serial.print("Temperatura: "); Serial.print(tempC); Serial.println(" °C");
      // Publica a temperatura
      char tempString[8];
      dtostrf(tempC, 4, 2, tempString); // Converte float para string
      mqttClient.publish(temperature_topic, tempString, true); // true = reter mensagem
    } else {
      Serial.println("Falha ao ler DS18B20.");
    }

    // 2. Ler Estado do SSR
    int ssrState = digitalRead(SSR_PIN);
    const char* ssrStateStr = (ssrState == HIGH) ? "ON" : "OFF";
    Serial.print("Estado SSR: "); Serial.println(ssrStateStr);
    // Publica o estado do SSR
    mqttClient.publish(ssr_state_topic, ssrStateStr, true); // true = reter mensagem

    Serial.println("--------------------------------------------------");
  }
}
