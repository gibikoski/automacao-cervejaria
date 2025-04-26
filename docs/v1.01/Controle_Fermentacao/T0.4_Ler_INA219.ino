// artifact_id: <UUID_GERADO_PARA_T0.4>
// Test ID: T0.4
// Function: Controle de Fermentação
// Objective: Verificar leitura de corrente/tensão do INA219
// Setup: INA219, carga resistiva, resistor 10 Ω
// Details: Conectar INA219: SDA(A5), SCL(A4), VCC(3V3), GND(GND), resistor 10 Ω entre VIN+ e VIN- (carga conectada em série com este resistor).

#include <Wire.h>
#include <Adafruit_INA219.h> // Exemplo, use a biblioteca apropriada

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Teste T0.4: Ler Corrente/Tensão INA219");
  Serial.println("--------------------------------------------------");
  Serial.println("Setup: Conecte INA219 (SDA->A5, SCL->A4, VCC->3V3, GND->GND).");
  Serial.println("       Conecte um resistor de carga de 10 Ohm entre VIN+ e VIN- do INA219.");
  Serial.println("       Alimente o circuito da carga (ex: 5V) passando pelo resistor shunt.");
  Serial.println("Ação: Ler valores de tensão do barramento, tensão do shunt e corrente.");
  Serial.println("Verificação: Verificar se os valores lidos são plausíveis para a carga conectada.");
  Serial.println("--------------------------------------------------");

  Wire.begin(); // I2C já deve ter sido iniciado implicitamente pela lib, mas pode ser explícito.
  if (!ina219.begin()) {
    Serial.println("Erro: Falha ao encontrar o chip INA219. Verifique a conexão.");
    while (1) { delay(10); }
  } else {
     Serial.println("INA219 encontrado e inicializado.");
     // Opcional: configurar calibração/range se necessário
     // ina219.setCalibration_32V_2A(); // Exemplo
  }
   Serial.println("--------------------------------------------------");
}

void loop() {
  float shuntVoltage = ina219.getShuntVoltage_mV();
  float busVoltage = ina219.getBusVoltage_V();
  float current_mA = ina219.getCurrent_mA();
  float power_mW = ina219.getPower_mW();
  float loadVoltage = busVoltage + (shuntVoltage / 1000); // V = V_bus + V_shunt

  Serial.print("Tensão Barramento (Vbus): "); Serial.print(busVoltage); Serial.println(" V");
  Serial.print("Tensão Shunt          : "); Serial.print(shuntVoltage); Serial.println(" mV");
  Serial.print("Tensão Carga (Vload)  : "); Serial.print(loadVoltage); Serial.println(" V");
  Serial.print("Corrente              : "); Serial.print(current_mA); Serial.println(" mA");
  Serial.print("Potência              : "); Serial.print(power_mW); Serial.println(" mW");
  Serial.println("--------------------------------------------------");

  delay(2000);
}
