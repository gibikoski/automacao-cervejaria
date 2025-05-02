// T0_4_Verificar_Leitura_Corrente_INA219.ino
// Função: Controle de Fermentação
// Artifact ID: b46a3026-f024-42e1-9ec4-8e5554588a1c
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD4.3 (Leitura de Corrente)
// Descrição: Verifica a leitura de corrente usando o sensor INA219 conectado ao Arduino R4 Connect via I2C, exibindo os valores no Serial Monitor.
// Diretório: docs/V1.01/codes/Controle_de_Fermentacao/T0_4

#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando o teste do INA219...");

  if (!ina219.begin()) {
    Serial.println("Falha ao encontrar o sensor INA219!");
    while (1);
  }
  Serial.println("INA219 encontrado!");
}

void loop() {
  float busvoltage = ina219.getBusVoltage_V();
  float shuntvoltage = ina219.getShuntVoltage_mV() / 1000;
  float current_mA = ina219.getCurrent_mA();

  Serial.print("Tensão do barramento: ");
  Serial.print(busvoltage);
  Serial.println(" V");
  Serial.print("Tensão de shunt: ");
  Serial.print(shuntvoltage);
  Serial.println(" V");
  Serial.print("Corrente: ");
  Serial.print(current_mA);
  Serial.println(" mA");
  Serial.println();

  delay(1000); // Lê os dados a cada 1 segundo
}
