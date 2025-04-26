// T3_1_Sistema_Completo_Medicao_Volume.ino
// Função: Balança de Volume
// Artifact ID: 819109a0-5a5a-47cc-a892-8ec6128f4791
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD5.1 (Sistema Completo)
// Descrição: Integra HX711, LCD, botão de tara e WiFi para medição de peso/volume, exibindo no LCD e enviando via WiFi.
// Diretório: docs/V1.01/codes/Balanca_de_Volume/T3_1

#include <HX711.h>
#include <LiquidCrystal.h>
#include <WiFi.h>

#define HX711_DOUT 3 // Pino de dados do HX711
#define HX711_SCK 2  // Pino de clock do HX711
#define TARE_BUTTON 7 // Pino do botão de tara
const char* ssid = "SUA_REDE_WIFI";
const char* password = "SUA_SENHA_WIFI";

HX711 scale;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos do LCD
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T3.1 - Sistema Completo Medição Volume Iniciado");

  pinMode(TARE_BUTTON, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.print("Balanca Volume");

  scale.begin(HX711_DOUT, HX711_SCK);
  scale.tare();
  scale.set_scale(100.0); // Ajustar após calibração real

  Serial.print("Conectando à rede: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado. IP: " + WiFi.localIP().toString());
}

void loop() {
  float weight = scale.get_units(10);
  float volume = weight / 1000.0; // 1 g = 1 ml, 1000 ml = 1 L

  bool buttonState = digitalRead(TARE_BUTTON);
  if (buttonState == LOW && lastButtonState == HIGH) {
    scale.tare();
    Serial.println("Tara realizada.");
    lcd.setCursor(0, 1);
    lcd.print("Tara realizada  ");
    delay(1000);
  }
  lastButtonState = buttonState;

  lcd.setCursor(0, 1);
  lcd.print("P:");
  lcd.print(weight);
  lcd.print("g V:");
  lcd.print(volume);
  lcd.print("L");

  Serial.print("Peso: ");
  Serial.print(weight);
  Serial.print(" g | Volume: ");
  Serial.print(volume);
  Serial.println(" L");
  Serial.println("Dados enviados (simulado): Peso=" + String(weight) + "g, Volume=" + String(volume) + "L");

  delay(2000);
}