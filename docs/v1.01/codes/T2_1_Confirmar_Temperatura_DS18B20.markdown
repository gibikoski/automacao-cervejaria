/*
 * Teste: T2.1 - Confirmar Temperatura com DS18B20
 * Artifact ID: bf5eae6e-9e2c-4eae-2121-3d4e5f6a7b8c
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RP2, RD2.1, RD2.2 (Precisão DS18B20)
 * Descrição: Confirma a temperatura do DS18B20 (±0,5°C) com um termômetro de referência.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T2.1.                |
 */

/*
 * Setup:
 * - Conectar DS18B20: DQ para GPIO2, VCC para 3V3, GND para GND do ESP32-C3.
 * - Adicionar resistor 4,7 kΩ entre DQ e VCC.
 * - Comparar com termômetro calibrado em líquido (0-50°C).
 * - Observar leituras no Serial Monitor (9600 baud).
 */

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T2.1: Confirmar Temperatura com DS18B20");
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  Serial.print("Temperatura: ");
  Serial.print(tempC);
  Serial.println(" °C");
  delay(1000);
}