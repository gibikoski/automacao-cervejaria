# Checklist de Testes - Automação Cervejeira v1.0.1

**Versão**: v1.0.1\
**Data**: 2025-04-20\
**Localização**: `docs/v1.0.1/Automacao_Cervejaria_Checklist_Testes_v1.0.1_20250420.markdown`

## Instruções para Uso

1. **Setup**: Configure o hardware conforme a coluna **Setup** (ex.: pinagem, alimentação).
2. **Detalhes**: Siga as instruções específicas (ex.: conexões, resistores).
3. **Status**: Atualize manualmente a coluna **Status** (✅ Concluído, ✈️ Em Andamento, 🔧 Em Revisão, 📅 Agendado, ⏳ Aguardando).
4. **Progresso**: Calcule manualmente o progresso por função e geral:
   - Por função: (Soma dos pesos de testes ✈️, 🔧, ✅) ÷ Peso Total da Função × 100.
   - Geral: (Soma dos pesos de testes ✈️, 🔧, ✅) ÷ 120 × 100.
5. **Manutenção**: Adicione testes novos ao Markdown, mantendo a estrutura.

## Resumo Geral

- **Total de Testes**: 43
- **Peso Total**: 120
- **Peso Pronto**: 65 (✈️, 🔧, ✅)
- **Progresso**: 54,2%
- **% do Total (Pronto)**: 54,2%

---

## Controle de Fermentação

**Peso Total**: 37\
**Peso Pronto**: 21 (8 testes ✈️)\
**Progresso**: 56,8%\
**% do Total (Pronto)**: 17,5%

| Teste | Objetivo | Setup | Detalhes | Status | Peso | % do Total |
| --- | --- | --- | --- | --- | --- | --- |
| T0.1.1 | Verificar energização do Arduino R4 Connect | Fonte 5V USB, LED onboard | Conectar USB-C de fonte 5V para USB-C de Arduino R4 Connect. Ligar e verificar LED onboard. | ✈️ | 1 | 0,8 |
| T0.1.2 | Testar I/O digital do Arduino R4 Connect | LED externo, resistor 220 Ω | Conectar LED: Anodo para D4 de Arduino R4 Connect, Cátodo para GND de Arduino R4 Connect via resistor 220 Ω. | ✈️ | 3 | 2,5 |
| T0.1.3 | Testar I2C do Arduino R4 Connect | INA219, pull-ups 4,7 kΩ | Conectar INA219: SDA de INA219 para A5 de Arduino R4 Connect, SCL de INA219 para A4 de Arduino R4 Connect, VCC de INA219 para 3V3 de Arduino R4 Connect, GND de INA219 para GND de Arduino R4 Connect, pull-ups 4,7 kΩ entre SDA/SCL e 3V3. | ✈️ | 3 | 2,5 |
| T0.1.4 | Testar Wi-Fi do Arduino R4 Connect | Roteador Wi-Fi, sketch de teste | Carregar sketch Wi-Fi. Conectar a rede Wi-Fi via SSID e senha. Verificar conexão estável. | ✈️ | 4 | 3,3 |
| T0.2 | Confirmar leitura de temperatura do DS18B20 | DS18B20, resistor 4,7 kΩ | Conectar DS18B20: DQ de DS18B20 para D2 de Arduino R4 Connect, VCC de DS18B20 para 3V3 de Arduino R4 Connect, GND de DS18B20 para GND de Arduino R4 Connect, resistor 4,7 kΩ entre DQ e VCC. | ✈️ | 1 | 0,8 |
| T0.3 | Verificar controle de saída do SSR-10DA | SSR-10DA, carga resistiva (ex.: lâmpada 40W) | Conectar SSR-10DA: Controle+ de SSR-10DA para D3 de Arduino R4 Connect, Controle- de SSR-10DA para GND de Arduino R4 Connect, carga em série com SSR-10DA. | ✈️ | 3 | 2,5 |
| T0.4 | Verificar leitura de corrente/tensão do INA219 | INA219, carga resistiva, resistor 10 Ω | Conectar INA219: SDA de INA219 para A5 de Arduino R4 Connect, SCL de INA219 para A4 de Arduino R4 Connect, VCC de INA219 para 3V3 de Arduino R4 Connect, GND de INA219 para GND de Arduino R4 Connect, resistor 10 Ω entre VIN+ e VIN- de INA219. | ✈️ | 2 | 1,7 |
| T1.1 | Verificar precisão do DS18B20 (±0,5°C) | DS18B20, termômetro de referência | Comparar leitura do DS18B20 (via D2) com termômetro calibrado em água (0-50°C). Erro ≤ ±0,5°C. | ✈️ | 3 | 2,5 |
| T1.2 | Confirmar controle de aquecimento via SSR-10DA | SSR-10DA, resistor de aquecimento | Conectar SSR-10DA como em T0.3. Ligar/desligar resistor via D3. Verificar aquecimento controlado. | 📅 | 4 | 3,3 |
| T2.1 | Verificar fusível 3 A (não destrutivo) | Fusível 3 A, multímetro | Conectar fusível em série com carga. Medir continuidade com multímetro. Verificar funcionamento sem queima. | 📅 | 1 | 0,8 |
| T3.1 | Testar integração MQTT com Home Assistant | Arduino R4 Connect, Home Assistant, broker MQTT | Configurar sketch MQTT. Publicar temperatura (DS18B20) e estado (SSR-10DA) no broker. Verificar no Home Assistant. | 📅 | 5 | 4,2 |
| T4.1 | Verificar autonomia da bateria 18650 | Bateria 18650, circuito de proteção | Conectar bateria 18650 ao circuito. Medir autonomia com carga típica (ex.: Arduino + sensores) por 24h. | 📅 | 4 | 3,3 |

---

## Balança de Volume

**Peso Total**: 26\
**Peso Pronto**: 15 (7 testes ✈️)\
**Progresso**: 57,7%\
**% do Total (Pronto)**: 12,5%

| Teste | Objetivo | Setup | Detalhes | Status | Peso | % do Total |
| --- | --- | --- | --- | --- | --- | --- |
| T0.1.1 | Verificar energização do ESP32-C3 | Fonte 3V3, LED onboard | Conectar fonte 3V3 a 3V3 de ESP32-C3, GND a GND de ESP32-C3. Verificar LED onboard. | ✈️ | 1 | 0,8 |
| T0.1.2 | Testar I/O digital do ESP32-C3 | LED externo, resistor 220 Ω | Conectar LED: Anodo para GPIO6 de ESP32-C3, Cátodo para GND de ESP32-C3 via resistor 220 Ω. | ✈️ | 3 | 2,5 |
| T0.1.3 | Testar I2C do ESP32-C3 | MPU6050, pull-ups 4,7 kΩ | Conectar MPU6050: SDA de MPU6050 para GPIO8 de ESP32-C3, SCL de MPU6050 para GPIO9 de ESP32-C3, VCC de MPU6050 para 3V3 de ESP32-C3, GND de MPU6050 para GND de ESP32-C3, pull-ups 4,7 kΩ entre SDA/SCL e 3V3. | ✈️ | 3 | 2,5 |
| T0.1.4 | Testar Wi-Fi do ESP32-C3 | Roteador Wi-Fi, sketch de teste | Carregar sketch Wi-Fi. Conectar a rede Wi-Fi via SSID e senha. Verificar conexão estável. | ✈️ | 4 | 3,3 |
| T0.2 | Confirmar leitura ADC do HX711 | HX711, célula de carga | Conectar HX711: DT de HX711 para GPIO5 de ESP32-C3, SCK de HX711 para GPIO4 de ESP32-C3, VCC de HX711 para 3V3 de ESP32-C3, GND de HX711 para GND de ESP32-C3. | ✈️ | 2 | 1,7 |
| T0.3 | Verificar leitura inercial do MPU6050 | MPU6050 | Conectar MPU6050 como em T0.1.3. Ler dados de aceleração e giroscópio via I2C. Verificar valores plausíveis. | ✈️ | 2 | 1,7 |
| T1.1 | Validar precisão de peso do HX711 (±0,1-1 g) | HX711, pesos padrão | Conectar HX711 como em T0.2. Medir pesos conhecidos (ex.: 100 g, 500 g). Erro ≤ ±0,1-1 g. | ✈️ | 3 | 2,5 |
| T1.2 | Validar cálculo de volume | HX711, recipiente com líquido | Conectar HX711 como em T0.2. Calcular volume com densidade conhecida. Comparar com medição manual. | 📅 | 4 | 3,3 |
| T2.1 | Verificar nivelamento com MPU6050 (±0,1 g) | MPU6050, superfície de referência | Conectar MPU6050 como em T0.1.3. Verificar inclinação com MPU6050. Erro ≤ ±0,1 g. | 📅 | 3 | 2,5 |
| T3.1 | Confirmar envio de dados de volume via MQTT | ESP32-C3, Home Assistant, broker MQTT | Configurar sketch MQTT. Publicar peso/volume (HX711) no broker. Verificar no Home Assistant. | 📅 | 5 | 4,2 |

---

## Densímetro Flutuante

**Peso Total**: 36\
**Peso Pronto**: 18 (8 testes ✈️)\
**Progresso**: 50,0%\
**% do Total (Pronto)**: 15,0%

| Teste | Objetivo | Setup | Detalhes | Status | Peso | % do Total |
| --- | --- | --- | --- | --- | --- | --- |
| T0.1.1 | Verificar energização do ESP32-C3 | Fonte 3V3, LED onboard | Conectar fonte 3V3 a 3V3 de ESP32-C3, GND a GND de ESP32-C3. Verificar LED onboard. | ✈️ | 1 | 0,8 |
| T0.1.2 | Testar I/O digital do ESP32-C3 | LED externo, resistor 220 Ω | Conectar LED: Anodo para GPIO6 de ESP32-C3, Cátodo para GND de ESP32-C3 via resistor 220 Ω. | ✈️ | 3 | 2,5 |
| T0.1.3 | Testar I2C do ESP32-C3 | ICM20948, pull-ups 4,7 kΩ | Conectar ICM20948: SDA de ICM20948 para GPIO8 de ESP32-C3, SCL de ICM20948 para GPIO9 de ESP32-C3, VCC de ICM20948 para 3V3 de ESP32-C3, GND de ICM20948 para GND de ESP32-C3, pull-ups 4,7 kΩ entre SDA/SCL e 3V3. | ✈️ | 3 | 2,5 |
| T0.1.4 | Testar Wi-Fi do ESP32-C3 | Roteador Wi-Fi, sketch de teste | Carregar sketch Wi-Fi. Conectar a rede Wi-Fi via SSID e senha. Verificar conexão estável. | ✈️ | 4 | 3,3 |
| T0.2 | Verificar leitura inercial do ICM20948 | ICM20948 | Conectar ICM20948 como em T0.1.3. Ler dados de aceleração e giroscópio via I2C. Verificar valores plausíveis. | ✈️ | 2 | 1,7 |
| T0.3 | Confirmar leitura de temperatura do DS18B20 | DS18B20, resistor 4,7 kΩ | Conectar DS18B20: DQ de DS18B20 para GPIO2 de ESP32-C3, VCC de DS18B20 para 3V3 de ESP32-C3, GND de DS18B20 para GND de ESP32-C3, resistor 4,7 kΩ entre DQ e VCC. | ✈️ | 1 | 0,8 |
| T0.4 | Verificar regulação de tensão do TPS63020 | TPS63020, bateria 18650 | Conectar TPS63020: VIN de TPS63020 para positivo de bateria 18650, GND de TPS63020 para negativo de bateria 18650, VOUT de TPS63020 para 3V3 de ESP32-C3. Medir VOUT = 3,3V. | ✈️ | 2 | 1,7 |
| T0.5 | Verificar leitura de corrente/tensão do INA219 | INA219, carga resistiva, resistor 10 Ω | Conectar INA219: SDA de INA219 para GPIO8 de ESP32-C3, SCL de INA219 para GPIO9 de ESP32-C3, VCC de INA219 para 3V3 de ESP32-C3, GND de INA219 para GND de ESP32-C3, resistor 10 Ω entre VIN+ e VIN- de INA219. | ✈️ | 2 | 1,7 |
| T1.1 | Validar precisão do ICM20948 (±0,005 g/cm³) | ICM20948, líquido de densidade conhecida | Conectar ICM20948 como em T0.1.3. Calcular densidade com dados inerciais. Erro ≤ ±0,005 g/cm³. | 📅 | 5 | 4,2 |
| T2.1 | Confirmar temperatura com DS18B20 (±0,5°C) | DS18B20, termômetro de referência | Conectar DS18B20 como em T0.3. Comparar leitura com termômetro calibrado em líquido (0-50°C). Erro ≤ ±0,5°C. | 📅 | 3 | 2,5 |
| T3.1 | Verificar autonomia da bateria 18650 | Bateria 18650, TPS63020 | Conectar bateria e TPS63020 como em T0.4. Medir autonomia com carga típica (ex.: ESP32-C3 + sensores) por 24h. | 📅 | 4 | 3,3 |
| T4.1 | Testar integração MQTT com Home Assistant | ESP32-C3, Home Assistant, broker MQTT | Configurar sketch MQTT. Publicar densidade (ICM20948) e temperatura (DS18B20) no broker. Verificar no Home Assistant. | 📅 | 5 | 4,2 |
| T4.2 | Testar monitoramento com INA219 | INA219 | Conectar INA219 como em T0.5. Monitorar corrente/tensão em operação. Verificar valores plausíveis. | 📅 | 3 | 2,5 |

---

## Controle e Monitoramento

**Peso Total**: 19\
**Peso Pronto**: 11 (5 testes ✈️)\
**Progresso**: 57,9%\
**% do Total (Pronto)**: 9,2%

| Teste | Objetivo | Setup | Detalhes | Status | Peso | % do Total |
| --- | --- | --- | --- | --- | --- | --- |
| T0.1.1 | Verificar energização do Mega 2560 | Fonte 12V, LED onboard | Conectar fonte 12V a VIN de Mega 2560, GND a GND de Mega 2560. Verificar LED onboard. | ✈️ | 1 | 0,8 |
| T0.1.2 | Testar UART do Mega 2560 | ESP8266, cabo USB | Conectar ESP8266: TX de ESP8266 para RX (0) de Mega 2560, RX de ESP8266 para TX (1) de Mega 2560, VCC de ESP8266 para 3V3 de Mega 2560, GND de ESP8266 para GND de Mega 2560. Testar comunicação serial. | ✈️ | 3 | 2,5 |
| T0.1.3 | Testar I2C do Mega 2560 | INA219, pull-ups 4,7 kΩ | Conectar INA219: SDA de INA219 para SDA (20) de Mega 2560, SCL de INA219 para SCL (21) de Mega 2560, VCC de INA219 para 5V de Mega 2560, GND de INA219 para GND de Mega 2560, pull-ups 4,7 kΩ entre SDA/SCL e 5V. | ✈️ | 3 | 2,5 |
| T0.2 | Verificar leitura de corrente/tensão do INA219 | INA219, carga resistiva, resistor 10 Ω | Conectar INA219 como em T0.1.3. Resistor 10 Ω entre VIN+ e VIN- de INA219. Verificar leitura via I2C. | ✈️ | 2 | 1,7 |
| T0.3 | Verificar funcionalidade do DFR0009 | DFR0009 (LCD 16x2) | Conectar DFR0009: RS de DFR0009 para 12 de Mega 2560, E de DFR0009 para 11 de Mega 2560, D4-D7 de DFR0009 para 5-2 de Mega 2560, VCC de DFR0009 para 5V de Mega 2560, GND de DFR0009 para GND de Mega 2560. Exibir texto de teste. | ✈️ | 2 | 1,7 |
| T1.1 | Confirmar integração MQTT via ESP8266 | ESP8266, Home Assistant, broker MQTT | Conectar ESP8266 como em T0.1.2. Configurar sketch MQTT. Publicar dados do Mega 2560 no broker. Verificar no Home Assistant. | 📅 | 5 | 4,2 |
| T1.2 | Testar monitoramento com INA219 | INA219 | Conectar INA219 como em T0.1.3. Monitorar corrente/tensão em operação. Verificar valores plausíveis. | 📅 | 3 | 2,5 |
| T1.3 | Testar exibição de dados no DFR0009 | DFR0009, INA219 | Conectar DFR0009 como em T0.3, INA219 como em T0.1.3. Exibir corrente/tensão do INA219 no LCD. | 📅 | 3 | 2,5 |
