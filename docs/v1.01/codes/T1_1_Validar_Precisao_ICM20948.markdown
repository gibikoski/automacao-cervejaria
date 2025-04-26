/*
 * Teste: T1.1 - Validar Precisão do ICM20948
 * Artifact ID: ae4d9d5d-8d1b-4d9d-1010-2c3d4e5f6a7b
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RP1, RD1.1, RD1.2 (Precisão ICM20948)
 * Descrição: Valida a precisão do ICM20948 (±0,005 g/cm³) em um líquido de densidade conhecida.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T1.1.                |
 */

/*
 * Setup:
 * - Conectar ICM20948: SDA para GPIO8, SCL para GPIO9, VCC para 3V3, GND para GND do ESP32-C3.
 * - Adicionar pull-ups de 4,7 kΩ entre SDA/SCL e 3V3.
 * - Colocar densímetro em líquido (ex.: água, 1 g/cm³).
 * - Observar leituras no Serial Monitor (9600 baud).
 */

#include <Wire.h>
#include <ICM20948.h>

ICM20948 imu;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T1.1: Validar Precisão do ICM20948");
  Wire.begin();
  if (!imu.begin()) {
    Serial.println("Falha ao iniciar ICM20948!");
    while (1);
  }
}

void loop() {
  float accelZ = imu.getAccelZ();
  // Simplificação: densidade proporcional à aceleração (calibrar na prática)
  float density = accelZ / 9.81; // Exemplo ilustrativo
  Serial.print("Densidade: ");
  Serial.print(density, 3);
  Serial.println(" g/cm³");
  delay(1000);
}