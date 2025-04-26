/*
 * Teste: T0.1.4 - Testar Wi-Fi do ESP32-C3 (Densímetro)
 * Artifact ID: 6a7b8c9d-0e1f-4091-2f3a-4b5c6d7e8f9a
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisito: RD4.1 (Wi-Fi)
 * Descrição: Testa a conexão Wi-Fi do ESP32-C3 a uma rede.
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
  Serial.println("Teste T0.1.4: Testar Wi-Fi do ESP32-C3 (Densímetro)");
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