# **4. Pinouts e Conexões**

## **Visão Geral**

Mapeia pinouts e conexões de componentes eletrônicos, com tabelas de/para e diagramas Mermaid detalhando portas e protocolos.

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
| <span style="color:red">3V3</span> | DS18B20 (<span style="color:red">VCC</span>), INA219 (<span style="color:red">VCC</span>) | Alimentação *3,3 V*. |
| <span style="color:black">GND</span> | DS18B20 (<span style="color:black">GND</span>), SSR-10DA (<span style="color:black">GND</span>), INA219 (<span style="color:black">GND</span>) | Terra comum. |
| <span style="color:blue">D2</span> | DS18B20 (<span style="color:yellow">DQ</span>) | Protocolo *1-wire*. |
| <span style="color:blue">D3</span> | SSR-10DA (<span style="color:blue">+ Entrada</span>) | Sinal digital (*5 V*). |
| <span style="color:yellow">A5 (SDA)</span> | INA219 (<span style="color:yellow">SDA</span>) | Protocolo *I2C*. |
| <span style="color:white;background-color:gray">A4 (SCL)</span> | INA219 (<span style="color:white;background-color:gray">SCL</span>) | Protocolo *I2C*. |

### **DS18B20**

- **Função**: Medição de temperatura.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| <span style="color:red">VCC</span> | Arduino R4 Connect (<span style="color:red">3V3</span>) | Alimentação *3,3 V*. |
| <span style="color:black">GND</span> | Arduino R4 Connect (<span style="color:black">GND</span>) | Terra comum. |
| <span style="color:yellow">DQ</span> | Arduino R4 Connect (<span style="color:blue">D2</span>) | Protocolo *1-wire*, resistor pull-up *4,7 kΩ*. |

### **SSR-10DA**

- **Função**: Controle da **Manta 500W**.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| <span style="color:blue">+ (Entrada)</span> | Arduino R4 Connect (<span style="color:blue">D3</span>) | Sinal digital (*5 V*). |
| <span style="color:black">- (Entrada)</span> | Arduino R4 Connect (<span style="color:black">GND</span>) | Terra comum. |
| <span style="color:blue">Saída</span> | Manta 500W (<span style="color:black">-</span>) | Não mapeado (resistor). |

### **INA219**

- **Função**: Monitoramento de corrente/tensão.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| <span style="color:red">VCC</span> | Arduino R4 Connect (<span style="color:red">3V3</span>) | Alimentação *3,3 V*. |
| <span style="color:black">GND</span> | Arduino R4 Connect (<span style="color:black">GND</span>) | Terra comum. |
| <span style="color:yellow">SDA</span> | Arduino R4 Connect (<span style="color:yellow">A5 (SDA)</span>) | Endereço I2C: *0x40* (A0, A1 em GND). |
| <span style="color:white;background-color:gray">SCL</span> | Arduino R4 Connect (<span style="color:white;background-color:gray">A4 (SCL)</span>) | Protocolo *I2C*. |
| <span style="color:black">A0</span> | Arduino R4 Connect (<span style="color:black">GND</span>) | Define endereço I2C *0x40*, Terra comum. |
| <span style="color:black">A1</span> | Arduino R4 Connect (<span style="color:black">GND</span>) | Define endereço I2C *0x40*, Terra comum. |

**Diagrama** 🖼️:

```mermaid
graph TD
    A[Arduino R4 Connect]
    B[DS18B20]
    C[SSR-10DA]
    D[INA219]
    E[3,3 V]
    F[GND]
    G[Manta 500W]
    E -->|🔴 VCC-VCC-3,3V| B
    E -->|🔴 VCC-VCC-3,3V| D
    B -->|⚫ GND-GND-GND| F
    C -->|⚫ GND-GND-GND| F
    D -->|⚫ GND-GND-GND| F
    A -->|🟡 DQ-D2-1-wire| B
    A -->|🔵 Entrada-D3-Digital| C
    A ---|🟡 SDA-A5-I2C| D
    A ---|⚪ SCL-A4-I2C| D
    C -->|🔵 Saída---Digital| G
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
| <span style="color:red">3V3</span> | HX711 (<span style="color:red">VCC</span>), MPU6050 (<span style="color:red">VCC</span>) | Alimentação *3,3 V*. |
| <span style="color:black">GND</span> | HX711 (<span style="color:black">GND</span>), MPU6050 (<span style="color:black">GND</span>) | Terra comum. |
| <span style="color:blue">D2 (GPIO2)</span> | HX711 (<span style="color:yellow">SDA</span>) | Protocolo *serial* (dados). |
| <span style="color:blue">D3 (GPIO3)</span> | HX711 (<span style="color:white;background-color:gray">SCL</span>) | Protocolo *serial* (clock). |
| <span style="color:yellow">A5 (SDA, GPIO4)</span> | MPU6050 (<span style="color:yellow">SDA</span>) | Protocolo *I2C*. |
| <span style="color:white;background-color:gray">A4 (SCL, GPIO5)</span> | MPU6050 (<span style="color:white;background-color:gray">SCL</span>) | Protocolo *I2C*. |

### **HX711**

- **Função**: Conversor ADC (módulo integrado, 4 pinos).
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| <span style="color:red">VCC</span> | ESP32-C3 (<span style="color:red">3V3</span>) | Alimentação *3,3 V*. |
| <span style="color:black">GND</span> | ESP32-C3 (<span style="color:black">GND</span>) | Terra comum. |
| <span style="color:yellow">SDA</span> | ESP32-C3 (<span style="color:blue">D2 (GPIO2)</span>) | Protocolo *serial* (dados). |
| <span style="color:white;background-color:gray">SCL</span> | ESP32-C3 (<span style="color:blue">D3 (GPIO3)</span>) | Protocolo *serial* (clock). |

### **MPU6050**

- **Função**: Sensor de movimento.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| <span style="color:red">VCC</span> | ESP32-C3 (<span style="color:red">3V3</span>) | Alimentação *3,3 V*. |
| <span style="color:black">GND</span> | ESP32-C3 (<span style="color:black">GND</span>) | Terra comum. |
| <span style="color:yellow">SDA</span> | ESP32-C3 (<span style="color:yellow">A5 (SDA, GPIO4)</span>) | Endereço I2C: *0x68* (AD0 em GND). |
| <span style="color:white;background-color:gray">SCL</span> | ESP32-C3 (<span style="color:white;background-color:gray">A4 (SCL, GPIO5)</span>) | Protocolo *I2C*. |
| <span style="color:black">AD0</span> | ESP32-C3 (<span style="color:black">GND</span>) | Define endereço I2C *0x68*, Terra comum. |
| <span style="color:black">INT</span> | ESP32-C3 (<span style="color:black">GND</span>) | Terra comum (não utilizado, evita ruído). |

**Diagrama** 🖼️:

```mermaid
graph TD
    A[ESP32-C3]
    B[HX711]
    C[MPU6050]
    D[3,3 V]
    E[GND]
    D -->|🔴 VCC-VCC-3,3V| B
    D -->|🔴 VCC-VCC-3,3V| C
    B -->|⚫ GND-GND-GND| E
    C -->|⚫ GND-GND-GND| E
    C -->|⚫ AD0-GND-GND| E
    C -->|⚫ INT-GND-GND| E
    A -->|🔵 SCL-GPIO3-Serial| B
    B -->|🟡 SDA-GPIO2-Serial| A
    A ---|🟡 SDA-GPIO4-I2C| C
    A ---|⚪ SCL-GPIO5-I2C| C
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
| <span style="color:red">3V3</span> | ICM20948 (<span style="color:red">VCC</span>), DS18B20 (<span style="color:red">VCC</span>), INA219 (<span style="color:red">VCC</span>) | Alimentação *3,3 V* (via **TPS63020**). |
| <span style="color:black">GND</span> | ICM20948 (<span style="color:black">GND</span>), DS18B20 (<span style="color:black">GND</span>), INA219 (<span style="color:black">GND</span>) | Terra comum. |
| <span style="color:yellow">GPIO18 (P13)</span> | ICM20948 (<span style="color:yellow">SDA</span>), INA219 (<span style="color:yellow">SDA</span>) | Protocolo *I2C*. |
| <span style="color:white;background-color:gray">GPIO19 (P14)</span> | ICM20948 (<span style="color:white;background-color:gray">SCL</span>), INA219 (<span style="color:white;background-color:gray">SCL</span>) | Protocolo *I2C*. |
| <span style="color:yellow">GPIO2 (P16)</span> | DS18B20 (<span style="color:yellow">DQ</span>) | Protocolo *1-wire*. |

### **ICM20948**

- **Função**: Sensor de movimento.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| <span style="color:red">VCC</span> | ESP32-C3 (<span style="color:red">3V3</span>) | Alimentação *3,3 V* (via **TPS63020**). |
| <span style="color:black">GND</span> | ESP32-C3 (<span style="color:black">GND</span>) | Terra comum. |
| <span style="color:yellow">SDA</span> | ESP32-C3 (<span style="color:yellow">GPIO18 (P13)</span>) | Endereço I2C: *0x68* (AD0 em GND). |
| <span style="color:white;background-color:gray">SCL</span> | ESP32-C3 (<span style="color:white;background-color:gray">GPIO19 (P14)</span>) | Protocolo *I2C*. |
| <span style="color:black">AD0</span> | ESP32-C3 (<span style="color:black">GND</span>) | Define endereço I2C *0x68*, Terra comum. |
| <span style="color:black">INT1</span> | ESP32-C3 (<span style="color:black">GND</span>) | Terra comum (não utilizado, evita ruído). |

### **DS18B20**

- **Função**: Medição de temperatura.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| <span style="color:red">VCC</span> | ESP32-C3 (<span style="color:red">3V3</span>) | Alimentação *3,3 V* (via **TPS63020**). |
| <span style="color:black">GND</span> | ESP32-C3 (<span style="color:black">GND</span>) | Terra comum. |
| <span style="color:yellow">DQ</span> | ESP32-C3 (<span style="color:yellow">GPIO2 (P16)</span>) | Protocolo *1-wire*, resistor pull-up *4,7 kΩ*. |

### **TPS63020**

- **Função**: Regulador de tensão.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| <span style="color:red">VIN</span> | Bateria 18650 (<span style="color:black">-</span>) | Entrada *2,5-5,5 V* (não mapeado). |
| <span style="color:red">VOUT</span> | ESP32-C3 (<span style="color:red">3V3</span>), ICM20948 (<span style="color:red">VCC</span>), DS18B20 (<span style="color:red">VCC</span>), INA219 (<span style="color:red">VCC</span>) | Alimentação *3,3 V*. |
| <span style="color:black">GND</span> | ESP32-C3 (<span style="color:black">GND</span>) | Terra comum. |

### **INA219**

- **Função**: Monitoramento de corrente/tensão.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| <span style="color:red">VCC</span> | ESP32-C3 (<span style="color:red">3V3</span>) | Alimentação *3,3 V* (via **TPS63020**). |
| <span style="color:black">GND</span> | ESP32-C3 (<span style="color:black">GND</span>) | Terra comum. |
| <span style="color:yellow">SDA</span> | ESP32-C3 (<span style="color:yellow">GPIO18 (P13)</span>) | Endereço I2C: *0x40* (A0, A1 em GND). |
| <span style="color:white;background-color:gray">SCL</span> | ESP32-C3 (<span style="color:white;background-color:gray">GPIO19 (P14)</span>) | Protocolo *I2C*. |
| <span style="color:black">A0</span> | ESP32-C3 (<span style="color:black">GND</span>) | Define endereço I2C *0x40*, Terra comum. |
| <span style="color:black">A1</span> | ESP32-C3 (<span style="color:black">GND</span>) | Define endereço I2C *0x40*, Terra comum. |

**Diagrama** 🖼️:

```mermaid
graph TD
    A[ESP32-C3]
    B[ICM20948]
    C[DS18B20]
    D[INA219]
    E[TPS63020]
    F[3,3 V]
    G[GND]
    H[Bateria 18650]
    H -->|🔴 VIN---3,3V| E
    E -->|🔴 VOUT-3V3-3,3V| F
    F -->|🔴 VCC-VCC-3,3V| B
    F -->|🔴 VCC-VCC-3,3V| C
    F -->|🔴 VCC-VCC-3,3V| D
    B -->|⚫ GND-GND-GND| G
    C -->|⚫ GND-GND-GND| G
    D -->|⚫ GND-GND-GND| G
    B -->|⚫ AD0-GND-GND| G
    B -->|⚫ INT1-GND-GND| G
    A ---|🟡 SDA-P13-I2C| B
    A ---|⚪ SCL-P14-I2C| B
    A ---|🟡 SDA-P13-I2C| D
    A ---|⚪ SCL-P14-I2C| D
    A -->|🟡 DQ-GPIO2-1-wire| C
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
| <span style="color:red">Vin</span> | <span style="color:black">-</span> (<span style="color:black">-</span>) | Entrada *7-12 V* (não mapeado). |
| <span style="color:red">5V</span> | ESP8266 (<span style="color:red">5V (P16)</span>), DFR0009 (<span style="color:red">VCC</span>), INA219 (<span style="color:red">VCC</span>) | Alimentação *5 V* (output). |
| <span style="color:black">GND</span> | ESP8266 (<span style="color:black">GND</span>), DFR0009 (<span style="color:black">GND</span>), INA219 (<span style="color:black">GND</span>) | Terra comum. |
| <span style="color:blue">PD0 (RXD1, 19)</span> | ESP8266 (<span style="color:blue">TX</span>) | Protocolo *UART*. |
| <span style="color:blue">PD1 (TXD1, 18)</span> | ESP8266 (<span style="color:blue">RX</span>) | Protocolo *UART*. |
| <span style="color:yellow">PF0 (SDA, 20)</span> | DFR0009 (<span style="color:yellow">SDA</span>), INA219 (<span style="color:yellow">SDA</span>) | Protocolo *I2C*. |
| <span style="color:white;background-color:gray">PF1 (SCL, 21)</span> | DFR0009 (<span style="color:white;background-color:gray">SCL</span>), INA219 (<span style="color:white;background-color:gray">SCL</span>) | Protocolo *I2C*. |

### **ESP8266**

- **Função**: Comunicação Wi-Fi.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| <span style="color:red">5V (P16)</span> | Mega 2560 (<span style="color:red">5V</span>) | Alimentação *5 V*, regulada internamente para *3,3 V* (AMS1117-3.3). |
| <span style="color:black">GND</span> | Mega 2560 (<span style="color:black">GND</span>) | Terra comum. |
| <span style="color:blue">TX</span> | Mega 2560 (<span style="color:blue">PD0 (RXD1, 19)</span>) | Protocolo *UART*. |
| <span style="color:blue">RX</span> | Mega 2560 (<span style="color:blue">PD1 (TXD1, 18)</span>) | Protocolo *UART*. |

### **DFR0009**

- **Função**: Shield I2C para LCD 1602.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| <span style="color:red">VCC</span> | Mega 2560 (<span style="color:red">5V</span>) | Alimentação *5 V*. |
| <span style="color:black">GND</span> | Mega 2560 (<span style="color:black">GND</span>) | Terra comum. |
| <span style="color:yellow">SDA</span> | Mega 2560 (<span style="color:yellow">PF0 (SDA, 20)</span>) | Endereço I2C: *0x27* (típico). |
| <span style="color:white;background-color:gray">SCL</span> | Mega 2560 (<span style="color:white;background-color:gray">PF1 (SCL, 21)</span>) | Protocolo *I2C*, conecta ao LCD 1602. |

### **INA219**

- **Função**: Monitoramento de corrente/tensão.
- **Conexões** 📋:

| **Pino (De)** | **Destino (Para)** | **Notas** |
| --- | --- | --- |
| <span style="color:red">VCC</span> | Mega 2560 (<span style="color:red">5V</span>) | Alimentação *5 V*. |
| <span style="color:black">GND</span> | Mega 2560 (<span style="color:black">GND</span>) | Terra comum. |
| <span style="color:yellow">SDA</span> | Mega 2560 (<span style="color:yellow">PF0 (SDA, 20)</span>) | Endereço I2C: *0x40* (A0, A1 em GND). |
| <span style="color:white;background-color:gray">SCL</span> | Mega 2560 (<span style="color:white;background-color:gray">PF1 (SCL, 21)</span>) | Protocolo *I2C*. |
| <span style="color:black">A0</span> | Mega 2560 (<span style="color:black">GND</span>) | Define endereço I2C *0x40*, Terra comum. |
| <span style="color:black">A1</span> | Mega 2560 (<span style="color:black">GND</span>) | Define endereço I2C *0x40*, Terra comum. |

**Diagrama** 🖼️:

```mermaid
graph TD
    A[Mega 2560]
    B[ESP8266]
    C[DFR0009]
    D[INA219]
    E[5 V]
    F[GND]
    G[LCD 1602]
    E -->|🔴 VCC-P16-5V| B
    E -->|🔴 VCC-VCC-5V| C
    E -->|🔴 VCC-VCC-5V| D
    B -->|⚫ GND-GND-GND| F
    C -->|⚫ GND-GND-GND| F
    D -->|⚫ GND-GND-GND| F
    A -->|🔵 RXD1-19-UART| B
    A -->|🔵 TXD1-18-UART| B
    A ---|🟡 SDA-20-I2C| C
    A ---|⚪ SCL-21-I2C| C
    A ---|🟡 SDA-20-I2C| D
    A ---|⚪ SCL-21-I2C| D
    C -->|🟡 I2C---I2C| G
```

## **Resumo do Mapeamento**

- **Componentes Mapeados** (16 instâncias, 12 únicos):
  - **Controle de Fermentação**: Arduino R4 Connect, DS18B20, SSR-10DA, INA219 (4 instâncias). ✅
  - **Balança de Volume**: ESP32-C3, HX711, MPU6050 (3 instâncias). ✅
  - **Densímetro Flutuante**: ESP32-C3, ICM20948, DS18B20, TPS63020, INA219 (5 instâncias). ✅
  - **Controle e Monitoramento**: Mega 2560, ESP8266, DFR0009, INA219 (4 instâncias). ✅
- **Lacunas**: Nenhuma. Todos os componentes mapeados com tabelas e diagramas.
- **Ajustes Realizados**:
  - Visão Geral mantida (concisa, sem componentes passivos, funções, ou protocolos).
  - Diagramas mantidos:
    - Rótulos com emojis (🔴, ⚫, ⚪, 🟡, 🔵) no formato `<emoji> <sinal>-<pino (De)>-<protocolo>` (ex.: `🔴 VCC-P16-5V`).
    - Sem legendas.
  - Tabelas atualizadas:
    - Pinos nas colunas **Pino (De)** e **Destino (Para)** coloridos com `<span style="color:...">` (ex.: `<span style="color:red">3V3</span>`, `<span style="color:yellow">SDA</span>`).
    - Esquema de cores: Vermelho (Alimentação), Preto (Terra), Branco com fundo cinza (Clock I2C), Amarelo (Dados I2C/Serial/1-wire), Azul (Digital/UART/Serial).
    - **MPU6050**: **AUX_DA**, **AUX_CL** removidos; **INT** ao GND.
    - **ESP8266**: Confirmado, sem pinos flutuantes ou "Aberto".
    - Outros componentes sem pinos flutuantes.
  - Arquivo preparado para UTF-8 e quebras de linha Unix (\\n).
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

- **Validação**: Confirme a Visão Geral, diagramas (rótulos com emojis, ex.: `🔴 VCC-P16-5V`), tabelas (pinos coloridos, ex.: `<span style="color:red">3V3</span>`), pinouts, e endereços I2C. Indique ajustes (ex.: cores, emojis, rótulos, pinos).
- **Testes**: Planeje testes em *Maio/Junho 2025* com multímetro (**RM113D**) e ferro de solda (**ANENG SL104**).
- **Documentação**: Atualize esta seção no GitHub após validação.
- **Compras**: Adquira componentes pendentes até *Maio 2025* (ex.: **ESP32-C3**, **INA219**).