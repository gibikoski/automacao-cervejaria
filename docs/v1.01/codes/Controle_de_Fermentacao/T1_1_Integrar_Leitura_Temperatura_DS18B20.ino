// T1_1_Integrar_Leitura_Temperatura_DS18B20.ino
// Função: Controle de Fermentação
// Artifact ID: 6e0e2fa6-3fbc-4d81-994b-bebf44afbc51
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD5.1 (Integração de Leitura de Temperatura)
// Descrição: Integra a leitura de temperatura com o sensor DS18B20, exibindo valores no Serial Monitor com validação de faixa.
// Diretório: docs/V1.01/codes/Controle_de_Fermentacao/T1_1

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 10 // Pino para o barramento OneWire (DS18B20)

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T1.1 - Integração Leitura Temperatura DS18B20 Iniciado");

  sensors.begin();
  if (sensors.getDeviceCount() == 0) {
    Serial.println("Nenhum sensor DS18B20 encontrado!");
  } else {
    Serial.println("Sensor DS18B20 detectado.");
  }
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  if (tempC != DEVICE_DISCONNECTED_C) {
    Serial.print("Temperatura: ");
    Serial.print(tempC);
    Serial.print(" °C");
    if (tempC >= 0 && tempC <= 50) {
      Serial.println(" (Faixa válida)");
    } else {
      Serial.println(" (Fora da faixa esperada)");
    }
  } else {
    Serial.println("Erro: Sensor DS18B20 desconectado!");
  }

  delay(2000);
}