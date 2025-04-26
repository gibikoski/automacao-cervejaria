// T0_1_4_Testar_WiFi_Arduino_R4_Connect.ino
// Função: Controle de Fermentação
// Artifact ID: 0af662e9-cc12-46b7-a420-e5d147172f81
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD3.4 (Conectividade WiFi)
// Descrição: Testa a conectividade WiFi do Arduino R4 Connect, conectando a uma rede WiFi e exibindo o status no Serial Monitor.
// Diretório: docs/V1.01/codes/Controle_de_Fermentacao/T0_1_4

#include <WiFi.h>

// Credenciais da rede WiFi (substituir pelos valores reais)
const char* ssid = "SUA_REDE_WIFI";
const char* password = "SUA_SENHA_WIFI";

void setup() {
  Serial.begin(9600); // Inicia comunicação serial a 9600 baud
  while (!Serial) {
    ; // Aguarda a conexão do Serial Monitor
  }
  Serial.println("Teste T0.1.4 - WiFi Arduino R4 Connect Iniciado");

  // Inicia a conexão WiFi
  Serial.print("Conectando à rede: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  // Aguarda até a conexão ser estabelecida
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Exibe informações da conexão
  Serial.println("");
  Serial.println("Conexão WiFi estabelecida!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Intensidade do sinal (RSSI): ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");
}

void loop() {
  // Verifica se a conexão WiFi ainda está ativa
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi conectado.");
  } else {
    Serial.println("WiFi desconectado!");
  }
  delay(5000); // Verifica a cada 5 segundos
}