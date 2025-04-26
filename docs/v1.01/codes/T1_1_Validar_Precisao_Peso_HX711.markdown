/*
 * Teste: T1.1 - Validar Precisão de Peso do HX711
 * Artifact ID: d0aaeaad-fdfa-4640-9c5f-303457c7646d
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RP1, RD1.1, RD1.2, RD1.4 (Precisão de Peso)
 * Descrição: Valida a precisão do HX711 (±0,1-1 g) com pesos conhecidos (ex.: 100 g, 500 g).
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T1.1.                |
 */

/*
 * Setup:
 * - Conectar HX711: DT para GPIO5, SCK para GPIO4, VCC para 3V3, GND para GND do ESP32-C3.
 * - Conectar célula de carga ao HX711.
 * - Colocar pesos conhecidos (ex.: 100 g, 500 g) na célula de carga.
 * - Observar leituras no Serial Monitor (9600 baud).
 */

#include <HX711.h>

#define HX711_DT 5
#define HX711_SCK 4

HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T1.1: Validar Precisão de Peso do HX711");
  scale.begin(HX711_DT, HX711_SCK);
  scale.set_scale(2280.f); // Ajustar com fator de calibração
  scale.tare(); // Zerar a balança
}

void loop() {
  float weight = scale.get_units(10);
  Serial.print("Peso: ");
  Serial.print(weight, 2);
  Serial.println(" g");
  delay(1000);
}