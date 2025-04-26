/*
 * Teste: T0.2 - Verificar Leitura Inercial do ICM20948
 * Artifact ID: 7b8c9d0e-1f2a-4092-3a4b-5c6d7e8f9a0b
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RD1.1, RD1.2 (Leitura ICM20948)
 * Descrição: Verifica a leitura inercial (aceleração e giroscópio) do ICM20948.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.2.                |
 */

/*
 * Setup:
 * - Conectar ICM20948: SDA para GPIO8, SCL para GPIO9, VCC para 3V3, GND para GND do ESP32-C3.
 * - Adicionar pull-ups de 4,7 kΩ entre SDA/SCL e 3V3.
 * - Observar leituras no Serial Monitor (9600 baud).
 */

#include <Wire.h>
#include <ICM20948.h>

ICM20948 imu;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T0.2: Verificar Leitura Inercial do ICM20948");
  Wire.begin();
  if (!imu.begin()) {
    Serial.println("Falha ao iniciar ICM20948!");
    while (1);
  }
}

void loop() {
  float accelX = imu.getAccelX();
  float gyroX = imu.getGyroX();
  Serial.print("Aceleracao X: ");
  Serial.print(accelX);
  Serial.println(" m/s²");
  Serial.print("Giroscopio X: ");
  Serial.print(gyroX);
  Serial.println(" rad/s");
  delay(1000);
}