// T4_1_Integracao_Completa_WiFi_LCD.ino
// Função: Densímetro Flutuante
// Artifact ID: 2429e396-92e8-4a52-a58d-1c301cd69acd
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD6.1 (Integração Completa)
// Descrição: Integra sensor, LCD, WiFi, botão e EEPROM para monitoramento, exibição e envio de densidades.
// Diretório: docs/V1.01/codes/Densimetro_Flutuante/T4_1

#include <Wire.h>
#include <VL53L0X.h>
#include <LiquidCrystal.h>
#include <WiFi.h>
#include <EEPROM.h>

#define RECALIBRATE_BUTTON 7 // Pino do botão de recalibração
#define EEPROM_ADDRESS 0 // Endereço inicial na EEPROM
const char* ssid = "SUA_REDE_WIFI";
const char* password = "SUA_SENHA_WIFI";
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos do LCD
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
  Serial.println("Teste T4.1 - Integração Completa WiFi LCD Iniciado");

  pinMode(RECALIBRATE_BUTTON, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.print("Densimetro");
  EEPROM.begin(512);

  Wire.begin();
  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Erro: Falha ao inicializar o VL53L0X!");
    lcd.setCursor(0, 1);
    lcd.print("Erro Sensor!");
    while (1);
  }
  sensor.startContinuous();

  Serial.print("Conectando à rede: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado. IP: " + WiFi.localIP().toString());

  Serial.println("Posicione o densímetro na posição de referência e pressione qualquer tecla...");
  while (!Serial.available());
  offset = sensor.readRangeContinuousMillimeters();
  Serial.println("Calibração inicial concluída. Offset: " + String(offset) + " mm");

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
    lcd.setCursor(0, 1);
    lcd.print("Erro Leitura!");
  } else {
    float displacement = (distance - offset) / 1000.0; // Deslocamento em metros
    float volumeDisplaced = displacement * DENSIMETER_AREA; // Volume deslocado em m³
    float density = DENSIMETER_MASS / (volumeDisplaced * 1000); // Densidade em kg/m³

    lcd.setCursor(0, 1);
    lcd.print("Dens: ");
    lcd.print(density);
    lcd.print(" kg/m3");

    if (recordCount < 100) {
      int address = EEPROM_ADDRESS + sizeof(int) + recordCount * sizeof(float);
      EEPROM.put(address, density);
      recordCount++;
      EEPROM.put(EEPROM_ADDRESS, recordCount);
      EEPROM.commit();
      Serial.println("Densidade armazenada: " + String(density) + " kg/m³, Registro #" + String(recordCount));
    }

    Serial.print("Densidade: ");
    Serial.print(density);
    Serial.println(" kg/m³");
    Serial.println("Dados enviados (simulado): Densidade=" + String(density) + " kg/m³");
  }
  delay(1000);
}