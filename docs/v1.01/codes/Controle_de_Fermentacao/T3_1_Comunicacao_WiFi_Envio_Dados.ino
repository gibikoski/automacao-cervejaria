// T3_1_Comunicacao_WiFi_Envio_Dados.ino
// Função: Controle de Fermentação
// Artifact ID: 890814c4-35fc-4571-9468-81340ca0be2f
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD7.1 (Comunicação WiFi)
// Descrição: Testa o envio de dados simulados (ex.: temperatura) via WiFi usando o Arduino R4 Connect, exibindo o status no Serial Monitor.
// Diretório: docs/V1.01/codes/Controle_de_Fermentacao/T3_1

#include <WiFi.h>

// Credenciais da rede WiFi (substituir pelos valores reais)
const char* ssid = "SUA_REDE_WIFI";
const char* password = "SUA_SENHA_WIFI";

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T3.1 - Comunicação WiFi Envio Dados Iniciado");

  Serial.print("Conectando à rede: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Conexão WiFi estabelecida!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Simula um dado (ex.: temperatura)
  float simulatedTemp = 25.5;
  Serial.print("Enviando dado simulado (Temperatura: ");
  Serial.print(simulatedTemp);
  Serial.println(" °C)");

  // Simula envio (ex.: para um servidor, aqui apenas exibe)
  Serial.println("Dado enviado com sucesso (simulado).");

  delay(5000);
}