// T2_1_Comunicacao_WiFi_Envio_Dados.ino
// Função: Balança de Volume
// Artifact ID: 9ba4d06b-7851-43a1-bc5e-1c61f115068a
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD4.1 (Comunicação WiFi)
// Descrição: Envia peso e volume medidos pelo HX711 via WiFi, exibindo status no Serial Monitor.
// Diretório: docs/V1.01/codes/Balanca_de_Volume/T2_1

#include <HX711.h>
#include <WiFi.h>

#define HX711_DOUT 3 // Pino de dados do HX711
#define HX711_SCK 2  // Pino de clock do HX711
const char* ssid = "SUA_REDE_WIFI";
const char* password = "SUA_SENHA_WIFI";

HX711 scale;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T2.1 - Comunicação WiFi Envio Dados Iniciado");

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

  Serial.print("Peso: ");
  Serial.print(weight);
  Serial.print(" g | Volume: ");
  Serial.print(volume);
  Serial.println(" L");
  Serial.println("Dados enviados (simulado): Peso=" + String(weight) + "g, Volume=" + String(volume) + "L");

  delay(5000);
}