/*
 * Teste: T3.1 - Verificar Autonomia da Bateria 18650
 * Artifact ID: c06fbf7f-af3d-4fbf-3232-4e5f6a7b8c9d
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RP3, RD3.2, RD3.3, RD3.4 (Autonomia da Bateria)
 * Descrição: Verifica a autonomia da bateria 18650 com carga típica por 24h.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T3.1.                |
 */

/*
 * Setup:
 * - Conectar bateria 18650 ao circuito de proteção (via TPS63020).
 * - Conectar circuito ao ESP32-C3 + sensores (ex.: ICM20948, INA219).
 * - Monitorar consumo no Serial Monitor (9600 baud).
 */

#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T3.1: Verificar Autonomia da Bateria 18650");
  Wire.begin();
  if (!ina219.begin()) {
    Serial.println("Falha ao iniciar INA219!");
    while (1);
  }
}

void loop() {
  float current_mA = ina219.getCurrent_mA();
  Serial.print("Corrente: ");
  Serial.print(current_mA);
  Serial.println(" mA");
  delay(3600000); // Log a cada hora
}