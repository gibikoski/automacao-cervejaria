// artifact_id: <UUID_GERADO_PARA_T0.2>
// Test ID: T0.2
// Function: Controle de Fermentação
// Objective: Confirmar leitura de temperatura do DS18B20
// Setup: DS18B20, resistor 4,7 kΩ
// Details: Conectar DS18B20: DQ(D2), VCC(3V3), GND(GND), resistor 4,7 kΩ entre DQ e VCC.

#include <OneWire.h>
#include <DallasTemperature.h>

// --- Configuração do Sensor ---
#define ONE_WIRE_BUS 2 // Pino onde o DS18B20 está conectado (DQ)
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress sensorAddress; // Armazena o endereço do sensor encontrado
// --------------------------

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Teste T0.2: Ler Temperatura DS18B20");
  Serial.println("--------------------------------------------------");
  Serial.println("Setup: Conecte DS18B20 (DQ->D2, VCC->3V3, GND->GND) com resistor pull-up.");
  Serial.println("Ação: Inicializar o sensor e solicitar leituras de temperatura.");
  Serial.println("Verificação: Verificar se uma leitura de temperatura válida é obtida.");
  Serial.println("--------------------------------------------------");

  sensors.begin(); // Inicializa a biblioteca DallasTemperature

  // Localiza o primeiro sensor no barramento
  if (!sensors.getAddress(sensorAddress, 0)) {
     Serial.println("Erro: Nenhum sensor DS18B20 encontrado no barramento! Verifique a conexão.");
     while(1); // Trava se não encontrar
  } else {
    Serial.print("Sensor DS18B20 encontrado no endereço: ");
    printAddress(sensorAddress);
    Serial.println();
    // Opcional: Definir a resolução (9, 10, 11, or 12 bits)
    sensors.setResolution(sensorAddress, 12);
  }
  Serial.println("--------------------------------------------------");
}

void loop() {
  Serial.print("Solicitando temperaturas...");
  sensors.requestTemperatures(); // Envia o comando para ler a temperatura
  Serial.println(" OK");

  // Obtém a temperatura em Celsius pelo endereço
  float tempC = sensors.getTempC(sensorAddress);

  // Verifica se a leitura foi válida
  if (tempC == DEVICE_DISCONNECTED_C) {
    Serial.println("Erro: Não foi possível ler a temperatura do sensor!");
  } else {
    Serial.print("Temperatura: ");
    Serial.print(tempC);
    Serial.println(" °C");
  }

  delay(2000); // Espera 2 segundos entre as leituras
}

// Função auxiliar para imprimir o endereço do sensor
void printAddress(DeviceAddress deviceAddress) {
  for (uint8_t i = 0; i < 8; i++) {
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}
