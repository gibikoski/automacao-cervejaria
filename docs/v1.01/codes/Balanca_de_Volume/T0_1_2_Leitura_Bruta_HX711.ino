// T0_1_2_Leitura_Bruta_HX711.ino
// Função: Balança de Volume
// Artifact ID: 1571700b-b50a-4ee7-9838-20741d90120c
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD1.2 (Leitura de Dados Brutos)
// Descrição: Testa a leitura de dados brutos do sensor HX711, exibindo valores no Serial Monitor.
// Diretório: docs/V1.01/codes/Balanca_de_Volume/T0_1_2

#include <HX711.h>

#define HX711_DOUT 3 // Pino de dados do HX711
#define HX711_SCK 2  // Pino de clock do HX711

HX711 scale;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.1.2 - Leitura Bruta HX711 Iniciado");

  scale.begin(HX711_DOUT, HX711_SCK);
  if (!scale.is_ready()) {
    Serial.println("Erro: HX711 não está pronto!");
    while (1);
  }
}

void loop() {
  if (scale.is_ready()) {
    long reading = scale.read();
    Serial.print("Leitura bruta: ");
    Serial.println(reading);
  } else {
    Serial.println("Erro: HX711 não responde!");
  }
  delay(1000);
}