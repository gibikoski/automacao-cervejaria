





Automação Cervejaria - Rastreabilidade
Controle de Versão



Versão
Data
Descrição



v1.0.0
19/04/2025
Versão inicial do documento.


6. Dependências entre Funções
Função Controle de Fermentação:

Depende de: Dados da Função Densímetro (temperatura, densidade) para ajustes.
Fornece: Temperatura para Função Controle e Monitoramento.

Função Balança de Volume:

Depende de: Densidade da Função Densímetro (ou manual) para calcular volume.
Fornece: Volume para Função Controle e Monitoramento.

Função Densímetro Flutuante:

Independente.
Fornece: Densidade e temperatura para Balança e Controle e Monitoramento.

Função Controle e Monitoramento:

Depende de: Dados de todas as funções (temperatura, volume, densidade).
Fornece: Interface para ajustes e exibição.

Referências Cruzadas:

Para especificações das funções, consulte Automação Cervejaria - Especificações e Configurações.
Para testes relacionados, consulte Automação Cervejaria - Plano de Execução.

7. Matriz de Rastreabilidade



Função
Requisito Primário (RP)
Requisito Derivado (RD)
Teste (T)



Controle de Fermentação
RP1: Controlar temperatura (manta 500W, ±0,5°C)
RD1.1: DS18B20 (±0,5°C)
T0.2, T1.1




RD1.2: SSR-10DA (3-32 V DC)
T0.3, T1.2




RD1.3: Biblioteca OneWire
T0.2, T1.1



RP2: Segurança elétrica (fusível 3 A)
RD2.1: Fusível 3 A
T2.1



RP3: Monitoramento remoto (MQTT)
RD3.1: Wi-Fi (R4 Connect)
T0.1, T3.1




RD3.2: Biblioteca PubSubClient
T3.1



RP4: Autonomia 24 horas
RD4.1: Bateria 18650
T4.1




RD4.2: INA219 (±1 mA, ±10 mV)
T0.4, T4.1




RD4.3: Biblioteca Adafruit_INA219
T0.4, T4.1


Balança de Volume
RP1: Medir volume (±0,1-1 litro)
RD1.1: HX711 (24 bits)
T0.2, T1.1




RD1.2: Células de carga (5-40 kg)
T1.1




RD1.3: Algoritmo Volume = Peso / Densidade
T1.2




RD1.4: Biblioteca HX711
T0.2, T1.1



RP2: Nivelamento automático (±0,1 g)
RD2.1: MPU6050 (I2C)
T0.3, T2.1




RD2.2: Biblioteca Adafruit_MPU6050
T0.3, T2.1



RP3: Enviar dados via MQTT
RD3.1: Wi-Fi (ESP32-C3)
T0.1, T3.1




RD3.2: Biblioteca PubSubClient
T3.1




RD3.3: Alimentação 3,3 V
T0.1, T1.1


Densímetro Flutuante
RP1: Medir densidade (±0,001-0,005 g/cm³)
RD1.1: ICM20948 (I2C)
T0.2, T1.1




RD1.2: Biblioteca ICM20948
T0.2, T1.1



RP2: Monitorar temperatura (±0,5°C)
RD2.1: DS18B20 (±0,5°C)
T0.3, T2.1




RD2.2: Biblioteca OneWire
T0.3, T2.1



RP3: Autonomia 3-5 dias
RD3.1: Bateria 18650
T3.1




RD3.2: TPS63020 (3,3 V)
T0.4, T3.1




RD3.3: INA219 (±1 mA, ±10 mV)
T0.5, T4.2




RD3.4: Biblioteca Adafruit_INA219
T0.5, T4.2



RP4: Comunicação Wi-Fi (MQTT)
RD4.1: Wi-Fi (ESP32-C3)
T0.1, T4.1




RD4.2: Biblioteca PubSubClient
T4.1


Controle e Monitoramento
RP1: Exibir dados (temperatura, volume, densidade)
RD1.1: DFR0009 (LCD 1602)
- (Item existente)




RD1.2: Biblioteca LiquidCrystal
- (Item existente)



RP2: Ajustes via interface
RD2.1: Keypad (DFR0009)
- (Item existente)




RD2.2: Mega 2560 (54 GPIO)
- (Item existente)



RP3: Conectividade Wi-Fi (MQTT)
RD3.1: Wi-Fi (ESP8266)
T0.1, T1.1




RD3.2: Biblioteca PubSubClient
T1.1




RD3.3: INA219 (±1 mA, ±10 mV)
T0.2, T1.2




RD3.4: Biblioteca Adafruit_INA219
T0.2, T1.2




RD3.5: Alimentação 5 V, 3,3 V
T0.2, T1.2


Referências Cruzadas:

Para detalhes dos requisitos, consulte Automação Cervejaria - Especificações e Configurações.
Para cronograma, consulte Automação Cervejaria - Plano de Execução.
Para pendências relacionadas, consulte Automação Cervejaria - Anotações, Pendências e Melhorias.

