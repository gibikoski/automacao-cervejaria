/*
 * Teste: T0.1.2 - Testar UART do Mega 2560
 * Artifact ID: 04a3f3c3-e371-4ff3-7676-8c9d0e1f2a3b
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisito: RD3.1 (UART)
 * Descrição: Testa a comunicação UART do Mega 2560 enviando e recebendo dados via Serial1.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.1.2.              |
 */

/*
 * Setup:
 * - Conectar TX1 (pin 18) a RX1 (pin 19) do Mega 2560 com um jumper.
 * - Observar dados enviados/recebidos no Serial Monitor (9600 baud).
 */

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("Teste T0.1.2: Testar UART do Mega 2560");
}

void loop() {
  Serial1.println("Teste UART");
  if (Serial1.available()) {
    String received = Serial1.readStringUntil('\n');
    Serial.print("Recebido: ");
    Serial.println(received);
  }
  delay(1000);
}