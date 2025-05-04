// T0_4_Verificar_Leitura_Corrente_INA219_ESP32.ino
// Função: Teste de Leitura de Corrente INA219 no ESP32-C3 Supermini
// Conexões:
// VCC (INA219) -> VCC (ESP32 C3 Super mini)
// GND -> GND
// SCL -> GPIO9
// SDA -> GPIO8
// A0/A1 em aberto (assumindo endereço I2C padrão 0x40)

#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando o teste do INA219 no ESP32-C3 Supermini...");

  // Inicializa o INA219 com o endereço I2C padrão (0x40)
  if (!ina219.begin()) {
    Serial.println("Falha ao encontrar o sensor INA219! Verifique as conexões e o endereço I2C.");
    while (1);
  }
  Serial.println("INA219 encontrado e inicializado!");
}

void loop() {
  float busvoltage = ina219.getBusVoltage_V();
  float shuntvoltage = ina219.getShuntVoltage_mV() / 1000;
  float current_mA = ina219.getCurrent_mA();
  float power_mW = ina219.getPower_mW();

  Serial.println("--------------------");
  Serial.print("Tensão do barramento: ");
  Serial.print(busvoltage);
  Serial.println(" V");

  Serial.print("Tensão de shunt: ");
  Serial.print(shuntvoltage);
  Serial.println(" V");

  Serial.print("Corrente: ");
  Serial.print(current_mA);
  Serial.println(" mA");

  Serial.print("Potência: ");
  Serial.print(power_mW);
  Serial.println(" mW");
  Serial.println("--------------------");

  delay(1000); // Lê os dados a cada 1 segundo
}
