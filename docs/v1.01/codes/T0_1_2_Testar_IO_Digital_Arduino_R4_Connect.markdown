/*
 * Teste: T0.1.2 - Testar I/O Digital do Arduino R4 Connect
 * Artifact ID: a2b3c4d5-e6f7-4098-9a0b-1c2d3e4f5a6b
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisito: RD3.1 (I/O Digital)
 * Descrição: Testa a saída digital do Arduino R4 Connect controlando um LED externo.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.1.2.              |
 */

/*
 * Setup:
 * - Conectar LED: Anodo para D4 do Arduino R4 Connect, Cátodo para GND via resistor 220 Ω.
 * - Observar o LED piscando (1s ligado, 1s desligado).
 */

#define LED_PIN 4

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Teste T0.1.2: Testar I/O Digital do Arduino R4 Connect");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED ON");
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED OFF");
  delay(1000);
}