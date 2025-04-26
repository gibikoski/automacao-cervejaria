// artifact_id: <UUID_GERADO_PARA_T0.1.1>
// Test ID: T0.1.1
// Function: Controle de Fermentação
// Objective: Verificar energização do Arduino R4 Connect
// Setup: Fonte 5V USB, LED onboard
// Details: Conectar USB-C de fonte 5V para USB-C de Arduino R4 Connect. Ligar e verificar LED onboard.

void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for serial connection

  Serial.println("Teste T0.1.1: Verificar Energização Arduino R4 Connect");
  Serial.println("--------------------------------------------------");
  Serial.println("Setup: Conecte a fonte 5V USB ao Arduino R4 Connect.");
  Serial.println("Ação: Ligue a fonte.");
  Serial.println("Verificação: Observe se o LED onboard do Arduino acende.");
  Serial.println("Resultado esperado: LED onboard aceso.");
  // Nenhuma ação de código necessária aqui, a verificação é visual.
  // Considere adicionar um pequeno blink no LED_BUILTIN para confirmação extra via código, se desejado.
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // Sinaliza início do teste
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);


  Serial.println("--------------------------------------------------");
  Serial.println("Teste concluído (verificação visual).");

}

void loop() {
  // Loop vazio, teste é executado no setup.
  delay(1000);
}
