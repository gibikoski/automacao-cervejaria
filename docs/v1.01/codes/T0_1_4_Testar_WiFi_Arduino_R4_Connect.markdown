/*
 * Teste: T0.1.4 - Testar Wi-Fi do Arduino R4 Connect
 * Artifact ID: c4d5e6f7-a8b9-4090-1c2d-3e4f5a6b7c8d
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisito: RD3.1 (Wi-Fi)
 * Descrição: Testa a conexão Wi-Fi do Arduino R4 Connect a uma rede.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.1.4.              |
 */

/*
 * Setup:
 * - Configurar SSID e senha da rede Wi-Fi no código.
 * - Carregar o sketch e verificar conexão no Serial Monitor (9600 baud).
 */

#include <WiFi.h>

const char* ssid = "SUA_REDE";
const char* password = "SUA_SENHA";

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T0.1.4: Testar Wi-Fi do Arduino R4 Connect");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conectado à rede Wi-Fi!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Loop vazio, teste é concluído no setup
}