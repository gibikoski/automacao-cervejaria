# Automação Cervejaria - Plano de Execução

## Controle de Versão

| Versão | Data | Descrição |
| --- | --- | --- |
| v1.0.0 | 19/04/2025 | Versão inicial do documento. |
| v1.0.1 | 20/04/2025 | Implementação das melhorias conforme abaixo: Melhorias Implementadas (v1.0.1). |

## Índice

| Seção | Título |
| --- | --- |
| 4 | Plano de Testes |
| 5 | Cronograma Geral |
| 6 | Melhorias Implementadas (v1.0.1) |

## Metadados

| Atributo | Valor |
| --- | --- |
| artifact_id | 7c2ae759-709d-471e-a03f-b990f5d3332f |
| Versão | v1.0.1 |
| Data | 20/04/2025 |
| Autor | Grok (xAI) |

## 4. Plano de Testes

**Nota**: Incluídos testes "stand alone" para ICs críticos, realizados em Mês 1 (Maio 2025) para validação inicial. Testes existentes mantidos, com sequência lógica (componentes → integração → Wi-Fi). Testes longos substituídos por alternativas curtas. Setups econômicos fornecidos.

**Resumo dos Testes**:

| Função | Nº de Testes | Status | Período |
| --- | --- | --- | --- |
| Controle de Fermentação | 9 | Pendente | Maio-Junho 2025 |
| Balança de Volume | 7 | Pendente | Maio-Junho 2025 |
| Densímetro Flutuante | 10 | Pendente | Maio-Julho 2025 |
| Controle e Monitoramento | 4 | Pendente | Maio-Agosto 2025 |

*Referências Cruzadas*: Para especificações, consulte *Especificações e Configurações*, Seção 2. Para rastreabilidade, consulte *Rastreabilidade*, Seção 7.

### 4.1 Função Controle de Fermentação (aquecimento)

**Testes de ICs Críticos (Stand Alone)**:

| Código | Objetivo | Procedimento | Setup Recomendado | Métricas | Tempo | Período |
| --- | --- | --- | --- | --- | --- | --- |
| T0.1 | Verificar funcionalidade básica e pinagem (GPIO, I2C, Wi-Fi) do Arduino R4 Connect. | Carregar sketch de teste (pisca LED em D3, lê I2C em A4/A5, conecta Wi-Fi), verificar via Serial Monitor. | Arduino R4 Connect, protoboard (€3,00), LED com resistor 220 Ω (€1,00), multímetro RM113D (€15,00), Wi-Fi roteador (€30,00). Alternativa: multímetro básico (€5,00), Wi-Fi doméstico. | LED pisca a 1 Hz, I2C responde, Wi-Fi conecta em &lt;10 s. | 1 hora | Maio 2025 |
| T0.2 | Confirmar leitura de temperatura e pinagem (1-Wire) do DS18B20. | Conectar DS18B20 (DQ a D2, pull-up 4,7 kΩ), carregar sketch OneWire, ler temperatura ambiente, verificar via Serial Monitor. | DS18B20, Arduino R4 Connect, resistor 4,7 kΩ (€0,50), protoboard (€3,00). Alternativa: resistor 5 kΩ, verificar manualmente. | Temperatura ±2°C do ambiente, leitura estável em 10 amostras. | 30 minutos | Maio 2025 |
| T0.3 | Verificar controle de saída e pinagem do SSR-10DA. | Conectar controle (+ a D3, - a GND), ligar LED com resistor 220 Ω como carga, ativar/desativar via sketch, medir tensão com multímetro. | SSR-10DA, Arduino R4 Connect, LED com resistor (€1,00), multímetro RM113D (€15,00). Alternativa: multímetro básico (€5,00), verificar visualmente. | Saída alterna 0-3,3 V, resposta &lt;1 s. | 30 minutos | Maio 2025 |
| T0.4 | Verificar leitura de corrente/tensão e pinagem (I2C) do INA219. | Conectar INA219 (SDA a A4, SCL a A5), medir resistor 10 Ω como carga, carregar sketch Adafruit_INA219, verificar via Serial Monitor. | INA219, Arduino R4 Connect, resistor 10 Ω (€1,00), multímetro RM113D (€15,00). Alternativa: multímetro básico (€5,00), verificar manualmente. | Corrente ±1 mA, tensão ±10 mV, I2C responde. | 1 hora | Maio 2025 |

**Testes Existentes**:

| Código | Objetivo | Procedimento | Setup Recomendado | Métricas | Tempo | Período |
| --- | --- | --- | --- | --- | --- | --- |
| T1.1 | Verificar precisão do DS18B20 (±0,5°C). | Colocar DS18B20 em banho-maria (20°C e 30°C), medir 100 amostras, comparar com termômetro de referência. | DS18B20, R4 Connect, banho-maria (€50,00), termômetro calibrado (€20,00). Alternativa: gelo e água quente, termômetro doméstico (€5,00). | Erro máximo ±0,5°C em 95% das medições. | 2 horas | Maio 2025 |
| T1.2 | Confirmar controle de aquecimento via SSR-10DA com manta 500W. | Conectar lâmpada 40W (proxy), ativar/desativar SSR, medir tempo de resposta. | SSR-10DA, R4 Connect, lâmpada 40W (€5,00), multímetro RM113D (€15,00). Alternativa: LED com resistor (€1,00), verificar visualmente. | Resposta &lt;1 s, sem falhas em 50 ciclos. | 1 hora | Junho 2025 |
| T2.1 | Verificar fusível 3 A (não destrutivo). | Medir continuidade e resistência do fusível com multímetro, verificar especificação (3 A). | Fusível 3 A, multímetro RM113D (€15,00). Alternativa: multímetro básico (€5,00). | Continuidade confirmada, resistência &lt;1 Ω. | 30 minutos | Junho 2025 |
| T3.1 | Testar integração MQTT com Home Assistant. | Publicar temperatura via MQTT, verificar recepção no Home Assistant. | R4 Connect, Wi-Fi roteador (€30,00), Home Assistant (Raspberry Pi, €50,00). Alternativa: Wi-Fi doméstico, Home Assistant em PC (grátis). | Latência &lt;2 s, 100% de pacotes recebidos em 1 hora. | 3 horas | Junho 2025 |
| T4.1 | Verificar autonomia da bateria 18650 (teste curto). | Conectar R4 Connect, DS18B20, INA219 a carga simulada (resistor 10 Ω), medir corrente/tensão por 2 horas, estimar autonomia. | Bateria 18650, INA219, multímetro RM113D (€15,00), resistor 10 Ω (€1,00). Alternativa: multímetro básico (€5,00), medir manualmente. | Autonomia estimada ≥24 horas, corrente ±1 mA. | 2 horas | Junho 2025 |

*Referências Cruzadas*: Para requisitos, consulte *Especificações e Configurações*, Seção 2.1. Para pendências, consulte *Anotações, Pendências e Melhorias*, Seção 8.

### 4.2 Função Balança de Volume (litros fermentador/keg)

**Testes de ICs Críticos (Stand Alone)**:

| Código | Objetivo | Procedimento | Setup Recomendado | Métricas | Tempo | Período |
| --- | --- | --- | --- | --- | --- | --- |
| T0.1 | Verificar funcionalidade básica e pinagem (GPIO, I2C, Wi-Fi) do ESP32-C3. | Carregar sketch de teste (pisca LED em GPIO4, lê I2C em GPIO18/19, conecta Wi-Fi), verificar via Serial Monitor. | ESP32-C3, protoboard (€3,00), LED com resistor 220 Ω (€1,00), multímetro RM113D (€15,00), Wi-Fi roteador (€30,00). Alternativa: multímetro básico (€5,00), Wi-Fi doméstico. | LED pisca a 1 Hz, I2C responde, Wi-Fi conecta em &lt;10 s. | 1 hora | Maio 2025 |
| T0.2 | Confirmar leitura ADC e pinagem do HX711. | Conectar HX711 (DT a GPIO4, SCK a GPIO5), carregar sketch HX711, simular entrada com resistor 1 kΩ, verificar leitura via Serial Monitor. | HX711, ESP32-C3, resistor 1 kΩ (€0,50), protoboard (€3,00). Alternativa: potenciômetro (€1,00), verificar manualmente. | Leitura estável, variação &lt;0,1% em 10 amostras. | 30 minutos | Maio 2025 |
| T0.3 | Verificar leitura inercial e pinagem (I2C) do MPU6050. | Conectar MPU6050 (SDA a GPIO18, SCL a GPIO19), carregar sketch Adafruit_MPU6050, ler aceleração/giroscópio, verificar via Serial Monitor. | MPU6050, ESP32-C3, protoboard (€3,00). Alternativa: superfície plana, verificar manualmente. | Aceleração ±0,1 g, giroscópio ±1°/s em 10 amostras. | 1 hora | Maio 2025 |

**Testes Existentes**:

| Código | Objetivo | Procedimento | Setup Recomendado | Métricas | Tempo | Período |
| --- | --- | --- | --- | --- | --- | --- |
| T1.1 | Validar precisão de peso do HX711 (±0,1-1 g). | Colocar pesos conhecidos (1 kg, 5 kg, 20 kg), medir 100 amostras. | HX711, células de carga, ESP32-C3, pesos calibrados (€30,00). Alternativa: objetos domésticos (garrafas d’água), balança de cozinha (€10,00). | Erro máximo ±0,1-1 g em 95% das medições. | 2 horas | Maio 2025 |
| T1.2 | Validar cálculo de volume (Volume = Peso / Densidade). | Usar peso medido (ex.: 5 kg) e densidade conhecida (ex.: 1,005 g/cm³), calcular volume, comparar com volume real. | HX711, ESP32-C3, líquidos calibrados (€10,00), densímetro manual (€15,00). Alternativa: densidade teórica (água, 1 g/cm³), recipiente medido (€5,00). | Erro máximo ±0,1-1 litro em 95% dos cálculos. | 2 horas | Junho 2025 |
| T2.1 | Verificar nivelamento com MPU6050 (±0,1 g). | Inclinar plataforma em 5°, medir correção do MPU6050. | MPU6050, ESP32-C3, plataforma inclinável (€20,00). Alternativa: superfície manual (livro inclinado), verificar via software. | Correção &lt;2 s, precisão ±0,1 g. | 1 hora | Junho 2025 |
| T3.1 | Confirmar envio de dados de volume via MQTT. | Publicar volume via MQTT, verificar no Home Assistant. | ESP32-C3, Wi-Fi roteador (€30,00), Home Assistant (Raspberry Pi, €50,00). Alternativa: Wi-Fi doméstico, Home Assistant em PC (grátis). | Latência &lt;2 s, 100% de pacotes recebidos. | 3 horas | Junho 2025 |

*Referências Cruzadas*: Para requisitos, consulte *Especificações e Configurações*, Seção 2.2. Para pendências, consulte *Anotações, Pendências e Melhorias*, Seção 8.

### 4.3 Função Densímetro Flutuante Remoto

**Testes de ICs Críticos (Stand Alone)**:

| Código | Objetivo | Procedimento | Setup Recomendado | Métricas | Tempo | Período |
| --- | --- | --- | --- | --- | --- | --- |
| T0.1 | Verificar funcionalidade básica e pinagem (GPIO, I2C, Wi-Fi) do ESP32-C3. | Carregar sketch de teste (pisca LED em GPIO2, lê I2C em GPIO18/19, conecta Wi-Fi), verificar via Serial Monitor. | ESP32-C3, protoboard (€3,00), LED com resistor 220 Ω (€1,00), multímetro RM113D (€15,00), Wi-Fi roteador (€30,00). Alternativa: multímetro básico (€5,00), Wi-Fi doméstico. | LED pisca a 1 Hz, I2C responde, Wi-Fi conecta em &lt;10 s. | 1 hora | Maio 2025 |
| T0.2 | Verificar leitura inercial e pinagem (I2C) do ICM20948. | Conectar ICM20948 (SDA a GPIO18, SCL a GPIO19), carregar sketch ICM20948, ler aceleração/magnetômetro, verificar via Serial Monitor. | ICM20948, ESP32-C3, protoboard (€3,00). Alternativa: superfície plana, verificar manualmente. | Aceleração ±0,1 g, magnetômetro ±1 µT em 10 amostras. | 1 hora | Maio 2025 |
| T0.3 | Confirmar leitura de temperatura e pinagem (1-Wire) do DS18B20. | Conectar DS18B20 (DQ a GPIO2, pull-up 4,7 kΩ), carregar sketch OneWire, ler temperatura ambiente, verificar via Serial Monitor. | DS18B20, ESP32-C3, resistor 4,7 kΩ (€0,50), protoboard (€3,00). Alternativa: resistor 5 kΩ, verificar manualmente. | Temperatura ±2°C do ambiente, leitura estável em 10 amostras. | 30 minutos | Maio 2025 |
| T0.4 | Verificar regulação de tensão e pinagem do TPS63020. | Conectar TPS63020 (VIN a bateria 3,7 V, VOUT a 3,3 V), medir VOUT com multímetro, conectar carga (resistor 10 Ω). | TPS63020, bateria 18650, resistor 10 Ω (€1,00), multímetro RM113D (€15,00). Alternativa: multímetro básico (€5,00), sem carga. | VOUT = 3,3 V ±5%, estável com carga. | 30 minutos | Maio 2025 |
| T0.5 | Verificar leitura de corrente/tensão e pinagem (I2C) do INA219. | Conectar INA219 (SDA a GPIO18, SCL a GPIO19), medir resistor 10 Ω como carga, carregar sketch Adafruit_INA219, verificar via Serial Monitor. | INA219, ESP32-C3, resistor 10 Ω (€1,00), multímetro RM113D (€15,00). Alternativa: multímetro básico (€5,00), verificar manualmente. | Corrente ±1 mA, tensão ±10 mV, I2C responde. | 1 hora | Maio 2025 |

**Testes Existentes**:

| Código | Objetivo | Procedimento | Setup Recomendado | Métricas | Tempo | Período |
| --- | --- | --- | --- | --- | --- | --- |
| T1.1 | Validar precisão do ICM20948 (±0,005 g/cm³). | Testar em líquidos de densidade conhecida (água, etanol), medir 100 amostras. | ICM20948, ESP32-C3, líquidos calibrados (€10,00), densímetro manual (€15,00). Alternativa: água e soluções caseiras (açúcar), densímetro básico (€5,00). | Erro máximo ±0,005 g/cm³ em 95% das medições. | 2 horas | Julho 2025 |
| T2.1 | Confirmar temperatura com DS18B20 (±0,5°C). | Medir temperatura em líquido (20°C), comparar com referência. | DS18B20, ESP32-C3, termômetro calibrado (€20,00). Alternativa: termômetro doméstico (€5,00), água a 20°C. | Erro máximo ±0,5°C em 95% das medições. | 1 hora | Julho 2025 |
| T3.1 | Verificar autonomia da bateria 18650 (teste curto). | Conectar densímetro a carga simulada (resistor 10 Ω), medir corrente/tensão por 2 horas, estimar autonomia. | Bateria 18650, TPS63020, INA219, multímetro RM113D (€15,00). Alternativa: multímetro básico (€5,00), medir manualmente. | Autonomia estimada ≥3 dias, tensão estável (±5%). | 2 horas | Julho 2025 |
| T4.1 | Testar integração MQTT com Home Assistant. | Publicar densidade e temperatura via MQTT, verificar recepção. | ESP32-C3, Wi-Fi roteador (€30,00), Home Assistant (Raspberry Pi, €50,00). Alternativa: Wi-Fi doméstico, Home Assistant em PC (grátis). | Latência &lt;2 s, 100% de pacotes recebidos em 1 hora. | 3 horas | Julho 2025 |
| T4.2 | Testar monitoramento com INA219. | Medir corrente/tensão da bateria, comparar com multímetro. | INA219, ESP32-C3, multímetro RM113D (€15,00). Alternativa: multímetro básico (€5,00). | Precisão ±1 mA, ±10 mV. | 1 hora | Julho 2025 |

*Referências Cruzadas*: Para requisitos, consulte *Especificações e Configurações*, Seção 2.3. Para pendências, consulte *Anotações, Pendências e Melhorias*, Seção 8.

### 4.4 Função Controle, Monitoramento e Alterações de Parâmetros

**Testes de ICs Críticos (Stand Alone)**:

| Código | Objetivo | Procedimento | Setup Recomendado | Métricas | Tempo | Período |
| --- | --- | --- | --- | --- | --- | --- |
| T0.1 | Verificar funcionalidade básica e pinagem (GPIO, I2C, Wi-Fi) do ESP8266. | Carregar sketch de teste (pisca LED em GPIO4, lê I2C em GPIO4/5, conecta Wi-Fi), verificar via Serial Monitor. | ESP8266, protoboard (€3,00), LED com resistor 220 Ω (€1,00), multímetro RM113D (€15,00), Wi-Fi roteador (€30,00). Alternativa: multímetro básico (€5,00), Wi-Fi doméstico. | LED pisca a 1 Hz, I2C responde, Wi-Fi conecta em &lt;10 s. | 1 hora | Maio 2025 |
| T0.2 | Verificar leitura de corrente/tensão e pinagem (I2C) do INA219. | Conectar INA219 (SDA a GPIO4, SCL a GPIO5), medir resistor 10 Ω como carga, carregar sketch Adafruit_INA219, verificar via Serial Monitor. | INA219, ESP8266, resistor 10 Ω (€1,00), multímetro RM113D (€15,00). Alternativa: multímetro básico (€5,00), verificar manualmente. | Corrente ±1 mA, tensão ±10 mV, I2C responde. | 1 hora | Maio 2025 |

**Testes Existentes**:

| Código | Objetivo | Procedimento | Setup Recomendado | Métricas | Tempo | Período |
| --- | --- | --- | --- | --- | --- | --- |
| T1.1 | Confirmar integração MQTT. | Publicar dados via MQTT, verificar no Home Assistant. | ESP8266, Wi-Fi roteador (€30,00), Home Assistant (Raspberry Pi, €50,00). Alternativa: Wi-Fi doméstico, Home Assistant em PC (grátis). | Latência &lt;2 s, 100% de pacotes recebidos em 1 hora. | 3 horas | Agosto 2025 |
| T1.2 | Testar monitoramento com INA219. | Medir corrente/tensão, comparar com multímetro. | INA219, ESP8266, multímetro RM113D (€15,00). Alternativa: multímetro básico (€5,00). | Precisão ±1 mA, ±10 mV. | 1 hora | Agosto 2025 |

*Referências Cruzadas*: Para requisitos, consulte *Especificações e Configurações*, Seção 2.4. Para pendências, consulte *Anotações, Pendências e Melhorias*, Seção 8.

## 5. Cronograma Geral

| Mês | Período | Atividades | Entregáveis | Dependências |
| --- | --- | --- | --- | --- |
| Mês 1 | Maio 2025 | Testes unitários de ICs (Arduino R4 Connect, ESP32-C3, DS18B20, etc.), compras de ferramentas (ferro de solda, multímetro, protetor silicone). | ICs validados, ferramentas adquiridas. | Compra de ferramentas (*Anotações, Pendências e Melhorias*, Seção 8). |
| Mês 2 | Junho 2025 | Integração da Função Controle de Fermentação e Balança, testes de integração. | Controle de temperatura, balança funcional. | Manta 500W, bateria 18650 (*Anotações, Pendências e Melhorias*, Seção 8). |
| Mês 3 | Julho 2025 | Desenvolvimento da Função Densímetro, testes unitários e MQTT. | Densímetro funcional. | ICM20948, TPS63020 (*Anotações, Pendências e Melhorias*, Seção 8). |
| Mês 4 | Agosto 2025 | Integração da Função Controle e Monitoramento, testes MQTT. | Interface central funcional. | ESP8266 (*Anotações, Pendências e Melhorias*, Seção 8). |
| Mês 5 | Setembro 2025 | Otimização de circuitos, validação de segurança. | Sistema estável. | \- |
| Mês 6 | Outubro 2025 | Validação final, documentação. | Sistema integrado, documentação. | \- |

*Referências Cruzadas*: Para componentes, consulte *Especificações e Configurações*, Seção 3. Para pendências, consulte *Anotações, Pendências e Melhorias*, Seção 8.

## Melhorias Implementadas (v1.0.1)

- Substituídas listas por tabelas para detalhes de testes (Seção 4) e resumo de testes por função (Seção 4).
- Adicionadas referências cruzadas ligando testes a requisitos (*Especificações e Configurações*, Seção 2) e pendências (*Anotações, Pendências e Melhorias*, Seção 8).
- Incluída tabela de resumo inicial na Seção 4 (número de testes por função, status, período).
- Expandida tabela do cronograma (Seção 5) com coluna de Dependências.
- Adicionado índice após o Controle de Versão.
- Padronizado formato dos testes (ex.: "Código: T0.1").