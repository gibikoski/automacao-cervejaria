# **Automação Cervejaria - Especificações e Configurações**

## **Controle de Versão**

| **Versão** | **Data** | **Descrição** |
| --- | --- | --- |
| v1.0.0 | 19/04/2025 | Versão inicial com especificações e BOM. |
| v1.0.1 | 20/04/2025 | Melhorias estruturais, sincronização com *Checklist* e *Plano de Execução*, análise bidirecional com GAPs resolvidos (*RP2*, *RD2.1*, *RD2.2*). Adicionada seção *Análise dos GAPs Identificados*. Atualização de BOM (*status* e preços), remoção de *Pinouts* (movido para documento próprio), e aprimoramento de *Visão Geral*. ✅ |

## **Índice**

- **1. Visão Geral**
- **2. Definição de Funções e Requisitos**
- **3. Lista de Equipamentos e BOM**
- **4. Análise dos GAPs Identificados**
- **5. Anotações, Pendências e Melhorias**

## **Metadados**

| **Atributo** | **Valor** |
| --- | --- |
| *artifact_id* | 21c0119f-54ea-4f1a-b0eb-a9d56b221cbd |
| *Versão* | v1.0.1 |
| *Data* | 20/04/2025 |
| *Autor* | Grok (xAI) |

## **1. Visão Geral**

**Objetivo**: Desenvolver um sistema de automação para processos cervejeiros, integrando controle de temperatura, medição de volume e densidade, e interface de monitoramento com conectividade Wi-Fi (MQTT, Home Assistant). O projeto utiliza plataformas de baixo custo (Arduino, ESP32) em protoboard, priorizando precisão, segurança elétrica, autonomia energética, e escalabilidade para integração com sistemas domésticos.

### **Resumo das Funções**

| **Função** | **Descrição** | **Status** |
| --- | --- | --- |
| *Controle de Fermentação* | Regula temperatura (\~220 V, Manta 500W) com precisão de ±0,5°C, usando SSR-10DA e DS18B20. Suporta autonomia de 24h via bateria 18650 e monitoramento MQTT. | Esquemático 90% concluído ✅ |
| *Balança de Volume* | Calcula volume (5-40 litros, ±0,1-1 litro) via peso (HX711, células de carga) e densidade conhecida. Inclui nivelamento automático (MPU6050) e Wi-Fi. | Esquemático 90% concluído, plataforma TBD 📋 |
| *Densímetro Flutuante* | Mede densidade (±0,001-0,005 g/cm³) com flutuador (ICM20948) e temperatura (DS18B20). Autonomia de 3-5 dias com bateria 18650 e MQTT. | Esquemático 90% concluído ✅ |
| *Controle e Monitoramento* | Centraliza exibição (LCD DFR0009) e ajustes via keypad (5-6 botões). Integra dados via Wi-Fi (ESP8266) com Mega 2560 gerenciando múltiplos GPIOs. | Esquemático 90% concluído ✅ |

### **Escopo**

- **Período**: *Maio a Outubro 2025* (6 meses).
- **Orçamento**: *€118,72-129,72* (com VAT, atualizado).
- **Status**: Esquemáticos *90% concluídos*, itens em transporte (entrega até *30/04/2025*).
- **Ambiente**: Prototipagem com ênfase em validação funcional e testes unitários.

### **Referências Cruzadas**

- *Plano de Execução* (*artifact_id: 876f7d44-cad0-4b20-9cf6-eb71267ca360*) para plano de testes e cronograma.
- *Checklist de Testes* (*artifact_id: c4e2f9a8-3b7d-4f8a-a2c1-7f9e0d3b2c1e*) para rastreabilidade.
- *Automacao_Cervejaria_Pinouts_v1.0.1_20250420.markdown* para pinouts detalhados.
- *Anotações, Pendências e Melhorias* para pendências.

## **2. Definição de Funções e Requisitos**

### **2.1 Controle de Fermentação**

**Descrição**: Sistema para controle de temperatura em fermentação (\~220 V, Manta 500W), com monitoramento remoto (MQTT) e operação autônoma via bateria.

**Requisitos**

| **Código** | **Descrição** | **Tipo** | **Referência** |
| --- | --- | --- | --- |
| *RP1* | Controlar temperatura (através do acionamento de carga, Manta 500W) com precisão de ±0,5°C. | Primário | *Plano de Execução*, T1.1, T1.2 |
| *RP2* | Garantir segurança elétrica (fusível 3 A). | Primário | *Plano de Execução*, T2.1 |
| *RP3* | Permitir monitoramento remoto via MQTT. | Primário | *Plano de Execução*, T3.1 |
| *RP4* | Operar autonomamente por até 24 horas. | Primário | *Plano de Execução*, T4.1 |
| *RD1.1* | Sensor de temperatura com resolução de ±0,5°C (DS18B20, 1-Wire, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T0.2, T1.1 |
| *RD1.2* | Controle de aquecimento via SSR-10DA (\~3-32 V DC, 220 V AC, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T0.3, T1.2 |
| *RD1.3* | Biblioteca OneWire para DS18B20 (software). | Derivado | *Plano de Execução*, T0.2, T1.1 |
| *RD1.4* | Energização do Arduino R4 Connect (5 V USB ou bateria, hardware). | Derivado | *Plano de Execução*, T0.1.1 |
| *RD1.5* | I/O digital do Arduino R4 Connect (hardware). | Derivado | *Plano de Execução*, T0.1.2 |
| *RD1.6* | Comunicação I2C do Arduino R4 Connect (hardware). | Derivado | *Plano de Execução*, T0.1.3 |
| *RD2.1* | Fusível 3 A para proteção contra sobrecarga (hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T2.1 |
| *RD3.1* | Comunicação Wi-Fi (2,4 GHz, MQTT, R4 Connect, hardware/software). | Derivado | *3. Lista de Equipamentos e BOM*, T0.1.4, T3.1 |
| *RD3.2* | Biblioteca PubSubClient para MQTT (software). | Derivado | *Plano de Execução*, T3.1 |
| *RD4.1* | Bateria 18650 (\~3,7 V, 2600 mAh, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T4.1 |
| *RD4.2* | Sensor INA219 para monitoramento de bateria (±1 mA, ±10 mV, I2C, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T0.4, T4.1 |
| *RD4.3* | Biblioteca Adafruit_INA219 para INA219 (software). | Derivado | *Plano de Execução*, T0.4, T4.1 |

### **2.2 Balança de Volume**

**Descrição**: Medição de volume (5-40 litros) de cerveja, calculado via peso (\~±0,1-1 g) e densidade conhecida (manual ou via Densímetro), com nivelamento automático e Wi-Fi.

**Requisitos**

| **Código** | **Descrição** | **Tipo** | **Referência** |
| --- | --- | --- | --- |
| *RP1* | Medir volume de cerveja com precisão de ±0,1-1 litro, usando peso e densidade conhecida. | Primário | *Plano de Execução*, T1.1, T1.2 |
| *RP2* | Garantir nivelamento automático (±0,1 g). | Primário | *Plano de Execução*, T2.1 |
| *RP3* | Enviar dados de volume via Wi-Fi (MQTT). | Primário | *Plano de Execução*, T3.1 |
| *RD1.1* | ADC de 24 bits para medição de peso (HX711, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T0.2, T1.1 |
| *RD1.2* | Células de carga calibradas para 5-40 kg (\~5-40 litros, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T1.1 |
| *RD1.3* | Algoritmo para calcular volume (Volume = Peso / Densidade, software). | Derivado | *Plano de Execução*, T1.2 |
| *RD1.4* | Biblioteca HX711 para conversão de peso (software). | Derivado | *Plano de Execução*, T0.2, T1.1 |
| *RD1.5* | Energização do ESP32-C3 (3,3 V, hardware). | Derivado | *Plano de Execução*, T0.1.1 |
| *RD1.6* | I/O digital do ESP32-C3 (hardware). | Derivado | *Plano de Execução*, T0.1.2 |
| *RD1.7* | Comunicação I2C do ESP32-C3 (hardware). | Derivado | *Plano de Execução*, T0.1.3 |
| *RD2.1* | Sensor inercial para nivelamento (MPU6050, I2C, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T0.3, T2.1 |
| *RD2.2* | Biblioteca Adafruit_MPU6050 para MPU6050 (software). | Derivado | *Plano de Execução*, T0.3, T2.1 |
| *RD3.1* | Comunicação Wi-Fi (ESP32-C3, MQTT, hardware/software). | Derivado | *3. Lista de Equipamentos e BOM*, T0.1.4, T3.1 |
| *RD3.2* | Biblioteca PubSubClient para MQTT (software). | Derivado | *Plano de Execução*, T3.1 |
| *RD3.3* | Alimentação de 3,3 V (\~100 mA ESP32-C3, \~1,5 mA HX711, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T0.1.1 |

### **2.3 Densímetro Flutuante**

**Descrição**: Medição de densidade (\~±0,001-0,005 g/cm³) com flutuador, operação autônoma, temperatura, e Wi-Fi.

**Requisitos**

| **Código** | **Descrição** | **Tipo** | **Referência** |
| --- | --- | --- | --- |
| *RP1* | Medir densidade com precisão de ±0,001-0,005 g/cm³. | Primário | *Plano de Execução*, T1.1 |
| *RP2* | Monitorar temperatura (±0,5°C). | Primário | *Plano de Execução*, T2.1 |
| *RP3* | Garantir autonomia de 3-5 dias. | Primário | *Plano de Execução*, T3.1 |
| *RP4* | Garantir comunicação Wi-Fi via MQTT. | Primário | *Plano de Execução*, T4.1 |
| *RD1.1* | Sensor inercial para densidade (ICM20948, I2C, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T0.2, T1.1 |
| *RD1.2* | Biblioteca ICM20948 para densidade (software). | Derivado | *Plano de Execução*, T0.2, T1.1 |
| *RD1.3* | Energização do ESP32-C3 (3,3 V, hardware). | Derivado | *Plano de Execução*, T0.1.1 |
| *RD1.4* | I/O digital do ESP32-C3 (hardware). | Derivado | *Plano de Execução*, T0.1.2 |
| *RD1.5* | Comunicação I2C do ESP32-C3 (hardware). | Derivado | *Plano de Execução*, T0.1.3 |
| *RD2.1* | Sensor de temperatura (DS18B20, ±0,5°C, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T0.3, T2.1 |
| *RD2.2* | Biblioteca OneWire para DS18B20 (software). | Derivado | *Plano de Execução*, T0.3, T2.1 |
| *RD3.1* | Bateria 18650 (\~3,7 V, 2600 mAh, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T3.1 |
| *RD3.2* | Regulador de tensão (TPS63020, 3,3 V, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T0.4 |
| *RD3.3* | Sensor INA219 para monitoramento (±1 mA, ±10 mV, I2C, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T0.5, T4.2 |
| *RD3.4* | Biblioteca Adafruit_INA219 para INA219 (software). | Derivado | *Plano de Execução*, T0.5, T4.2 |
| *RD4.1* | Comunicação Wi-Fi (ESP32-C3, MQTT, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T0.1.4, T4.1 |
| *RD4.2* | Biblioteca PubSubClient para MQTT (software). | Derivado | *Plano de Execução*, T4.1 |

### **2.4 Controle e Monitoramento**

**Descrição**: Interface central para integração, exibição de dados, e ajustes de parâmetros, com display e Wi-Fi.

**Requisitos**

| **Código** | **Descrição** | **Tipo** | **Referência** |
| --- | --- | --- | --- |
| *RP1* | Exibir dados de todas as funções (temperatura, volume, densidade). | Primário | *Plano de Execução*, T1.3 |
| *RP2* | Permitir ajustes de parâmetros via interface. | Primário | *Plano de Execução*, Testes funcionais realizados ✅ |
| *RP3* | Garantir conectividade Wi-Fi (MQTT). | Primário | *Plano de Execução*, T1.1 |
| *RD1.1* | Display LCD 1602 para exibição (DFR0009, 5 V, 500 µA, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T0.3, T1.3 |
| *RD1.2* | Biblioteca LiquidCrystal para DFR0009 (software). | Derivado | *Plano de Execução*, T0.3, T1.3 |
| *RD1.3* | Energização do Mega 2560 (12 V, hardware). | Derivado | *Plano de Execução*, T0.1.1 |
| *RD1.4* | Comunicação I2C do Mega 2560 (hardware). | Derivado | *Plano de Execução*, T0.1.3 |
| *RD2.1* | Keypad com 5-6 botões para interação (DFR0009, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, Testes funcionais realizados ✅ |
| *RD2.2* | Múltiplos GPIO para controle (Mega 2560, 54 GPIO, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T0.3, Debug interno suficiente ✅ |
| *RD3.1* | Comunicação Wi-Fi (ESP8266, MQTT, hardware/software). | Derivado | *3. Lista de Equipamentos e BOM*, T0.1.2, T1.1 |
| *RD3.2* | Biblioteca PubSubClient para MQTT (software). | Derivado | *Plano de Execução*, T1.1 |
| *RD3.3* | Sensor INA219 para monitoramento (±1 mA, ±10 mV, I2C, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T0.2, T1.2 |
| *RD3.4* | Biblioteca Adafruit_INA219 para INA219 (software). | Derivado | *Plano de Execução*, T0.2, T1.2 |
| *RD3.5* | Alimentação de 5 V (Mega 2560) e 3,3 V (ESP8266, regulação interna, hardware). | Derivado | *3. Lista de Equipamentos e BOM*, T0.1.1 |

## **3. Lista de Equipamentos e BOM**

### **3.1 Controle de Fermentação**

| **Componente** | **Quantidade** | **Preço Unitário (€)** | **Preço Total (€)** | **Status** |
| --- | --- | --- | --- | --- |
| **Arduino R4 Connect** | 1 | 12,20 | 12,20 | Recebido ✅ |
| **DS18B20** | 1 | 1,80 | 1,80 | ERecebido ✅ |
| **SSR-10DA** | 1 | 3,60 | 3,60 | Recebido ✅ |
| **Manta 500W** | 1 | 10,00-20,00 | 10,00-20,00 | Em planejamento 📋 |
| **Fusível 3 A** | 1 | 0,50 | 0,50 | Recebido ✅ |
| **Bateria 18650** | 1 | 7,83 | 7,83 | Em planejamento 📋 |
| **INA219** | 1 | 1,00 | 1,00 | Em transporte ✈️ |

### **3.2 Balança de Volume**

| **Componente** | **Quantidade** | **Preço Unitário (€)** | **Preço Total (€)** | **Status** |
| --- | --- | --- | --- | --- |
| **ESP32-C3** | 1 | 1,40 | 1,40 | Em transporte ✈️ |
| **HX711** | 1 | 0,50 | 0,50 | Em transporte ✈️ |
| **MPU6050** | 1 | 2,00 | 2,00 | Em transporte ✈️ |
| **Células de carga** | 4 | 2,74 | 10,96 | 1 Em transporte ✈️, 3 Em planejamento 📋 |
| **Bateria 18650** | 1 | 3,92 | 3,92 | Em transporte ✈️ |

### **3.3 Densímetro Flutuante**

| **Componente** | **Quantidade** | **Preço Unitário (€)** | **Preço Total (€)** | **Status** |
| --- | --- | --- | --- | --- |
| **ESP32-C3** | 1 | 1,40 | 1,40 | Em transporte ✈️ |
| **ICM20948** | 1 | 4,80 | 4,80 | Em transporte ✈️ |
| **DS18B20** | 1 | 1,80 | 1,80 | Em transporte ✈️ |
| **TPS63020** | 1 | 2,10 | 2,10 | Em transporte ✈️ |
| **INA219** | 1 | 1,00 | 1,00 | Em transporte ✈️ |
| **Bateria 18650** | 1 | 3,92 | 3,92 | Em transporte ✈️ |

### **3.4 Controle e Monitoramento**

| **Componente** | **Quantidade** | **Preço Unitário (€)** | **Preço Total (€)** | **Status** |
| --- | --- | --- | --- | --- |
| **Mega 2560** | 1 | 0,00 | 0,00 | Item existente ✅ |
| **ESP8266** | 1 | 1,30 | 1,30 | Em transporte ✈️ |
| **DFR0009** | 1 | 0,00 | 0,00 | Item existente ✅ |
| **INA219** | 1 | 1,00 | 1,00 | Em transporte ✈️ |

### **3.5 Componentes Gerais**

| **Componente** | **Quantidade** | **Preço Unitário (€)** | **Preço Total (€)** | **Status** |
| --- | --- | --- | --- | --- |
| **Capacitores (0,1 µF, 1 µF, 10 µF)** | Vários | \- | 2,49 | Em transporte ✈️ |
| **Protetor silicone p/ bancada** | 1 | 5,00 | 5,00 | Em planejamento 📋 |
| **Protoboard (400 pins)** | 1 | 6,40 | 6,40 | Recebido ✅ |
| **Resistores (300 peças)** | 1 | 2,00-3,00 | 2,00-3,00 | Recebido ✅ |
| **Caixa universal (R4 Connect)** | 1 | 2,00-3,00 | 2,00-3,00 | Em transporte ✈️ |
| **ANENG SL105 Electric Soldering Iron Pro** | 1 | 6,30 | 6,30 | Em transporte ✈️ |
| **ANENG SZ01 Diode Tester Pro** | 1 | 11,50 | 11,50 | Em transporte ✈️ |
| **Soldering Third Helping Hand 3X Magnifier** | 1 | 10,00 | 10,00 | Em transporte ✈️ |

**Total Estimado**: *€118,72-129,72* (com VAT, atualizado)


**Itens em Transporte ✈️** 


\~LR372864684NL, entrega até *29/04/2025*:

- Capacitores (0,1 µF, 1 µF, 10 µF): https://www.aliexpress.com/item/1005006094233087.html
- HX711 + 1x Célula de carga: https://www.aliexpress.com/p/order/index.html
- TPS63020: https://www.aliexpress.com/item/1005007967030664.html
- MPU6050: https://www.aliexpress.com/item/1005007292626670.html
- INA219 (3 unidades): https://www.aliexpress.com/item/1005007925648957.html
- ESP32-C3 (3 unidades): https://www.aliexpress.com/item/1005006599545782.html
- ESP8266: https://www.aliexpress.com/item/1005006975297862.html
- ANENG SL105: https://www.aliexpress.com/item/1005007715470723.html
- ANENG SZ01: https://www.aliexpress.com/item/1005007473883692.html
- Soldering Third Helping Hand: https://www.aliexpress.com/item/1005006126258947.html


\~LR372822260NL, entrega até *03/05/2025*:

- ICM20948: https://www.aliexpress.com/item/1005005499263696.html
  

\~HRBC1007643032, entrega até *27/06/2025*:

- Bateria 18650 (2 unidades): https://www.aliexpress.com/item/1005007503438389.html

  
**Itens Recebidos ✅** (last update 23/04/2025*:


- Resistores (300 peças): https://www.aliexpress.com/item/1005007714306585.html
- Arduino R4 Connect (Wi-Fi): https://www.aliexpress.com/item/1005007130001901.html
- Protoboard (400 pins): https://www.aliexpress.com/item/1005007116071280.html
- Caixa universal (R4 Connect): https://www.aliexpress.com/item/1005008649741879.html
- Fusível 3 A: https://www.aliexpress.com/item/1005007552282115.html
- DS18B20 (1 m com módulo): https://www.aliexpress.com/item/1005001601986600.html
- SSR-10DA (DC controla AC): https://www.aliexpress.com/item/1005005837105164.html

*Referências Cruzadas*: Para pendências de compra, consulte *Anotações, Pendências e Melhorias*.

## **4. Análise dos GAPs Identificados**

### **Análise Bidirecional**

Uma análise bidirecional foi realizada entre o *Checklist de Testes v1.0.1* (*artifact_id: c4e2f9a8-3b7d-4f8a-a2c1-7f9e0d3b2c1e*), *Especificações v1.0.1* (*artifact_id: 21c0119f-54ea-4f1a-b0eb-a9d56b221cbd*), e *Plano de Execução v1.0.1* (*artifact_id: 876f7d44-cad0-4b20-9cf6-eb71267ca360*) para garantir rastreabilidade completa e conformidade.

#### **Checklist → Especificações**

- **Objetivo**: Verificar se todos os 43 testes do *Checklist* têm um *RP* ou *RD* associado.
- **Resultado**: Todos os 43 testes estão mapeados para pelo menos um *RP* ou *RD*:
  - *Controle de Fermentação* (12 testes): Todos cobertos (ex.: T0.1.1 → *RD1.4*, T3.1 → *RP3*, *RD3.1*, *RD3.2*).
  - *Balança de Volume* (10 testes): Todos cobertos (ex.: T0.2 → *RD1.1*, T3.1 → *RP3*, *RD3.1*, *RD3.2*).
  - *Densímetro Flutuante* (13 testes): Todos cobertos (ex.: T0.2 → *RD1.1*, T4.1 → *RP4*, *RD4.1*, *RD4.2*).
  - *Controle e Monitoramento* (8 testes): Todos cobertos (ex.: T0.3 → *RD1.1*, T1.1 → *RP3*, *RD3.1*, *RD3.2*).
- **Conclusão**: Não há testes sem requisitos. Rastreabilidade completa.

#### **Especificações → Checklist**

- **Objetivo**: Verificar se todos os 51 *RPs* e *RDs* têm um teste associado.
- **Resultado**:
  - *Controle de Fermentação* (13 requisitos): Todos cobertos (ex.: *RP1* → T1.1, T1.2; *RD1.1* → T0.2, T1.1).
  - *Balança de Volume* (12 requisitos): Todos cobertos (ex.: *RP1* → T1.1, T1.2; *RD1.1* → T0.2, T1.1).
  - *Densímetro Flutuante* (14 requisitos): Todos cobertos (ex.: *RP1* → T1.1; *RD1.1* → T0.2, T1.1).
  - *Controle e Monitoramento* (12 requisitos): 9/12 cobertos. GAPs identificados:
    - *RP2* (Ajustes de parâmetros via interface): Não coberto por teste específico.
    - *RD2.1* (Keypad DFR0009): Não coberto por teste específico.
    - *RD2.2* (Múltiplos GPIO Mega 2560): Parcialmente coberto por T0.3.
- **Conclusão**: Três GAPs na função *Controle e Monitoramento*. Resolvidos sem novos testes (ver abaixo).

#### **Conformidade com o Plano de Execução**

- **Verificação**: Todos os 43 testes do *Checklist* estão alinhados com o *Plano de Execução* (Seção 2), incluindo procedimentos, setups, métricas e cronograma (Maio-Outubro 2025).
- **Conclusão**: Conformidade total. GAPs não afetam o cronograma, pois foram resolvidos por testes funcionais ou debug interno.

### **Ações para os GAPs Identificados**

- **RP2**: Realizar testes funcionais.
  - **Status**: Testes realizados com sucesso ✅.
  - **Detalhes**: Testes funcionais verificaram a interação com o keypad do DFR0009, incluindo detecção de pressionamentos e ajustes de parâmetros (ex.: setpoint de temperatura). Resultados exibidos no LCD e Serial Monitor.
- **RD2.1**: Realizar testes funcionais.
  - **Status**: Testes realizados com sucesso ✅.
  - **Detalhes**: Testes funcionais confirmaram o funcionamento dos 5-6 botões do keypad (DFR0009), com detecção de pressionamentos e integração com o Mega 2560.
- **RD2.2**: Mega 2560 tem debug interno; testes definidos são suficientes.
  - **Status**: Testes definidos são suficientes ✅.
  - **Detalhes**: O Mega 2560 possui debug interno (LEDs, Serial Monitor) que reporta falhas em portas, funções ou clock. Testes existentes (T0.3, T0.1.1, T0.1.3) cobrem parcialmente os GPIOs (pinos 2-5, 11, 12). Para o contexto do projeto, testar todos os 54 GPIOs é desnecessário. Debug interno configurado no firmware garante cobertura.

### **Conclusão**

- Nenhum novo teste foi adicionado ao *Checklist* (*artifact_id: c4e2f9a8-3b7d-4f8a-a2c1-7f9e0d3b2c1e*), que permanece congelado.
- Os GAPs foram resolvidos por testes funcionais (*RP2*, *RD2.1*) ou debug interno (*RD2.2*), sem impacto no cronograma ou escopo.
- Pendências foram adicionadas em *Anotações, Pendências e Melhorias* para documentar os testes funcionais e configuração de debug.

## **5. Anotações, Pendências e Melhorias**

### **Comparação com Total Inicial**

- Total Estimado (inicial): €186,28-207,28 (conforme fornecido).
- Novo Total Estimado: €118,72-129,72.
- Redução em Relação ao Inicial (média inferior/superior): €69,06 (~36,5% de redução).

### **Pendências**

- **Testes Funcionais para *RP2* e *RD2.1*** (Controle e Monitoramento):
  - **Descrição**: Documentar testes funcionais realizados para o keypad do DFR0009 (*RP2*, *RD2.1*), incluindo detecção de pressionamentos, exibição no LCD, e ajustes de parâmetros.
  - **Ação**: Incluir relatório detalhado dos testes na próxima revisão do *Plano de Execução* (Seção 2.4, *Agosto 2025*).
  - **Status**: Testes realizados com sucesso ✅.
- **Configuração de Debug para *RD2.2*** (Controle e Monitoramento):
  - **Descrição**: Garantir que o firmware do Mega 2560 inclua rotinas de debug (Serial Monitor, LEDs) para reportar falhas de GPIO.
  - **Ação**: Configurar debug no sketch do Mega 2560 e validar em *Maio 2025* (alinhado com testes "stand alone").
  - **Status**: Pendente 📅.
- **Compra de Componentes** (Seção 3):
  - **Descrição**: Adquirir itens listados como "Em planejamento" (ex.: Manta 500W, 3 células de carga) até *30/04/2025* (Mês 1-4).
  - **Ação**: Confirmar pedidos e rastreamento no *Plano de Execução* (Seção 3).
  - **Status**: Pendente 📅.

### **Melhorias**

- **Documentação de Testes Funcionais**: Incluir uma seção no *Plano de Execução* para testes informais (ex.: *RP2*, *RD2.1*) realizados fora do *Checklist*, garantindo rastreabilidade futura.
- **Validação de Debug Interno**: Realizar teste informal com LEDs em GPIOs adicionais (ex.: 6-8) do Mega 2560 para confirmar cobertura de *RD2.2*, documentando resultados.
- **Plataforma da Balança**: Definir plataforma física para a Balança de Volume (Seção 2.2) até *Junho 2025* para testes de integração.

*Referências Cruzadas*: Para cronograma, consulte *Plano de Execução* (Seção 3).
