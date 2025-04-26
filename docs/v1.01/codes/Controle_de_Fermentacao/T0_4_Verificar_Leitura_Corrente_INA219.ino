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

Adafruit_INA219 ina219; // Inicializa o sensor INA219

void setup() {
  Serial.begin(9600); // Inicia comunicação serial a 9600 baud
  while (!Serial) {
    ; // Aguarda a conexão do Serial Monitor
  }
  Serial.println("Teste T0.4 - Leitura Corrente INA219 Iniciado");

  // Inicializa o sensor INA219
  if (!ina219.begin()) {
    Serial.println("Erro: Falha ao inicializar o INA219!");
    while (1); // Para a execução em caso de erro
  }
  Serial.println("Sensor INA219 inicializado com sucesso.");
}

void loop() {
  float current_mA = ina219.getCurrent_mA(); // Lê a corrente em mA
  float voltage_V = ina219.getBusVoltage_V(); // Lê a tensão no barramento em V

  Serial.print("Corrente: ");
  Serial.print(current_mA);
  Serial.println(" mA");
  Serial.print("Tensão: ");
  Serial.print(voltage_V);
  Serial.println(" V");

  delay(2000); // Aguarda 2 segundos antes da próxima leitura
}