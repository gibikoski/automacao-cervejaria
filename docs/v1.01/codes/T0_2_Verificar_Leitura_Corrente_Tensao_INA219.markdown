/*
 * Teste: T0.2 - Verificar Leitura de Corrente/Tensão do INA219
 * Artifact ID: 26c515e5-0593-4ff5-9898-0e1f2a3b4c5d
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RD3.3, RD3.4 (Monitoramento INA219)
 * Descrição: Verifica a leitura de corrente e tensão do INA219 com uma carga resistiva.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.2.                |
 */

/*
 * Setup:
 * - Conectar INA219: SDA para SDA (pin 20), SCL para SCL (pin 21), VCC para 5V, GND para GND do Mega 2560.
 * - Conectar resistor 10 Ω entre VIN+ e VIN- do INA219.
 * - Observar leituras no Serial Monitor (9600 baud).
 */

#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T0.2: Verificar Leitura de Corrente/Tensão do INA219");
  Wire.begin();
  if (!ina219.begin()) {
    Serial.println("Falha ao iniciar INA219!");
    while (1);
  }
}

void loop() {
  float current_mA = ina219.getCurrent_mA();
  float busVoltage = ina219.getBusVoltage_V();
  Serial.print("Corrente: ");
  Serial.print(current_mA);
  Serial.println(" mA");
  Serial.print("Tensão: ");
  Serial.print(busVoltage);
  Serial.println(" V");
  delay(1000);
}