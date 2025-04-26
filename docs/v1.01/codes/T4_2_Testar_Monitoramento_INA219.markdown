/*
 * Teste: T4.2 - Testar Monitoramento com INA219
 * Artifact ID: e281d1a1-c15f-4fd1-5454-6a7b8c9d0e1f
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RD3.3, RD3.4 (Monitoramento INA219)
 * Descrição: Testa o monitoramento de corrente e tensão do INA219 durante operação do densímetro.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T4.2.                |
 */

/*
 * Setup:
 * - Conectar INA219: SDA para GPIO8, SCL para GPIO9, VCC para 3V3, GND para GND do ESP32-C3.
 * - Conectar circuito do densímetro (ex.: ICM20948, DS18B20) em série com INA219.
 * - Observar leituras no Serial Monitor (9600 baud).
 */

#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T4.2: Testar Monitoramento com INA219");
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