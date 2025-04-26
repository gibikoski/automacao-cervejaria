/*
 * Teste: T1.1 - Verificar Precisão do DS18B20
 * Artifact ID: a8b9c0d1-e2f3-4094-5a6b-7c8d9e0f1a2b
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RP1, RD1.1, RD1.3 (Precisão de Temperatura)
 * Descrição: Verifica a precisão do DS18B20 (±0,5°C) comparando com um termômetro de referência.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T1.1.                |
 */

/*
 * Setup:
 * - Conectar DS18B20: DQ para D2, VCC para 3V3, GND para GND do Arduino R4 Connect.
 * - Adicionar resistor 4,7 kΩ entre DQ e VCC.
 * - Comparar leitura com termômetro calibrado em água (0-50°C).
 * - Observar leituras no Serial Monitor (9600 baud).
 */

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T1.1: Verificar Precisão do DS18B20");
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