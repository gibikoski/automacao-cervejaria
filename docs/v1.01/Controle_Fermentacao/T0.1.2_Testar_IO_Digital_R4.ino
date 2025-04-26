// artifact_id: <UUID_GERADO_PARA_T0.1.2>
// Test ID: T0.1.2
// Function: Controle de Fermentação
// Objective: Testar I/O digital do Arduino R4 Connect
// Setup: LED externo, resistor 220 Ω
// Details: Conectar LED: Anodo para D4 de Arduino R4 Connect, Cátodo para GND de Arduino R4 Connect via resistor 220 Ω.

const int ledPin = 4; // Pino digital D4

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Teste T0.1.2: Testar I/O Digital Arduino R4 Connect (Pino D4)");
  Serial.println("--------------------------------------------------");
  Serial.println("Setup: Conecte Anodo do LED a D4, Catodo a GND via resistor 220 Ohm.");
  Serial.println("Ação: O pino D4 será alternado entre HIGH e LOW.");
  Serial.println("Verificação: Observe se o LED externo pisca.");
  Serial.println("--------------------------------------------------");

  pinMode(ledPin, OUTPUT);
}

void loop() {
  Serial.println("Ligando LED (HIGH)...");
  digitalWrite(ledPin, HIGH);
  delay(1000); // Espera 1 segundo

  Serial.println("Desligando LED (LOW)...");
  digitalWrite(ledPin, LOW);
  delay(1000); // Espera 1 segundo
}
