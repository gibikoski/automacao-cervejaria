/*
 * Teste: T0.1.3 - Testar I2C do ESP32-C3 (Densímetro)
 * Artifact ID: 5f6a7b8c-9d0e-4090-1e2f-3a4b5c6d7e8f
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisito: RD4.1 (I2C)
 * Descrição: Testa a comunicação I2C do ESP32-C3 com o sensor ICM20948.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.1.3.              |
 */

/*
 * Setup:
 * - Conectar ICM20948: SDA para GPIO8, SCL para GPIO9, VCC para 3V3, GND para GND do ESP32-C3.
 * - Adicionar pull-ups de 4,7 kΩ entre SDA/SCL e 3V3.
 * - Observar leituras de aceleração no Serial Monitor (9600 baud).
 */

#include <Wire.h>
#include <ICM20948.h> // Biblioteca genérica para ICM20948

ICM20948 imu;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T0.1.3: Testar I2C do ESP32-C3 (Densímetro)");
  Wire.begin();
  if (!imu.begin()) {
    Serial.println("Falha ao iniciar ICM20948!");
    while (1);
  }
}

void loop() {
  float accelX = imu.getAccelX();
  Serial.print("Aceleracao X: ");
  Serial.print(accelX);
  Serial.println(" m/s²");
  delay(1000);
}