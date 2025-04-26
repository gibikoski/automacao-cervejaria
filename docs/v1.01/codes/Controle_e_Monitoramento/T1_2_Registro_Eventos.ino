// T1_2_Registro_Eventos.ino
// Função: Controle e Monitoramento
// Artifact ID: 06b2a889-babf-4272-a08e-406699ef7094
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RC3.2 (Registro de Eventos)
// Descrição: Registra eventos (ex.: relé ligado/desligado) na EEPROM com base em sensor analógico, exibindo no Serial Monitor.
// Diretório: docs/V1.01/codes/Controle_e_Monitoramento/T1_2

#include <EEPROM.h>

#define SENSOR_PIN A0 // Pino analógico para simular sensor
#define RELAY_PIN 9 // Pino do relé
#define EEPROM_ADDRESS 0 // Endereço inicial na EEPROM
float threshold = 50.0; // Limite para evento
int eventCount = 0;
bool lastRelayState = false;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T1.2 - Registro Eventos Iniciado");

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Relé inicialmente desligado
  EEPROM.begin(512); // Inicializa EEPROM com 512 bytes

  // Ler número de eventos salvos
  EEPROM.get(EEPROM_ADDRESS, eventCount);
  if (eventCount < 0 || eventCount > 50) eventCount = 0;
}

void loop() {
  int sensorValue = analogRead(SENSOR_PIN);
  float scaledValue = sensorValue * (100.0 / 1023.0); // Escala 0-100
  bool relayState = (scaledValue > threshold);
  digitalWrite(RELAY_PIN, relayState ? HIGH : LOW);

  if (relayState != lastRelayState && eventCount < 50) {
    int address = EEPROM_ADDRESS + sizeof(int) + eventCount * sizeof(float);
    EEPROM.put(address, scaledValue);
    eventCount++;
    EEPROM.put(EEPROM_ADDRESS, eventCount);
    EEPROM.commit();
    Serial.println("Evento registrado: Relé " + String(relayState ? "LIGADO" : "DESLIGADO") + ", Valor: " + String(scaledValue) + ", Evento #" + String(eventCount));
  }
  lastRelayState = relayState;

  Serial.print("Sensor: ");
  Serial.print(scaledValue);
  Serial.print(" | Relé: ");
  Serial.println(relayState ? "LIGADO" : "DESLIGADO");
  delay(1000);
}