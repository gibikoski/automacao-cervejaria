// artifact_id: <UUID_GERADO_PARA_T0.1.3>
// Test ID: T0.1.3
// Function: Controle de Fermentação
// Objective: Testar I2C do Arduino R4 Connect
// Setup: INA219, pull-ups 4,7 kΩ
// Details: Conectar INA219: SDA(A5), SCL(A4), VCC(3V3), GND(GND), pull-ups 4,7 kΩ entre SDA/SCL e 3V3.

#include <Wire.h>
// Inclua a biblioteca específica para o INA219 (ex: Adafruit_INA219.h)
// #include <Adafruit_INA219.h>
// Adafruit_INA219 ina219;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Teste T0.1.3: Testar I2C Arduino R4 Connect com INA219");
  Serial.println("--------------------------------------------------");
  Serial.println("Setup: Conecte INA219 (SDA->A5, SCL->A4, VCC->3V3, GND->GND) com pull-ups.");
  Serial.println("Ação: Inicializar comunicação I2C e tentar detectar o INA219.");
  Serial.println("Verificação: Verificar se o dispositivo INA219 é encontrado no barramento I2C.");
  Serial.println("--------------------------------------------------");

  Wire.begin();
  // Adicione aqui a inicialização da biblioteca do INA219
  // if (!ina219.begin()) {
  //   Serial.println("Erro: Falha ao encontrar o chip INA219. Verifique a conexão e o endereço I2C.");
  //   while (1) { delay(10); }
  // }
  Serial.println("INA219 inicializado com sucesso (placeholder - adicione a lógica real da biblioteca).");

  // Opcional: Fazer uma varredura I2C para confirmar a detecção
  byte error, address;
  int nDevices = 0;
  Serial.println("Scanning I2C bus...");
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) Serial.print("0");
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address<16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found.\n");
  } else {
    Serial.println("Done I2C Scan.\n");
  }
  Serial.println("--------------------------------------------------");
  Serial.println("Teste concluído (requer lógica da biblioteca INA219).");

}

void loop() {
  // Adicione aqui a leitura periódica do INA219, se necessário para o teste.
  // float current_mA = ina219.getCurrent_mA();
  // Serial.print("Current: "); Serial.print(current_mA); Serial.println(" mA");
  delay(2000);
}
