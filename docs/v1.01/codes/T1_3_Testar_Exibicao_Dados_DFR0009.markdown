/*
 * Teste: T1.3 - Testar Exibição de Dados no DFR0009
 * Artifact ID: 6b095919-38c6-4ff8-1dcd-3b4c5d6e7f8a
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisito: RD3.5 (Exibição DFR0009)
 * Descrição: Testa a exibição de dados simulados no DFR0009 (LCD 16x2).
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T1.3.                |
 */

/*
 * Setup:
 * - Conectar DFR0009: RS para pin 12, E para pin 11, D4-D7 para pins 5-2, VCC para 5V, GND para GND do Mega 2560.
 * - Observar dados simulados (ex.: temperatura) no LCD.
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println("Teste T1.3: Testar Exibição de Dados no DFR0009");
}

void loop() {
  float tempC = random(200, 300) / 10.0; // Simula temperatura (20,0-30,0°C)
  lcd.clear();
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print(" C");
  Serial.print("Temperatura: ");
  Serial.print(tempC);
  Serial.println(" °C");
  delay(2000);
}