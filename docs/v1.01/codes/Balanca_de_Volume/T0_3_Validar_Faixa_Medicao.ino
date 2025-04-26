// T0_3_Validar_Faixa_Medicao.ino
// Função: Balança de Volume
// Artifact ID: c7c30809-5130-4d41-82e3-cd6817face86
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD2.2 (Validação de Faixa)
// Descrição: Valida se o peso medido pelo HX711 está dentro da faixa esperada (ex.: 0–5000 g).
// Diretório: docs/V1.01/codes/Balanca_de_Volume/T0_3

#include <HX711.h>

#define HX711_DOUT 3 // Pino de dados do HX711
#define HX711_SCK 2  // Pino de clock do HX711
#define MAX_WEIGHT 5000 // Peso máximo em gramas

HX711 scale;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.3 - Validação Faixa Medição Iniciado");

  scale.begin(HX711_DOUT, HX711_SCK);
  scale.tare();
  scale.set_scale(100.0); // Ajustar após calibração real
}

void loop() {
  float weight = scale.get_units(10);
  Serial.print("Peso: ");
  Serial.print(weight);
  Serial.print(" g");

  if (weight >= 0 && weight <= MAX_WEIGHT) {
    Serial.println(" (Faixa válida)");
  } else {
    Serial.println(" (Fora da faixa esperada)");
  }
  delay(1000);
}