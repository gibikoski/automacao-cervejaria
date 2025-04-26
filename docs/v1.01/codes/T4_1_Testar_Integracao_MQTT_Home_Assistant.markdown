/*
 * Teste: T4.1 - Testar Integração MQTT com Home Assistant
 * Artifact ID: d170c090-b04e-4fc0-4343-5f6a7b8c9d0e
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RP4, RD4.1, RD4.2 (Integração MQTT)
 * Descrição: Testa a integração MQTT publicando densidade (ICM20948) e temperatura (DS18B20) para o Home Assistant.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T4.1.                |
 */

/*
 * Setup:
 * - Conectar ICM20948: SDA para GPIO8, SCL para GPIO9, VCC para 3V3, GND para GND do ESP32-C3.
 * - Conectar DS18B20: DQ para GPIO2, VCC para 3V3, GND para GND.
 * - Configurar SSID, senha, e broker MQTT no código.
 * - Verificar dados no Home Assistant.
 */

#include <WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <ICM20948.h>

#define ONE_WIRE_BUS 2

const char* ssid = "SUA_REDE";
const char* password = "SUA_SENHA";
const char* mqtt_server = "SEU_BROKER";

WiFiClient espClient;
PubSubClient client(espClient);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
ICM20948 imu;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T4.1: Testar Integração MQTT com Home Assistant");
  sensors.begin();
  Wire.begin();
  if (!imu.begin()) {
    Serial.println("Falha ao iniciar ICM20948!");
    while (1);
  }
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
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  float accelZ = imu.getAccelZ();
  float density = accelZ / 9.81; // Exemplo ilustrativo
  char tempStr[8], densityStr[8];
  dtostrf(tempC, 6, 2, tempStr);
  dtostrf(density, 6, 3, densityStr);
  client.publish("densimetro/temperatura", tempStr);
  client.publish("densimetro/densidade", densityStr);
  Serial.print("Temperatura: ");
  Serial.print(tempC);
  Serial.println(" °C");
  Serial.print("Densidade: ");
  Serial.print(density, 3);
  Serial.println(" g/cm³");
  delay(5000);
}