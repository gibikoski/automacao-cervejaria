#include <HX711.h>

// Defina os pinos do HX711
#define LOADCELL_DOUT_PIN 3 // DFT no seu caso
#define LOADCELL_SCK_PIN 2  // SCL no seu caso

HX711 scale;
long tareValue = 0;
float calibrationFactor = 105.60; // Fator de calibração fixo INICIAL
const float knownWeightGram = 1000.0; // Peso de referência para o fator
unsigned long lastReadTime = 0;
const unsigned long readInterval = 1000; // Intervalo de leitura em milissegundos (1 segundo)
bool calibrated = true; // Inicialmente considerado calibrado com o fator fixo
bool calibrationMessageDisplayed = false;
float liquidDensitySG = 1.000; // Densidade inicial (água)
bool densitySet = true; // Densidade inicial já está definida
float lastDisplayedVolume = 0.0;
const float significantChangeThreshold = 0.05;

void reinitializeScale() {
  Serial.println("\nRe-inicializando o sensor HX711...");
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  Serial.println("HX711 re-inicializado.");
  tareValue = 0; // Reset da tara também pode ser útil
}

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
  if (readingWithWeight <= tareValue) {
    Serial.println("Erro na leitura com peso. Certifique-se de que o peso conhecido está na balança.");
    Serial.println("Recalibração abortada. Digite 'r' para tentar novamente.");
    calibrated = true; // Mantém como calibrado com o fator fixo
    calibrationMessageDisplayed = false;
    return;
  }
  calibrationFactor = (float)(readingWithWeight - tareValue) / knownWeightGram;
  Serial.print("Novo fator de calibração calculado: ");
  Serial.println(calibrationFactor, 2);
  Serial.println("Calibração concluída.");
  calibrated = true;
  calibrationMessageDisplayed = false; // Reset da flag após a calibração bem-sucedida
}

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("Iniciando balança com HX711...");
  Serial.println("HX711 inicializado.");
  Serial.print("Fator de calibração inicial: " + String(calibrationFactor, 2) + " (referência: 1000g/SG1.000)");
  Serial.println();
  Serial.println("Densidade inicial do líquido: " + String(liquidDensitySG, 3) + " (SG)");
  Serial.println("Digite 'r' seguido de Enter para recalibrar a balança.");
  Serial.println("Digite 't' seguido de Enter para zerar a balança.");
  Serial.println("Digite 'z' seguido de Enter para re-inicializar o sensor.");
  Serial.println("Digite a densidade do líquido (1.000-1.999) e pressione Enter para alterar.");
  calibrationMessageDisplayed = true; // Marca que a mensagem de instrução foi exibida
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    if (command == "r") {
      calibrated = false; // Permite a recalibração
      calibrateScale();
    } else if (command == "t") {
      tareValue = scale.read();
      Serial.print("Balança zerada. Novo valor de tara: ");
      Serial.println(tareValue);
      lastDisplayedVolume = 0.0; // Força a exibir a próxima leitura após zerar
    } else if (command == "z") {
      reinitializeScale();
      lastDisplayedVolume = 0.0; // Força a exibir a próxima leitura após re-inicializar
    } else if (command.toFloat() >= 1.000 && command.toFloat() <= 1.999) {
      liquidDensitySG = command.toFloat();
      Serial.print("Densidade do líquido definida como: ");
      Serial.println(liquidDensitySG, 3);
      densitySet = true;
      lastDisplayedVolume = 0.0; // Força a exibir a próxima leitura após mudar a densidade
    } else if (command.length() > 0 && command != "r" && command != "t" && command != "z") {
      Serial.println("Comando desconhecido ou densidade inválida. Digite 'r', 't', 'z' ou a densidade (1.000-1.999).");
    }
    while (Serial.available()) {
      Serial.read(); // Limpar o buffer serial
    }
  }

  if (calibrated && scale.is_ready() && densitySet && (millis() - lastReadTime >= readInterval)) {
    long rawValue = scale.read();
    float weightKg = (rawValue - tareValue) / calibrationFactor / 1000.0;
    float volumeLiters = weightKg / liquidDensitySG;

    if (abs(volumeLiters - lastDisplayedVolume) >= significantChangeThreshold) {
      Serial.print("Volume: ");
      Serial.print(volumeLiters, 2); // Apenas 2 dígitos após a vírgula para o volume
      Serial.println(" L");
      lastDisplayedVolume = volumeLiters; // Atualiza o último volume exibido
    }
    lastReadTime = millis(); // Correção aqui!
  } else if (!calibrated && !calibrationMessageDisplayed) {
    Serial.println("A balança precisa ser calibrada. Digite 'r' seguido de Enter.");
    calibrationMessageDisplayed = true; // Marca que a mensagem foi exibida
  } else if (!scale.is_ready() && (millis() - lastReadTime >= readInterval)) { // Correção aqui!
    Serial.println("HX711 não está pronto.");
    lastReadTime = millis();
  } else if (!densitySet) {
    Serial.println("Digite a densidade do líquido (1.000-1.999) e pressione Enter.");
  }
  delay(10); // Pequeno delay para evitar ocupação excessiva da CPU
}
