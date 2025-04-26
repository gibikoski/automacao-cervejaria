/*
 * Teste: T0.1.3 - Testar I2C do ESP32-C3 (Balança)
 * Artifact ID: b5c6d7e8-f9a0-4091-2b3c-4d5e6f7a8b9c
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisito: RD3.1 (I2C)
 * Descrição: Testa a comunicação I2C do ESP32-C3 com o sensor MPU6050.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.1.3.              |
 */

/*
 * Setup:
 * - Conectar MPU6050: SDA para GPIO8, SCL para GPIO9, VCC para 3V3, GND para GND do ESP32-C3.
 * - Adicionar pull-ups de 4,7 kΩ entre SDA/SCL e 3V3.
 * - Observar leituras de aceleração no Serial Monitor (9600 baud).
 */

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T0.1.3: Testar I2C do ESP32-C3 (Balança)");
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
  delay(1000);
}