/*
 * Teste: T3.1 - Confirmar Envio de Dados de Volume via MQTT
 * Artifact ID: 2c3d4e5f-6a7b-4097-8b9c-0d1e2f3a4b5c
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RP3, RD3.1, RD3.2 (Integração MQTT)
 * Descrição: Confirma o envio de dados de peso/volume (HX711) via MQTT para o Home Assistant.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T3.1.                |
 */

/*
 * Setup:
 * - Conectar HX711: DT para GPIO5, SCK para GPIO4, VCC para 3V3, GND para GND do ESP32-C3.
 * - Conectar célula de carga ao HX711.
 * - Configurar SSID, senha, e broker MQTT no código.
 * - Verificar dados no Home Assistant.
 */

#include <WiFi.h>
#include <PubSubClient.h>
#include <HX711.h>

#define HX711_DT 5
#define HX711_SCK 4
#define DENSITY 1.0 // Densidade em g/cm³

const char* ssid = "SUA_REDE";
const char* password = "SUA_SENHA";
const char* mqtt_server = "SEU_BROKER";

WiFiClient espClient;
PubSubClient client(espClient);
HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T3.1: Confirmar Envio de Dados de Volume via MQTT");
  scale.begin(HX711_DT, HX711_SCK);
  scale.set_scale(2280.f);
  scale.tare();
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
    if (client.connect("ESP32Client")) {
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
  float weight = scale.get_units(10);
  float volume = weight / DENSITY;
  char weightStr[8], volumeStr[8];
  dtostrf(weight, 6, 2, weightStr);
  dtostrf(volume, 6, 2, volumeStr);
  client.publish("balanca/peso", weightStr);
  client.publish("balanca/volume", volumeStr);
  Serial.print("Peso: ");
  Serial.print(weight, 2);
  Serial.println(" g");
  Serial.print("Volume: ");
  Serial.print(volume, 2);
  Serial.println(" cm³");
  delay(5000);
}