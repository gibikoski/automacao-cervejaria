// T0_1_3_Testar_I2C_Arduino_R4_Connect.ino
// Função: Controle de Fermentação
// Artifact ID: 45a0dfc9-2878-4812-ae74-3d98531f37c0
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD3.3 (Comunicação I2C)
// Descrição: Testa a comunicação I2C do Arduino R4 Connect, verificando a detecção de um dispositivo I2C (ex.: INA219) e lendo dados.
// Diretório: docs/V1.01/codes/Controle_de_Fermentacao/T0_1_3

#include <Wire.h>

void setup() {
  Serial.begin(9600); // Inicia comunicação serial a 9600 baud
  while (!Serial) {
    ; // Aguarda a conexão do Serial Monitor
  }
  Serial.println("Teste T0.1.3 - I2C Arduino R4 Connect Iniciado");

  Wire.begin(); // Inicia o barramento I2C como mestre
  Serial.println("Escaneando barramento I2C...");

  // Escaneia endereços I2C de 0x08 a 0x77
  byte error, address;
  int deviceCount = 0;

  for (address = 8; address < 120; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Dispositivo I2C encontrado no endereço 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      deviceCount++;
    }
  }

  if (deviceCount == 0) {
    Serial.println("Nenhum dispositivo I2C encontrado.");
  } else {
    Serial.print("Total de dispositivos encontrados: ");
    Serial.println(deviceCount);
  }
}

void loop() {
  // Loop vazio, escaneamento ocorre apenas no setup
}
