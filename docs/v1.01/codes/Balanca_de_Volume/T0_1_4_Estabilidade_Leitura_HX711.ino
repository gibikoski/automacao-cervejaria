// T0_1_4_Estabilidade_Leitura_HX711.ino
// Função: Balança de Volume
// Artifact ID: de2c4e30-a29e-4173-b04d-bee48e4406c9
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD1.4 (Estabilidade de Leitura)
// Descrição: Testa a estabilidade da leitura do HX711, exibindo peso médio e desvio no Serial Monitor.
// Diretório: docs/V1.01/codes/Balanca_de_Volume/T0_1_4

#include <HX711.h>

#define HX711_DOUT 3 // Pino de dados do HX711
#define HX711_SCK 2  // Pino de clock do HX711

HX711 scale;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.1.4 - Estabilidade Leitura HX711 Iniciado");

  scale.begin(HX711_DOUT, HX711_SCK);
  scale.tare();
  scale.set_scale(100.0); // Valor temporário, ajustar após calibração real
}

void loop() {
  float readings[10];
  float sum = 0;
  for (int i = 0; i < 10; i++) {
    readings[i] = scale.get_units();
    sum += readings[i];
    delay(100);
  }
  float average = sum / 10;

  float deviation = 0;
  for (int i = 0; i < 10; i++) {
    deviation += pow(readings[i] - average, 2);
  }
  deviation = sqrt(deviation / 10);

  Serial.print("Peso médio: ");
  Serial.print(average);
  Serial.print(" g | Desvio padrão: ");
  Serial.print(deviation);
  Serial.println(" g");
  delay(2000);
}