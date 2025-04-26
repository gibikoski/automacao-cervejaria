// artifact_id: <UUID_GERADO_PARA_T4.1_CF>
// Test ID: T4.1 (Controle de Fermentação)
// Function: Controle de Fermentação
// Objective: Verificar autonomia da bateria 18650
// Setup: Bateria 18650, circuito de proteção
// Details: Conectar bateria 18650 ao circuito. Medir autonomia com carga típica (ex.: Arduino + sensores) por 24h.

// Incluir bibliotecas relevantes, se houver monitoramento de tensão/corrente (ex: INA219)
// #include <Wire.h>
// #include <Adafruit_INA219.h>
// Adafruit_INA219 ina219;

// Definir pino para leitura de tensão da bateria (se usando divisor de tensão)
// const int batteryVoltagePin = A0; // Exemplo
// const float R1 = 10000.0; // Resistor superior do divisor (ex: 10k)
// const float R2 = 10000.0; // Resistor inferior do divisor (ex: 10k)
// const float AREF_VOLTAGE = 3.3; // Tensão de referência do ADC

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Teste T4.1: Verificar Autonomia Bateria 18650");
  Serial.println("--------------------------------------------------");
  Serial.println("Setup: Bateria 18650 CARREGADA conectada alimentando o Arduino e sensores.");
  Serial.println("       (Opcional: INA219 ou divisor de tensão para monitorar a bateria).");
  Serial.println("Ação: Deixar o sistema rodando com sua carga típica (sensores lendo, talvez WiFi/MQTT publicando).");
  Serial.println("      Marcar o horário de início.");
  Serial.println("Verificação: Medir quanto tempo o sistema permanece operacional (ex: por 24 horas).");
  Serial.println("             (Opcional: Monitorar a tensão da bateria via Serial ou MQTT até atingir o corte).");
  Serial.println("--------------------------------------------------");
  Serial.println("Iniciando teste de autonomia...");
  Serial.print("Horário de início: "); // Idealmente, sincronizar com NTP ou registrar manualmente
  Serial.println(millis()); // Tempo em ms desde o boot

  // Inicializar INA219 ou ADC se estiver monitorando
  // Wire.begin();
  // if (ina219.begin()) { Serial.println("INA219 OK"); } else { Serial.println("INA219 Falha"); }
  // pinMode(batteryVoltagePin, INPUT);
   Serial.println("--------------------------------------------------");
}

void loop() {
  // Simular a carga típica do sistema aqui
  // Exemplo: Ler sensores, piscar LED, enviar dados via WiFi/MQTT periodicamente

  Serial.print("Tempo rodando (ms): ");
  Serial.println(millis());

  // --- Monitoramento Opcional da Bateria ---
  // // Usando INA219
  // float busVoltage = ina219.getBusVoltage_V();
  // float current_mA = ina219.getCurrent_mA();
  // Serial.print(" | Vbat (INA): "); Serial.print(busVoltage); Serial.print(" V");
  // Serial.print(" | Corrente: "); Serial.print(current_mA); Serial.println(" mA");

  // // Usando Divisor de Tensão e ADC
  // int adcValue = analogRead(batteryVoltagePin);
  // float voltage = adcValue * (AREF_VOLTAGE / 1023.0); // Tensão no pino do Arduino
  // float batteryVoltage = voltage * ((R1 + R2) / R2); // Tensão real da bateria
  // Serial.print(" | Vbat (ADC): "); Serial.print(batteryVoltage, 2); Serial.println(" V");
  // ---------------------------------------

  // Coloque aqui a lógica normal de operação do seu sistema
  // Ex: Ler DS18B20, controlar SSR (se aplicável neste teste), etc.
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
   digitalWrite(LED_BUILTIN, LOW);


  delay(10000); // Executa a lógica a cada 10 segundos
}
