// artifact_id: <UUID_GERADO_PARA_T2.1_CF>
// Test ID: T2.1 (Controle de Fermentação)
// Function: Controle de Fermentação
// Objective: Verificar fusível 3 A (não destrutivo)
// Setup: Fusível 3 A, multímetro
// Details: Conectar fusível em série com carga. Medir continuidade com multímetro. Verificar funcionamento sem queima.

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Teste T2.1: Verificar Fusível 3A (Não Destrutivo)");
  Serial.println("--------------------------------------------------");
  Serial.println("Setup: Um fusível de 3A instalado no circuito.");
  Serial.println("       Multímetro configurado para medir continuidade (teste de diodo/beep).");
  Serial.println("Ação 1: Com o circuito DESLIGADO, meça a continuidade através do fusível.");
  Serial.println("Verificação 1: O multímetro deve indicar continuidade (idealmente 0 Ohms ou beep).");
  Serial.println("Ação 2: Ligue o circuito com uma carga que demande MENOS de 3A.");
  Serial.println("Verificação 2: O circuito deve funcionar normalmente e o fusível NÃO deve queimar.");
  Serial.println("Ação 3 (Opcional - CUIDADO): Teste com carga próxima a 3A (se seguro).");
  Serial.println("Verificação 3: O fusível ainda não deve queimar.");
  Serial.println("--------------------------------------------------");
  Serial.println("Este teste é primariamente manual/visual e com uso de multímetro.");
  Serial.println("Não há código Arduino específico para este teste de componente passivo.");
  Serial.println("--------------------------------------------------");
  Serial.println("Teste concluído (verificação manual).");

   // Pode adicionar um blink para indicar que o Arduino está rodando, se útil.
   pinMode(LED_BUILTIN, OUTPUT);
   digitalWrite(LED_BUILTIN, HIGH); delay(1000); digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // Loop vazio
  delay(5000);
}
