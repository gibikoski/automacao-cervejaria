// T0_1_1_Inicializacao_Sistema_Controle.ino
// Função: Controle e Monitoramento
// Artifact ID: 1a5148be-b003-4276-8d1e-024aa5d998c0
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RC1.1 (Inicialização do Sistema)
// Descrição: Inicializa sensores (temperatura e densidade), LCD e WiFi, exibindo status inicial no LCD e Serial Monitor.
// Diretório: docs/V1.01/codes/Controle_e_Monitoramento/T0_1_1

#include <Wire.h>
#include <DHT.h>
#include <VL53L0X.h>
#include <LiquidCrystal.h>
#include <WiFi.h>

#define DHTPIN 8 // Pino do sensor DHT22
#define DHTTYPE DHT22
#define RECALIBRATE_BUTTON 7 // Pino do botão de recalibração
const char* ssid = "SUA_REDE_WIFI";
const char* password = "SUA_SENHA_WIFI";
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos do LCD
VL53L0X sensor;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T0.1.1 - Inicialização Sistema Controle Iniciado");

  pinMode(RECALIBRATE_BUTTON, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.print("Inicializando...");

  // Inicializar DHT22
  dht.begin();
  float temp = dht.readTemperature();
  if (isnan(temp)) {
    Serial.println("Erro: Falha ao inicializar o DHT22!");
    lcd.setCursor(0, 1);
    lcd.print("Erro DHT22!");
    while (1);
  }

  // Inicializar VL53L0X
  Wire.begin();
  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Erro: Falha ao inicializar o VL53L0X!");
    lcd.setCursor(0, 1);
    lcd.print("Erro VL53L0X!");
    while (1);
  }
  sensor.startContinuous();

  // Inicializar WiFi
  Serial.print("Conectando à rede: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  int wifiAttempts = 0;
  while (WiFi.status() != WL_CONNECTED && wifiAttempts < 20) {
    delay(500);
    Serial.print(".");
    wifiAttempts++;
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi conectado. IP: " + WiFi.localIP().toString());
  } else {
    Serial.println("Erro: Falha ao conectar ao WiFi!");
    lcd.setCursor(0, 1);
    lcd.print("Erro WiFi!");
    while (1);
  }

  lcd.setCursor(0, 1);
  lcd.print("Sistema OK");
  Serial.println("Sistema inicializado com sucesso.");
}

void loop() {
  // Loop vazio, apenas inicialização é testada
}