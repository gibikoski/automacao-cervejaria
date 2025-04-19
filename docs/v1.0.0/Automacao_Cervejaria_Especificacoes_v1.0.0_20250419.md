<!-- Nome de arquivo sugerido: Automacao_Cervejaria_Especificacoes_v1.0.0_20250419.md --> <!-- Metadados --> <!-- artifact_id: 21c0119f-54ea-4f1a-b0eb-a9d56b221cbd --> <!-- Versão: v1.0.0 --> <!-- Data: 19/04/2025 -->
Automação Cervejaria - Especificações e Configurações
Controle de Versão
Versão	Data	Descrição
v1.0.0	19/04/2025	Versão inicial do documento.
1. Visão Geral do Projeto
Título: Automação Cervejaria Utilizando Arduino/ESP32

Objetivo: Desenvolver um sistema de automação para processos cervejeiros, incluindo controle de temperatura de fermentação, medição de volume (litros), densidade de líquido, e interface para monitoramento e ajustes, integrado via Wi-Fi (MQTT, Home Assistant).

Escopo:

Período: Maio a Outubro 2025 (6 meses).
Orçamento: €186,28-207,28 (com VAT).
Status: Esquemáticos 90% concluídos, itens em transporte (entrega até 30/04/2025).
Ambiente: Prototipagem em protoboard, com foco em precisão, segurança, e conectividade.
Nota: Custos de frete, impostos, e tempo de transporte estimados com base em fornecedores internacionais (ex.: AliExpress).
Funções do Sistema:

Função Controle de Fermentação (aquecimento): Controle de temperatura (~220 V, Manta 500W) com precisão de ±0,5°C, operação autônoma via bateria.
Função Balança de Volume (litros fermentador/keg): Medição de volume (5-40 litros) de cerveja via peso (±0,1-1 g) e densidade conhecida.
Função Densímetro Flutuante Remoto: Medição de densidade (~±0,001-0,005 g/cm³) com operação autônoma e Wi-Fi.
Função Controle, Monitoramento e Alterações de Parâmetros: Interface central para integração, exibição, e ajustes via Wi-Fi.
Referências Cruzadas:

Para o plano de testes e cronograma, consulte Automação Cervejaria - Plano de Execução.
Para dependências e rastreabilidade, consulte Automação Cervejaria - Rastreabilidade.
Para pendências e sugestões, consulte Automação Cervejaria - Anotações, Pendências e Melhorias.
2. Definição de Funções e Requisitos
2.1 Função Controle de Fermentação (aquecimento)
Descrição: Sistema para controle de temperatura em fermentação (~220 V, Manta 500W), com monitoramento remoto (MQTT) e operação autônoma via bateria.

Requisitos Primários:

RP1: Controlar temperatura (através do acionamento de carga, manta 500W) com precisão de ±0,5°C.
RP2: Garantir segurança elétrica (fusível 3 A).
RP3: Permitir monitoramento remoto via MQTT.
RP4: Operar autonomamente por até 24 horas.
Requisitos Derivados:

RD1.1: Sensor de temperatura com resolução de ±0,5°C (DS18B20, 1-Wire, hardware).
RD1.2: Controle de aquecimento via SSR-10DA (~3-32 V DC, 220 V AC, hardware).
RD1.3: Biblioteca OneWire para DS18B20 (software).
RD2.1: Fusível 3 A para proteção contra sobrecarga (hardware).
RD3.1: Comunicação Wi-Fi (2,4 GHz, MQTT, R4 Connect, hardware/software).
RD3.2: Biblioteca PubSubClient para MQTT (software).
RD4.1: Bateria 18650 (~3,7 V, 2600 mAh, hardware).
RD4.2: Sensor INA219 para monitoramento de bateria (±1 mA, ±10 mV, I2C, hardware).
RD4.3: Biblioteca Adafruit_INA219 para INA219 (software).
Componentes:

Arduino R4 Connect (€22,00)
DS18B20 (€1,00-3,00)
SSR-10DA (€5,00-10,00)
Manta 500W (€10,00-20,00)
Fusível 3 A (€0,50-1,00)
Bateria 18650 (€4,47)
INA219 (€1,00-3,00)
Capacitores (0,1 µF, 1 µF, €9,50)
Protoboard (400 pins, €3,00-5,00)
Resistores (300 peças, €2,00-3,00)
Caixa universal (€2,00-3,00)
Pinouts e Conexões:

Arduino R4 Connect:
Pino D2: DS18B20 (DQ, 1-Wire, resistor pull-up 4,7 kΩ para 3,3 V).
Pino D3: SSR-10DA (controle, 3-32 V DC).
Pinos A4, A5: INA219 (SDA, SCL, I2C).
VCC: 5 V (fonte USB ou bateria via regulador).
GND: Terra comum.
Nota: Verificar pinagem Wi-Fi interna (não requer conexões externas).
DS18B20:
VCC: 3,3 V (Arduino R4 Connect).
GND: Terra.
DQ: D2 (Arduino R4 Connect, pull-up 4,7 kΩ).
Nota: Modo parasitário não recomendado; usar alimentação externa.
SSR-10DA:
Controle (+): D3 (Arduino R4 Connect, 3-32 V DC).
Controle (-): GND (Arduino R4 Connect).
Saída: 220 V AC (Manta 500W, com fusível 3 A em série).
Nota: Isolar circuito AC, usar multímetro para verificar.
INA219:
VCC: 3,3 V (Arduino R4 Connect).
GND: Terra.
SDA: A4 (Arduino R4 Connect).
SCL: A5 (Arduino R4 Connect).
VIN+: Bateria 18650 (+).
VIN-: Carga (ex.: resistor 10 Ω).
Nota: Conectar em série com carga para medir corrente.
Status: Esquemático 90% concluído, lâmpada 40W como proxy para Manta.

2.2 Função Balança de Volume (litros fermentador/keg)
Descrição: Medição de volume (5-40 litros) de cerveja, calculado via peso (~±0,1-1 g) e densidade conhecida (manual ou via Densímetro), com nivelamento automático e Wi-Fi.

Requisitos Primários:

RP1: Medir volume de cerveja com precisão de ±0,1-1 litro, usando peso e densidade conhecida.
RP2: Garantir nivelamento automático (±0,1 g).
RP3: Enviar dados de volume via Wi-Fi (MQTT).
Requisitos Derivados:

RD1.1: ADC de 24 bits para medição de peso (HX711, hardware).
RD1.2: Células de carga calibradas para 5-40 kg (~5-40 litros, hardware).
RD1.3: Algoritmo para calcular volume (Volume = Peso / Densidade, software).
RD1.4: Biblioteca HX711 para conversão de peso (software).
RD2.1: Sensor inercial para nivelamento (MPU6050, I2C, hardware).
RD2.2: Biblioteca Adafruit_MPU6050 para MPU6050 (software).
RD3.1: Comunicação Wi-Fi (ESP32-C3, MQTT, hardware/software).
RD3.2: Biblioteca PubSubClient para MQTT (software).
RD3.3: Alimentação de 3,3 V (~100 mA ESP32-C3, ~1,5 mA HX711, hardware).
Componentes:

ESP32-C3 (€3,00-5,00)
HX711 (€1,00-3,00)
MPU6050 (€2,00-4,00)
Células de carga (€10,00-15,00)
Bateria 18650 (€4,47)
Capacitores (0,1 µF, €9,50)
Protoboard (400 pins, €3,00-5,00)
Resistores (300 peças, €2,00-3,00)
Pinouts e Conexões:

ESP32-C3:
Pino GPIO4: HX711 (DT).
Pino GPIO5: HX711 (SCK).
Pino GPIO18: MPU6050 (SDA, I2C).
Pino GPIO19: MPU6050 (SCL, I2C).
VCC: 3,3 V (bateria 18650 via regulador).
GND: Terra comum.
Nota: Wi-Fi interno, verificar antena livre de obstruções.
HX711:
VCC: 3,3 V (ESP32-C3).
GND: Terra.
DT: GPIO4 (ESP32-C3).
SCK: GPIO5 (ESP32-C3).
E+: Células de carga (excitação +).
E-: Células de carga (excitação -).
A+: Células de carga (sinal +).
A-: Células de carga (sinal -).
Nota: Calibrar com peso conhecido após conexão.
MPU6050:
VCC: 3,3 V (ESP32-C3).
GND: Terra.
SDA: GPIO18 (ESP32-C3).
SCL: GPIO19 (ESP32-C3).
Nota: Resistor pull-up 4,7 kΩ em SDA/SCL, se necessário.
Status: Esquemático 90% concluído, plataforma TBD.

2.3 Função Densímetro Flutuante Remoto
Descrição: Medição de densidade (~±0,001-0,005 g/cm³) com flutuador, operação autônoma, temperatura, e Wi-Fi.

Requisitos Primários:

RP1: Medir densidade com precisão de ±0,001-0,005 g/cm³.
RP2: Monitorar temperatura (±0,5°C).
RP3: Garantir autonomia de 3-5 dias.
RP4: Garantir comunicação Wi-Fi via MQTT.
Requisitos Derivados:

RD1.1: Sensor inercial para densidade (ICM20948, I2C, hardware).
RD1.2: Biblioteca ICM20948 para densidade (software).
RD2.1: Sensor de temperatura (DS18B20, ±0,5°C, hardware).
RD2.2: Biblioteca OneWire para DS18B20 (software).
RD3.1: Bateria 18650 (~3,7 V, 2600 mAh, hardware).
RD3.2: Regulador de tensão (TPS63020, 3,3 V, hardware).
RD3.3: Sensor INA219 para monitoramento (±1 mA, ±10 mV, I2C, hardware).
RD3.4: Biblioteca Adafruit_INA219 para INA219 (software).
RD4.1: Comunicação Wi-Fi (ESP32-C3, MQTT, hardware).
RD4.2: Biblioteca PubSubClient para MQTT (software).
Componentes:

ESP32-C3 (€3,00-5,00)
ICM20948 (€5,00-7,00)
DS18B20 (€1,00-3,00)
TPS63020 (€3,00-5,00)
INA219 (€1,00-3,00)
Bateria 18650 (€4,47)
Capacitores (0,1 µF, 10 µF, €9,50)
Protoboard (400 pins, €3,00-5,00)
Resistores (300 peças, €2,00-3,00)
Pinouts e Conexões:

ESP32-C3:
Pino GPIO2: DS18B20 (DQ, 1-Wire, pull-up 4,7 kΩ).
Pino GPIO18: ICM20948, INA219 (SDA, I2C).
Pino GPIO19: ICM20948, INA219 (SCL, I2C).
VCC: 3,3 V (TPS63020).
GND: Terra comum.
Nota: Wi-Fi interno, verificar alcance.
ICM20948:
VCC: 3,3 V (TPS63020).
GND: Terra.
SDA: GPIO18 (ESP32-C3).
SCL: GPIO19 (ESP32-C3).
Nota: Resistor pull-up 4,7 kΩ em SDA/SCL.
DS18B20:
VCC: 3,3 V (TPS63020).
GND: Terra.
DQ: GPIO2 (ESP32-C3, pull-up 4,7 kΩ).
Nota: Usar alimentação externa.
TPS63020:
VIN: Bateria 18650 (3,7 V).
VOUT: 3,3 V (para ESP32-C3, ICM20948, DS18B20, INA219).
GND: Terra.
EN: Conectado a VIN (ativo).
Nota: Capacitores 0,1 µF e 10 µF em VIN/VOUT.
INA219:
VCC: 3,3 V (TPS63020).
GND: Terra.
SDA: GPIO18 (ESP32-C3).
SCL: GPIO19 (ESP32-C3).
VIN+: Bateria 18650 (+).
VIN-: Carga (ex.: resistor 10 Ω).
Nota: Conectar em série com carga.
Status: Esquemático 90% concluído.

2.4 Função Controle, Monitoramento e Alterações de Parâmetros
Descrição: Interface central para integração, exibição de dados, e ajustes de parâmetros, com display e Wi-Fi.

Requisitos Primários:

RP1: Exibir dados de todas as funções (temperatura, volume, densidade).
RP2: Permitir ajustes de parâmetros via interface.
RP3: Garantir conectividade Wi-Fi (MQTT).
Requisitos Derivados:

RD1.1: Display LCD 1602 para exibição (DFR0009, 5 V, 500 µA, hardware).
RD1.2: Biblioteca LiquidCrystal para DFR0009 (software).
RD2.1: Keypad com 5-6 botões para interação (DFR0009, hardware).
RD2.2: Múltiplos GPIO para controle (Mega 2560, 54 GPIO, hardware).
RD3.1: Comunicação Wi-Fi (ESP8266, MQTT, hardware/software).
RD3.2: Biblioteca PubSubClient para MQTT (software).
RD3.3: Sensor INA219 para monitoramento (±1 mA, ±10 mV, I2C, hardware).
RD3.4: Biblioteca Adafruit_INA219 para INA219 (software).
RD3.5: Alimentação de 5 V (Mega 2560) e 3,3 V (ESP8266, regulação interna, hardware).
Componentes:

Mega 2560 (€12,00)
ESP8266 (€4,89)
DFR0009 (€7,00)
INA219 (€1,00-3,00)
Capacitores (0,1 µF, €9,50)
Protoboard (400 pins, €3,00-5,00)
Resistores (300 peças, €2,00-3,00)
Pinouts e Conexões:

ESP8266:
Pino GPIO4: INA219 (SDA, I2C).
Pino GPIO5: INA219 (SCL, I2C).
VCC: 3,3 V (fonte externa ou regulador).
GND: Terra.
CH_PD: 3,3 V (habilitar chip).
Nota: Resistor pull-up 10 kΩ em CH_PD.
INA219:
VCC: 3,3 V (ESP8266).
GND: Terra.
SDA: GPIO4 (ESP8266).
SCL: GPIO5 (ESP8266).
VIN+: Fonte 5 V (ex.: Mega 2560).
VIN-: Carga (ex.: resistor 10 Ω).
Nota: Conectar em série com carga.
Status: Esquemático 90% concluído.

3. Lista de Equipamentos e BOM
Função	Componente	Quantidade	Preço Unitário (€)	Preço Total (€)	Status
Controle de Fermentação	Arduino R4 Connect	1	22,00	22,00	Em transporte
Controle de Fermentação	DS18B20	1	1,00-3,00	1,00-3,00	Em transporte
Controle de Fermentação	SSR-10DA	1	5,00-10,00	5,00-10,00	Em transporte
Controle de Fermentação	Manta 500W	1	10,00-20,00	10,00-20,00	A comprar (Mês 2)
Controle de Fermentação	Fusível 3 A	1	0,50-1,00	0,50-1,00	Em transporte
Controle de Fermentação	Bateria 18650	1	4,47	4,47	A comprar (Mês 2)
Controle de Fermentação	INA219	1	1,00-3,00	1,00-3,00	A comprar (Mês 2)
Balança de Volume	ESP32-C3	1	3,00-5,00	3,00-5,00	A comprar (Mês 1)
Balança de Volume	HX711	1	1,00-3,00	1,00-3,00	A comprar (Mês 1)
Balança de Volume	MPU6050	1	2,00-4,00	2,00-4,00	A comprar (Mês 1)
Balança de Volume	Células de carga	4	2,50-3,75	10,00-15,00	A comprar (Mês 1)
Balança de Volume	Bateria 18650	1	4,47	4,47	A comprar (Mês 1)
Densímetro Flutuante	ESP32-C3	1	3,00-5,00	3,00-5,00	A comprar (Mês 2)
Densímetro Flutuante	ICM20948	1	5,00-7,00	5,00-7,00	A comprar (Mês 2)
Densímetro Flutuante	DS18B20	1	1,00-3,00	1,00-3,00	Em transporte
Densímetro Flutuante	TPS63020	1	3,00-5,00	3,00-5,00	A comprar (Mês 2)
Densímetro Flutuante	INA219	1	1,00-3,00	1,00-3,00	A comprar (Mês 2)
Densímetro Flutuante	Bateria 18650	1	4,47	4,47	A comprar (Mês 2)
Controle e Monitoramento	Mega 2560	1	12,00	12,00	Item existente
Controle e Monitoramento	ESP8266	1	4,89	4,89	A comprar (Mês 3)
Controle e Monitoramento	DFR0009	1	7,00	7,00	Item existente
Controle e Monitoramento	INA219	1	1,00-3,00	1,00-3,00	A comprar (Mês 3)
Geral	Capacitores (0,1 µF, 1 µF, 10 µF)	Vários	-	9,50	A comprar (Mês 4)
Geral	Protetor silicone p/ bancada	1	5,00	5,00	A comprar (Mês 1)
Geral	Protoboard (400 pins)	1	3,00-5,00	3,00-5,00	Em transporte
Geral	Resistores (300 peças)	1	2,00-3,00	2,00-3,00	Em transporte
Geral	Caixa universal (R4 Connect)	1	2,00-3,00	2,00-3,00	A comprar (Mês 2)
Geral	Ferro de solda TS85 (Quecoo)	1	20,00-30,00	20,00-30,00	A comprar (Mês 1)
Geral	Multímetro RM113D (Richmeters)	1	15,00-20,00	15,00-20,00	A comprar (Mês 1)
Total Estimado: €186,28-207,28 (com VAT).

Itens em Transporte (~3SALX000015911263, entrega até 30/04/2025):

Resistores (300 peças, https://www.aliexpress.com/item/1005007714306585.html).
Arduino R4 Connect (Wi-Fi, https://www.aliexpress.com/item/1005007130001901.html).
Protoboard (400 pins, https://www.aliexpress.com/item/1005007116071280.html).
Caixa universal (R4 Connect, https://www.aliexpress.com/item/1005008649741879.html).
Fusível 3 A (https://www.aliexpress.com/item/1005007552282115.html).
DS18B20 (1 m com módulo, https://www.aliexpress.com/item/1005001601986600.html).
SSR-10DA (DC controla AC, https://www.aliexpress.com/item/1005005837105164.html).
Referências Cruzadas:

Para detalhes dos testes de componentes, consulte Automação Cervejaria - Plano de Execução.
Para pendências d
