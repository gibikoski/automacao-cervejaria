/*
 * Teste: T0.3 - Verificar Leitura Inercial do MPU6050
 * Artifact ID: e8f9a0b1-c2d3-4094-5e6f-7a8b9c0d1e2f
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RD2.1, RD2.2 (Leitura MPU6050)
 * Descrição: Verifica a leitura inercial (aceleração e giroscópio) do MPU6050.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.3.                |
 */

/*
 * Setup:
 * - Conectar MPU6050: SDA para GPIO8, SCL para GPIO9, VCC para 3V3, GND para GND do ESP32-C3.
 * - Adicionar pull-ups de 4,7 kΩ entre SDA/SCL e 3V3.
 * - Observar leituras no Serial Monitor (9600 baud).
 */

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T0.3: Verificar Leitura Inercial do MPU6050");
  Wire.begin();
  if (!mpu.begin()) {
    Serial.println("Falha ao iniciar MPU6050!");
    while (1);
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  Serial.print("Aceleracao X: ");
  Serial.print(a.acceleration.x);
  Serial.println(" m/s²");
  Serial.print("Giroscopio X: ");
  Serial.print(g.gyro.x);
  Serial.println(" rad/s");
  delay(1000);
}