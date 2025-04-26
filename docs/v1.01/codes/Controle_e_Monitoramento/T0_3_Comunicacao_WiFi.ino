// T0_3_Comunicacao_WiFi.ino
// Função: Controle e Monitoramento
// Artifact ID: 75562dd6-a594-459c-b571-14ac81de3abd
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RC2.2 (Comunicação Remota)
// Descrição: Estabelece conexão WiFi e envia dados de um sensor analógico (simulando monitoramento) para o Serial Monitor, simulando envio remoto.
// Diretório: docs/V1.01/codes/Controle_e_Monitoramento/T0_3

#include <WiFi.h>
#include <LiquidCrystal.h>

#define SENSOR_PIN A0 // Pino analógico para simular sensor
const char* ssid = "SUA_REDE_WIFI";
const char* password = "SUA_SENHA_WIFI";
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos do LCD

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.3 - Comunicação WiFi Iniciado");

  lcd.begin(16, 2);
  lcd.print("Conectando WiFi");

  Serial.print("Conectando à rede: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  int wifiAttempts = 0;
  while (WiFi.status() != WL_CONNECTED && wifiAttempts < 20) {
    delay(500);
    Serial.print(".");
    lcd.setCursor(wifiAttempts % 16, 1);
    lcd.print(".");
    wifiAttempts++;
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi conectado. IP: " + WiFi.localIP().toString());
    lcd.setCursor(0, 1);
    lcd.print("IP:");
    lcd.print(WiFi.localIP());
  } else {
    Serial.println("Erro: Falha ao conectar ao WiFi!");
    lcd.setCursor(0, 1);
    lcd.print("Erro WiFi!");
    while (1);
  }
}

void loop() {
  int sensorValue = analogRead(SENSOR_PIN);
  float scaledValue = sensorValue * (100.0 / 1023.0); // Escala 0-100 para simulação

  lcd.setCursor(0, 1);
  lcd.print("Valor: ");
  lcd.print(scaledValue);
  lcd.print("   ");

  Serial.print("Sensor: ");
  Serial.print(scaledValue);
  Serial.println(" (enviado remotamente)");
  delay(2000);
}