// T2_1_Integrar_Leitura_Controle_DS18B20_SSR.ino
// Função: Controle de Fermentação
// Artifact ID: de329107-3a66-4112-80bb-58bf0dca6b72
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD6.1 (Integração de Leitura e Controle)
// Descrição: Integra a leitura de temperatura (DS18B20) com o controle do relé SSR-10DA, ligando/desligando com base na temperatura.
// Diretório: docs/V1.01/codes/Controle_de_Fermentacao/T2_1

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 10 // Pino para o DS18B20
#define SSR_PIN 9 // Pino para o relé SSR-10DA

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  pinMode(SSR_PIN, OUTPUT);
  digitalWrite(SSR_PIN, LOW);
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T2.1 - Integração DS18B20 e SSR-10DA Iniciado");

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
    if (tempC > 25.0) {
      digitalWrite(SSR_PIN, HIGH);
      Serial.println(" | Relé SSR-10DA: LIGADO");
    } else {
      digitalWrite(SSR_PIN, LOW);
      Serial.println(" | Relé SSR-10DA: DESLIGADO");
    }
  } else {
    Serial.println("Erro: Sensor DS18B20 desconectado!");
    digitalWrite(SSR_PIN, LOW);
  }

  delay(2000);
}