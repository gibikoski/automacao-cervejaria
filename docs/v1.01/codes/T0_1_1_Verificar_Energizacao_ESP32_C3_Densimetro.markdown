/*
 * Teste: T0.1.1 - Verificar Energização do ESP32-C3 (Densímetro)
 * Artifact ID: 3d4e5f6a-7b8c-4098-9c0d-1e2f3a4b5c6d
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisito: RD4.1 (Energização do Microcontrolador)
 * Descrição: Verifica se o ESP32-C3 é energizado corretamente via 3V3, observando o LED onboard.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.1.1.              |
 */

/*
 * Setup:
 * - Conectar fonte 3V3 a 3V3 do ESP32-C3, GND a GND.
 * - Verificar visualmente o LED onboard (deve acender).
 * - Este sketch pisca o LED para confirmação.
 */

#define LED_BUILTIN 2 // LED onboard do ESP32-C3

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Teste T0.1.1: Verificar Energização do ESP32-C3 (Densímetro)");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED ON");
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LED OFF");
  delay(1000);
}