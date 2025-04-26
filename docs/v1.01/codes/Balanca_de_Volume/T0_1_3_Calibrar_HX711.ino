// T0_1_3_Calibrar_HX711.ino
// Função: Balança de Volume
// Artifact ID: 7b9603e3-df08-4c0d-adb5-293e8ef391ca
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD1.3 (Calibração de Sensor)
// Descrição: Realiza a calibração do sensor HX711, exibindo peso bruto e permitindo tara no Serial Monitor.
// Diretório: docs/V1.01/codes/Balanca_de_Volume/T0_1_3

#include <HX711.h>

#define HX711_DOUT 3 // Pino de dados do HX711
#define HX711_SCK 2  // Pino de clock do HX711

HX711 scale;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.1.3 - Calibração HX711 Iniciado");

  scale.begin(HX711_DOUT, HX711_SCK);
  if (!scale.is_ready()) {
    Serial.println("Erro: HX711 não está pronto!");
    while (1);
  }

  Serial.println("Coloque um peso conhecido e pressione qualquer tecla para tarar...");
  while (!Serial.available());
  scale.tare();
  Serial.println("Tara realizada. Digite o peso conhecido (em gramas):");

  while (!Serial.available());
  float knownWeight = Serial.parseFloat();
  scale.set_scale(knownWeight / scale.read_average(10));
  Serial.println("Calibração concluída.");
}

void loop() {
  float weight = scale.get_units(10);
  Serial.print("Peso: ");
  Serial.print(weight);
  Serial.println(" g");
  delay(1000);
}