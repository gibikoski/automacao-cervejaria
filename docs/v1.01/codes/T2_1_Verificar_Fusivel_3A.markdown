/*
 * Teste: T2.1 - Verificar Fusível 3 A
 * Artifact ID: c0d1e2f3-a4b5-4096-7c8d-9e0f1a2b3c4d
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RP2, RD2.1 (Fusível)
 * Descrição: Verifica o funcionamento do fusível 3 A (não destrutivo) com um multímetro.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T2.1.                |
 */

/*
 * Setup:
 * - Conectar fusível 3 A em série com uma carga resistiva.
 * - Medir continuidade com multímetro.
 * - Este sketch simula uma carga controlada para monitoramento.
 */

#define LOAD_PIN 3

void setup() {
  pinMode(LOAD_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Teste T2.1: Verificar Fusível 3 A");
}

void loop() {
  digitalWrite(LOAD_PIN, HIGH);
  Serial.println("Carga ON");
  delay(2000);
  digitalWrite(LOAD_PIN, LOW);
  Serial.println("Carga OFF");
  delay(2000);
}