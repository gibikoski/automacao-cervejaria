/*
 * Teste: T0.1.2 - Testar I/O Digital do ESP32-C3 (Balança)
 * Artifact ID: a4b5c6d7-e8f9-4090-1a2b-3c4d5e6f7a8b
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisito: RD3.1 (I/O Digital)
 * Descrição: Testa a saída digital do ESP32-C3 controlando um LED externo.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.1.2.              |
 */

/*
 * Setup:
 * - Conectar LED: Anodo para GPIO6 do ESP32-C3, Cátodo para GND via resistor 220 Ω.
 * - Observar o LED piscando (1s ligado, 1s desligado).
 */

#define LED_PIN 6

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Teste T0.1.2: Testar I/O Digital do ESP32-C3 (Balança)");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED ON");
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED OFF");
  delay(1000);
}