// T1_2_Integrar_Controle_SSR_10DA.ino
// Função: Controle de Fermentação
// Artifact ID: 3494fc1b-d435-45d9-8628-9e1191e68234
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD5.2 (Integração de Controle de Saída)
// Descrição: Integra o controle do relé SSR-10DA com base em uma condição simulada (ex.: temperatura), exibindo o estado no Serial Monitor.
// Diretório: docs/V1.01/codes/Controle_de_Fermentacao/T1_2

#define SSR_PIN 9 // Pino conectado ao relé SSR-10DA

void setup() {
  pinMode(SSR_PIN, OUTPUT); // Configura o pino do relé como saída
  digitalWrite(SSR_PIN, LOW); // Garante que o relé comece desligado
  Serial.begin(9600); // Inicia comunicação serial a 9600 baud
  while (!Serial) {
    ; // Aguarda a conexão do Serial Monitor
  }
  Serial.println("Teste T1.2 - Integração Controle SSR-10DA Iniciado");
}

void loop() {
  // Simula uma condição (ex.: temperatura > 25°C)
  float simulatedTemp = 26.5; // Valor fixo para teste
  Serial.print("Temperatura simulada: ");
  Serial.print(simulatedTemp);
  Serial.println(" °C");

  if (simulatedTemp > 25.0) {
    digitalWrite(SSR_PIN, HIGH); // Liga o relé
    Serial.println("Relé SSR-10DA: LIGADO (Temperatura > 25°C)");
  } else {
    digitalWrite(SSR_PIN, LOW); // Desliga o relé
    Serial.println("Relé SSR-10DA: DESLIGADO (Temperatura <= 25°C)");
  }

  delay(2000); // Aguarda 2 segundos antes da próxima verificação
}