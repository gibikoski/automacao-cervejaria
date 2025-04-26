// T2_1_Deteccao_Variacao_Densidade.ino
// Função: Densímetro Flutuante
// Artifact ID: a189da32-e594-4f2f-bc1a-764b13f83fdf
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD4.1 (Detecção de Variação)
// Descrição: Detecta variações na densidade do líquido, alertando no LCD e Serial Monitor se a variação exceder 5%.
// Diretório: docs/V1.01/codes/Densimetro_Flutuante/T2_1

#include <Wire.h>
#include <VL53L0X.h>
#include <LiquidCrystal.h>

#define RECALIBRATE_BUTTON 7 // Pino do botão de recalibração
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos do LCD
VL53L0X sensor;
float offset = 0;
float previousDensity = 0;
const float DENSIMETER_MASS = 50.0; // Massa do densímetro em gramas
const float DENSIMETER_AREA = 0.0001; // Área da seção transversal em m²
const float VARIATION_THRESHOLD = 0.05; // 5% de variação
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T2.1 - Detecção Variação Densidade Iniciado");

  pinMode(RECALIBRATE_BUTTON, INPUT_PULLUP);
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

    if (previousDensity != 0 && abs(density - previousDensity) / previousDensity > VARIATION_THRESHOLD) {
      Serial.println("Alerta: Variação de densidade > 5%!");
      lcd.setCursor(0, 1);
      lcd.print("Variação Alta!  ");
      delay(2000);
    }

    Serial.print("Densidade: ");
    Serial.print(density);
    Serial.println(" kg/m³");
    previousDensity = density;
  }
  delay(500);
}