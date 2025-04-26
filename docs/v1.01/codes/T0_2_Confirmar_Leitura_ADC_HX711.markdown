/*
 * Teste: T0.2 - Confirmar Leitura ADC do HX711
 * Artifact ID: d7e8f9a0-b1c2-4093-4d5e-6f7a8b9c0d1e
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RD1.1, RD1.4 (Leitura HX711)
 * Descrição: Confirma a leitura ADC do HX711 com uma célula de carga.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.2.                |
 */

/*
 * Setup:
 * - Conectar HX711: DT para GPIO5, SCK para GPIO4, VCC para 3V3, GND para GND do ESP32-C3.
 * - Conectar célula de carga ao HX711.
 * - Observar leituras no Serial Monitor (9600 baud).
 */

#include <HX711.h>

#define HX711_DT 5
#define HX711_SCK 4

HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T0.2: Confirmar Leitura ADC do HX711");
  scale.begin(HX711_DT, HX711_SCK);
  scale.set_scale();
  scale.tare();
}

void loop() {
  float weight = scale.get_units(10);
  Serial.print("Peso: ");
  Serial.print(weight, 2);
  Serial.println(" g");
  delay(1000);
}