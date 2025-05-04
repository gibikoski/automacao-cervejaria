#include <HX711.h>

// Defina os pinos do HX711
#define LOADCELL_DOUT_PIN 3 // DFT no seu caso
#define LOADCELL_SCK_PIN 2  // SCL no seu caso

HX711 scale;

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando teste do HX711...");
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  Serial.println("HX711 inicializado.");
}

void loop() {
  if (scale.is_ready()) {
    long reading = scale.read();
    Serial.print("Leitura bruta do HX711: ");
    Serial.println(reading);
  } else {
    Serial.println("HX711 não está pronto.");
  }
  delay(500);
}
