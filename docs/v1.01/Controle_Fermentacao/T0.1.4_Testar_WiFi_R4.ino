// artifact_id: <UUID_GERADO_PARA_T0.1.4>
// Test ID: T0.1.4
// Function: Controle de Fermentação
// Objective: Testar Wi-Fi do Arduino R4 Connect
// Setup: Roteador Wi-Fi, sketch de teste
// Details: Carregar sketch Wi-Fi. Conectar a rede Wi-Fi via SSID e senha. Verificar conexão estável.

#include <WiFiS3.h> // Biblioteca para R4 WiFi

// --- Configurações de Rede ---
char ssid[] = "SEU_SSID";        // Substitua pelo SSID da sua rede
char pass[] = "SUA_SENHA";       // Substitua pela senha da sua rede
int status = WL_IDLE_STATUS;    // Status da conexão Wi-Fi
// --------------------------

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Teste T0.1.4: Testar Wi-Fi Arduino R4 Connect");
  Serial.println("--------------------------------------------------");
  Serial.println("Setup: Roteador Wi-Fi configurado e acessível.");
  Serial.println("Ação: Tentar conectar à rede Wi-Fi especificada.");
  Serial.println("Verificação: Verificar se a conexão é estabelecida e se um IP é obtido.");
  Serial.println("--------------------------------------------------");

  // Verifica se o módulo WiFi está presente
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Erro: Módulo Wi-Fi não encontrado!");
    while (true); // Trava a execução
  }

  Serial.print("Tentando conectar à rede SSID: ");
  Serial.println(ssid);

  // Tenta conectar à rede Wi-Fi
  status = WiFi.begin(ssid, pass);

  // Aguarda a conexão (com timeout)
  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startTime < 15000) { // Timeout de 15 segundos
    Serial.print(".");
    delay(500);
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConectado à rede Wi-Fi com sucesso!");
    printWifiStatus();
  } else {
    Serial.println("\nFalha ao conectar à rede Wi-Fi.");
    Serial.print("Status da conexão: ");
    Serial.println(WiFi.status());
  }
  Serial.println("--------------------------------------------------");
  Serial.println("Teste concluído.");
}

void loop() {
  // Opcional: Verificar periodicamente se a conexão ainda está ativa
  if (WiFi.status() != WL_CONNECTED) {
      Serial.println("Conexão Wi-Fi perdida. Tentando reconectar...");
      // Adicionar lógica de reconexão se necessário
  }
  delay(10000); // Verifica a cada 10 segundos
}

void printWifiStatus() {
  // Imprime o SSID da rede à qual você está conectado
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // Imprime o endereço IP do R4
  IPAddress ip = WiFi.localIP();
  Serial.print("Endereço IP: ");
  Serial.println(ip);

  // Imprime a força do sinal recebido
  long rssi = WiFi.RSSI();
  Serial.print("Força do sinal (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
