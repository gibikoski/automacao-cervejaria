





Automação Cervejaria - Especificações e Configurações
Controle de Versão



Versão
Data
Descrição



v1.0.0
19/04/2025
Versão inicial do documento.


v1.0.1
20/04/2025
Implementação das melhorias conforme abaixo: Melhorias Implementadas (v1.0.1).


Índice



Seção
Título



1
Visão Geral do Projeto


2
Definição de Funções e Requisitos


3
Lista de Equipamentos e BOM


4
Melhorias Implementadas (v1.0.1)


Metadados



Atributo
Valor



artifact_id
21c0119f-54ea-4f1a-b0eb-a9d56b221cbd


Versão
v1.0.1


Data
20/04/2025


Autor
Grok (xAI)


1. Visão Geral do Projeto
Título: Automação Cervejaria Utilizando Arduino/ESP32Objetivo: Desenvolver um sistema de automação para processos cervejeiros, incluindo controle de temperatura de fermentação, medição de volume (litros), densidade de líquido, e interface para monitoramento e ajustes, integrado via Wi-Fi (MQTT, Home Assistant).Escopo:  

Período: Maio a Outubro 2025 (6 meses).  
Orçamento: €186,28-207,28 (com VAT).  
Status: Esquemáticos 90% concluídos, itens em transporte (entrega até 30/04/2025).  
Ambiente: Prototipagem em protoboard, com foco em precisão, segurança, e conectividade.  
Nota: Custos de frete, impostos, e tempo de transporte estimados com base em fornecedores internacionais (ex.: AliExpress).

Resumo das Funções:



Nome da Função
Objetivo
Status
Orçamento Estimado (€)



Controle de Fermentação
Controle de temperatura (~220 V, Manta 500W) com precisão de ±0,5°C, operação autônoma via bateria.
Esquemático 90% concluído.
61,47-77,47


Balança de Volume
Medição de volume (5-40 litros) via peso (±0,1-1 g) e densidade conhecida.
Esquemático 90% concluído, plataforma TBD.
29,47-41,47


Densímetro Flutuante
Medição de densidade (±0,001-0,005 g/cm³) com operação autônoma e Wi-Fi.
Esquemático 90% concluído.
26,47-37,47


Controle e Monitoramento
Interface para integração, exibição e ajustes via Wi-Fi.
Esquemático 90% concluído.
36,89-47,89


Referências Cruzadas: Para detalhes, consulte Seção 2. Para cronograma, consulte Plano de Execução, Seção 5. Para pendências, consulte Anotações, Pendências e Melhorias, Seção 8.
2. Definição de Funções e Requisitos
2.1 Função Controle de Fermentação (aquecimento)
Descrição: Sistema para controle de temperatura em fermentação (~220 V, Manta 500W), com monitoramento remoto (MQTT) e operação autônoma via bateria.
Requisitos:



Código
Descrição
Tipo
Referência



RP1
Controlar temperatura (manta 500W) com precisão de ±0,5°C.
Primário
Plano de Execução, Seção 4.1, T1.1, T1.2


RD1.1
Sensor de temperatura DS18B20 (±0,5°C, 1-Wire).
Derivado
Plano de Execução, Seção 4.1, T0.2, T1.1


RD1.2
Controle de aquecimento via SSR-10DA (~3-32 V DC).
Derivado
Plano de Execução, Seção 4.1, T0.3, T1.2


RD1.3
Biblioteca OneWire para DS18B20.
Derivado
Plano de Execução, Seção 4.1, T0.2, T1.1


RP2
Garantir segurança elétrica (fusível 3 A).
Primário
Plano de Execução, Seção 4.1, T2.1


RD2.1
Fusível 3 A para proteção contra sobrecarga.
Derivado
Plano de Execução, Seção 4.1, T2.1


RP3
Permitir monitoramento remoto via MQTT.
Primário
Plano de Execução, Seção 4.1, T3.1


RD3.1
Comunicação Wi-Fi (2,4 GHz, MQTT, R4 Connect).
Derivado
Plano de Execução, Seção 4.1, T0.1, T3.1


RD3.2
Biblioteca PubSubClient para MQTT.
Derivado
Plano de Execução, Seção 4.1, T3.1


RP4
Operar autonomamente por até 24 horas.
Primário
Plano de Execução, Seção 4.1, T4.1


RD4.1
Bateria 18650 (~3,7 V, 2600 mAh).
Derivado
Plano de Execução, Seção 4.1, T4.1


RD4.2
Sensor INA219 (±1 mA, ±10 mV, I2C).
Derivado
Plano de Execução, Seção 4.1, T0.4, T4.1


RD4.3
Biblioteca Adafruit_INA219 para INA219.
Derivado
Plano de Execução, Seção 4.1, T0.4, T4.1


Componentes:



Componente
Quantidade
Preço Unitário (€)
Preço Total (€)
Status



Arduino R4 Connect
1
22,00
22,00
Em transporte


DS18B20
1
1,00-3,00
1,00-3,00
Em transporte


SSR-10DA
1
5,00-10,00
5,00-10,00
Em transporte


Manta 500W
1
10,00-20,00
10,00-20,00
A comprar (Mês 2)


Fusível 3 A
1
0,50-1,00
0,50-1,00
Em transporte


Bateria 18650
1
4,47
4,47
A comprar (Mês 2)


INA219
1
1,00-3,00
1,00-3,00
A comprar (Mês 2)


Capacitores (0,1 µF, 1 µF)
Vários
-
9,50
A comprar (Mês 4)


Protoboard (400 pins)
1
3,00-5,00
3,00-5,00
Em transporte


Resistores (300 peças)
1
2,00-3,00
2,00-3,00
Em transporte


Caixa universal
1
2,00-3,00
2,00-3,00
A comprar (Mês 2)


Pinouts e Conexões:



Componente
Pino
Conexão
Observação



Arduino R4 Connect
D2
DS18B20 (DQ, 1-Wire)
Resistor pull-up 4,7 kΩ para 3,3 V.


Arduino R4 Connect
D3
SSR-10DA (controle, 3-32 V DC)
-


Arduino R4 Connect
A4, A5
INA219 (SDA, SCL, I2C)
-


Arduino R4 Connect
VCC
5 V (fonte USB ou bateria via regulador)
-


Arduino R4 Connect
GND
Terra comum
-


DS18B20
VCC
3,3 V (Arduino R4 Connect)
Modo parasitário não recomendado.


DS18B20
GND
Terra
-


DS18B20
DQ
D2 (Arduino R4 Connect)
Pull-up 4,7 kΩ.


SSR-10DA
Controle (+)
D3 (Arduino R4 Connect)
-


SSR-10DA
Controle (-)
GND (Arduino R4 Connect)
-


SSR-10DA
Saída
220 V AC (Manta 500W)
Fusível 3 A em série.


INA219
VCC
3,3 V (Arduino R4 Connect)
-


INA219
GND
Terra
-


INA219
SDA, SCL
A4, A5 (Arduino R4 Connect)
-


INA219
VIN+
Bateria 18650 (+)
-


INA219
VIN-
Carga (resistor 10 Ω)
Conectar em série.


Status: Esquemático 90% concluído, lâmpada 40W como proxy para Manta.Referências Cruzadas: Para testes, consulte Plano de Execução, Seção 4.1. Para pendências, consulte Anotações, Pendências e Melhorias, Seção 8.
2.2 Função Balança de Volume (litros fermentador/keg)
Descrição: Medição de volume (5-40 litros) de cerveja, calculado via peso (~±0,1-1 g) e densidade conhecida (manual ou via Densímetro), com nivelamento automático e Wi-Fi.
Requisitos:



Código
Descrição
Tipo
Referência



RP1
Medir volume com precisão de ±0,1-1 litro, usando peso e densidade.
Primário
Plano de Execução, Seção 4.2, T1.1, T1.2


RD1.1
ADC de 24 bits (HX711).
Derivado
Plano de Execução, Seção 4.2, T0.2, T1.1


RD1.2
Células de carga calibradas (5-40 kg).
Derivado
Plano de Execução, Seção 4.2, T1.1


RD1.3
Algoritmo Volume = Peso / Densidade.
Derivado
Plano de Execução, Seção 4.2, T1.2


RD1.4
Biblioteca HX711.
Derivado
Plano de Execução, Seção 4.2, T0.2, T1.1


RP2
Garantir nivelamento automático (±0,1 g).
Primário
Plano de Execução, Seção 4.2, T2.1


RD2.1
Sensor inercial MPU6050 (I2C).
Derivado
Plano de Execução, Seção 4.2, T0.3, T2.1


RD2.2
Biblioteca Adafruit_MPU6050.
Derivado
Plano de Execução, Seção 4.2, T0.3, T2.1


RP3
Enviar dados de volume via MQTT.
Primário
Plano de Execução, Seção 4.2, T3.1


RD3.1
Comunicação Wi-Fi (ESP32-C3).
Derivado
Plano de Execução, Seção 4.2, T0.1, T3.1


RD3.2
Biblioteca PubSubClient.
Derivado
Plano de Execução, Seção 4.2, T3.1


RD3.3
Alimentação de 3,3 V (~100 mA ESP32-C3, ~1,5 mA HX711).
Derivado
Plano de Execução, Seção 4.2, T0.1, T1.1


Componentes:



Componente
Quantidade
Preço Unitário (€)
Preço Total (€)
Status



ESP32-C3
1
3,00-5,00
3,00-5,00
A comprar (Mês 1)


HX711
1
1,00-3,00
1,00-3,00
A comprar (Mês 1)


MPU6050
1
2,00-4,00
2,00-4,00
A comprar (Mês 1)


Células de carga
4
2,50-3,75
10,00-15,00
A comprar (Mês 1)


Bateria 18650
1
4,47
4,47
A comprar (Mês 1)


Capacitores (0,1 µF)
Vários
-
9,50
A comprar (Mês 4)


Protoboard (400 pins)
1
3,00-5,00
3,00-5,00
Em transporte


Resistores (300 peças)
1
2,00-3,00
2,00-3,00
Em transporte


Pinouts e Conexões:



Componente
Pino
Conexão
Observação



ESP32-C3
GPIO4
HX711 (DT)
-


ESP32-C3
GPIO5
HX711 (SCK)
-


ESP32-C3
GPIO18, GPIO19
MPU6050 (SDA, SCL, I2C)
Resistor pull-up 4,7 kΩ, se necessário.


ESP32-C3
VCC
3,3 V (bateria 18650 via regulador)
-


ESP32-C3
GND
Terra comum
Wi-Fi interno, antena livre.


HX711
VCC
3,3 V (ESP32-C3)
-


HX711
GND
Terra
-


HX711
DT, SCK
GPIO4, GPIO5 (ESP32-C3)
-


HX711
E+, E-, A+, A-
Células de carga
Calibrar com peso conhecido.


MPU6050
VCC
3,3 V (ESP32-C3)
-


MPU6050
GND
Terra
-


MPU6050
SDA, SCL
GPIO18, GPIO19 (ESP32-C3)
Resistor pull-up 4,7 kΩ, se necessário.


Status: Esquemático 90% concluído, plataforma TBD.Referências Cruzadas: Para testes, consulte Plano de Execução, Seção 4.2. Para pendências, consulte Anotações, Pendências e Melhorias, Seção 8.
2.3 Função Densímetro Flutuante Remoto
Descrição: Medição de densidade (~±0,001-0,005 g/cm³) com flutuador, operação autônoma, temperatura, e Wi-Fi.
Requisitos:



Código
Descrição
Tipo
Referência



RP1
Medir densidade com precisão de ±0,001-0,005 g/cm³.
Primário
Plano de Execução, Seção 4.3, T1.1


RD1.1
Sensor inercial ICM20948 (I2C).
Derivado
Plano de Execução, Seção 4.3, T0.2, T1.1


RD1.2
Biblioteca ICM20948.
Derivado
Plano de Execução, Seção 4.3, T0.2, T1.1


RP2
Monitorar temperatura (±0,5°C).
Primário
Plano de Execução, Seção 4.3, T2.1


RD2.1
Sensor de temperatura DS18B20 (±0,5°C).
Derivado
Plano de Execução, Seção 4.3, T0.3, T2.1


RD2.2
Biblioteca OneWire.
Derivado
Plano de Execução, Seção 4.3, T0.3, T2.1


RP3
Garantir autonomia de 3-5 dias.
Primário
Plano de Execução, Seção 4.3, T3.1


RD3.1
Bateria 18650 (~3,7 V, 2600 mAh).
Derivado
Plano de Execução, Seção 4.3, T3.1


RD3.2
Regulador de tensão TPS63020 (3,3 V).
Derivado
Plano de Execução, Seção 4.3, T0.4, T3.1


RD3.3
Sensor INA219 (±1 mA, ±10 mV, I2C).
Derivado
Plano de Execução, Seção 4.3, T0.5, T4.2


RD3.4
Biblioteca Adafruit_INA219.
Derivado
Plano de Execução, Seção 4.3, T0.5, T4.2


RP4
Garantir comunicação Wi-Fi via MQTT.
Primário
Plano de Execução, Seção 4.3, T4.1


RD4.1
Comunicação Wi-Fi (ESP32-C3).
Derivado
Plano de Execução, Seção 4.3, T0.1, T4.1


RD4.2
Biblioteca PubSubClient.
Derivado
Plano de Execução, Seção 4.3, T4.1


Componentes:



Componente
Quantidade
Preço Unitário (€)
Preço Total (€)
Status



ESP32-C3
1
3,00-5,00
3,00-5,00
A comprar (Mês 2)


ICM20948
1
5,00-7,00
5,00-7,00
A comprar (Mês 2)


DS18B20
1
1,00-3,00
1,00-3,00
Em transporte


TPS63020
1
3,00-5,00
3,00-5,00
A comprar (Mês 2)


INA219
1
1,00-3,00
1,00-3,00
A comprar (Mês 2)


Bateria 18650
1
4,47
4,47
A comprar (Mês 2)


Capacitores (0,1 µF, 10 µF)
Vários
-
9,50
A comprar (Mês 4)


Protoboard (400 pins)
1
3,00-5,00
3,00-5,00
Em transporte


Resistores (300 peças)
1
2,00-3,00
2,00-3,00
Em transporte


Pinouts e Conexões:



Componente
Pino
Conexão
Observação



ESP32-C3
GPIO2
DS18B20 (DQ, 1-Wire)
Pull-up 4,7 kΩ.


ESP32-C3
GPIO18, GPIO19
ICM20948, INA219 (SDA, SCL, I2C)
Resistor pull-up 4,7 kΩ.


ESP32-C3
VCC
3,3 V (TPS63020)
-


ESP32-C3
GND
Terra comum
Wi-Fi interno, verificar alcance.


ICM20948
VCC
3,3 V (TPS63020)
-


ICM20948
GND
Terra
-


ICM20948
SDA, SCL
GPIO18, GPIO19 (ESP32-C3)
Resistor pull-up 4,7 kΩ.


DS18B20
VCC
3,3 V (TPS63020)
Alimentação externa.


DS18B20
GND
Terra
-


DS18B20
DQ
GPIO2 (ESP32-C3)
Pull-up 4,7 kΩ.


TPS63020
VIN
Bateria 18650 (3,7 V)
-


TPS63020
VOUT
3,3 V (ESP32-C3, ICM20948, DS18B20, INA219)
Capacitores 0,1 µF e 10 µF.


TPS63020
GND
Terra
-


TPS63020
EN
Conectado a VIN (ativo)
-


INA219
VCC
3,3 V (TPS63020)
-


INA219
GND
Terra
-


INA219
SDA, SCL
GPIO18, GPIO19 (ESP32-C3)
-


INA219
VIN+
Bateria 18650 (+)
-


INA219
VIN-
Carga (resistor 10 Ω)
Conectar em série.


Status: Esquemático 90% concluído.Referências Cruzadas: Para testes, consulte Plano de Execução, Seção 4.3. Para pendências, consulte Anotações, Pendências e Melhorias, Seção 8.
2.4 Função Controle, Monitoramento e Alterações de Parâmetros
Descrição: Interface central para integração, exibição de dados, e ajustes de parâmetros, com display e Wi-Fi.
Requisitos:



Código
Descrição
Tipo
Referência



RP1
Exibir dados de todas as funções (temperatura, volume, densidade).
Primário
Plano de Execução, Seção 4.4, T1.1


RD1.1
Display LCD 1602 (DFR0009, 5 V, 500 µA).
Derivado
Item existente


RD1.2
Biblioteca LiquidCrystal.
Derivado
Item existente


RP2
Permitir ajustes de parâmetros via interface.
Primário
Plano de Execução, Seção 4.4, T1.1


RD2.1
Keypad com 5-6 botões (DFR0009).
Derivado
Item existente


RD2.2
Múltiplos GPIO (Mega 2560, 54 GPIO).
Derivado
Item existente


RP3
Garantir conectividade Wi-Fi (MQTT).
Primário
Plano de Execução, Seção 4.4, T1.1, T1.2


RD3.1
Comunicação Wi-Fi (ESP8266).
Derivado
Plano de Execução, Seção 4.4, T0.1, T1.1


RD3.2
Biblioteca PubSubClient.
Derivado
Plano de Execução, Seção 4.4, T1.1


RD3.3
Sensor INA219 (±1 mA, ±10 mV, I2C).
Derivado
Plano de Execução, Seção 4.4, T0.2, T1.2


RD3.4
Biblioteca Adafruit_INA219.
Derivado
Plano de Execução, Seção 4.4, T0.2, T1.2


RD3.5
Alimentação de 5 V (Mega 2560) e 3,3 V (ESP8266).
Derivado
Plano de Execução, Seção 4.4, T0.2, T1.2


Componentes:



Componente
Quantidade
Preço Unitário (€)
Preço Total (€)
Status



Mega 2560
1
12,00
12,00
Item existente


ESP8266
1
4,89
4,89
A comprar (Mês 3)


DFR0009
1
7,00
7,00
Item existente


INA219
1
1,00-3,00
1,00-3,00
A comprar (Mês 3)


Capacitores (0,1 µF)
Vários
-
9,50
A comprar (Mês 4)


Protoboard (400 pins)
1
3,00-5,00
3,00-5,00
Em transporte


Resistores (300 peças)
1
2,00-3,00
2,00-3,00
Em transporte


Pinouts e Conexões:



Componente
Pino
Conexão
Observação



ESP8266
GPIO4, GPIO5
INA219 (SDA, SCL, I2C)
Resistor pull-up 10 kΩ em CH_PD.


ESP8266
VCC
3,3 V (fonte externa ou regulador)
-


ESP8266
GND
Terra
-


ESP8266
CH_PD
3,3 V (habilitar chip)
-


INA219
VCC
3,3 V (ESP8266)
-


INA219
GND
Terra
-


INA219
SDA, SCL
GPIO4, GPIO5 (ESP8266)
-


INA219
VIN+
Fonte 5 V (Mega 2560)
-


INA219
VIN-
Carga (resistor 10 Ω)
Conectar em série.


Status: Esquemático 90% concluído.Referências Cruzadas: Para testes, consulte Plano de Execução, Seção 4.4. Para pendências, consulte Anotações, Pendências e Melhorias, Seção 8.
3. Lista de Equipamentos e BOM



Função
Componente
Quantidade
Preço Unitário (€)
Preço Total (€)
Status



Controle de Fermentação
Arduino R4 Connect
1
22,00
22,00
Em transporte


Controle de Fermentação
DS18B20
1
1,00-3,00
1,00-3,00
Em transporte


Controle de Fermentação
SSR-10DA
1
5,00-10,00
5,00-10,00
Em transporte


Controle de Fermentação
Manta 500W
1
10,00-20,00
10,00-20,00
A comprar (Mês 2)


Controle de Fermentação
Fusível 3 A
1
0,50-1,00
0,50-1,00
Em transporte


Controle de Fermentação
Bateria 18650
1
4,47
4,47
A comprar (Mês 2)


Controle de Fermentação
INA219
1
1,00-3,00
1,00-3,00
A comprar (Mês 2)


Balança de Volume
ESP32-C3
1
3,00-5,00
3,00-5,00
A comprar (Mês 1)


Balança de Volume
HX711
1
1,00-3,00
1,00-3,00
A comprar (Mês 1)


Balança de Volume
MPU6050
1
2,00-4,00
2,00-4,00
A comprar (Mês 1)


Balança de Volume
Células de carga
4
2,50-3,75
10,00-15,00
A comprar (Mês 1)


Balança de Volume
Bateria 18650
1
4,47
4,47
A comprar (Mês 1)


Densímetro Flutuante
ESP32-C3
1
3,00-5,00
3,00-5,00
A comprar (Mês 2)


Densímetro Flutuante
ICM20948
1
5,00-7,00
5,00-7,00
A comprar (Mês 2)


Densímetro Flutuante
DS18B20
1
1,00-3,00
1,00-3,00
Em transporte


Densímetro Flutuante
TPS63020
1
3,00-5,00
3,00-5,00
A comprar (Mês 2)


Densímetro Flutuante
INA219
1
1,00-3,00
1,00-3,00
A comprar (Mês 2)


Densímetro Flutuante
Bateria 18650
1
4,47
4,47
A comprar (Mês 2)


Controle e Monitoramento
Mega 2560
1
12,00
12,00
Item existente


Controle e Monitoramento
ESP8266
1
4,89
4,89
A comprar (Mês 3)


Controle e Monitoramento
DFR0009
1
7,00
7,00
Item existente


Controle e Monitoramento
INA219
1
1,00-3,00
1,00-3,00
A comprar (Mês 3)


Geral
Capacitores (0,1 µF, 1 µF, 10 µF)
Vários
-
9,50
A comprar (Mês 4)


Geral
Protetor silicone p/ bancada
1
5,00
5,00
A comprar (Mês 1)


Geral
Protoboard (400 pins)
1
3,00-5,00
3,00-5,00
Em transporte


Geral
Resistores (300 peças)
1
2,00-3,00
2,00-3,00
Em transporte


Geral
Caixa universal (R4 Connect)
1
2,00-3,00
2,00-3,00
A comprar (Mês 2)


Geral
Ferro de solda TS85 (Quecoo)
1
20,00-30,00
20,00-30,00
A comprar (Mês 1)


Geral
Multímetro RM113D (Richmeters)
1
15,00-20,00
15,00-20,00
A comprar (Mês 1)


Total Estimado: €186,28-207,28 (com VAT).
Itens em Transporte (~3SALX000015911263, entrega até 30/04/2025):

Resistores (300 peças, AliExpress).
Arduino R4 Connect (Wi-Fi, AliExpress).
Protoboard (400 pins, AliExpress).
Caixa universal (R4 Connect, AliExpress).
Fusível 3 A (AliExpress).
DS18B20 (1 m com módulo, AliExpress).
SSR-10DA (DC controla AC, AliExpress).

Referências Cruzadas: Para testes, consulte Plano de Execução, Seção 4. Para pendências, consulte Anotações, Pendências e Melhorias, Seção 8.
Melhorias Implementadas (v1.0.1)

Substituídas listas por tabelas para Funções do Sistema (Seção 1), Requisitos Primários e Derivados (Seção 2), Pinouts e Conexões (Seção 2).
Adicionadas referências cruzadas ligando requisitos a testes (Plano de Execução, Seção 4) e componentes a pendências (Anotações, Pendências e Melhorias, Seção 8).
Incluída tabela de resumo inicial na Seção 1 (funções, objetivos, status, orçamento).
Adicionado índice após o Controle de Versão.
Padronizados cabeçalhos de tabelas (ex.: "Código" para requisitos).
Adicionada tabela de metadados visuais após o Controle de Versão.


