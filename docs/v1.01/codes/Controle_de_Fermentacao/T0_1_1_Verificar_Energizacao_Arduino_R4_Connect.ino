// T0_1_1_Verificar_Energizacao_Arduino_R4_Connect.ino
// Função: Controle de Fermentação
// Artifact ID: 5148934c-c09f-4088-8bb3-af49cbf142bf
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD3.1, RD3.5 (Energização do Microcontrolador)
// Descrição: Verifica a energização do Arduino R4 Connect, piscando o LED onboard e enviando mensagens ao Serial Monitor.
// Diretório: docs/V1.01/codes/Controle_de_Fermentacao/T0_1_1

#define LED_BUILTIN 13 // LED onboard do Arduino R4 Connect

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // Configura o pino do LED como saída
  Serial.begin(9600);           // Inicia comunicação serial a 9600 baud
  while (!Serial) {
    ; // Aguarda a conexão do Serial Monitor
  }
  Serial.println("Teste T0.1.1 - Energização Arduino R4 Connect Iniciado");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // Liga o LED
  Serial.println("LED ON");
  delay(1000);                     // Aguarda 1 segundo
  digitalWrite(LED_BUILTIN, LOW);  // Desliga o LED
  Serial.println("LED OFF");
  delay(1000);                     // Aguarda 1 segundo
}