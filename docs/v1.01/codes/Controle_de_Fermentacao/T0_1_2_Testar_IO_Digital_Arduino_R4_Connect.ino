// T0_1_2_Testar_IO_Digital_Arduino_R4_Connect.ino
// Função: Controle de Fermentação
// Artifact ID: e144b732-8ebf-4e1f-9a9a-9bd3b1808950
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD3.2 (Funcionamento de I/O Digital)
// Descrição: Testa os pinos de I/O digital do Arduino R4 Connect, alternando um pino de saída e lendo um pino de entrada.
// Diretório: docs/V1.01/codes/Controle_de_Fermentacao/T0_1_2

#define OUTPUT_PIN 12 // Pino de saída digital
#define INPUT_PIN 11  // Pino de entrada digital

void setup() {
  pinMode(OUTPUT_PIN, OUTPUT); // Configura o pino de saída
  pinMode(INPUT_PIN, INPUT);   // Configura o pino de entrada
  Serial.begin(9600);          // Inicia comunicação serial a 9600 baud
  while (!Serial) {
    ; // Aguarda a conexão do Serial Monitor
  }
  Serial.println("Teste T0.1.2 - I/O Digital Arduino R4 Connect Iniciado");
}

void loop() {
  // Testa saída digital
  digitalWrite(OUTPUT_PIN, HIGH); // Liga o pino de saída
  Serial.println("Saída: HIGH");
  delay(1000);                    // Aguarda 1 segundo
  digitalWrite(OUTPUT_PIN, LOW);  // Desliga o pino de saída
  Serial.println("Saída: LOW");
  delay(1000);                    // Aguarda 1 segundo

  // Testa entrada digital
  int inputState = digitalRead(INPUT_PIN); // Lê o estado do pino de entrada
  Serial.print("Entrada: ");
  Serial.println(inputState == HIGH ? "HIGH" : "LOW");
  delay(1000); // Aguarda 1 segundo antes da próxima leitura
}