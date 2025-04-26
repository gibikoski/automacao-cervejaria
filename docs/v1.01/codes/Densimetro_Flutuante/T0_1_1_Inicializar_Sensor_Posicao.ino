// T0_1_1_Inicializar_Sensor_Posicao.ino
// Função: Densímetro Flutuante
// Artifact ID: 0561d7ee-269b-4666-b230-7f8098353019
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD1.1 (Inicialização de Sensor)
// Descrição: Testa a inicialização do sensor de posição (ex.: VL53L0X ToF), verificando comunicação e exibindo status no Serial Monitor.
// Diretório: docs/V1.01/codes/Densimetro_Flutuante/T0_1_1

#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.1.1 - Inicialização Sensor Posição Iniciado");

  Wire.begin();
  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Erro: Falha ao inicializar o VL53L0X!");
    while (1);
  }
  Serial.println("VL53L0X inicializado com sucesso.");
  sensor.startContinuous();
}

void loop() {
  // Apenas inicialização, sem loop ativo
}