/*
 * Teste: T0.1.1 - Verificar Energização do Mega 2560
 * Artifact ID: f392e2b2-d260-4fe2-6565-7b8c9d0e1f2a
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RD3.1, RD3.5 (Energização do Microcontrolador)
 * Descrição: Verifica se o Mega 2560 é energizado corretamente via USB ou VIN (7-12V), observando o LED onboard.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.1.1.              |
 */

/*
 * Setup:
 * - Conectar cabo USB ou fonte 7-12V ao Mega 2560.
 * - Verificar visualmente o LED onboard (deve acender).
 * - Este sketch pisca o LED para confirmação.
 */

#define LED_BUILTIN 13 // LED onboard do Mega 2560

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Teste T0.1.1: Verificar Energização do Mega 2560");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED ON");
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LED OFF");
  delay(1000);
}