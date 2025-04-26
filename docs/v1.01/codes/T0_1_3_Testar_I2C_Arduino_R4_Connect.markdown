/*
 * Teste: T0.1.3 - Testar I2C do Arduino R4 Connect
 * Artifact ID: b3c4d5e6-f7a8-4099-0b1c-2d3e4f5a6b7c
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisito: RD3.1 (I2C)
 * Descrição: Testa a comunicação I2C do Arduino R4 Connect com o sensor INA219.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.1.3.              |
 */

/*
 * Setup:
 * - Conectar INA219: SDA para A5, SCL para A4, VCC para 3V3, GND para GND do Arduino R4 Connect.
 * - Adicionar pull-ups de 4,7 kΩ entre SDA/SCL e 3V3.
 * - Observar leituras de corrente no Serial Monitor (9600 baud).
 */

#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T0.1.3: Testar I2C do Arduino R4 Connect");
  Wire.begin();
  if (!ina219.begin()) {
    Serial.println("Falha ao iniciar INA219!");
    while (1);
  }
}

void loop() {
  float current_mA = ina219.getCurrent_mA();
  Serial.print("Corrente: ");
  Serial.print(current_mA);
  Serial.println(" mA");
  delay(1000);
}