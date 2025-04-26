// T1_1_Integrar_Display_LCD.ino
// Função: Balança de Volume
// Artifact ID: d0aaeaad-fdfa-4640-9c5f-303457c7646d
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD3.1 (Integração com Display)
// Descrição: Integra o sensor HX711 com um display LCD 16x2, exibindo peso e volume.
// Diretório: docs/V1.01/codes/Balanca_de_Volume/T1_1

#include <HX711.h>
#include <LiquidCrystal.h>

#define HX711_DOUT 3 // Pino de dados do HX711
#define HX711_SCK 2  // Pino de clock do HX711

HX711 scale;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos do LCD

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T1.1 - Integração Display LCD Iniciado");

  lcd.begin(16, 2);
  lcd.print("Balanca Volume");

  scale.begin(HX711_DOUT, HX711_SCK);
  scale.tare();
  scale.set_scale(100.0); // Ajustar após calibração real
}

void loop() {
  float weight = scale.get_units(10);
  float volume = weight / 1000.0; // 1 g = 1 ml, 1000 ml = 1 L

  lcd.setCursor(0, 1);
  lcd.print("P:");
  lcd.print(weight);
  lcd.print("g V:");
  lcd.print(volume);
  lcd.print("L");

  Serial.print("Peso: ");
  Serial.print(weight);
  Serial.print(" g | Volume: ");
  Serial.print(volume);
  Serial.println(" L");
  delay(1000);
}