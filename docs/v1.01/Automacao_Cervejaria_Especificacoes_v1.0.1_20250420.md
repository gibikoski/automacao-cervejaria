# **Automação Cervejaria - Especificações e Configurações**

## **Controle de Versão**

| **Versão** | **Data** | **Descrição** |
| --- | --- | --- |
| v1.0.0 | 19/04/2025 | Versão inicial do documento com especificações, pinouts e BOM. |
| v1.0.1 | 20/04/2025 | Melhorias estruturais: tabelas separadas por função (Requisitos, BOM, Pinouts), índices com hiperlinks, referências cruzadas, formatações (**negrito**, *itálico*, emojis), metadados visuais, todos os dados da fonte original incluídos. Ajuste no índice para remover subitens, mantendo apenas seções principais. ✅ |

## **Índice**

- **1. Visão Geral**
- **2. Definição de Funções e Requisitos**
- **3. Lista de Equipamentos e BOM**
- **4. Pinouts e Conexões**

## **Metadados**

| **Atributo** | **Valor** |
| --- | --- |
| *artifact_id* | 21c0119f-54ea-4f1a-b0eb-a9d56b221cbd |
| *Versão* | v1.0.1 |
| *Data* | 20/04/2025 |
| *Autor* | Grok (xAI) |

## **1. Visão Geral**

**Título**: Automação Cervejaria Utilizando Arduino/ESP32\
**Objetivo**: Desenvolver um sistema de automação para processos cervejeiros, incluindo:

- Controle de temperatura de fermentação.
- Medição de volume (litros).
- Medição de densidade de líquido.
- Interface para monitoramento e ajustes, integrado via Wi-Fi (MQTT, Home Assistant).

**Escopo**:

- **Período**: *Maio a Outubro 2025* (6 meses).
- **Orçamento**: *€186,28-207,28* (com VAT).
- **Status**: Esquemáticos *90% concluídos*, itens em transporte (entrega até *30/04/2025*).
- **Ambiente**: Prototipagem em protoboard, com foco em precisão, segurança, e conectividade.
- **Nota**: Custos de frete, impostos, e tempo de transporte estimados com base em fornecedores internacionais (ex.: AliExpress).

### **Resumo das Funções**

| **Função** | **Descrição** | **Status** |
| --- | --- | --- |
| *Controle de Fermentação* | Controle de temperatura (\~220 V, Manta 500W) com precisão de ±0,5°C, operação autônoma via bateria. | Esquemático 90% concluído ✅ |
| *Balança de Volume* | Medição de volume (5-40 litros) via peso (±0,1-1 g) e densidade conhecida. | Esquemático 90% concluído, plataforma TBD 🔴 |
| *Densímetro Flutuante* | Medição de densidade (\~±0,001-0,005 g/cm³) com operação autônoma e Wi-Fi. | Esquemático 90% concluído ✅ |
| *Controle e Monitoramento* | Interface central para integração, exibição, e ajustes via Wi-Fi. | Esquemático 90% concluído ✅ |

*Referências Cruzadas*:

- Para o plano de testes e cronograma, consulte *Plano de Execução*.
- Para dependências e rastreabilidade, consulte *Rastreabilidade*.
- Para pendências e sugestões, consulte *Anotações, Pendências e Melhorias*.

## **2. Definição de Funções e Requisitos**

### **2.1 Controle de Fermentação**

**Descrição**: Sistema para controle de temperatura em fermentação (\~220 V, Manta 500W), com monitoramento remoto (MQTT) e operação autônoma via bateria.

**Requisitos**

| **Código** | **Descrição** | **Tipo** | **Referência** |
| --- | --- | --- | --- |
| *RP1* | Controlar temperatura (através do acionamento de carga, Manta 500W) com precisão de ±0,5°C. | Primário | *Plano de Execução*, T1.1 |
| *RP2* | Garantir segurança elétrica (fusível 3 A). | Primário | *3. Lista de Equipamentos e BOM* |
| *RP3* | Permitir monitoramento remoto via MQTT. | Primário | *Plano de Execução*, T4.1 |
| *RP4* | Operar autonomamente por até 24 horas. | Primário | *3. Lista de Equipamentos e BOM* |
| *RD1.1* | Sensor de temperatura com resolução de ±0,5°C (DS18B20, 1-Wire, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD1.2* | Controle de aquecimento via SSR-10DA (\~3-32 V DC, 220 V AC, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD1.3* | Biblioteca OneWire para DS18B20 (software). | Derivado | *Plano de Execução* |
| *RD2.1* | Fusível 3 A para proteção contra sobrecarga (hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD3.1* | Comunicação Wi-Fi (2,4 GHz, MQTT, R4 Connect, hardware/software). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD3.2* | Biblioteca PubSubClient para MQTT (software). | Derivado | *Plano de Execução* |
| *RD4.1* | Bateria 18650 (\~3,7 V, 2600 mAh, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD4.2* | Sensor INA219 para monitoramento de bateria (±1 mA, ±10 mV, I2C, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD4.3* | Biblioteca Adafruit_INA219 para INA219 (software). | Derivado | *Plano de Execução* |

### **2.2 Balança de Volume**

**Descrição**: Medição de volume (5-40 litros) de cerveja, calculado via peso (\~±0,1-1 g) e densidade conhecida (manual ou via Densímetro), com nivelamento automático e Wi-Fi.

**Requisitos**

| **Código** | **Descrição** | **Tipo** | **Referência** |
| --- | --- | --- | --- |
| *RP1* | Medir volume de cerveja com precisão de ±0,1-1 litro, usando peso e densidade conhecida. | Primário | *Plano de Execução*, T2.1 |
| *RP2* | Garantir nivelamento automático (±0,1 g). | Primário | *3. Lista de Equipamentos e BOM* |
| *RP3* | Enviar dados de volume via Wi-Fi (MQTT). | Primário | *Plano de Execução*, T4.1 |
| *RD1.1* | ADC de 24 bits para medição de peso (HX711, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD1.2* | Células de carga calibradas para 5-40 kg (\~5-40 litros, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD1.3* | Algoritmo para calcular volume (Volume = Peso / Densidade, software). | Derivado | *Plano de Execução* |
| *RD1.4* | Biblioteca HX711 para conversão de peso (software). | Derivado | *Plano de Execução* |
| *RD2.1* | Sensor inercial para nivelamento (MPU6050, I2C, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD2.2* | Biblioteca Adafruit_MPU6050 para MPU6050 (software). | Derivado | *Plano de Execução* |
| *RD3.1* | Comunicação Wi-Fi (ESP32-C3, MQTT, hardware/software). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD3.2* | Biblioteca PubSubClient para MQTT (software). | Derivado | *Plano de Execução* |
| *RD3.3* | Alimentação de 3,3 V (\~100 mA ESP32-C3, \~1,5 mA HX711, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |

### **2.3 Densímetro Flutuante**

**Descrição**: Medição de densidade (\~±0,001-0,005 g/cm³) com flutuador, operação autônoma, temperatura, e Wi-Fi.

**Requisitos**

| **Código** | **Descrição** | **Tipo** | **Referência** |
| --- | --- | --- | --- |
| *RP1* | Medir densidade com precisão de ±0,001-0,005 g/cm³. | Primário | *Plano de Execução*, T3.1 |
| *RP2* | Monitorar temperatura (±0,5°C). | Primário | *Plano de Execução*, T3.1 |
| *RP3* | Garantir autonomia de 3-5 dias. | Primário | *3. Lista de Equipamentos e BOM* |
| *RP4* | Garantir comunicação Wi-Fi via MQTT. | Primário | *Plano de Execução*, T4.1 |
| *RD1.1* | Sensor inercial para densidade (ICM20948, I2C, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD1.2* | Biblioteca ICM20948 para densidade (software). | Derivado | *Plano de Execução* |
| *RD2.1* | Sensor de temperatura (DS18B20, ±0,5°C, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD2.2* | Biblioteca OneWire para DS18B20 (software). | Derivado | *Plano de Execução* |
| *RD3.1* | Bateria 18650 (\~3,7 V, 2600 mAh, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD3.2* | Regulador de tensão (TPS63020, 3,3 V, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD3.3* | Sensor INA219 para monitoramento (±1 mA, ±10 mV, I2C, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD3.4* | Biblioteca Adafruit_INA219 para INA219 (software). | Derivado | *Plano de Execução* |
| *RD4.1* | Comunicação Wi-Fi (ESP32-C3, MQTT, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD4.2* | Biblioteca PubSubClient para MQTT (software). | Derivado | *Plano de Execução* |

### **2.4 Controle e Monitoramento**

**Descrição**: Interface central para integração, exibição de dados, e ajustes de parâmetros, com display e Wi-Fi.

**Requisitos**

| **Código** | **Descrição** | **Tipo** | **Referência** |
| --- | --- | --- | --- |
| *RP1* | Exibir dados de todas as funções (temperatura, volume, densidade). | Primário | *Plano de Execução*, T4.1 |
| *RP2* | Permitir ajustes de parâmetros via interface. | Primário | *Plano de Execução*, T4.1 |
| *RP3* | Garantir conectividade Wi-Fi (MQTT). | Primário | *Plano de Execução*, T4.1 |
| *RD1.1* | Display LCD 1602 para exibição (DFR0009, 5 V, 500 µA, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD1.2* | Biblioteca LiquidCrystal para DFR0009 (software). | Derivado | *Plano de Execução* |
| *RD2.1* | Keypad com 5-6 botões para interação (DFR0009, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD2.2* | Múltiplos GPIO para controle (Mega 2560, 54 GPIO, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD3.1* | Comunicação Wi-Fi (ESP8266, MQTT, hardware/software). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD3.2* | Biblioteca PubSubClient para MQTT (software). | Derivado | *Plano de Execução* |
| *RD3.3* | Sensor INA219 para monitoramento (±1 mA, ±10 mV, I2C, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |
| *RD3.4* | Biblioteca Adafruit_INA219 para INA219 (software). | Derivado | *Plano de Execução* |
| *RD3.5* | Alimentação de 5 V (Mega 2560) e 3,3 V (ESP8266, regulação interna, hardware). | Derivado | *3. Lista de Equipamentos e BOM* |

## **3. Lista de Equipamentos e BOM**

### **3.1 Controle de Fermentação**

| **Componente** | **Quantidade** | **Preço Unitário (€)** | **Preço Total (€)** | **Status** |
| --- | --- | --- | --- | --- |
| **Arduino R4 Connect** | 1 | 22,00 | 22,00 | Em transporte 📦 |
| **DS18B20** | 1 | 1,00-3,00 | 1,00-3,00 | Em transporte 📦 |
| **SSR-10DA** | 1 | 5,00-10,00 | 5,00-10,00 | Em transporte 📦 |
| **Manta 500W** | 1 | 10,00-20,00 | 10,00-20,00 | A comprar (Mês 2) 🔴 |
| **Fusível 3 A** | 1 | 0,50-1,00 | 0,50-1,00 | Em transporte 📦 |
| **Bateria 18650** | 1 | 4,47 | 4,47 | A comprar (Mês 2) 🔴 |
| **INA219** | 1 | 1,00-3,00 | 1,00-3,00 | A comprar (Mês 2) 🔴 |

### **3.2 Balança de Volume**

| **Componente** | **Quantidade** | **Preço Unitário (€)** | **Preço Total (€)** | **Status** |
| --- | --- | --- | --- | --- |
| **ESP32-C3** | 1 | 3,00-5,00 | 3,00-5,00 | A comprar (Mês 1) 🔴 |
| **HX711** | 1 | 1,00-3,00 | 1,00-3,00 | A comprar (Mês 1) 🔴 |
| **MPU6050** | 1 | 2,00-4,00 | 2,00-4,00 | A comprar (Mês 1) 🔴 |
| **Células de carga** | 4 | 2,50-3,75 | 10,00-15,00 | A comprar (Mês 1) 🔴 |
| **Bateria 18650** | 1 | 4,47 | 4,47 | A comprar (Mês 1) 🔴 |

### **3.3 Densímetro Flutuante**

| **Componente** | **Quantidade** | **Preço Unitário (€)** | **Preço Total (€)** | **Status** |
| --- | --- | --- | --- | --- |
| **ESP32-C3** | 1 | 3,00-5,00 | 3,00-5,00 | A comprar (Mês 2) 🔴 |
| **ICM20948** | 1 | 5,00-7,00 | 5,00-7,00 | A comprar (Mês 2) 🔴 |
| **DS18B20** | 1 | 1,00-3,00 | 1,00-3,00 | Em transporte 📦 |
| **TPS63020** | 1 | 3,00-5,00 | 3,00-5,00 | A comprar (Mês 2) 🔴 |
| **INA219** | 1 | 1,00-3,00 | 1,00-3,00 | A comprar (Mês 2) 🔴 |
| **Bateria 18650** | 1 | 4,47 | 4,47 | A comprar (Mês 2) 🔴 |

### **3.4 Controle e Monitoramento**

| **Componente** | **Quantidade** | **Preço Unitário (€)** | **Preço Total (€)** | **Status** |
| --- | --- | --- | --- | --- |
| **Mega 2560** | 1 | 12,00 | 12,00 | Item existente ✅ |
| **ESP8266** | 1 | 4,89 | 4,89 | A comprar (Mês 3) 🔴 |
| **DFR0009** | 1 | 7,00 | 7,00 | Item existente ✅ |
| **INA219** | 1 | 1,00-3,00 | 1,00-3,00 | A comprar (Mês 3) 🔴 |

### **3.5 Componentes Gerais**

| **Componente** | **Quantidade** | **Preço Unitário (€)** | **Preço Total (€)** | **Status** |
| --- | --- | --- | --- | --- |
| **Capacitores (0,1 µF, 1 µF, 10 µF)** | Vários | \- | 9,50 | A comprar (Mês 4) 🔴 |
| **Protetor silicone p/ bancada** | 1 | 5,00 | 5,00 | A comprar (Mês 1) 🔴 |
| **Protoboard (400 pins)** | 1 | 3,00-5,00 | 3,00-5,00 | Em transporte 📦 |
| **Resistores (300 peças)** | 1 | 2,00-3,00 | 2,00-3,00 | Em transporte 📦 |
| **Caixa universal (R4 Connect)** | 1 | 2,00-3,00 | 2,00-3,00 | Em transporte 📦 |
| **Ferro de solda TS85 (Quecoo)** | 1 | 20,00-30,00 | 20,00-30,00 | A comprar (Mês 1) 🔴 |
| **Multímetro RM113D (Richmeters)** | 1 | 15,00-20,00 | 15,00-20,00 | A comprar (Mês 1) 🔴 |

**Total Estimado**: *€186,28-207,28* (com VAT)

**Itens em Transporte** (\~3SALX000015911263, entrega até *30/04/2025*):

- Resistores (300 peças): `markdown [https://www.aliexpress.com/item/1005007714306585.html](https://www.aliexpress.com/item/1005007714306585.html)`
- Arduino R4 Connect (Wi-Fi): `markdown [https://www.aliexpress.com/item/1005007130001901.html](https://www.aliexpress.com/item/1005007130001901.html)`
- Protoboard (400 pins): `markdown [https://www.aliexpress.com/item/1005007116071280.html](https://www.aliexpress.com/item/1005007116071280.html)`
- Caixa universal (R4 Connect): `markdown [https://www.aliexpress.com/item/1005008649741879.html](https://www.aliexpress.com/item/1005008649741879.html)`
- Fusível 3 A: `markdown [https://www.aliexpress.com/item/1005007552282115.html](https://www.aliexpress.com/item/1005007552282115.html)`
- DS18B20 (1 m com módulo): `markdown [https://www.aliexpress.com/item/1005001601986600.html](https://www.aliexpress.com/item/1005001601986600.html)`
- SSR-10DA (DC controla AC): `markdown [https://www.aliexpress.com/item/1005005837105164.html](https://www.aliexpress.com/item/1005005837105164.html)`

*Referências Cruzadas*: Para pendências de compra, consulte *Anotações, Pendências e Melhorias*, Seção 8.

## **4. Pinouts e Conexões**

### **4.1 Controle de Fermentação**

**Arduino R4 Connect**

| **Pino** | **Conexão** | **Observação** |
| --- | --- | --- |
| **D2** | DS18B20 (DQ, 1-Wire) | Resistor pull-up 4,7 kΩ para 3,3 V. |
| **D3** | SSR-10DA (controle, 3-32 V DC) | \- |
| **A4** | INA219 (SDA, I2C) | \- |
| **A5** | INA219 (SCL, I2C) | \- |
| **VCC** | 5 V (fonte USB ou bateria via regulador) | \- |
| **GND** | Terra comum | \- |

**Notas**:

- Verificar pinagem Wi-Fi interna (não requer conexões externas).

**DS18B20**

| **Pino** | **Conexão** | **Observação** |
| --- | --- | --- |
| **VCC** | 3,3 V (Arduino R4 Connect) | \- |
| **GND** | Terra | \- |
| **DQ** | D2 (Arduino R4 Connect) | Resistor pull-up 4,7 kΩ. Modo parasitário não recomendado; usar alimentação externa. |

**SSR-10DA**

| **Pino** | **Conexão** | **Observação** |
| --- | --- | --- |
| **Controle (+)** | D3 (Arduino R4 Connect, 3-32 V DC) | \- |
| **Controle (-)** | GND (Arduino R4 Connect) | \- |
| **Saída** | 220 V AC (Manta 500W) | Com fusível 3 A em série. Isolar circuito AC, usar multímetro para verificar. |

**INA219**

| **Pino** | **Conexão** | **Observação** |
| --- | --- | --- |
| **VCC** | 3,3 V (Arduino R4 Connect) | \- |
| **GND** | Terra | \- |
| **SDA** | A4 (Arduino R4 Connect) | \- |
| **SCL** | A5 (Arduino R4 Connect) | \- |
| **VIN+** | Bateria 18650 (+) | \- |
| **VIN-** | Carga (ex.: resistor 10 Ω) | Conectar em série com carga para medir corrente. |

**Status**: Esquemático *90% concluído*, lâmpada 40W como proxy para Manta.

### **4.2 Balança de Volume**

**ESP32-C3**

| **Pino** | **Conexão** | **Observação** |
| --- | --- | --- |
| **GPIO4** | HX711 (DT) | \- |
| **GPIO5** | HX711 (SCK) | \- |
| **GPIO18** | MPU6050 (SDA, I2C) | \- |
| **GPIO19** | MPU6050 (SCL, I2C) | \- |
| **VCC** | 3,3 V (bateria 18650 via regulador) | \- |
| **GND** | Terra comum | Wi-Fi interno, verificar antena livre de obstruções. |

**HX711**

| **Pino** | **Conexão** | **Observação** |
| --- | --- | --- |
| **VCC** | 3,3 V (ESP32-C3) | \- |
| **GND** | Terra | \- |
| **DT** | GPIO4 (ESP32-C3) | \- |
| **SCK** | GPIO5 (ESP32-C3) | \- |
| **E+** | Células de carga (excitação +) | \- |
| **E-** | Células de carga (excitação -) | \- |
| **A+** | Células de carga (sinal +) | \- |
| **A-** | Células de carga (sinal -) | Calibrar com peso conhecido após conexão. |

**MPU6050**

| **Pino** | **Conexão** | **Observação** |
| --- | --- | --- |
| **VCC** | 3,3 V (ESP32-C3) | \- |
| **GND** | Terra | \- |
| **SDA** | GPIO18 (ESP32-C3) | Resistor pull-up 4,7 kΩ, se necessário. |
| **SCL** | GPIO19 (ESP32-C3) | Resistor pull-up 4,7 kΩ, se necessário. |

**Status**: Esquemático *90% concluído*, plataforma TBD.

### **4.3 Densímetro Flutuante**

**ESP32-C3**

| **Pino** | **Conexão** | **Observação** |
| --- | --- | --- |
| **GPIO2** | DS18B20 (DQ, 1-Wire) | Resistor pull-up 4,7 kΩ. |
| **GPIO18** | ICM20948, INA219 (SDA, I2C) | \- |
| **GPIO19** | ICM20948, INA219 (SCL, I2C) | \- |
| **VCC** | 3,3 V (TPS63020) | \- |
| **GND** | Terra comum | Wi-Fi interno, verificar alcance. |

**ICM20948**

| **Pino** | **Conexão** | **Observação** |
| --- | --- | --- |
| **VCC** | 3,3 V (TPS63020) | \- |
| **GND** | Terra | \- |
| **SDA** | GPIO18 (ESP32-C3) | Resistor pull-up 4,7 kΩ. |
| **SCL** | GPIO19 (ESP32-C3) | Resistor pull-up 4,7 kΩ. |

**DS18B20**

| **Pino** | **Conexão** | **Observação** |
| --- | --- | --- |
| **VCC** | 3,3 V (TPS63020) | \- |
| **GND** | Terra | \- |
| **DQ** | GPIO2 (ESP32-C3) | Resistor pull-up 4,7 kΩ. Usar alimentação externa. |

**TPS63020**

| **Pino** | **Conexão** | **Observação** |
| --- | --- | --- |
| **VIN** | Bateria 18650 (3,7 V) | \- |
| **VOUT** | 3,3 V (ESP32-C3, ICM20948, DS18B20, INA219) | Capacitores 0,1 µF e 10 µF em VIN/VOUT. |
| **GND** | Terra | \- |
| **EN** | Conectado a VIN (ativo) | \- |

**INA219**

| **Pino** | **Conexão** | **Observação** |
| --- | --- | --- |
| **VCC** | 3,3 V (TPS63020) | \- |
| **GND** | Terra | \- |
| **SDA** | GPIO18 (ESP32-C3) | \- |
| **SCL** | GPIO19 (ESP32-C3) | \- |
| **VIN+** | Bateria 18650 (+) | \- |
| **VIN-** | Carga (ex.: resistor 10 Ω) | Conectar em série com carga. |

**Status**: Esquemático *90% concluído*.

### **4.4 Controle e Monitoramento**

**ESP8266**

| **Pino** | **Conexão** | **Observação** |
| --- | --- | --- |
| **GPIO4** | INA219 (SDA, I2C) | \- |
| **GPIO5** | INA219 (SCL, I2C) | \- |
| **VCC** | 3,3 V (fonte externa ou regulador) | \- |
| **GND** | Terra | \- |
| **CH_PD** | 3,3 V (habilitar chip) | Resistor pull-up 10 kΩ. |

**INA219**

| **Pino** | **Conexão** | **Observação** |
| --- | --- | --- |
| **VCC** | 3,3 V (ESP8266) | \- |
| **GND** | Terra | \- |
| **SDA** | GPIO4 (ESP8266) | \- |
| **SCL** | GPIO5 (ESP8266) | \- |
| **VIN+** | Fonte 5 V (ex.: Mega 2560) | \- |
| **VIN-** | Carga (ex.: resistor 10 Ω) | Conectar em série com carga. |

**Status**: Esquemático *90% concluído*.
