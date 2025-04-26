// artifact_id: <UUID_GERADO_PARA_T1.1_CF>
// Test ID: T1.1 (Controle de Fermentação)
// Function: Controle de Fermentação
// Objective: Verificar precisão do DS18B20 (±0,5°C)
// Setup: DS18B20, termômetro de referência
// Details: Comparar leitura do DS18B20 (via D2) com termômetro calibrado em água (0-50°C). Erro ≤ ±0,5°C.

#include <OneWire.h>
#include <DallasTemperature.h>

// --- Configuração do Sensor ---
#define ONE_WIRE_BUS 2 // Pino D2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress sensorAddress;
const float MAX_ERROR = 0.5; // Erro máximo permitido em °C
// --------------------------

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Teste T1.1: Validar Precisão DS18B20");
  Serial.println("--------------------------------------------------");
  Serial.println("Setup: Conecte DS18B20 (D2), coloque-o junto a um termômetro de referência em água (0-50°C).");
  Serial.println("Ação: Ler a temperatura do DS18B20. Comparar manualmente com o termômetro de referência.");
  Serial.println("Verificação: A diferença entre as leituras deve ser <= +/- " + String(MAX_ERROR) + " °C.");
  Serial.println("--------------------------------------------------");

  sensors.begin();
  if (!sensors.getAddress(sensorAddress, 0)) {
     Serial.println("Erro: Nenhum sensor DS18B20 encontrado!");
     while(1);
  }
  sensors.setResolution(sensorAddress, 12); // Usar resolução máxima para melhor precisão
  Serial.println("Sensor DS18B20 pronto. Aguardando estabilização térmica...");
  delay(2000); // Pequena pausa
  Serial.println("--------------------------------------------------");
}

void loop() {
  Serial.print("Solicitando temperatura do DS18B20...");
  sensors.requestTemperatures();
  float tempC_DS18B20 = sensors.getTempC(sensorAddress);
  Serial.println(" OK");

  if (tempC_DS18B20 == DEVICE_DISCONNECTED_C) {
    Serial.println("Erro: Falha ao ler o sensor DS18B20!");
  } else {
    Serial.print("Leitura DS18B20: ");
    Serial.print(tempC_DS18B20, 2); // Imprime com 2 casas decimais
    Serial.println(" °C");
    Serial.println(">>> COMPARE este valor com o termômetro de referência e verifique se a diferença é <= " + String(MAX_ERROR) + " °C.");
  }
   Serial.println("--------------------------------------------------");
  delay(5000); // Lê a cada 5 segundos
}
