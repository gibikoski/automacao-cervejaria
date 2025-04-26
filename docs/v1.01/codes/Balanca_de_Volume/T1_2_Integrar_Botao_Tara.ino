// T1_2_Integrar_Botao_Tara.ino
// Função: Balança de Volume
// Artifact ID: 05ebee9b-151e-4bcc-bb9f-870767719e5c
// Versão: v1.0.1
// Data: 2025-04-20
// Iteração: 34
// Requisitos: RD3.2 (Interação com Usuário)
// Descrição: Integra um botão para realizar tara no HX711, exibindo peso e volume no Serial Monitor.
// Diretório: docs/V1.01/codes/Balanca_de_Volume/T1_2

#include <HX711.h>

#define HX711_DOUT 3 // Pino de dados do HX711
#define HX711_SCK 2  // Pino de clock do HX711
#define TARE_BUTTON 7 // Pino do botão de tara

HX711 scale;
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Teste T1.2 - Integração Botão Tara Iniciado");

  pinMode(TARE_BUTTON, INPUT_PULLUP);
  scale.begin(HX711_DOUT, HX711_SCK);
  scale.tare();
  scale.set_scale(100.0); // Ajustar após calibração real
}

void loop() {
  float weight = scale.get_units(10);
  float volume = weight / 1000.0; // 1 g = 1 ml, 1000 ml = 1 L

  bool buttonState = digitalRead(TARE_BUTTON);
  if (buttonState == LOW && lastButtonState == HIGH) {
    scale.tare();
    Serial.println("Tara realizada.");
  }
  lastButtonState = buttonState;

  Serial.print("Peso: ");
  Serial.print(weight);
  Serial.print(" g | Volume: ");
  Serial.print(volume);
  Serial.println(" L");
  delay(500);
}