// T0_1_2_Leitura_Posicao_Bruta.ino
// Função: Densímetro Flutuante
// Artifact ID: 22c3cdbe-3527-4688-8431-6f2114020132
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD1.2 (Leitura de Dados Brutos)
// Descrição: Testa a leitura de dados brutos de posição (distância) do sensor VL53L0X, exibindo valores no Serial Monitor.
// Diretório: docs/V1.01/codes/Densimetro_Flutuante/T0_1_2

#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.1.2 - Leitura Posição Bruta Iniciado");

  Wire.begin();
  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Erro: Falha ao inicializar o VL53L0X!");
    while (1);
  }
  sensor.startContinuous();
}

void loop() {
  uint16_t distance = sensor.readRangeContinuousMillimeters();
  if (sensor.timeoutOccurred()) {
    Serial.println("Erro: Timeout na leitura do VL53L0X!");
  } else {
    Serial.print("Distância: ");
    Serial.print(distance);
    Serial.println(" mm");
  }
  delay(1000);
}