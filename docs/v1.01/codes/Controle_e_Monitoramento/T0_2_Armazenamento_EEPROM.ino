// T0_2_Armazenamento_EEPROM.ino
// Função: Controle e Monitoramento
// Artifact ID: bf32b947-f819-4d47-8c88-aff04dc64a12
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RC2.1 (Armazenamento de Dados)
// Descrição: Armazena temperaturas medidas pelo DHT22 na EEPROM e exibe no Serial Monitor.
// Diretório: docs/V1.01/codes/Controle_e_Monitoramento/T0_2

#include <DHT.h>
#include <EEPROM.h>

#define DHTPIN 8 // Pino do sensor DHT22
#define DHTTYPE DHT22
#define EEPROM_ADDRESS 0 // Endereço inicial na EEPROM
DHT dht(DHTPIN, DHTTYPE);
int recordCount = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.2 - Armazenamento EEPROM Iniciado");

  EEPROM.begin(512); // Inicializa EEPROM com 512 bytes
  dht.begin();
  float temp = dht.readTemperature();
  if (isnan(temp)) {
    Serial.println("Erro: Falha ao inicializar o DHT22!");
    while (1);
  }

  // Ler número de registros salvos
  EEPROM.get(EEPROM_ADDRESS, recordCount);
  if (recordCount < 0 || recordCount > 100) recordCount = 0;
}

void loop() {
  float temp = dht.readTemperature();
  if (isnan(temp)) {
    Serial.println("Erro: Falha na leitura do DHT22!");
  } else {
    // Armazenar temperatura na EEPROM
    if (recordCount < 100) {
      int address = EEPROM_ADDRESS + sizeof(int) + recordCount * sizeof(float);
      EEPROM.put(address, temp);
      recordCount++;
      EEPROM.put(EEPROM_ADDRESS, recordCount);
      EEPROM.commit();
      Serial.println("Temperatura armazenada: " + String(temp) + " °C, Registro #" + String(recordCount));
    } else {
      Serial.println("EEPROM cheia!");
    }

    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println(" °C");
  }
  delay(2000);
}