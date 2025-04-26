// T0_2_Confirmar_Leitura_Temperatura_DS18B20.ino
// Função: Controle de Fermentação
// Artifact ID: f2c4643b-0120-4bae-b32c-e3254da9b993
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD4.1 (Leitura de Temperatura)
// Descrição: Confirma a leitura de temperatura usando o sensor DS18B20 conectado ao Arduino R4 Connect, exibindo os valores no Serial Monitor.
// Diretório: docs/V1.01/codes/Controle_de_Fermentacao/T0_2

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 10 // Pino para o barramento OneWire (DS18B20)

OneWire oneWire(ONE_WIRE_BUS); // Inicializa o barramento OneWire
DallasTemperature sensors(&oneWire); // Inicializa a biblioteca DallasTemperature

void setup() {
  Serial.begin(9600); // Inicia comunicação serial a 9600 baud
  while (!Serial) {
    ; // Aguarda a conexão do Serial Monitor
  }
  Serial.println("Teste T0.2 - Leitura Temperatura DS18B20 Iniciado");

  sensors.begin(); // Inicializa o sensor DS18B20
  if (sensors.getDeviceCount() == 0) {
    Serial.println("Nenhum sensor DS18B20 encontrado!");
  } else {
    Serial.print("Sensor DS18B20 encontrado. Endereço: ");
    DeviceAddress sensorAddress;
    sensors.getAddress(sensorAddress, 0);
    for (uint8_t i = 0; i < 8; i++) {
      if (sensorAddress[i] < 16) Serial.print("0");
      Serial.print(sensorAddress[i], HEX);
    }
    Serial.println();
  }
}

void loop() {
  sensors.requestTemperatures(); // Solicita leitura de temperatura
  float tempC = sensors.getTempCByIndex(0); // Lê temperatura em Celsius

  if (tempC != DEVICE_DISCONNECTED_C) {
    Serial.print("Temperatura: ");
    Serial.print(tempC);
    Serial.println(" °C");
  } else {
    Serial.println("Erro: Sensor DS18B20 desconectado!");
  }

  delay(2000); // Aguarda 2 segundos antes da próxima leitura
}