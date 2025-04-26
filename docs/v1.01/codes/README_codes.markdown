# README - Códigos de Testes - Automação Cervejeira v1.0.1

## Visão Geral

A pasta `/docs/v1.01/codes/` contém os códigos para os 43 testes definidos no *Checklist de Testes - Automação Cervejeira v1.0.1* (`Automacao_Cervejaria_Checklist_Testes_v1.0.1_20250420.markdown`). Cada artefato é um arquivo `.ino` (Arduino C++) correspondente a um teste específico, com rastreabilidade para requisitos e controle de versão. Os testes cobrem as funções *Controle de Fermentação*, *Balança de Volume*, *Densímetro Flutuante*, e *Controle e Monitoramento*. Cada teste possui um arquivo Markdown associado com detalhes adicionais.

**Objetivo**: Fornecer sketches e documentação para validar os componentes e funcionalidades do projeto, conforme especificado no *Plano de Execução* e *Especificações*.

## Estrutura

- **Arquivos de Código**: Cada teste tem um arquivo `.ino` nomeado como `T<numero>_<nome do teste>.ino` (ex.: `T0_1_1_Verificar_Energizacao_Arduino_R4_Connect.ino`).
- **Arquivos Markdown**: Cada teste tem um arquivo `.markdown` com descrição, setup, e resultados esperados (ex.: `T0_1_1_Verificar_Energizacao_Arduino_R4_Connect.markdown`).
- **Metadados**: Cada código e Markdown inclui `artifact_id`, versão, data, requisito atendido, e controle de versão.
- **Índice**: O arquivo `INDEX_codes.markdown` lista todos os artefatos com metadados.
- **Localização**: `/docs/v1.01/codes/`.

## Lista de Testes

### Controle de Fermentação (12 Testes)
- T0.1.1: Verificar Energização do Arduino R4 Connect ([T0_1_1_Verificar_Energizacao_Arduino_R4_Connect.ino](./T0_1_1_Verificar_Energizacao_Arduino_R4_Connect.ino), [Markdown](./T0_1_1_Verificar_Energizacao_Arduino_R4_Connect.markdown))
- T0.1.2: Testar I/O Digital do Arduino R4 Connect ([T0_1_2_Testar_IO_Digital_Arduino_R4_Connect.ino](./T0_1_2_Testar_IO_Digital_Arduino_R4_Connect.ino), [Markdown](./T0_1_2_Testar_IO_Digital_Arduino_R4_Connect.markdown))
- T0.1.3: Testar I2C do Arduino R4 Connect ([T0_1_3_Testar_I2C_Arduino_R4_Connect.ino](./T0_1_3_Testar_I2C_Arduino_R4_Connect.ino), [Markdown](./T0_1_3_Testar_I2C_Arduino_R4_Connect.markdown))
- T0.1.4: Testar Wi-Fi do Arduino R4 Connect ([T0_1_4_Testar_WiFi_Arduino_R4_Connect.ino](./T0_1_4_Testar_WiFi_Arduino_R4_Connect.ino), [Markdown](./T0_1_4_Testar_WiFi_Arduino_R4_Connect.markdown))
- T0.2: Confirmar Leitura de Temperatura do DS18B20 ([T0_2_Confirmar_Leitura_Temperatura_DS18B20.ino](./T0_2_Confirmar_Leitura_Temperatura_DS18B20.ino), [Markdown](./T0_2_Confirmar_Leitura_Temperatura_DS18B20.markdown))
- T0.3: Verificar Controle de Saída do SSR-10DA ([T0_3_Verificar_Controle_Saida_SSR_10DA.ino](./T0_3_Verificar_Controle_Saida_SSR_10DA.ino), [Markdown](./T0_3_Verificar_Controle_Saida_SSR_10DA.markdown))
- T0.4: Verificar Leitura de Corrente/Tensão do INA219 ([T0_4_Verificar_Leitura_Corrente_Tensao_INA219.ino](./T0_4_Verificar_Leitura_Corrente_Tensao_INA219.ino), [Markdown](./T0_4_Verificar_Leitura_Corrente_Tensao_INA219.markdown))
- T1.1: Verificar Precisão do DS18B20 ([T1_1_Verificar_Precisao_DS18B20.ino](./T1_1_Verificar_Precisao_DS18B20.ino), [Markdown](./T1_1_Verificar_Precisao_DS18B20.markdown))
- T1.2: Confirmar Controle de Aquecimento via SSR-10DA ([T1_2_Confirmar_Controle_Aquecimento_SSR_10DA.ino](./T1_2_Confirmar_Controle_Aquecimento_SSR_10DA.ino), [Markdown](./T1_2_Confirmar_Controle_Aquecimento_SSR_10DA.markdown))
- T2.1: Verificar Fusível 3 A ([T2_1_Verificar_Fusivel_3A.ino](./T2_1_Verificar_Fusivel_3A.ino), [Markdown](./T2_1_Verificar_Fusivel_3A.markdown))
- T3.1: Testar Integração MQTT com Home Assistant ([T3_1_Testar_Integracao_MQTT_Home_Assistant.ino](./T3_1_Testar_Integracao_MQTT_Home_Assistant.ino), [Markdown](./T3_1_Testar_Integracao_MQTT_Home_Assistant.markdown))
- T4.1: Verificar Autonomia da Bateria 18650 ([T4_1_Verificar_Autonomia_Bateria_18650.ino](./T4_1_Verificar_Autonomia_Bateria_18650.ino), [Markdown](./T4_1_Verificar_Autonomia_Bateria_18650.markdown))

### Balança de Volume (10 Testes)
- T0.1.1: Verificar Energização do ESP32-C3 ([T0_1_1_Verificar_Energizacao_ESP32_C3_Balanca.ino](./T0_1_1_Verificar_Energizacao_ESP32_C3_Balanca.ino), [Markdown](./T0_1_1_Verificar_Energizacao_ESP32_C3_Balanca.markdown))
- T0.1.2: Testar I/O Digital do ESP32-C3 ([T0_1_2_Testar_IO_Digital_ESP32_C3_Balanca.ino](./T0_1_2_Testar_IO_Digital_ESP32_C3_Balanca.ino), [Markdown](./T0_1_2_Testar_IO_Digital_ESP32_C3_Balanca.markdown))
- T0.1.3: Testar I2C do ESP32-C3 ([T0_1_3_Testar_I2C_ESP32_C3_Balanca.ino](./T0_1_3_Testar_I2C_ESP32_C3_Balanca.ino), [Markdown](./T0_1_3_Testar_I2C_ESP32_C3_Balanca.markdown))
- T0.1.4: Testar Wi-Fi do ESP32-C3 ([T0_1_4_Testar_WiFi_ESP32_C3_Balanca.ino](./T0_1_4_Testar_WiFi_ESP32_C3_Balanca.ino), [Markdown](./T0_1_4_Testar_WiFi_ESP32_C3_Balanca.markdown))
- T0.2: Confirmar Leitura ADC do HX711 ([T0_2_Confirmar_Leitura_ADC_HX711.ino](./T0_2_Confirmar_Leitura_ADC_HX711.ino), [Markdown](./T0_2_Confirmar_Leitura_ADC_HX711.markdown))
- T0.3: Verificar Leitura Inercial do MPU6050 ([T0_3_Verificar_Leitura_Inercial_MPU6050.ino](./T0_3_Verificar_Leitura_Inercial_MPU6050.ino), [Markdown](./T0_3_Verificar_Leitura_Inercial_MPU6050.markdown))
- T1.1: Validar Precisão de Peso do HX711 ([T1_1_Validar_Precisao_Peso_HX711.ino](./T1_1_Validar_Precisao_Peso_HX711.ino), [Markdown](./T1_1_Validar_Precisao_Peso_HX711.markdown))
- T1.2: Validar Cálculo de Volume ([T1_2_Validar_Calculo_Volume.ino](./T1_2_Validar_Calculo_Volume.ino), [Markdown](./T1_2_Validar_Calculo_Volume.markdown))
- T2.1: Verificar Nivelamento com MPU6050 ([T2_1_Verificar_Nivelamento_MPU6050.ino](./T2_1_Verificar_Nivelamento_MPU6050.ino), [Markdown](./T2_1_Verificar_Nivelamento_MPU6050.markdown))
- T3.1: Confirmar Envio de Dados de Volume via MQTT ([T3_1_Confirmar_Envio_Dados_Volume_MQTT.ino](./T3_1_Confirmar_Envio_Dados_Volume_MQTT.ino), [Markdown](./T3_1_Confirmar_Envio_Dados_Volume_MQTT.markdown))

### Densímetro Flutuante (13 Testes)
- T0.1.1: Verificar Energização do ESP32-C3 ([T0_1_1_Verificar_Energizacao_ESP32_C3_Densimetro.ino](./T0_1_1_Verificar_Energizacao_ESP32_C3_Densimetro.ino), [Markdown](./T0_1_1_Verificar_Energizacao_ESP32_C3_Densimetro.markdown))
- T0.1.2: Testar I/O Digital do ESP32-C3 ([T0_1_2_Testar_IO_Digital_ESP32_C3_Densimetro.ino](./T0_1_2_Testar_IO_Digital_ESP32_C3_Densimetro.ino), [Markdown](./T0_1_2_Testar_IO_Digital_ESP32_C3_Densimetro.markdown))
- T0.1.3: Testar I2C do ESP32-C3 ([T0_1_3_Testar_I2C_ESP32_C3_Densimetro.ino](./T0_1_3_Testar_I2C_ESP32_C3_Densimetro.ino), [Markdown](./T0_1_3_Testar_I2C_ESP32_C3_Densimetro.markdown))
- T0.1.4: Testar Wi-Fi do ESP32-C3 ([T0_1_4_Testar_WiFi_ESP32_C3_Densimetro.ino](./T0_1_4_Testar_WiFi_ESP32_C3_Densimetro.ino), [Markdown](./T0_1_4_Testar_WiFi_ESP32_C3_Densimetro.markdown))
- T0.2: Verificar Leitura Inercial do ICM20948 ([T0_2_Verificar_Leitura_Inercial_ICM20948.ino](./T0_2_Verificar_Leitura_Inercial_ICM20948.ino), [Markdown](./T0_2_Verificar_Leitura_Inercial_ICM20948.markdown))
- T0.3: Confirmar Leitura de Temperatura do DS18B20 ([T0_3_Confirmar_Leitura_Temperatura_DS18B20.ino](./T0_3_Confirmar_Leitura_Temperatura_DS18B20.ino), [Markdown](./T0_3_Confirmar_Leitura_Temperatura_DS18B20.markdown))
- T0.4: Verificar Regulação de Tensão do TPS63020 ([T0_4_Verificar_Regulacao_Tensao_TPS63020.ino](./T0_4_Verificar_Regulacao_Tensao_TPS63020.ino), [Markdown](./T0_4_Verificar_Regulacao_Tensao_TPS63020.markdown))
- T0.5: Verificar Leitura de Corrente/Tensão do INA219 ([T0_5_Verificar_Leitura_Corrente_Tensao_INA219.ino](./T0_5_Verificar_Leitura_Corrente_Tensao_INA219.ino), [Markdown](./T0_5_Verificar_Leitura_Corrente_Tensao_INA219.markdown))
- T1.1: Validar Precisão do ICM20948 ([T1_1_Validar_Precisao_ICM20948.ino](./T1_1_Validar_Precisao_ICM20948.ino), [Markdown](./T1_1_Validar_Precisao_ICM20948.markdown))
- T2.1: Confirmar Temperatura com DS18B20 ([T2_1_Confirmar_Temperatura_DS18B20.ino](./T2_1_Confirmar_Temperatura_DS18B20.ino), [Markdown](./T2_1_Confirmar_Temperatura_DS18B20.markdown))
- T3.1: Verificar Autonomia da Bateria 18650 ([T3_1_Verificar_Autonomia_Bateria_18650.ino](./T3_1_Verificar_Autonomia_Bateria_18650.ino), [Markdown](./T3_1_Verificar_Autonomia_Bateria_18650.markdown))
- T4.1: Testar Integração MQTT com Home Assistant ([T4_1_Testar_Integracao_MQTT_Home_Assistant.ino](./T4_1_Testar_Integracao_MQTT_Home_Assistant.ino), [Markdown](./T4_1_Testar_Integracao_MQTT_Home_Assistant.markdown))
- T4.2: Testar Monitoramento com INA219 ([T4_2_Testar_Monitoramento_INA219.ino](./T4_2_Testar_Monitoramento_INA219.ino), [Markdown](./T4_2_Testar_Monitoramento_INA219.markdown))

### Controle e Monitoramento (8 Testes)
- T0.1.1: Verificar Energização do Mega 2560 ([T0_1_1_Verificar_Energizacao_Mega_2560.ino](./T0_1_1_Verificar_Energizacao_Mega_2560.ino), [Markdown](./T0_1_1_Verificar_Energizacao_Mega_2560.markdown))
- T0.1.2: Testar UART do Mega 2560 ([T0_1_2_Testar_UART_Mega_2560.ino](./T0_1_2_Testar_UART_Mega_2560.ino), [Markdown](./T0_1_2_Testar_UART_Mega_2560.markdown))
- T0.1.3: Testar I2C do Mega 2560 ([T0_1_3_Testar_I2C_Mega_2560.ino](./T0_1_3_Testar_I2C_Mega_2560.ino), [Markdown](./T0_1_3_Testar_I2C_Mega_2560.markdown))
- T0.2: Verificar Leitura de Corrente/Tensão do INA219 ([T0_2_Verificar_Leitura_Corrente_Tensao_INA219.ino](./T0_2_Verificar_Leitura_Corrente_Tensao_INA219.ino), [Markdown](./T0_2_Verificar_Leitura_Corrente_Tensao_INA219.markdown))
- T0.3: Verificar Funcionalidade do DFR0009 ([T0_3_Verificar_Funcionalidade_DFR0009.ino](./T0_3_Verificar_Funcionalidade_DFR0009.ino), [Markdown](./T0_3_Verificar_Funcionalidade_DFR0009.markdown))
- T1.1: Confirmar Integração MQTT com ESP8266 ([T1_1_Confirmar_Integracao_MQTT_ESP8266.ino](./T1_1_Confirmar_Integracao_MQTT_ESP8266.ino), [Markdown](./T1_1_Confirmar_Integracao_MQTT_ESP8266.markdown))
- T1.2: Testar Monitoramento com INA219 ([T1_2_Testar_Monitoramento_INA219.ino](./T1_2_Testar_Monitoramento_INA219.ino), [Markdown](./T1_2_Testar_Monitoramento_INA219.markdown))
- T1.3: Testar Exibição de Dados no DFR0009 ([T1_3_Testar_Exibicao_Dados_DFR0009.ino](./T1_3_Testar_Exibicao_Dados_DFR0009.ino), [Markdown](./T1_3_Testar_Exibicao_Dados_DFR0009.markdown))

## Instruções de Uso

1. **Executar um Teste**:
   - Abra o arquivo `.ino` correspondente no Arduino IDE.
   - Siga as instruções de setup no código e no arquivo Markdown associado.
   - Carregue o sketch no microcontrolador especificado.

2. **Consultar Documentação**:
   - Leia o arquivo Markdown de cada teste para detalhes sobre setup, requisitos, e resultados esperados.
   - Verifique o `INDEX_codes.markdown` para metadados e status.

3. **Atualizar Testes**:
   - Modifique os arquivos `.ino` ou `.markdown` conforme necessário.
   - Atualize o `INDEX_codes.markdown` com nova iteração e status.
   - Mantenha o mesmo `artifact_id` para artefatos existentes.

## Notas

- Todos os artefatos estão em `v1.0.1`, alinhados com o *Checklist de Testes*.
- Status inicial: Pendente (atualizar conforme execução dos testes).
- Mantenha codificação UTF-8 e quebras de linha Unix (\n).