// artifact_id: <UUID_GERADO_PARA_T0.3>
// Test ID: T0.3
// Function: Controle de Fermentação
// Objective: Verificar controle de saída do SSR-10DA
// Setup: SSR-10DA, carga resistiva (ex.: lâmpada 40W)
// Details: Conectar SSR-10DA: Controle+(D3), Controle-(GND), carga em série com SSR-10DA.

const int ssrPin = 3; // Pino D3 para controlar o SSR

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Teste T0.3: Controlar Saída SSR-10DA");
  Serial.println("--------------------------------------------------");
  Serial.println("Setup: Conecte SSR (Controle+ -> D3, Controle- -> GND), Carga (ex: lâmpada) em série com a saída AC do SSR.");
  Serial.println("CUIDADO: ALTA TENSÃO NA CARGA!");
  Serial.println("Ação: O pino D3 alternará entre HIGH e LOW para ligar/desligar o SSR.");
  Serial.println("Verificação: Observe se a carga (lâmpada) liga e desliga corretamente.");
  Serial.println("--------------------------------------------------");

  pinMode(ssrPin, OUTPUT);
  digitalWrite(ssrPin, LOW); // Garante que o SSR comece desligado
  Serial.println("SSR Inicialmente DESLIGADO.");
}

void loop() {
  Serial.println("Ligando SSR (HIGH)... A carga deve ligar.");
  digitalWrite(ssrPin, HIGH);
  delay(5000); // Mantém ligado por 5 segundos

  Serial.println("Desligando SSR (LOW)... A carga deve desligar.");
  digitalWrite(ssrPin, LOW);
  delay(5000); // Mantém desligado por 5 segundos
}
