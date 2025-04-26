/*
 * Teste: T0.3 - Verificar Funcionalidade do DFR0009
 * Artifact ID: 75562dd6-a594-459c-b571-14ac81de3abd
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisito: RD3.5 (Funcionalidade DFR0009)
 * Descrição: Verifica a funcionalidade do DFR0009 (LCD 16x2) exibindo texto de teste.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.3.                |
 */

/*
 * Setup:
 * - Conectar DFR0009: RS para pin 12, E para pin 11, D4-D7 para pins 5-2, VCC para 5V, GND para GND do Mega 2560.
 * - Observar texto exibido no LCD.
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Teste T0.3");
  lcd.setCursor(0, 1);
  lcd.print("DFR0009 OK");
}

void loop() {
  // Loop vazio, teste é visual
}