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
| **A0** | Arduino R4 Connect (*GND*) | Define endereço I2C *0x40*, Terra comum. |
| **A1** | Arduino R4 Connect (*GND*) | Define endereço I2C *0x40*, Terra comum. |

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
| **AD0** | ESP32-C3 (*GND*) | Define endereço I2C *0x68*, Terra comum. |
| **INT** | ESP32-C3 (*GND*) | Terra comum (não utilizado, evita ruído). |

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
| **AD0** | ESP32-C3 (*GND*) | Define endereço I2C *0x68*, Terra comum. |
| **INT1** | ESP32-C3 (*GND*) | Terra comum (não utilizado, evita ruído). |

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
| **A0** | ESP32-C3 (*GND*) | Define endereço I2C *0x40*, Terra comum. |
| **A1** | ESP32-C3 (*GND*) | Define endereço I2C *0x40*, Terra comum. |

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
| **A0** | Mega 2560 (*GND*) | Define endereço I2C *0x40*, Terra comum. |
| **A1** | Mega 2560 (*GND*) | Define endereço I2C *0x40*, Terra comum. |

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
  - Diagramas atualizados:
    - Rótulos com emojis (🔴, ⚫, ⚪, 🟡, 🔵) no formato `<emoji> <sinal>-<pino (De)>-<protocolo>` (ex.: `🔴 VCC-P16-5V`).
    - Legendas removidas (ex.: `**Legenda do Diagrama** 📋: ...`).
  - Tabelas mantidas:
    - **MPU6050**: **AUX_DA**, **AUX_CL** removidos; **INT** ao GND.
    - **ESP8266**: Confirmado, sem pinos flutuantes ou "Aberto".
    - Outros componentes sem pinos flutuantes.
  - Arquivo preparado para UTF-8 e quebras de linha Unix (\n).
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

- **Validação**: Confirme a Visão Geral, diagramas (rótulos com emojis, ex.: `🔴 VCC-P16-5V`), tabelas (ESP8266 sem pinos flutuantes), pinouts, e endereços I2C. Indique ajustes (ex.: emojis, rótulos, pinos).
- **Testes**: Planeje testes em *Maio/Junho 2025* com multímetro (**RM113D**) e ferro de solda (**ANENG SL104**).
- **Documentação**: Atualize esta seção no GitHub após validação.
- **Compras**: Adquira componentes pendentes até *Maio 2025* (ex.: **ESP32-C3**, **INA219**).