// T0_1_2_Monitoramento_Temperatura.ino
// Função: Controle e Monitoramento
// Artifact ID: daa0f8ad-47cf-4179-beb5-b4678c7d6bec
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RC1.2 (Monitoramento de Temperatura)
// Descrição: Monitora a temperatura com o sensor DHT22, exibindo valores no LCD e Serial Monitor.
// Diretório: docs/V1.01/codes/Controle_e_Monitoramento/T0_1_2

#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 8 // Pino do sensor DHT22
#define DHTTYPE DHT22
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos do LCD
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.1.2 - Monitoramento Temperatura Iniciado");

  lcd.begin(16, 2);
  lcd.print("Monitor Temp");

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
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print(" C   ");

    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println(" °C");
  }
  delay(1000);
}