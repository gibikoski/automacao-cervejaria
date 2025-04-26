// T1_3_Interface_Usuario.ino
// Função: Controle e Monitoramento
// Artifact ID: ea976526-9cee-47e5-974a-cf674b66368c
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RC3.3 (Interface de Usuário)
// Descrição: Interface de usuário com LCD e botões para exibir dados de sensor analógico e alternar entre modos (ex.: monitoramento, configuração).
// Diretório: docs/V1.01/codes/Controle_e_Monitoramento/T1_3

#include <LiquidCrystal.h>

#define SENSOR_PIN A0 // Pino analógico para simular sensor
#define MODE_BUTTON 7 // Botão para alternar modo
#define SELECT_BUTTON 6 // Botão para selecionar
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos do LCD
bool lastModeState = HIGH;
bool lastSelectState = HIGH;
int mode = 0; // 0: Monitoramento, 1: Configuração
float threshold = 50.0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T1.3 - Interface Usuário Iniciado");

  pinMode(MODE_BUTTON, INPUT_PULLUP);
  pinMode(SELECT_BUTTON, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.print("Interface Usuario");
}

void loop() {
  // Alternar modo
  bool modeState = digitalRead(MODE_BUTTON);
  if (modeState == LOW && lastModeState == HIGH) {
    mode = (mode + 1) % 2;
    Serial.println("Modo: " + String(mode == 0 ? "Monitoramento" : "Configuração"));
    lcd.clear();
    lcd.print(mode == 0 ? "Monitoramento" : "Configuracao");
  }
  lastModeState = modeState;

  int sensorValue = analogRead(SENSOR_PIN);
  float scaledValue = sensorValue * (100.0 / 1023.0); // Escala 0-100

  if (mode == 0) {
    // Modo Monitoramento
    lcd.setCursor(0, 1);
    lcd.print("Valor: ");
    lcd.print(scaledValue);
    lcd.print("   ");

    Serial.print("Sensor: ");
    Serial.println(scaledValue);
  } else {
    // Modo Configuração
    bool selectState = digitalRead(SELECT_BUTTON);
    if (selectState == LOW && lastSelectState == HIGH) {
      threshold += 10.0;
      if (threshold > 100.0) threshold = 0.0;
      Serial.println("Novo limite: " + String(threshold));
    }
    lastSelectState = selectState;

    lcd.setCursor(0, 1);
    lcd.print("Limite: ");
    lcd.print(threshold);
    lcd.print("   ");
  }
  delay(500);
}