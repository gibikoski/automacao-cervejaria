/*
 * Teste: T0.3 - Verificar Controle de Saída do SSR-10DA
 * Artifact ID: e6f7a8b9-c0d1-4092-3e4f-5a6b7c8d9e0f
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisito: RD1.2 (Controle SSR)
 * Descrição: Verifica o controle de saída do SSR-10DA com uma carga resistiva.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.3.                |
 */

/*
 * Setup:
 * - Conectar SSR-10DA: Controle+ para D3, Controle- para GND do Arduino R4 Connect.
 * - Conectar carga resistiva (ex.: lâmpada 40W) em série com SSR-10DA.
 * - Observar a carga ligando/desligando.
 */

#define SSR_PIN 3

void setup() {
  pinMode(SSR_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Teste T0.3: Verificar Controle de Saída do SSR-10DA");
}

void loop() {
  digitalWrite(SSR_PIN, HIGH);
  Serial.println("SSR ON");
  delay(2000);
  digitalWrite(SSR_PIN, LOW);
  Serial.println("SSR OFF");
  delay(2000);
}