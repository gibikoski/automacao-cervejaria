// T0_3_Verificar_Controle_Saida_SSR_10DA.ino
// Função: Controle de Fermentação
// Artifact ID: 0aef38a2-15df-4ff4-9265-8cc6fd8e66fd
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD4.2 (Controle de Saída)
// Descrição: Verifica o controle de saída do relé SSR-10DA conectado ao Arduino R4 Connect, alternando o estado e exibindo no Serial Monitor.
// Diretório: docs/V1.01/codes/Controle_de_Fermentacao/T0_3

#define SSR_PIN 9 // Pino conectado ao relé SSR-10DA

void setup() {
  pinMode(SSR_PIN, OUTPUT); // Configura o pino do relé como saída
  digitalWrite(SSR_PIN, LOW); // Garante que o relé comece desligado
  Serial.begin(9600); // Inicia comunicação serial a 9600 baud
  while (!Serial) {
    ; // Aguarda a conexão do Serial Monitor
  }
  Serial.println("Teste T0.3 - Controle Saída SSR-10DA Iniciado");
}

void loop() {
  digitalWrite(SSR_PIN, HIGH); // Liga o relé
  Serial.println("Relé SSR-10DA: LIGADO");
  delay(2000); // Aguarda 2 segundos
  digitalWrite(SSR_PIN, LOW); // Desliga o relé
  Serial.println("Relé SSR-10DA: DESLIGADO");
  delay(2000); // Aguarda 2 segundos
}