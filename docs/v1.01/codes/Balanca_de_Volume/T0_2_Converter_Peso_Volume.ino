// T0_2_Converter_Peso_Volume.ino
// Função: Balança de Volume
// Artifact ID: c0afaf04-d934-4c2c-aeac-60a0a4834fc8
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD2.1 (Conversão de Peso para Volume)
// Descrição: Converte o peso medido pelo HX711 em volume (litros), assumindo densidade da água (1 g/ml).
// Diretório: docs/V1.01/codes/Balanca_de_Volume/T0_2

#include <HX711.h>

#define HX711_DOUT 3 // Pino de dados do HX711
#define HX711_SCK 2  // Pino de clock do HX711

HX711 scale;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.2 - Conversão Peso para Volume Iniciado");

  scale.begin(HX711_DOUT, HX711_SCK);
  scale.tare();
  scale.set_scale(100.0); // Ajustar após calibração real
}

void loop() {
  float weight = scale.get_units(10);
  float volume = weight / 1000.0; // 1 g = 1 ml, 1000 ml = 1 L

  Serial.print("Peso: ");
  Serial.print(weight);
  Serial.print(" g | Volume: ");
  Serial.print(volume);
  Serial.println(" L");
  delay(1000);
}