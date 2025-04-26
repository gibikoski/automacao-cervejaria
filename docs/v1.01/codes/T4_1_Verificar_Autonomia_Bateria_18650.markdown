/*
 * Teste: T4.1 - Verificar Autonomia da Bateria 18650
 * Artifact ID: e2f3a4b5-c6d7-4098-9e0f-1a2b3c4d5e6f
 * Versão: v1.0.1
 * Data: 2025-04-20
 * Requisitos: RP4, RD4.1, RD4.2 (Autonomia da Bateria)
 * Descrição: Verifica a autonomia da bateria 18650 com carga típica por 24h.
 */

/*
 * Controle de Versão
 * | Versão | Data       | Descrição                                      |
 * |--------|------------|------------------------------------------------|
 * | v1.0.1 | 2025-04-20 | Código inicial para teste T4.1.                |
 */

/*
 * Setup:
 * - Conectar bateria 18650 ao circuito de proteção.
 * - Conectar circuito ao Arduino R4 Connect + sensores (ex.: DS18B20, INA219).
 * - Monitorar consumo no Serial Monitor (9600 baud).
 */

#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(9600);
  Serial.println("Teste T4.1: Verificar Autonomia da Bateria 18650");
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