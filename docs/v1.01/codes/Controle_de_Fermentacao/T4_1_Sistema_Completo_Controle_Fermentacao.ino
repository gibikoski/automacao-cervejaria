// T4_1_Sistema_Completo_Controle_Fermentacao.ino
// Função: Controle de Fermentação
// Artifact ID: b2366c19-6651-4127-8413-9642773892a3
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD8.1 (Sistema Completo)
// Descrição: Integra leitura de temperatura (DS18B20), corrente (INA219), controle de relé (SSR-10DA) e envio de dados via WiFi.
// Diretório: docs/V1.01/codes/Controle_de_Fermentacao/T4_1

#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <WiFi.h>

#define ONE_WIRE_BUS 10 // DS18B20
#define SSR_PIN 9 // SSR-10DA
const char* ssid = "SUA_REDE_WIFI";
const char* password = "SUA_SENHA_WIFI";

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
Adafruit_INA219 ina219;

void setup() {
  pinMode(SSR_PIN, OUTPUT);
  digitalWrite(SSR_PIN, LOW);
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T4.1 - Sistema Completo Controle Fermentação Iniciado");

  sensors.begin();
  if (sensors.getDeviceCount() == 0) {
    Serial.println("Nenhum sensor DS18B20 encontrado!");
  }

  if (!ina219.begin()) {
    Serial.println("Erro: Falha ao inicializar o INA219!");
  }

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado. IP: " + WiFi.localIP().toString());
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  float current_mA = ina219.getCurrent_mA();
  float voltage_V = ina219.getBusVoltage_V();

  Serial.print("Temperatura: ");
  Serial.print(tempC);
  Serial.print(" °C | Corrente: ");
  Serial.print(current_mA);
  Serial.print(" mA | Tensão: ");
  Serial.print(voltage_V);
  Serial.println(" V");

  if (tempC != DEVICE_DISCONNECTED_C && tempC > 25.0) {
    digitalWrite(SSR_PIN, HIGH);
    Serial.println("Relé SSR-10DA: LIGADO");
  } else {
    digitalWrite(SSR_PIN, LOW);
    Serial.println("Relé SSR-10DA: DESLIGADO");
  }

  // Simula envio de dados via WiFi
  Serial.println("Dados enviados (simulado): Temp=" + String(tempC) + "°C, Corrente=" + String(current_mA) + "mA");

  delay(5000);
}