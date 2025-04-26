// T0_1_3_Controle_Atuadores.ino
// Função: Controle e Monitoramento
// Artifact ID: 540da23e-139a-444b-8e62-ea86e2f4d580
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RC1.3 (Controle de Atuadores)
// Descrição: Controla um relé com base na temperatura medida pelo DHT22, exibindo status no LCD e Serial Monitor.
// Diretório: docs/V1.01/codes/Controle_e_Monitoramento/T0_1_3

#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 8 // Pino do sensor DHT22
#define DHTTYPE DHT22
#define RELAY_PIN 9 // Pino do relé
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos do LCD
DHT dht(DHTPIN, DHTTYPE);
const float TEMP_THRESHOLD = 30.0; // Limite de temperatura em °C

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.1.3 - Controle Atuadores Iniciado");

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Relé inicialmente desligado
  lcd.begin(16, 2);
  lcd.print("Controle Atuador");

  dht.begin();
  float temp = dht.readTemperature();
  if (isnan(temp)) {
    Serial.println("Erro: Falha ao inicializar o DHT22!");
    lcd.setCursor(0, 1);
    lcd.print("Erro DHT22!");
    while (1);
  }
}

void loop() {
  float temp = dht.readTemperature();
  if (isnan(temp)) {
    Serial.println("Erro: Falha na leitura do DHT22!");
    lcd.setCursor(0, 1);
    lcd.print("Erro Leitura!");
  } else {
    bool relayState = (temp > TEMP_THRESHOLD);
    digitalWrite(RELAY_PIN, relayState ? HIGH : LOW);

    lcd.setCursor(0, 1);
    lcd.print("Temp:");
    lcd.print(temp);
    lcd.print(" R:");
    lcd.print(relayState ? "ON " : "OFF");

    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.print(" °C | Relé: ");
    Serial.println(relayState ? "LIGADO" : "DESLIGADO");
  }
  delay(1000);
}