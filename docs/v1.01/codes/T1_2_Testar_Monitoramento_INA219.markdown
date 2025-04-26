/*
 * Teste: T1.2 - Testar Monitoramento com INA219
 * Artifact ID: 59f84808-27b5-4ff7-0cbc-2a3b4c5d6e7f
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RP3, RD3.3, RD3.4 (Monitoramento INA219)
 * Descrição: Testa o monitoramento de corrente e tensão do INA219 durante operação do sistema.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T1.2.                |
 */

/*
 * Setup:
 * - Conectar INA219: SDA para SDA (pin 20), SCL para SCL (pin 21), VCC para 5V, GND para GND do Mega 2560.
 * - Conectar circuito de monitoramento (ex.: ESP8266) em série com INA219.
 * - Observar leituras no Serial Monitor (9600 baud).
 */

#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T1.2: Testar Monitoramento com INA219");
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