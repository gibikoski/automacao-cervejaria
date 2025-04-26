// T0_1_4_Estabilidade_Leitura_Posicao.ino
// Função: Densímetro Flutuante
// Artifact ID: 11eb892f-6a87-460c-ab94-e7e0fb92cd5b
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD1.4 (Estabilidade de Leitura)
// Descrição: Avalia a estabilidade da leitura de posição do VL53L0X, calculando média e desvio padrão de 10 leituras.
// Diretório: docs/V1.01/codes/Densimetro_Flutuante/T0_1_4

#include <Wire.h>
#include <VL53L0X.h>
#include <math.h>

VL53L0X sensor;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.1.4 - Estabilidade Leitura Posição Iniciado");

  Wire.begin();
  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Erro: Falha ao inicializar o VL53L0X!");
    while (1);
  }
  sensor.startContinuous();
}

void loop() {
  float readings[10];
  float sum = 0;
  for (int i = 0; i < 10; i++) {
    readings[i] = sensor.readRangeContinuousMillimeters();
    sum += readings[i];
    delay(100);
  }
  float average = sum / 10;

  float deviation = 0;
  for (int i = 0; i < 10; i++) {
    deviation += pow(readings[i] - average, 2);
  }
  deviation = sqrt(deviation / 10);

  Serial.print("Distância média: ");
  Serial.print(average);
  Serial.print(" mm | Desvio padrão: ");
  Serial.print(deviation);
  Serial.println(" mm");
  delay(2000);
}