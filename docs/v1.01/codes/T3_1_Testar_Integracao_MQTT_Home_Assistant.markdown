/*
 * Teste: T3.1 - Testar Integração MQTT com Home Assistant
 * Artifact ID: d1e2f3a4-b5c6-4097-8d9e-0f1a2b3c4d5e
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RP3, RD3.1, RD3.2 (Integração MQTT)
 * Descrição: Testa a integração MQTT publicando temperatura (DS18B20) e estado (SSR-10DA) para o Home Assistant.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T3.1.                |
 */

/*
 * Setup:
 * - Conectar DS18B20: DQ para D2, VCC para 3V3, GND para GND do Arduino R4 Connect.
 * - Conectar SSR-10DA: Controle+ para D3, Controle- para GND.
 * - Configurar SSID, senha, e broker MQTT no código.
 * - Verificar dados no Home Assistant.
 */

#include <WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
#define SSR_PIN 3

const char* ssid = "SUA_REDE";
const char* password = "SUA_SENHA";
const char* mqtt_server = "SEU_BROKER";

WiFiClient espClient;
PubSubClient client(espClient);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T3.1: Testar Integração MQTT com Home Assistant");
  pinMode(SSR_PIN, OUTPUT);
  sensors.begin();
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
    if (client.connect("ArduinoClient")) {
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
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  char tempStr[8];
  dtostrf(tempC, 6, 2, tempStr);
  client.publish("fermentacao/temperatura", tempStr);
  digitalWrite(SSR_PIN, !digitalRead(SSR_PIN));
  client.publish("fermentacao/ssr", digitalRead(SSR_PIN) ? "ON" : "OFF");
  Serial.print("Temperatura: ");
  Serial.print(tempC);
  Serial.println(" °C");
  Serial.print("SSR: ");
  Serial.println(digitalRead(SSR_PIN) ? "ON" : "OFF");
  delay(5000);
}