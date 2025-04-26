/*
 * Teste: T0.1.1 - Verificar Energização do Arduino R4 Connect
 * Artifact ID: 5148934c-c09f-4088-8bb3-af49cbf142bf
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisito: RD3.1 (Energização do Microcontrolador)
 * Descrição: Verifica se o Arduino R4 Connect é energizado corretamente via USB-C (5V), observando o LED onboard.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.1.1.              |
 */

/*
 * Setup:
 * - Conectar cabo USB-C de fonte 5V à porta USB-C do Arduino R4 Connect.
 * - Verificar visualmente o LED onboard (deve acender).
 * - Este sketch pisca o LED para confirmação adicional.
 */

#define LED_BUILTIN 13 // LED onboard do Arduino R4 Connect

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Teste T0.1.1: Verificar Energização do Arduino R4 Connect");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED ON");
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LED OFF");
  delay(1000);
}