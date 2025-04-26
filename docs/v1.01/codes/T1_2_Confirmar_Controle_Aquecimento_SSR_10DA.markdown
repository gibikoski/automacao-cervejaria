/*
 * Teste: T1.2 - Confirmar Controle de Aquecimento via SSR-10DA
 * Artifact ID: b9c0d1e2-f3a4-4095-6b7c-8d9e0f1a2b3c
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RP1, RD1.2 (Controle de Aquecimento)
 * Descrição: Confirma o controle de aquecimento via SSR-10DA com um resistor de aquecimento.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T1.2.                |
 */

/*
 * Setup:
 * - Conectar SSR-10DA: Controle+ para D3, Controle- para GND do Arduino R4 Connect.
 * - Conectar resistor de aquecimento em série com SSR-10DA.
 * - Observar aquecimento controlado no Serial Monitor (9600 baud).
 */

#define SSR_PIN 3

void setup() {
  pinMode(SSR_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Teste T1.2: Confirmar Controle de Aquecimento via SSR-10DA");
}

void loop() {
  digitalWrite(SSR_PIN, HIGH);
  Serial.println("Aquecimento ON");
  delay(5000);
  digitalWrite(SSR_PIN, LOW);
  Serial.println("Aquecimento OFF");
  delay(5000);
}