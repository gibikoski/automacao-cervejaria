/*
 * Teste: T0.1.3 - Testar I2C do Mega 2560
 * Artifact ID: 15b404d4-f482-4ff4-8787-9d0e1f2a3b4c
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisito: RD3.1 (I2C)
 * Descrição: Testa a comunicação I2C do Mega 2560 com o sensor INA219.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.1.3.              |
 */

/*
 * Setup:
 * - Conectar INA219: SDA para SDA (pin 20), SCL para SCL (pin 21), VCC para 5V, GND para GND do Mega 2560.
 * - Adicionar pull-ups de 4,7 kΩ entre SDA/SCL e 5V.
 * - Observar leituras de corrente no Serial Monitor (9600 baud).
 */

#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T0.1.3: Testar I2C do Mega 2560");
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