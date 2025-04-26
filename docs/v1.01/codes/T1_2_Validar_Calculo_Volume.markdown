/*
 * Teste: T1.2 - Validar Cálculo de Volume
 * Artifact ID: 0a1b2c3d-4e5f-4095-6f7a-8b9c0d1e2f3a
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RP1, RD1.3 (Cálculo de Volume)
 * Descrição: Valida o cálculo de volume com base no peso medido pelo HX711 e densidade conhecida.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T1.2.                |
 */

/*
 * Setup:
 * - Conectar HX711: DT para GPIO5, SCK para GPIO4, VCC para 3V3, GND para GND do ESP32-C3.
 * - Conectar célula de carga ao HX711.
 * - Usar líquido com densidade conhecida (ex.: água, 1 g/cm³).
 * - Observar volume calculado no Serial Monitor (9600 baud).
 */

#include <HX711.h>

#define HX711_DT 5
#define HX711_SCK 4
#define DENSITY 1.0 // Densidade em g/cm³ (ex.: água)

HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T1.2: Validar Cálculo de Volume");
  scale.begin(HX711_DT, HX711_SCK);
  scale.set_scale(2280.f); // Ajustar com fator de calibração
  scale.tare();
}

void loop() {
  float weight = scale.get_units(10);
  float volume = weight / DENSITY;
  Serial.print("Peso: ");
  Serial.print(weight, 2);
  Serial.println(" g");
  Serial.print("Volume: ");
  Serial.print(volume, 2);
  Serial.println(" cm³");
  delay(1000);
}