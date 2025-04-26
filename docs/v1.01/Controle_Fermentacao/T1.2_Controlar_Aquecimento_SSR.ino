// artifact_id: <UUID_GERADO_PARA_T1.2_CF>
// Test ID: T1.2 (Controle de Fermentação)
// Function: Controle de Fermentação
// Objective: Confirmar controle de aquecimento via SSR-10DA
// Setup: SSR-10DA, resistor de aquecimento
// Details: Conectar SSR-10DA como em T0.3. Ligar/desligar resistor via D3. Verificar aquecimento controlado.

const int ssrPin = 3; // Pino D3 para controlar o SSR
const int TEMP_SENSOR_PIN = 2; // Pino D2 para o DS18B20

// Incluir bibliotecas do DS18B20
#include <OneWire.h>
#include <DallasTemperature.h>
OneWire oneWire(TEMP_SENSOR_PIN);
DallasTemperature sensors(&oneWire);
DeviceAddress sensorAddress;

// --- Parâmetros de Controle (Exemplo Simples - ON/OFF) ---
float setpoint = 30.0; // Temperatura desejada (exemplo)
float hysteresis = 1.0; // Histerese para evitar chaveamento rápido
// ---------------------------------------------------------

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Teste T1.2: Controlar Aquecimento via SSR");
  Serial.println("--------------------------------------------------");
  Serial.println("Setup: Conecte SSR (Controle D3), carga (resistor aquecimento) na saída AC.");
  Serial.println("       Conecte DS18B20 (D2) para monitorar a temperatura perto do aquecedor.");
  Serial.println("CUIDADO: ALTA TENSÃO E CALOR!");
  Serial.println("Ação: O SSR será ligado/desligado para tentar manter a temperatura em " + String(setpoint) + "°C.");
  Serial.println("Verificação: Observar se a temperatura sobe quando o SSR está ligado e se ele desliga perto do setpoint.");
  Serial.println("--------------------------------------------------");

  pinMode(ssrPin, OUTPUT);
  digitalWrite(ssrPin, LOW); // Começa desligado

  sensors.begin();
   if (!sensors.getAddress(sensorAddress, 0)) {
     Serial.println("Erro: Nenhum sensor DS18B20 encontrado!");
     // Considerar parar ou continuar sem controle de temp? Por ora, continua.
  } else {
      sensors.setResolution(sensorAddress, 12);
      Serial.println("Sensor de temperatura inicializado.");
  }
   Serial.println("--------------------------------------------------");
}

void loop() {
  // 1. Ler a temperatura atual
  sensors.requestTemperatures();
  float currentTemp = sensors.getTempC(sensorAddress);

  if (currentTemp == DEVICE_DISCONNECTED_C) {
    Serial.println("Erro ao ler temperatura! Desligando aquecedor por segurança.");
    digitalWrite(ssrPin, LOW);
    delay(5000); // Espera antes de tentar novamente
    return;
  }

  Serial.print("Temperatura Atual: "); Serial.print(currentTemp, 2); Serial.print("°C");
  Serial.print(" | Setpoint: "); Serial.print(setpoint, 1); Serial.println("°C");

  // 2. Lógica de Controle ON/OFF com Histerese
  if (currentTemp < (setpoint - hysteresis / 2.0)) {
    // Temperatura abaixo do limite inferior -> Ligar aquecedor
    if (digitalRead(ssrPin) == LOW) {
      Serial.println(">>> Ligando Aquecedor (SSR ON)");
      digitalWrite(ssrPin, HIGH);
    } else {
        Serial.println("    Aquecedor já está LIGADO.");
    }
  } else if (currentTemp > (setpoint + hysteresis / 2.0)) {
    // Temperatura acima do limite superior -> Desligar aquecedor
     if (digitalRead(ssrPin) == HIGH) {
       Serial.println(">>> Desligando Aquecedor (SSR OFF)");
       digitalWrite(ssrPin, LOW);
     } else {
         Serial.println("    Aquecedor já está DESLIGADO.");
     }
  } else {
      // Dentro da banda de histerese -> Manter estado atual
      Serial.println("    Temperatura na faixa de histerese. Mantendo estado.");
  }

  Serial.println("--------------------------------------------------");
  delay(3000); // Intervalo entre verificações
}
