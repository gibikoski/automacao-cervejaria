// T0_1_3_Calibrar_Sensor_Posicao.ino
// Função: Densímetro Flutuante
// Artifact ID: 3b6b3d33-7492-47ad-9fa5-8edd13ec0d5e
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD1.3 (Calibração de Sensor)
// Descrição: Realiza a calibração do sensor VL53L0X, ajustando a posição de referência (zero) e exibindo distâncias calibradas.
// Diretório: docs/V1.01/codes/Densimetro_Flutuante/T0_1_3

#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
float offset = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.1.3 - Calibração Sensor Posição Iniciado");

  Wire.begin();
  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Erro: Falha ao inicializar o VL53L0X!");
    while (1);
  }
  sensor.startContinuous();

  Serial.println("Posicione o densímetro na posição de referência e pressione qualquer tecla...");
  while (!Serial.available());
  offset = sensor.readRangeContinuousMillimeters();
  Serial.println("Calibração concluída. Offset: " + String(offset) + " mm");
}

void loop() {
  uint16_t distance = sensor.readRangeContinuousMillimeters();
  if (sensor.timeoutOccurred()) {
    Serial.println("Erro: Timeout na leitura!");
  } else {
    float calibratedDistance = distance - offset;
    Serial.print("Distância calibrada: ");
    Serial.print(calibratedDistance);
    Serial.println(" mm");
  }
  delay(1000);
}