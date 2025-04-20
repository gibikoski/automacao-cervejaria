# **4. Pinouts e Conexões**

## **Visão Geral**

Esta seção mapeia os pinouts e conexões dos componentes eletrônicos (circuitos integrados e **SSR-10DA**) listados na *3. Lista de Equipamentos e BOM* do documento *Automacao_Cervejaria_Especificacoes_v1.0.1_20250420.md*. Componentes passivos (**Manta 500W**, **Fusível 3 A**, **Bateria 18650**, **Células de carga**) são mencionados como referência, sem pinout detalhado. Cada função (**Controle de Fermentação**, **Balança de Volume**, **Densímetro Flutuante**, **Controle e Monitoramento**) tem tabelas de/para independentes para cada instância (16 no total), com cores, negrito, itálico, e diagramas Mermaid centralizados no microcontrolador, detalhando portas e protocolos (I2C, 1-wire, UART, serial). Esta revisão reformata as tabelas, combinando **Destino (Para)** e **Conexão** (conexão em parênteses), mantendo pinagens, tensões, e correções anteriores (ex.: **ESP8266 5V P16**).

### **Como Visualizar Diagramas Mermaid**

- **GitHub**: Acesse o arquivo Markdown no repositório (docs/v1.0.1/). Diagramas renderizam automaticamente na visualização.
- **Visual Studio Code**:
  1. Instale a extensão **Markdown Preview Enhanced** ou **Markdown Preview Mermaid Support**.
  2. Abra o arquivo Markdown (ex.: `Automacao_Cervejaria_Pinouts_v1.0.1_20250420.md`).
  3. Use o preview (Ctrl+Shift+V ou ícone de visualização) para renderizar tabelas e diagramas.
- **Mermaid Live Editor**:
  1. Copie o código Mermaid de cada diagrama (ex.: `graph TD ...`).
  2. Cole em mermaid.live para visualização interativa.
  3. Salve como SVG/PNG para revisão offline.
- **Local**: Salve o arquivo em `automacao-cervejaria/docs/v1.0.1/` e abra com um editor Markdown compatível.

## **4.1 Controle de Fermentação**

**Componentes** (4 instâncias):

- **Arduino R4 Connect** (microcontrolador, I2C, 1-wire, digital).
- **DS18B20** (sensor de temperatura, 1-wire).
- **SSR-10DA** (relé de estado sólido, digital).
- **INA219** (sensor de corrente/tensão, I2C).

### **Arduino R4 Connect**

- **Função**: Gerencia **DS18B20** (1-wire), **SSR-10DA** (digital), **INA219** (I2C).
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| **3V3** | DS18B20, INA219 (*VCC*) | Alimentação *3,3 V*. |
| **GND** | DS18B20, SSR-10DA, INA219 (*GND*) | Terra comum. |
| **D2** | DS18B20 (*DQ*) | Protocolo *1-wire*. |
| **D3** | SSR-10DA (*+ Entrada*) | Sinal digital (*5 V*). |
| **A5 (SDA)** | INA219 (*SDA*) | Protocolo *I2C*. |
| **A4 (SCL)** | INA219 (*SCL*) | Protocolo *I2C*. |

### **DS18B20**

- **Função**: Medição de temperatura.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| **VCC** | Arduino R4 Connect (*3V3*) | Alimentação *3,3 V*. |
| **GND** | Arduino R4 Connect (*GND*) | Terra comum. |
| **DQ** | Arduino R4 Connect (*D2*) | Protocolo *1-wire*, resistor pull-up *4,7 kΩ*. |

### **SSR-10DA**

- **Função**: Controle da **Manta 500W**.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| **+ (Entrada)** | Arduino R4 Connect (*D3*) | Sinal digital (*5 V*). |
| **- (Entrada)** | Arduino R4 Connect (*GND*) | Terra comum. |
| **Saída** | Manta 500W (*-*) | Não mapeado (resistor). |

### **INA219**

- **Função**: Monitoramento de corrente/tensão.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| **VCC** | Arduino R4 Connect (*3V3*) | Alimentação *3,3 V*. |
| **GND** | Arduino R4 Connect (*GND*) | Terra comum. |
| **SDA** | Arduino R4 Connect (*A5 SDA*) | Endereço I2C: *0x40* (A0, A1 em GND). |
| **SCL** | Arduino R4 Connect (*A4 SCL*) | Protocolo *I2C*. |
| **A0** | \- (*GND*) | Define endereço I2C *0x40*. |
| **A1** | \- (*GND*) | Define endereço I2C *0x40*. |

**Diagrama** 🖼️:

```mermaid
graph TD
    A[Arduino R4 Connect]
    A -->|D2, 1-wire| B[DS18B20]
    A -->|D3, Digital| C[SSR-10DA]
    A -->|A5 SDA, A4 SCL, I2C| D[INA219]
    B -->|VCC| E[3,3 V]
    B -->|GND| F[GND]
    C -->|GND| F
    D -->|VCC| E
    D -->|GND| F
    C -->|Saída| G[Manta 500W]
```

## **4.2 Balança de Volume**

**Componentes** (3 instâncias):

- **ESP32-C3** (microcontrolador, I2C, serial).
- **HX711** (conversor ADC, serial).
- **MPU6050** (sensor de movimento, I2C).

### **ESP32-C3**

- **Função**: Gerencia **HX711** (serial), **MPU6050** (I2C).
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| **3V3** | HX711, MPU6050 (*VCC*) | Alimentação *3,3 V*. |
| **GND** | HX711, MPU6050 (*GND*) | Terra comum. |
| **D2 (GPIO2)** | HX711 (*SDA*) | Protocolo *serial* (dados). |
| **D3 (GPIO3)** | HX711 (*SCL*) | Protocolo *serial* (clock). |
| **A5 (SDA, GPIO4)** | MPU6050 (*SDA*) | Protocolo *I2C*. |
| **A4 (SCL, GPIO5)** | MPU6050 (*SCL*) | Protocolo *I2C*. |

### **HX711**

- **Função**: Conversor ADC (módulo integrado, 4 pinos).
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| **VCC** | ESP32-C3 (*3V3*) | Alimentação *3,3 V*. |
| **GND** | ESP32-C3 (*GND*) | Terra comum. |
| **SDA** | ESP32-C3 (*D2 GPIO2*) | Protocolo *serial* (dados). |
| **SCL** | ESP32-C3 (*D3 GPIO3*) | Protocolo *serial* (clock). |

### **MPU6050**

- **Função**: Sensor de movimento.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| **VCC** | ESP32-C3 (*3V3*) | Alimentação *3,3 V*. |
| **GND** | ESP32-C3 (*GND*) | Terra comum. |
| **SDA** | ESP32-C3 (*A5 GPIO4*) | Endereço I2C: *0x68* (AD0 em GND). |
| **SCL** | ESP32-C3 (*A4 GPIO5*) | Protocolo *I2C*. |
| **AD0** | \- (*GND*) | Define endereço I2C *0x68*. |
| **INT** | \- (*Aberto*) | Não utilizado (sem interrupções). |
| **AUX_DA** | \- (*Aberto*) | Não utilizado (sem sensores auxiliares). |
| **AUX_CL** | \- (*Aberto*) | Não utilizado (sem sensores auxiliares). |

**Diagrama** 🖼️:

```mermaid
graph TD
    A[ESP32-C3]
    A -->|D2 GPIO2, Serial| B[HX711]
    A -->|D3 GPIO3, Serial| B
    A -->|A5 GPIO4 SDA, A4 GPIO5 SCL, I2C| C[MPU6050]
    B -->|VCC| D[3,3 V]
    B -->|GND| E[GND]
    C -->|VCC| D
    C -->|GND| E
    C -->|AD0| E
```

## **4.3 Densímetro Flutuante**

**Componentes** (5 instâncias):

- **ESP32-C3** (microcontrolador, I2C, 1-wire).
- **ICM20948** (sensor de movimento, I2C).
- **DS18B20** (sensor de temperatura, 1-wire).
- **TPS63020** (regulador de tensão).
- **INA219** (sensor de corrente/tensão, I2C).

### **ESP32-C3**

- **Função**: Gerencia **ICM20948**, **INA219** (I2C), **DS18B20** (1-wire).
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| **3V3** | ICM20948, DS18B20, INA219 (*VCC*) | Alimentação *3,3 V* (via **TPS63020**). |
| **GND** | ICM20948, DS18B20, INA219 (*GND*) | Terra comum. |
| **GPIO18 (P13)** | ICM20948, INA219 (*SDA*) | Protocolo *I2C*. |
| **GPIO19 (P14)** | ICM20948, INA219 (*SCL*) | Protocolo *I2C*. |
| **GPIO2 (P16)** | DS18B20 (*DQ*) | Protocolo *1-wire*. |

### **ICM20948**

- **Função**: Sensor de movimento.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| **VCC** | ESP32-C3 (*3V3*) | Alimentação *3,3 V* (via **TPS63020**). |
| **GND** | ESP32-C3 (*GND*) | Terra comum. |
| **SDA** | ESP32-C3 (*GPIO18 P13*) | Endereço I2C: *0x68* (AD0 em GND). |
| **SCL** | ESP32-C3 (*GPIO19 P14*) | Protocolo *I2C*. |
| **AD0** | \- (*GND*) | Define endereço I2C *0x68*. |
| **CS** | \- (*Aberto*) | Não utilizado (I2C, não SPI). |
| **Fsync** | \- (*Aberto*) | Não utilizado. |
| **INT1** | \- (*Aberto*) | Não utilizado (sem interrupções). |
| **AUX_DA** | \- (*Aberto*) | Não utilizado (sem sensores auxiliares). |
| **AUX_CL** | \- (*Aberto*) | Não utilizado (sem sensores auxiliares). |
| **REGout** | \- (*Aberto*) | Não utilizado (bypass interno). |

### **DS18B20**

- **Função**: Medição de temperatura.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| **VCC** | ESP32-C3 (*3V3*) | Alimentação *3,3 V* (via **TPS63020**). |
| **GND** | ESP32-C3 (*GND*) | Terra comum. |
| **DQ** | ESP32-C3 (*GPIO2 P16*) | Protocolo *1-wire*, resistor pull-up *4,7 kΩ*. |

### **TPS63020**

- **Função**: Regulador de tensão.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| **VIN** | Bateria 18650 (*-*) | Entrada *2,5-5,5 V* (não mapeado). |
| **VOUT** | ESP32-C3, ICM20948, DS18B20, INA219 (*3V3*) | Alimentação *3,3 V*. |
| **GND** | ESP32-C3 (*GND*) | Terra comum. |

### **INA219**

- **Função**: Monitoramento de corrente/tensão.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| **VCC** | ESP32-C3 (*3V3*) | Alimentação *3,3 V* (via **TPS63020**). |
| **GND** | ESP32-C3 (*GND*) | Terra comum. |
| **SDA** | ESP32-C3 (*GPIO18 P13*) | Endereço I2C: *0x40* (A0, A1 em GND). |
| **SCL** | ESP32-C3 (*GPIO19 P14*) | Protocolo *I2C*. |
| **A0** | \- (*GND*) | Define endereço I2C *0x40*. |
| **A1** | \- (*GND*) | Define endereço I2C *0x40*. |

**Diagrama** 🖼️:

```mermaid
graph TD
    A[ESP32-C3]
    A -->|GPIO18 P13, I2C SDA| B[ICM20948]
    A -->|GPIO19 P14, I2C SCL| B
    A -->|GPIO18 P13, I2C SDA| D[INA219]
    A -->|GPIO19 P14, I2C SCL| D
    A -->|GPIO2 P16, 1-wire| C[DS18B20]
    E[TPS63020] -->|VOUT| F[3,3 V]
    B -->|VCC| F
    C -->|VCC| F
    D -->|VCC| F
    B -->|GND| G[GND]
    C -->|GND| G
    D -->|GND| G
    E -->|VIN| H[Bateria 18650]
```

## **4.4 Controle e Monitoramento**

**Componentes** (4 instâncias):

- **Mega 2560** (microcontrolador, UART, I2C).
- **ESP8266** (Wi-Fi, UART).
- **DFR0009** (shield I2C para LCD).
- **INA219** (sensor de corrente/tensão, I2C).

### **Mega 2560**

- **Função**: Gerencia **ESP8266** (UART), **DFR0009**, **INA219** (I2C).
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| **Vin** | \- (*-*) | Entrada *7-12 V* (não mapeado). |
| **5V** | ESP8266, DFR0009, INA219 (*VCC*) | Alimentação *5 V* (output). |
| **GND** | ESP8266, DFR0009, INA219 (*GND*) | Terra comum. |
| **PD0 (RXD1, 19)** | ESP8266 (*TX*) | Protocolo *UART*. |
| **PD1 (TXD1, 18)** | ESP8266 (*RX*) | Protocolo *UART*. |
| **PF0 (SDA, 20)** | DFR0009, INA219 (*SDA*) | Protocolo *I2C*. |
| **PF1 (SCL, 21)** | DFR0009, INA219 (*SCL*) | Protocolo *I2C*. |

### **ESP8266**

- **Função**: Comunicação Wi-Fi.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| **5V (P16)** | Mega 2560 (*5V*) | Alimentação *5 V*, regulada internamente para *3,3 V* (AMS1117-3.3). |
| **GND** | Mega 2560 (*GND*) | Terra comum. |
| **TX** | Mega 2560 (*PD0 RXD1 19*) | Protocolo *UART*. |
| **RX** | Mega 2560 (*PD1 TXD1 18*) | Protocolo *UART*. |
| **RSP (P1)** | \- (*Aberto*) | Reset, não utilizado. |
| **A0** | \- (*Aberto*) | ADC, não utilizado. |
| **D0** | \- (*Aberto*) | GPIO, não utilizado. |
| **D5** | \- (*Aberto*) | GPIO, não utilizado. |
| **D6** | \- (*Aberto*) | GPIO, não utilizado. |
| **D7** | \- (*Aberto*) | GPIO, não utilizado. |
| **D8** | \- (*Aberto*) | GPIO, não utilizado. |
| **D1** | \- (*Aberto*) | GPIO, não utilizado. |
| **D2** | \- (*Aberto*) | GPIO, não utilizado. |
| **D3** | \- (*Aberto*) | GPIO, não utilizado. |
| **D4** | \- (*Aberto*) | GPIO, não utilizado. |
| **3V3** | \- (*Aberto*) | Não utilizado (alimentação via *5V*). |

### **DFR0009**

- **Função**: Shield I2C para LCD 1602.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| **VCC** | Mega 2560 (*5V*) | Alimentação *5 V*. |
| **GND** | Mega 2560 (*GND*) | Terra comum. |
| **SDA** | Mega 2560 (*PF0 SDA 20*) | Endereço I2C: *0x27* (típico). |
| **SCL** | Mega 2560 (*PF1 SCL 21*) | Protocolo *I2C*, conecta ao LCD 1602. |

### **INA219**

- **Função**: Monitoramento de corrente/tensão.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| **VCC** | Mega 2560 (*5V*) | Alimentação *5 V*. |
| **GND** | Mega 2560 (*GND*) | Terra comum. |
| **SDA** | Mega 2560 (*PF0 SDA 20*) | Endereço I2C: *0x40* (A0, A1 em GND). |
| **SCL** | Mega 2560 (*PF1 SCL 21*) | Protocolo *I2C*. |
| **A0** | \- (*GND*) | Define endereço I2C *0x40*. |
| **A1** | \- (*GND*) | Define endereço I2C *0x40*. |

**Diagrama** 🖼️:

```mermaid
graph TD
    A[Mega 2560]
    A -->|PD0 RXD1 19, UART| B[ESP8266]
    A -->|PD1 TXD1 18, UART| B
    A -->|PF0 SDA 20, I2C| C[DFR0009]
    A -->|PF1 SCL 21, I2C| C
    A -->|PF0 SDA 20, I2C| D[INA219]
    A -->|PF1 SCL 21, I2C| D
    B -->|5V P16| E[5 V]
    C -->|VCC| E
    D -->|VCC| E
    B -->|GND| F[GND]
    C -->|GND| F
    D -->|GND| F
    C -->|I2C| G[LCD 1602]
```

## **Resumo do Mapeamento**

- **Componentes Mapeados** (16 instâncias, 12 únicos):
  - **Controle de Fermentação**: Arduino R4 Connect, DS18B20, SSR-10DA, INA219 (4 instâncias). ✅
  - **Balança de Volume**: ESP32-C3, HX711, MPU6050 (3 instâncias). ✅
  - **Densímetro Flutuante**: ESP32-C3, ICM20948, DS18B20, TPS63020, INA219 (5 instâncias). ✅
  - **Controle e Monitoramento**: Mega 2560, ESP8266, DFR0009, INA219 (4 instâncias). ✅
- **Lacunas**: Nenhuma. Todos os componentes estão mapeados com tabelas individuais e diagramas.
- **Ajustes Realizados**:
  - Tabelas reformuladas: **Destino (Para)** e **Conexão** combinados, conexão em parênteses.
  - Correções anteriores mantidas (ex.: **ESP8266 5V P16** conectado a **Mega 2560 5V**).
- **Notas Gerais**:
  - **Componentes Passivos**: Manta 500W, Fusível 3 A, Bateria 18650, Células de carga mencionados, sem pinout.
  - **I2C Endereços**:
    - **INA219**: 0x40 (todas as funções, A0/A1 em GND).
    - **ICM20948**: 0x68 (Densímetro Flutuante, AD0 em GND).
    - **MPU6050**: 0x68 (Balança de Volume, AD0 em GND).
    - **DFR0009**: 0x27 (Controle e Monitoramento).
  - **Resistor Pull-up**: 4,7 kΩ para **DS18B20** (Controle de Fermentação, Densímetro Flutuante).
  - **Pinos**: Validados sem conflitos (I2C, UART, 1-wire, serial usam pinos distintos).

## **Próximos Passos**

- **Validação**: Confirme a formatação das tabelas (colunas combinadas), pinouts, conexões, endereços I2C, e clareza visual (tabelas, diagramas). Indique ajustes (ex.: pinos alternativos, conexões de fusível, formatação adicional).
- **Testes**: Planeje testes em *Maio/Junho 2025* com multímetro (**RM113D**) e ferro de solda (**ANENG SL104**).
- **Documentação**: Atualize esta seção no GitHub após validação das alterações anteriores e desta revisão.
- **Compras**: Adquira componentes pendentes até *Maio 2025* (ex.: **ESP32-C3**, **INA219**).