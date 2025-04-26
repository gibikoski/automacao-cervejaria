/*
 * Teste: T1.1 - Confirmar Integração MQTT com ESP8266
 * Artifact ID: 48e737f7-16a4-4ff6-9bab-1f2a3b4c5d6e
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RP3, RD3.1, RD3.2 (Integração MQTT)
 * Descrição: Confirma a integração MQTT do ESP8266 publicando dados de teste para o Home Assistant.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T1.1.                |
 */

/*
 * Setup:
 * - Conectar ESP8266: TX para RX1 (pin 19), RX para TX1 (pin 18) do Mega 2560, VCC para 3V3, GND para GND.
 * - Configurar SSID, senha, e broker MQTT no código.
 * - Verificar dados no Home Assistant.
 */

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "SUA_REDE";
const char* password = "SUA_SENHA";
const char* mqtt_server = "SEU_BROKER";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T1.1: Confirmar Integração MQTT com ESP8266");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conectado à rede Wi-Fi!");
  client.setServer(mqtt_server, 1883);
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP8266Client")) {
      Serial.println("Conectado ao broker MQTT!");
    } else {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  client.publish("monitoramento/teste", "OK");
  Serial.println("Mensagem enviada: OK");
  delay(5000);
}