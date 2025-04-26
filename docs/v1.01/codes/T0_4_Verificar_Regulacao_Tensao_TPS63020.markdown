/*
 * Teste: T0.4 - Verificar Regulação de Tensão do TPS63020
 * Artifact ID: 8c2b7b3b-6b99-4b7b-9e9e-0a1b2c3d4e5f
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisito: RD3.2 (Regulação de Tensão)
 * Descrição: Verifica a regulação de tensão do TPS63020 (3,3V ±5%) com uma carga típica.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T0.4.                |
 */

/*
 * Setup:
 * - Conectar TPS63020: VIN a bateria 18650 (3,0-4,2V), VOUT a 3V3 do ESP32-C3, GND a GND.
 * - Conectar carga resistiva (ex.: resistor 100 Ω) em VOUT.
 * - Medir tensão em VOUT com multímetro.
 * - Este sketch monitora o sistema para estabilidade.
 */

#define LOAD_PIN 6 // Simula carga controlada

void setup() {
  pinMode(LOAD_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Teste T0.4: Verificar Regulação de Tensão do TPS63020");
}

void loop() {
  digitalWrite(LOAD_PIN, HIGH);
  Serial.println("Carga ON");
  delay(2000);
  digitalWrite(LOAD_PIN, LOW);
  Serial.println("Carga OFF");
  delay(2000);
}