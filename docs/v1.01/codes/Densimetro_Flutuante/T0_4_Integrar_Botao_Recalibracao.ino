// T0_4_Integrar_Botao_Recalibracao.ino
// Função: Densímetro Flutuante
// Artifact ID: c1891ed7-7286-4c61-8f79-2cdecbb355d5
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD2.3 (Interação com Usuário)
// Descrição: Integra um botão para recalibrar a posição de referência do sensor VL53L0X, exibindo densidade no Serial Monitor.
// Diretório: docs/V1.01/codes/Densimetro_Flutuante/T0_4

#include <Wire.h>
#include <VL53L0X.h>

#define RECALIBRATE_BUTTON 7 // Pino do botão de recalibração

VL53L0X sensor;
float offset = 0;
const float DENSIMETER_MASS = 50.0; // Massa do densímetro em gramas
const float DENSIMETER_AREA = 0.0001; // Área da seção transversal em m²
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.4 - Integração Botão Recalibração Iniciado");

  pinMode(RECALIBRATE_BUTTON, INPUT_PULLUP);
  Wire.begin();
  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Erro: Falha ao inicializar o VL53L0X!");
    while (1);
  }
  sensor.startContinuous();

  Serial.println("Posicione o densímetro na posição de referência e pressione qualquer tecla...");
  while (!Serial.available());
  offset = sensor.readRangeContinuousMillimeters();
  Serial.println("Calibração inicial concluída. Offset: " + String(offset) + " mm");
}

void loop() {
  bool buttonState = digitalRead(RECALIBRATE_BUTTON);
  if (buttonState == LOW && lastButtonState == HIGH) {
    offset = sensor.readRangeContinuousMillimeters();
    Serial.println("Recalibração concluída. Novo offset: " + String(offset) + " mm");
  }
  lastButtonState = buttonState;

  uint16_t distance = sensor.readRangeContinuousMillimeters();
  if (sensor.timeoutOccurred()) {
    Serial.println("Erro: Timeout na leitura!");
  } else {
    float displacement = (distance - offset) / 1000.0; // Deslocamento em metros
    float volumeDisplaced = displacement * DENSIMETER_AREA; // Volume deslocado em m³
    float density = DENSIMETER_MASS / (volumeDisplaced * 1000); // Densidade em kg/m³

    Serial.print("Densidade: ");
    Serial.print(density);
    Serial.println(" kg/m³");
  }
  delay(1000);
}