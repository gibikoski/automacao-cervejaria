// T1_1_Controle_Limites.ino
// Função: Controle e Monitoramento
// Artifact ID: c1db1077-d4ae-4317-893e-a46a84aa957a
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RC3.1 (Controle com Limites Configuráveis)
// Descrição: Controla um relé com base em limites configuráveis de um sensor analógico, exibindo status no LCD e Serial Monitor.
// Diretório: docs/V1.01/codes/Controle_e_Monitoramento/T1_1

#include <LiquidCrystal.h>

#define SENSOR_PIN A0 // Pino analógico para simular sensor
#define RELAY_PIN 9 // Pino do relé
#define BUTTON_PIN 7 // Botão para ajustar limite
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos do LCD
float threshold = 50.0; // Limite inicial (escala 0-100)
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T1.1 - Controle Limites Iniciado");

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  digitalWrite(RELAY_PIN, LOW); // Relé inicialmente desligado
  lcd.begin(16, 2);
  lcd.print("Controle Limites");
}

void loop() {
  // Ajustar limite com botão
  bool buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == LOW && lastButtonState == HIGH) {
    threshold += 10.0;
    if (threshold > 100.0) threshold = 0.0;
    Serial.println("Novo limite: " + String(threshold));
  }
  lastButtonState = buttonState;

  int sensorValue = analogRead(SENSOR_PIN);
  float scaledValue = sensorValue * (100.0 / 1023.0); // Escala 0-100
  bool relayState = (scaledValue > threshold);
  digitalWrite(RELAY_PIN, relayState ? HIGH : LOW);

  lcd.setCursor(0, 1);
  lcd.print("V:");
  lcd.print(scaledValue);
  lcd.print(" L:");
  lcd.print(threshold);
  lcd.print("  ");

  Serial.print("Sensor: ");
  Serial.print(scaledValue);
  Serial.print(" | Limite: ");
  Serial.print(threshold);
  Serial.print(" | Relé: ");
  Serial.println(relayState ? "LIGADO" : "DESLIGADO");
  delay(1000);
}