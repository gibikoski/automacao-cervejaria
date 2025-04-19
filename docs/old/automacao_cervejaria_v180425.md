Automação Cervejaria Utilizando Arduino/ESP32 - v180425
1. Visão Geral do Projeto
[Inalterado, conforme última versão.]
Orçamento: €190,28-217,28 (com VAT).
Versão: v180425 (18/04/2025)

2. Definição de Funções e Requisitos
2.1 Função Controle de Fermentação (aquecimento)
[Inalterado.]
2.4 Função Controle, Monitoramento e Alterações de Parâmetros
Descrição: Interface central para integração, exibição de dados, e ajustes de parâmetros, com display e Wi-Fi.
Requisitos Primários:

RP1: Exibir dados de todas as funções (temperatura, volume, densidade).
RP2: Permitir ajustes de parâmetros via interface.
RP3: Garantir conectividade Wi-Fi (MQTT).

Requisitos Derivados:

RD1.1: Display LCD 1602 para exibição (DFR0009, 5 V, 500 µA, hardware).
RD1.2: Biblioteca LiquidCrystal para DFR0009 (software).
RD2.1: Keypad com 5 botões para interação (DFR0009, hardware).
RD2.2: Múltiplos GPIO para controle (Mega 2560, 54 GPIO, hardware).
RD3.1: Comunicação Wi-Fi (ESP8266, MQTT, UART via Pinos 0/TX, 8/RX, I2C via Pinos 21/SDA, 20/SCL, hardware/software).
RD3.2: Biblioteca PubSubClient para MQTT (software).
RD3.3: Sensor INA219 para monitoramento (±1 mA, ±10 mV, I2C, hardware).
RD3.4: Biblioteca Adafruit_INA219 para INA219 (software).
RD3.5: Alimentação de 5 V (Mega 2560) e 3,3 V (ESP8266, INA219, hardware).
RD3.6: Regulador 3,3 V integrado no Feather HUZZAH ESP8266 para alimentação estável de 3,3 V (hardware).

Componentes:

Mega 2560 (€12,00)
ESP8266 (Feather HUZZAH) (€4,89)
DFR0009 (€7,00)
INA219 (€1,00-3,00)
Protoboard (400 pins, €3,00-5,00)
Resistores (300 peças, €2,00-3,00)

Pinouts e Conexões:

Mega 2560:
Pino D4 (PG5): DFR0009 (LCD D4).
Pino D5 (PE3): DFR0009 (LCD D5).
Pino D6 (PH3): DFR0009 (LCD D6).
Pino D7 (PH4): DFR0009 (LCD D7).
Pino D8 (PB4): DFR0009 (LCD RS).
Pino D9 (PB5): DFR0009 (LCD EN).
Pino A0 (PF0): DFR0009 (Keypad, botão 1).
Pino A1 (PF1): DFR0009 (Keypad, botão 2).
Pino A2 (PF2): DFR0009 (Keypad, botão 3).
Pino A3 (PF3): DFR0009 (Keypad, botão 4).
Pino A4 (PF4): DFR0009 (Keypad, botão 5).
Pino D18 (PD3, TX1): ESP8266 Pino 8 (RX, GPIO3, UART).
Pino D19 (PD2, RX1): ESP8266 Pino 0 (TX, GPIO1, UART).
VCC: 5 V (fonte USB ou externa) → ESP8266 Pino 12 (Vusb), DFR0009 VCC.
GND: Terra comum → ESP8266 Pino 3 (GND), INA219 GND, DFR0009 GND.


ESP8266 (Feather HUZZAH):
Pino 0: TX (GPIO1) → Mega 2560 D19 (PD2, RX1, UART).
Pino 8: RX (GPIO3) → Mega 2560 D18 (PD3, TX1, UART).
Pino 21: SDA (GPIO4) → INA219 SDA (I2C).
Pino 20: SCL (GPIO5) → INA219 SCL (I2C).
Pino 12: Vusb → Mega 2560 VCC (5 V).
Pino 2: 3V → INA219 VCC (3,3 V do regulador integrado).
Pino 3: GND → Mega 2560 GND.
Pino 11: EN (CH_PD) → ESP8266 Pino 2 (3V, pull-up 10 kΩ).
Pino 9: GPIO0 → ESP8266 Pino 2 (3V, pull-up 10 kΩ).
Pino 13: GPIO2 → ESP8266 Pino 2 (3V, pull-up 10 kΩ).
Pinos 1, 4-7, 10, 14-15: Não usados.
Nota: Pinagem baseada no Feather HUZZAH (https://cdn-learn.adafruit.com/downloads/pdf/adafruit-feather-huzzah-esp8266.pdf) e lista fornecida.


INA219:
VCC: ESP8266 Pino 2 (3V, 3,3 V).
GND: Mega 2560 GND.
SDA: ESP8266 Pino 21 (SDA, GPIO4).
SCL: ESP8266 Pino 20 (SCL, GPIO5).
VIN+: Mega 2560 VCC (5 V).
VIN-: Carga (ex.: resistor 10 Ω).
A0, A1: Deixar abertos (endereço I2C 0x40).


DFR0009 (Display Keypad Shield):
LCD Pins (D4-D7, RS, EN): D4-D7, D8-D9 (Mega 2560).
Keypad Pins: A0-A4 (Mega 2560).
VCC: 5 V (Mega 2560).
GND: Terra.



Status: Esquemático 90% concluído, pinagem do ESP8266 corrigida, TPS63020 (3,3 V) removido. Versão v180425 congelada.

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


Controle de Fermentação
TPS63020 (VOUT 5 V)
1
3,00-5,00
3,00-5,00
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


Balança de Volume
TPS63020 (VOUT 3,3 V)
1
3,00-5,00
3,00-5,00
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
TPS63020 (VOUT 3,3 V)
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
ESP8266 (Feather HUZZAH)
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
Capacitors (0,1 µF, 10 µF)
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


Total Estimado: €190,28-217,28 (com VAT).

4. Plano de Testes
4.1 Função Controle de Fermentação (aquecimento)
[Inalterado.]
4.4 Função Controle, Monitoramento e Alterações de Parâmetros
Testes de ICs Críticos (Stand Alone)

T0.1 (Valida ESP8266):
Objetivo: Verificar funcionalidade básica e pinagem (UART via Pinos 0/8, I2C via Pinos 20/21, Wi-Fi).
Procedimento: Carregar sketch de teste (pisca LED em Pino 15/GPIO16, lê I2C em Pinos 21/20, conecta Wi-Fi, envia/recebe mensagem UART com Mega 2560 via Pinos 0/8), verificar via Serial Monitor.
Setup Recomendado: ESP8266 (Feather HUZZAH), Mega 2560, protoboard (€3,00), LED com resistor 220 Ω (€1,00), multímetro RM113D (€15,00), Wi-Fi roteador (€30,00).
Alternativa: Multímetro básico (€5,00), Wi-Fi doméstico, verificar GPIO com LED visual.
Métricas: LED pisca a 1 Hz, I2C responde, Wi-Fi conecta em <10 s, UART envia/recebe mensagem.
Tempo Estimado: 1 hora.
Período: Mês 1 (Maio 2025).


T0.2 (Valida INA219):
Objetivo: Verificar leitura de corrente/tensão e pinagem (I2C).
Procedimento: Carregar sketch Adafruit_INA219, conectar SDA/SCL (Pinos 21/20 do ESP8266), VCC ao Pino 2 (3V), VIN+/VIN- a resistor 10 Ω, verificar leitura via Serial Monitor.
Setup Recomendado: ESP8266, INA219, protoboard (€3,00), resistor 10 Ω (€1,00), multímetro RM113D (€15,00).
Alternativa: Multímetro básico (€5,00), verificar I2C visualmente.
Métricas: Leitura de corrente/tensão com precisão de ±1 mA, ±10 mV, I2C funcional.
Tempo Estimado: 1 hora.
Período: Mês 1 (Maio 2025).


T0.3 (Valida Regulador 3,3 V do Feather HUZZAH):
Objetivo: Verificar regulação de tensão.
Procedimento: Conectar Pino 12 (Vusb) a Mega 2560 VCC (5 V), medir Pino 2 (3V) com multímetro, conectar ESP8266 (Wi-Fi ativo) e INA219, verificar estabilidade.
Setup Recomendado: ESP8266, Mega 2560, INA219, resistor 10 Ω (€1,00), multímetro RM113D (€15,00).
Alternativa: Multímetro básico (€5,00), sem carga.
Métricas: 3V = 3,3 V ±5%, estável com carga (~202 mA).
Tempo Estimado: 30 minutos.
Período: Mês 1 (Maio 2025).


T0.4 (Valida DFR0009): Verificar funcionalidade do LCD e Keypad. [Inalterado].
T0.5 (Valida ESP8266 Pinagem):
Objetivo: Confirmar pinagem do Feather HUZZAH (Pinos 0/TX, 8/RX, 20/SCL, 21/SDA, 12/Vusb, 2/3V, 3/GND, 11/EN, 9/GPIO0, 13/GPIO2).
Procedimento: Carregar sketch de teste (pisca LED em Pino 15/GPIO16, lê I2C do INA219 em Pinos 21/20, envia/recebe mensagem UART com Mega 2560 via Pinos 0/8, verifica Vusb/3V/GND com multímetro, confirma Pinos 9/13/11 em pull-up), monitorar via Serial Monitor.
Setup Recomendado: ESP8266, Mega 2560, INA219, protoboard (€3,00), LED com resistor 220 Ω (€1,00), multímetro RM113D (€15,00).
Alternativa: Multímetro básico (€5,00), verificar I2C/UART visualmente.
Métricas: LED pisca, I2C responde, UART funcional, Vusb = 5 V, 3V = 3,3 V, Pinos 9/13/11 em pull-up (3,3 V).
Tempo Estimado: 1 hora.
Período: Mês 1 (Maio 2025).



Testes Funcionais

T1.1 (Valida RP3, RD3.1, RD3.2): Confirmar integração MQTT. [Inalterado].
T1.2 (Valida RP3, RD3.3): Testar monitoramento com INA219. [Inalterado].


5. Cronograma Geral



Mês
Período
Atividades
Entregáveis



Mês 1
Maio 2025
Testes unitários de ICs (Arduino R4 Connect, ESP32-C3, ESP8266, regulador Feather HUZZAH), compras de ferramentas e TPS63020 (Balança).
ICs e reguladores validados, ferramentas adquiridas.


Mês 2
Junho 2025
Integração da Função Controle de Fermentação e Balança, testes de integração, compra de TPS63020 (5 V, Controle de Fermentação).
Controle de temperatura, balança funcional.


Mês 3
Julho 2025
Desenvolvimento da Função Densímetro, testes unitários e MQTT.
Densímetro funcional.


Mês 4
Agosto 2025
Integração da Função Controle e Monitoramento, testes MQTT.
Interface central funcional.


Mês 5
Setembro 2025
Otimização de circuitos, validação de segurança, planejamento de testes de integração.
Sistema estável, plano de integração.


Mês 6
Outubro 2025
Testes de integração, validação final, documentação.
Sistema integrado, documentação.



7. Matriz de Rastreabilidade



Função
Requisito Primário (RP)
Requisito Derivado (RD)
Teste (T)



Controle e Monitoramento
RP1: Exibir dados
RD1.1: DFR0009 (LCD 1602)
T0.4




RD1.2: Biblioteca LiquidCrystal
T0.4



RP2: Ajustes via interface
RD2.1: Keypad (DFR0009)
T0.4




RD2.2: Mega 2560 (54 GPIO)
T0.4



RP3: Conectividade Wi-Fi
RD3.1: Wi-Fi (ESP8266, Pinos 0/TX, 8/RX, 20/SCL, 21/SDA)
T0.1, T0.5, T1.1




RD3.2: Biblioteca PubSubClient
T1.1




RD3.3: INA219 (±1 mA, ±10 mV)
T0.2, T1.2




RD3.4: Biblioteca Adafruit_INA219
T0.2, T1.2




RD3.5: Alimentação 5 V, 3,3 V
T0.2, T0.3, T1.2




RD3.6: Regulador 3,3 V (Feather HUZZAH)
T0.3, T0.5


[Demais funções inalteradas.]

9. Tabelas de Conexões por Função
9.1 Função Controle de Fermentação (aquecimento)
[Inalterado.]
9.4 Função Controle, Monitoramento e Alterações de Parâmetros



Origem
Destino
Tipo de Conexão
Notas



Mega 2560: D4 (PG5)
DFR0009: LCD D4
GPIO
Padrão do shield.


Mega 2560: D5 (PE3)
DFR0009: LCD D5
GPIO
Padrão do shield.


Mega 2560: D6 (PH3)
DFR0009: LCD D6
GPIO
Padrão do shield.


Mega 2560: D7 (PH4)
DFR0009: LCD D7
GPIO
Padrão do shield.


Mega 2560: D8 (PB4)
DFR0009: LCD RS
GPIO
Padrão do shield.


Mega 2560: D9 (PB5)
DFR0009: LCD EN
GPIO
Padrão do shield.


Mega 2560: A0 (PF0)
DFR0009: Keypad (botão 1)
Analog
Leitura de botões.


Mega 2560: A1 (PF1)
DFR0009: Keypad (botão 2)
Analog
Leitura de botões.


Mega 2560: A2 (PF2)
DFR0009: Keypad (botão 3)
Analog
Leitura de botões.


Mega 2560: A3 (PF3)
DFR0009: Keypad (botão 4)
Analog
Leitura de botões.


Mega 2560: A4 (PF4)
DFR0009: Keypad (botão 5)
Analog
Leitura de botões.


Mega 2560: D18 (PD3, TX1)
ESP8266: Pino 8 (RX, GPIO3)
UART
Comunicação com ESP8266.


Mega 2560: D19 (PD2, RX1)
ESP8266: Pino 0 (TX, GPIO1)
UART
Comunicação com ESP8266.


Mega 2560: VCC
ESP8266: Pino 12 (Vusb), DFR0009: VCC
Alimentação
5 V.


Mega 2560: GND
ESP8266: Pino 3 (GND), INA219: GND, DFR0009: GND
Terra
Terra comum.


ESP8266: Pino 12 (Vusb)
Mega 2560: VCC
Alimentação
5 V, regulador interno converte para 3,3 V.


ESP8266: Pino 3 (GND)
Mega 2560: GND
Terra
Terra comum.


ESP8266: Pino 8 (RX, GPIO3)
Mega 2560: D18 (PD3, TX1)
UART
Recebe dados do Mega 2560.


ESP8266: Pino 0 (TX, GPIO1)
Mega 2560: D19 (PD2, RX1)
UART
Envia dados ao Mega 2560.


ESP8266: Pino 21 (SDA, GPIO4)
INA219: SDA
I2C
Resistor pull-up 4,7 – 10 kΩ.


ESP8266: Pino 20 (SCL, GPIO5)
INA219: SCL
I2C
Resistor pull-up 4,7 – 10 kΩ.


ESP8266: Pino 9 (GPIO0)
ESP8266: Pino 2 (3V)
Pull-up
Pull-up 10 kΩ para 3,3 V, evitar boot/flash.


ESP8266: Pino 13 (GPIO2)
ESP8266: Pino 2 (3V)
Pull-up
Pull-up 10 kΩ para 3,3 V, evitar boot/flash.


ESP8266: Pino 11 (EN, CH_PD)
ESP8266: Pino 2 (3V)
Alimentação
Pull-up 10 kΩ para 3,3 V.


ESP8266: Pino 2 (3V)
INA219: VCC
Alimentação
3,3 V do regulador integrado.


INA219: VCC
ESP8266: Pino 2 (3V)
Alimentação
3,3 V.


INA219: GND
Mega 2560: GND
Terra
Terra comum.


INA219: VIN+
Mega 2560: VCC
Alimentação
5 V, conectar em série com carga.


INA219: VIN-
Carga (ex.: resistor 10 Ω)
Alimentação
Medir corrente/tensão.


INA219: A0, A1
-
-
Deixar abertos (endereço 0x40).



10. Pendências e Notas

Pendências:
Monitorar entrega (~3SALX000015911263, até 30/04/2025).
Identificar plataforma TBD para Função Balança de Volume (Mês 2).
Finalizar esquemáticos (10% restantes, Mês 1-2).
Comprar Manta 500W, bateria 18650, INA219, TPS63020 (5 V, Controle de Fermentação) (Mês 2).
Comprar INA219, ESP8266 (Mês 3).
Comprar ferro de solda, multímetro, protetor silicone (Mês 1).
Comprar caixa universal (Mês 2).


Notas:
Versão v180425 congelada em 18/04/2025.
Pinagem do ESP8266 corrigida (Pinos 0/TX, 8/RX, 20/SCL, 21/SDA, 12/Vusb, 2/3V, 3/GND, 11/EN, 9/GPIO0, 13/GPIO2).
TPS63020 (3,3 V, Controle e Monitoramento) removido, regulador 3,3 V do Feather HUZZAH usado.
Testes T0.1, T0.5 ajustados para nova pinagem.
Orçamento mantido em €190,28-217,28.
Tabela de conexões (9.4) atualizada.




11. Sugestões para Próximos Passos

Estruturação do Código:
Desenvolver sketch .ino para Função Controle e Monitoramento, usando pinagem do ESP8266 (Pinos 0/TX, 8/RX, 20/SCL, 21/SDA) e Mega 2560 (D4-D9, A0-A4, D18-D19). Aguardar nova versão.


Documentação Visual:
Criar diagrama esquemático (Fritzing/KiCad) com pinagem do ESP8266. Aguardar nova versão.


Planejamento de Testes:
Detalhar testes de integração MQTT (Mês 4-6). Aguardar nova versão.



Próximo Passo Sugerido:

Aguardar instruções para iniciar nova versão (ex.: vDDMMAA) com desenvolvimento de código .ino ou diagrama esquemático.

