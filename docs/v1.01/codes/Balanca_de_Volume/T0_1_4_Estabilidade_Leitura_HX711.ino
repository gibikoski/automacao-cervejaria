#include <HX711.h>

// Defina os pinos do HX711
#define LOADCELL_DOUT_PIN 3 // DFT no seu caso
#define LOADCELL_SCK_PIN 2  // SCL no seu caso

HX711 scale;
long tareValue = 0;
float calibrationFactor = 1.0; // Inicialmente sem calibração
const float knownWeightGram = 1000.0; // Insira o seu peso conhecido aqui

void calibrateScale() {
  Serial.println("\nProcesso de calibração:");
  Serial.println("1. Certifique-se de que não há peso na balança e pressione 't' seguido de Enter para zerar.");
  while (Serial.available() == 0 || Serial.read() != 't') {
    delay(100);
  }
  tareValue = scale.read();
  Serial.print("Tara definida como: ");
  Serial.println(tareValue);

  Serial.println("2. Coloque um peso conhecido de " + String(knownWeightGram) + " gramas na balança.");
  Serial.println("3. Aguarde alguns segundos para estabilizar e pressione 'c' seguido de Enter.");
  while (Serial.available() == 0 || Serial.read() != 'c') {
    delay(100);
  }
  long readingWithWeight = scale.read();
  calibrationFactor = (float)(readingWithWeight - tareValue) / knownWeightGram;
  Serial.print("Fator de calibração calculado: ");
  Serial.println(calibrationFactor);
  Serial.println("Calibração concluída. O fator de calibração está armazenado.");
}

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("Iniciando balança com HX711...");

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  Serial.println("HX711 inicializado.");

  calibrateScale();
}

void loop() {
  if (scale.is_ready() && calibrationFactor != 1.0) {
    long rawValue = scale.read();
    float weightKg = (rawValue - tareValue) / calibrationFactor / 1000.0;
    Serial.print("Peso: ");
    Serial.print(weightKg, 3); // Exibe com 3 casas decimais
    Serial.println(" kg");
  } else if (calibrationFactor == 1.0) {
    Serial.println("A balança ainda não foi calibrada.");
  } else {
    Serial.println("HX711 não está pronto.");
  }
  delay(500);
}
