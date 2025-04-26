// T0_3_Integrar_Display_LCD.ino
// Função: Densímetro Flutuante
// Artifact ID: cd286597-86d8-470f-8ae3-76bf43a59a7f
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD2.2 (Integração com Display)
// Descrição: Integra o sensor VL53L0X com um display LCD 16x2, exibindo densidade calculada.
// Diretório: docs/V1.01/codes/Densimetro_Flutuante/T0_3

#include <Wire.h>
#include <VL53L0X.h>
#include <LiquidCrystal.h>

VL53L0X sensor;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos do LCD
float offset = 0;
const float DENSIMETER_MASS = 50.0; // Massa do densímetro em gramas
const float DENSIMETER_AREA = 0.0001; // Área da seção transversal em m²

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.3 - Integração Display LCD Iniciado");

  lcd.begin(16, 2);
  lcd.print("Densimetro");

  Wire.begin();
  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Erro: Falha ao inicializar o VL53L0X!");
    lcd.setCursor(0, 1);
    lcd.print("Erro Sensor!");
    while (1);
  }
  sensor.startContinuous();

  Serial.println("Posicione o densímetro na posição de referência e pressione qualquer tecla...");
  while (!Serial.available());
  offset = sensor.readRangeContinuousMillimeters();
  Serial.println("Calibração concluída. Offset: " + String(offset) + " mm");
}

void loop() {
  uint16_t distance = sensor.readRangeContinuousMillimeters();
  if (sensor.timeoutOccurred()) {
    Serial.println("Erro: Timeout na leitura!");
    lcd.setCursor(0, 1);
    lcd.print("Erro Leitura!");
  } else {
    float displacement = (distance - offset) / 1000.0; // Deslocamento em metros
    float volumeDisplaced = displacement * DENSIMETER_AREA; // Volume deslocado em m³
    float density = DENSIMETER_MASS / (volumeDisplaced * 1000); // Densidade em kg/m³

    lcd.setCursor(0, 1);
    lcd.print("Dens: ");
    lcd.print(density);
    lcd.print(" kg/m3");

    Serial.print("Densidade: ");
    Serial.print(density);
    Serial.println(" kg/m³");
  }
  delay(1000);
}