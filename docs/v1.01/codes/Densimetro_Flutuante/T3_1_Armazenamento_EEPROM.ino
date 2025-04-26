// T3_1_Armazenamento_EEPROM.ino
// Função: Densímetro Flutuante
// Artifact ID: 64c8fdd7-949e-4c77-b30a-4853866d5989
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD5.1 (Armazenamento de Dados)
// Descrição: Armazena densidades medidas na EEPROM do Arduino e exibe no Serial Monitor.
// Diretório: docs/V1.01/codes/Densimetro_Flutuante/T3_1

#include <Wire.h>
#include <VL53L0X.h>
#include <EEPROM.h>

#define RECALIBRATE_BUTTON 7 // Pino do botão de recalibração
#define EEPROM_ADDRESS 0 // Endereço inicial na EEPROM
VL53L0X sensor;
float offset = 0;
const float DENSIMETER_MASS = 50.0; // Massa do densímetro em gramas
const float DENSIMETER_AREA = 0.0001; // Área da seção transversal em m²
bool lastButtonState = HIGH;
int recordCount = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T3.1 - Armazenamento EEPROM Iniciado");

  pinMode(RECALIBRATE_BUTTON, INPUT_PULLUP);
  EEPROM.begin(512); // Inicializa EEPROM com 512 bytes

  Wire.begin();
  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Erro: Falha ao inicializar o VL53L0X!");
    while (1);
  }
  sensor.startContinuous();

  Serial.println("Posicione o densímetro na posição de referência e pressione qualquer tecla...");
  while (!Serial.available());
  offset = sensor.readRangeContinuousMillimeters();
  Serial.println("Calibração inicial concluída. Offset: " + String(offset) + " mm");

  // Ler número de registros salvos
  EEPROM.get(EEPROM_ADDRESS, recordCount);
  if (recordCount < 0 || recordCount > 100) recordCount = 0;
}

void loop() {
  bool buttonState = digitalRead(RECALIBRATE_BUTTON);
  if (buttonState == LOW && lastButtonState == HIGH) {
    offset = sensor.readRangeContinuousMillimeters();
    Serial.println("Recalibração concluída. Novo offset: " + String(offset) + " mm");
  }
  lastButtonState = buttonState;

  uint16_t distance = sensor.readRangeContinuousMillimeters();
  if (sensor.timeoutOccurred()) {
    Serial.println("Erro: Timeout na leitura!");
  } else {
    float displacement = (distance - offset) / 1000.0; // Deslocamento em metros
    float volumeDisplaced = displacement * DENSIMETER_AREA; // Volume deslocado em m³
    float density = DENSIMETER_MASS / (volumeDisplaced * 1000); // Densidade em kg/m³

    // Armazenar densidade na EEPROM
    if (recordCount < 100) {
      int address = EEPROM_ADDRESS + sizeof(int) + recordCount * sizeof(float);
      EEPROM.put(address, density);
      recordCount++;
      EEPROM.put(EEPROM_ADDRESS, recordCount);
      EEPROM.commit();
      Serial.println("Densidade armazenada: " + String(density) + " kg/m³, Registro #" + String(recordCount));
    } else {
      Serial.println("EEPROM cheia!");
    }

    Serial.print("Densidade: ");
    Serial.print(density);
    Serial.println(" kg/m³");
  }
  delay(1000);
}