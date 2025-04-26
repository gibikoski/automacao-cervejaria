// T0_1_1_Inicializar_HX711.ino
// Função: Balança de Volume
// Artifact ID: a33d4101-3eb3-4b33-91e9-3b9d15b77630
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD1.1 (Inicialização de Sensor)
// Descrição: Testa a inicialização do sensor HX711, verificando comunicação e exibindo status no Serial Monitor.
// Diretório: docs/V1.01/codes/Balanca_de_Volume/T0_1_1

#include <HX711.h>

#define HX711_DOUT 3 // Pino de dados do HX711
#define HX711_SCK 2  // Pino de clock do HX711

HX711 scale;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.1.1 - Inicialização HX711 Iniciado");

  scale.begin(HX711_DOUT, HX711_SCK);
  if (scale.is_ready()) {
    Serial.println("HX711 inicializado com sucesso.");
  } else {
    Serial.println("Erro: Falha ao inicializar o HX711!");
  }
}

void loop() {
  // Apenas inicialização, sem loop ativo
}