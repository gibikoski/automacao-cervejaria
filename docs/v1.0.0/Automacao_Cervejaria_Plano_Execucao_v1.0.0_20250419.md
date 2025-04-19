





Automação Cervejaria - Plano de Execução
Controle de Versão



Versão
Data
Descrição



v1.0.0
19/04/2025
Versão inicial do documento.


4. Plano de Testes
Nota: Incluídos testes "stand alone" para ICs críticos, realizados em Mês 1 (Maio 2025) para validação inicial. Testes existentes mantidos, com sequência lógica (componentes → integração → Wi-Fi). Testes longos substituídos por alternativas curtas. Setups econômicos fornecidos.
Referências Cruzadas:

Para especificações dos componentes testados, consulte Automação Cervejaria - Especificações e Configurações.
Para rastreabilidade dos testes, consulte Automação Cervejaria - Rastreabilidade.

4.1 Função Controle de Fermentação (aquecimento)
Testes de ICs Críticos (Stand Alone)
T0.1 (Valida Arduino R4 Connect):

Objetivo: Verificar funcionalidade básica e pinagem (GPIO, I2C, Wi-Fi).
Procedimento: Carregar sketch de teste (pisca LED em D3, lê I2C em A4/A5, conecta Wi-Fi), verificar saída via Serial Monitor.
Setup Recomendado: Arduino R4 Connect, protoboard (€3,00), LED com resistor 220 Ω (€1,00), multímetro RM113D (€15,00), Wi-Fi roteador (€30,00).
Alternativa: Usar multímetro básico (€5,00), Wi-Fi doméstico, verificar GPIO com LED visual.
Métricas: LED pisca a 1 Hz, I2C responde, Wi-Fi conecta em <10 s.
Tempo Estimado: 1 hora.
Período: Mês 1 (Maio 2025).

T0.2 (Valida DS18B20):

Objetivo: Confirmar leitura de temperatura e pinagem (1-Wire).
Procedimento: Conectar DS18B20 (DQ a D2, pull-up 4,7 kΩ), carregar sketch OneWire, ler temperatura ambiente, verificar via Serial Monitor.
Setup Recomendado: DS18B20, Arduino R4 Connect, resistor 4,7 kΩ (€0,50), protoboard (€3,00).
Alternativa: Usar resistor de valor próximo (ex.: 5 kΩ), verificar temperatura manualmente.
Métricas: Temperatura ±2°C do ambiente, leitura estável em 10 amostras.
Tempo Estimado: 30 minutos.
Período: Mês 1 (Maio 2025).

T0.3 (Valida SSR-10DA):

Objetivo: Verificar controle de saída e pinagem.
Procedimento: Conectar controle (+ a D3, - a GND), ligar LED com resistor 220 Ω como carga, ativar/desativar via sketch, medir tensão com multímetro.
Setup Recomendado: SSR-10DA, Arduino R4 Connect, LED com resistor (€1,00), multímetro RM113D (€15,00).
Alternativa: Usar multímetro básico (€5,00), verificar visualmente LED.
Métricas: Saída alterna 0-3,3 V, resposta <1 s.
Tempo Estimado: 30 minutos.
Período: Mês 1 (Maio 2025).
Nota: Não conectar carga AC (220 V) neste teste.

T0.4 (Valida INA219):

Objetivo: Verificar leitura de corrente/tensão e pinagem (I2C).
Procedimento: Conectar INA219 (SDA a A4, SCL a A5), medir resistor 10 Ω como carga, carregar sketch Adafruit_INA219, verificar via Serial Monitor.
Setup Recomendado: INA219, Arduino R4 Connect, resistor 10 Ω (€1,00), multímetro RM113D (€15,00).
Alternativa: Usar multímetro básico (€5,00), verificar valores manualmente.
Métricas: Corrente ±1 mA, tensão ±10 mV, I2C responde.
Tempo Estimado: 1 hora.
Período: Mês 1 (Maio 2025).

Testes Existentes
T1.1 (Valida RP1, RD1.1):

Objetivo: Verificar precisão do DS18B20 (±0,5°C).
Procedimento: Colocar DS18B20 em banho-maria (20°C e 30°C), medir 100 amostras, comparar com termômetro de referência.
Setup Recomendado: DS18B20, R4 Connect, banho-maria (€50,00), termômetro calibrado (€20,00).
Alternativa: Usar gelo e água quente (20-30°C), termômetro doméstico (€5,00).
Métricas: Erro máximo ±0,5°C em 95% das medições.
Tempo Estimado: 2 horas.
Período: Mês 1 (Maio 2025).

T1.2 (Valida RP1, RD1.2):

Objetivo: Confirmar controle de aquecimento via SSR-10DA com manta 500W.
Procedimento: Conectar lâmpada 40W (proxy), ativar/desativar SSR, medir tempo de resposta.
Setup Recomendado: SSR-10DA, R4 Connect, lâmpada 40W (€5,00), multímetro RM113D (€15,00).
Alternativa: Usar LED com resistor (€1,00), verificar visualmente.
Métricas: Resposta <1 s, sem falhas em 50 ciclos.
Tempo Estimado: 1 hora.
Período: Mês 2 (Junho 2025).
Nota: Risco potencial (sobrecarga na lâmpada); usar carga de baixa potência.

T2.1 (Valida RP2, RD2.1):

Objetivo: Verificar fusível 3 A (não destrutivo).
Procedimento: Medir continuidade e resistência do fusível com multímetro, verificar especificação (3 A).
Setup Recomendado: Fusível 3 A, multímetro RM113D (€15,00).
Alternativa: Usar multímetro básico (€5,00).
Métricas: Continuidade confirmada, resistência <1 Ω.
Tempo Estimado: 30 minutos.
Período: Mês 2 (Junho 2025).

T3.1 (Valida RP3, RD3.1, RD3.2):

Objetivo: Testar integração MQTT com Home Assistant.
Procedimento: Publicar temperatura via MQTT, verificar recepção no Home Assistant.
Setup Recomendado: R4 Connect, Wi-Fi roteador (€30,00), Home Assistant (Raspberry Pi, €50,00).
Alternativa: Usar Wi-Fi doméstico, Home Assistant em PC (grátis).
Métricas: Latência <2 s, 100% de pacotes recebidos em 1 hora.
Tempo Estimado: 3 horas.
Período: Mês 2 (Junho 2025).

T4.1 (Valida RP4, RD4.1, RD4.2):

Objetivo: Verificar autonomia da bateria 18650 (teste curto).
Procedimento: Conectar R4 Connect, DS18B20, INA219 a carga simulada (resistor 10 Ω), medir corrente/tensão por 2 horas, estimar autonomia.
Setup Recomendado: Bateria 18650, INA219, multímetro RM113D (€15,00), resistor 10 Ω (€1,00).
Alternativa: Usar multímetro básico (€5,00), medir corrente manualmente.
Métricas: Autonomia estimada ≥24 horas, corrente ±1 mA.
Tempo Estimado: 2 horas.
Período: Mês 2 (Junho 2025).

4.2 Função Balança de Volume (litros fermentador/keg)
Testes de ICs Críticos (Stand Alone)
T0.1 (Valida ESP32-C3):

Objetivo: Verificar funcionalidade básica e pinagem (GPIO, I2C, Wi-Fi).
Procedimento: Carregar sketch de teste (pisca LED em GPIO4, lê I2C em GPIO18/19, conecta Wi-Fi), verificar via Serial Monitor.
Setup Recomendado: ESP32-C3, protoashboard (€3,00), LED com resistor 220 Ω (€1,00), multímetro RM113D (€15,00), Wi-Fi roteador (€30,00).
Alternativa: Usar multímetro básico (€5,00), Wi-Fi doméstico, verificar GPIO com LED visual.
Métricas: LED pisca a 1 Hz, I2C responde, Wi-Fi conecta em <10 s.
Tempo Estimado: 1 hora.
Período: Mês 1 (Maio 2025).

T0.2 (Valida HX711):

Objetivo: Confirmar leitura ADC e pinagem.
Procedimento: Conectar HX711 (DT a GPIO4, SCK a GPIO5), carregar sketch HX711, simular entrada com resistor 1 kΩ, verificar leitura via Serial Monitor.
Setup Recomendado: HX711, ESP32-C3, resistor 1 kΩ (€0,50), protoboard (€3,00).
Alternativa: Usar potenciômetro (€1,00) como entrada, verificar valores manualmente.
Métricas: Leitura estável, variação <0,1% em 10 amostras.
Tempo Estimado: 30 minutos.
Período: Mês 1 (Maio 2025).

T0.3 (Valida MPU6050):

Objetivo: Verificar leitura inercial e pinagem (I2C).
Procedimento: Conectar MPU6050 (SDA a GPIO18, SCL a GPIO19), carregar sketch Adafruit_MPU6050, ler aceleração/giroscópio, verificar via Serial Monitor.
Setup Recomendado: MPU6050, ESP32-C3, protoboard (€3,00).
Alternativa: Usar superfície plana, verificar valores manualmente.
Métricas: Aceleração ±0,1 g, giroscópio ±1°/s em 10 amostras.
Tempo Estimado: 1 hora.
Período: Mês 1 (Maio 2025).

Testes Existentes
T1.1 (Valida RP1, RD1.1, RD1.2):

Objetivo: Validar precisão de peso do HX711 (±0,1-1 g).
Procedimento: Colocar pesos conhecidos (1 kg, 5 kg, 20 kg), medir 100 amostras.
Setup Recomendado: HX711, células de carga, ESP32-C3, pesos calibrados (€30,00).
Alternativa: Usar objetos domésticos (ex.: garrafas d’água), balança de cozinha (€10,00).
Métricas: Erro máximo ±0,1-1 g em 95% das medições.
Tempo Estimado: 2 horas.
Período: Mês 1 (Maio 2025).

T1.2 (Valida RP1, RD1.3):

Objetivo: Validar cálculo de volume (Volume = Peso / Densidade).
Procedimento: Usar peso medido (ex.: 5 kg) e densidade conhecida (ex.: 1,005 g/cm³), calcular volume, comparar com volume real.
Setup Recomendado: HX711, ESP32-C3, líquidos calibrados (€10,00), densímetro manual (€15,00).
Alternativa: Usar densidade teórica (ex.: água, 1 g/cm³), recipiente medido (€5,00).
Métricas: Erro máximo ±0,1-1 litro em 95% dos cálculos.
Tempo Estimado: 2 horas.
Período: Mês 2 (Junho 2025).

T2.1 (Valida RP2, RD2.1):

Objetivo: Verificar nivelamento com MPU6050 (±0,1 g).
Procedimento: Inclinar plataforma em 5°, medir correção do MPU6050.
Setup Recomendado: MPU6050, ESP32-C3, plataforma inclinável (€20,00).
Alternativa: Usar superfície manual (ex.: livro inclinado), verificar via software.
Métricas: Correção <2 s, precisão ±0,1 g.
Tempo Estimado: 1 hora.
Período: Mês 2 (Junho 2025).

T3.1 (Valida RP3, RD3.1, RD3.2):

Objetivo: Confirmar envio de dados de volume via MQTT.
Procedimento: Publicar volume via MQTT, verificar no Home Assistant.
Setup Recomendado: ESP32-C3, Wi-Fi roteador (€30,00), Home Assistant (Raspberry Pi, €50,00).
Alternativa: Usar Wi-Fi doméstico, Home Assistant em PC (grátis).
Métricas: Latência <2 s, 100% de pacotes recebidos.
Tempo Estimado: 3 horas.
Período: Mês 2 (Junho 2025).

4.3 Função Densímetro Flutuante Remoto
Testes de ICs Críticos (Stand Alone)
T0.1 (Valida ESP32-C3):

Objetivo: Verificar funcionalidade básica e pinagem (GPIO, I2C, Wi-Fi).
Procedimento: Carregar sketch de teste (pisca LED em GPIO2, lê I2C em GPIO18/19, conecta Wi-Fi), verificar via Serial Monitor.
Setup Recomendado: ESP32-C3, protoboard (€3,00), LED com resistor 220 Ω (€1,00), multímetro RM113D (€15,00), Wi-Fi roteador (€30,00).
Alternativa: Usar multímetro básico (€5,00), Wi-Fi doméstico, verificar GPIO com LED visual.
Métricas: LED pisca a 1 Hz, I2C responde, Wi-Fi conecta em <10 s.
Tempo Estimado: 1 hora.
Período: Mês 1 (Maio 2025).

T0.2 (Valida ICM20948):

Objetivo: Verificar leitura inercial e pinagem (I2C).
Procedimento: Conectar ICM20948 (SDA a GPIO18, SCL a GPIO19), carregar sketch ICM20948, ler aceleração/magnetômetro, verificar via Serial Monitor.
Setup Recomendado: ICM20948, ESP32-C3, protoboard (€3,00).
Alternativa: Usar superfície plana, verificar valores manualmente.
Métricas: Aceleração ±0,1 g, magnetômetro ±1 µT em 10 amostras.
Tempo Estimado: 1 hora.
Período: Mês 1 (Maio 2025).

T0.3 (Valida DS18B20):

Objetivo: Confirmar leitura de temperatura e pinagem (1-Wire).
Procedimento: Conectar DS18B20 (DQ a GPIO2, pull-up 4,7 kΩ), carregar sketch OneWire, ler temperatura ambiente, verificar via Serial Monitor.
Setup Recomendado: DS18B20, ESP32-C3, resistor 4,7 kΩ (€0,50), protoboard (€3,00).
Alternativa: Usar resistor de valor próximo (ex.: 5 kΩ), verificar temperatura manualmente.
Métricas: Temperatura ±2°C do ambiente, leitura estável em 10 amostras.
Tempo Estimado: 30 minutos.
Período: Mês 1 (Maio 2025).

T0.4 (Valida TPS63020):

Objetivo: Verificar regulação de tensão e pinagem.
Procedimento: Conectar TPS63020 (VIN a bateria 3,7 V, VOUT a 3,3 V), medir VOUT com multímetro, conectar carga (resistor 10 Ω).
Setup Recomendado: TPS63020, bateria 18650, resistor 10 Ω (€1,00), multímetro RM113D (€15,00).
Alternativa: Usar multímetro básico (€5,00), sem carga.
Métricas: VOUT = 3,3 V ±5%, estável com carga.
Tempo Estimado: 30 minutos.
Período: Mês 1 (Maio 2025).

T0.5 (Valida INA219):

Objetivo: Verificar leitura de corrente/tensão e pinagem (I2C).
Procedimento: Conectar INA219 (SDA a GPIO18, SCL a GPIO19), medir resistor 10 Ω como carga, carregar sketch Adafruit_INA219, verificar via Serial Monitor.
Setup Recomendado: INA219, ESP32-C3, resistor 10 Ω (€1,00), multímetro RM113D (€15,00).
Alternativa: Usar multímetro básico (€5,00), verificar valores manualmente.
Métricas: Corrente ±1 mA, tensão ±10 mV, I2C responde.
Tempo Estimado: 1 hora.
Período: Mês 1 (Maio 2025).

Testes Existentes
T1.1 (Valida RP1, RD1.1):

Objetivo: Validar precisão do ICM20948 (±0,005 g/cm³).
Procedimento: Testar em líquidos de densidade conhecida (água, etanol), medir 100 amostras.
Setup Recomendado: ICM20948, ESP32-C3, líquidos calibrados (€10,00), densímetro manual (€15,00).
Alternativa: Usar água e soluções caseiras (ex.: açúcar), densímetro básico (€5,00).
Métricas: Erro máximo ±0,005 g/cm³ em 95% das medições.
Tempo Estimado: 2 horas.
Período: Mês 3 (Julho 2025).

T2.1 (Valida RP2, RD2.1):

Objetivo: Confirmar temperatura com DS18B20 (±0,5°C).
Procedimento: Medir temperatura em líquido (20°C), comparar com referência.
Setup Recomendado: DS18B20, ESP32-C3, termômetro calibrado (€20,00).
Alternativa: Usar termômetro doméstico (€5,00), água a 20°C.
Métricas: Erro máximo ±0,5°C em 95% das medições.
Tempo Estimado: 1 hora.
Período: Mês 3 (Julho 2025).

T3.1 (Valida RP3, RD3.1, RD3.2):

Objetivo: Verificar autonomia da bateria 18650 (teste curto).
Procedimento: Conectar densímetro a carga simulada (resistor 10 Ω), medir corrente/tensão por 2 horas, estimar autonomia.
Setup Recomendado: Bateria 18650, TPS63020, INA219, multímetro RM113D (€15,00).
Alternativa: Usar multímetro básico (€5,00), medir manualmente.
Métricas: Autonomia estimada ≥3 dias, tensão estável (±5%).
Tempo Estimado: 2 horas.
Período: Mês 3 (Julho 2025).

T4.1 (Valida RP4, RD4.1, RD4.2):

Objetivo: Testar integração MQTT com Home Assistant.
Procedimento: Publicar densidade e temperatura via MQTT, verificar recepção.
Setup Recomendado: ESP32-C3, Wi-Fi roteador (€30,00), Home Assistant (Raspberry Pi, €50,00).
Alternativa: Usar Wi-Fi doméstico, Home Assistant em PC (grátis).
Métricas: Latência <2 s, 100% de pacotes recebidos em 1 hora.
Tempo Estimado: 3 horas.
Período: Mês 3 (Julho 2025).

T4.2 (Valida RP3, RD3.3):

Objetivo: Testar monitoramento com INA219.
Procedimento: Medir corrente/tensão da bateria, comparar com multímetro.
Setup Recomendado: INA219, ESP32-C3, multímetro RM113D (€15,00).
Alternativa: Usar multímetro básico (€5,00).
Métricas: Precisão ±1 mA, ±10 mV.
Tempo Estimado: 1 hora.
Período: Mês 3 (Julho 2025).

4.4 Função Controle, Monitoramento e Alterações de Parâmetros
Testes de ICs Críticos (Stand Alone)
T0.1 (Valida ESP8266):

Objetivo: Verificar funcionalidade básica e pinagem (GPIO, I2C, Wi-Fi).
Procedimento: Carregar sketch de teste (pisca LED em GPIO4, lê I2C em GPIO4/5, conecta Wi-Fi), verificar via Serial Monitor.
Setup Recomendado: ESP8266, protoboard (€3,00), LED com resistor 220 Ω (€1,00), multímetro RM113D (€15,00), Wi-Fi roteador (€30,00).
Alternativa: Usar multímetro básico (€5,00), Wi-Fi doméstico, verificar GPIO com LED visual.
Métricas: LED pisca a 1 Hz, I2C responde, Wi-Fi conecta em <10 s.
Tempo Estimado: 1 hora.
Período: Mês 1 (Maio 2025).

T0.2 (Valida INA219):

Objetivo: Verificar leitura de corrente/tensão e pinagem (I2C).
Procedimento: Conectar INA219 (SDA a GPIO4, SCL a GPIO5), medir resistor 10 Ω como carga, carregar sketch Adafruit_INA219, verificar via Serial Monitor.
Setup Recomendado: INA219, ESP8266, resistor 10 Ω (€1,00), multímetro RM113D (€15,00).
Alternativa: Usar multímetro básico (€5,00), verificar valores manualmente.
Métricas: Corrente ±1 mA, tensão ±10 mV, I2C responde.
Tempo Estimado: 1 hora.
Período: Mês 1 (Maio 2025).

Testes Existentes
T1.1 (Valida RP3, RD3.1, RD3.2):

Objetivo: Confirmar integração MQTT.
Procedimento: Publicar dados via MQTT, verificar no Home Assistant.
Setup Recomendado: ESP8266, Wi-Fi roteador (€30,00), Home Assistant (Raspberry Pi, €50,00).
Alternativa: Usar Wi-Fi doméstico, Home Assistant em PC (grátis).
Métricas: Latência <2 s, 100% de pacotes recebidos em 1 hora.
Tempo Estimado: 3 horas.
Período: Mês 4 (Agosto 2025).

T1.2 (Valida RP3, RD3.3):

Objetivo: Testar monitoramento com INA219.
Procedimento: Medir corrente/tensão, comparar com multímetro.
Setup Recomendado: INA219, ESP8266, multímetro RM113D (€15,00).
Alternativa: Usar multímetro básico (€5,00).
Métricas: Precisão ±1 mA, ±10 mV.
Tempo Estimado: 1 hora.
Período: Mês 4 (Agosto 2025).

5. Cronograma Geral



Mês
Período
Atividades
Entregáveis



Mês 1
Maio 2025
Testes unitários de ICs (Arduino R4 Connect, ESP32-C3, DS18B20, etc.), compras de ferramentas (ferro de solda, multímetro, protetor silicone).
ICs validados, ferramentas adquiridas.


Mês 2
Junho 2025
Integração da Função Controle de Fermentação e Balança, testes de integração.
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
Otimização de circuitos, validação de segurança.
Sistema estável.


Mês 6
Outubro 2025
Validação final, documentação.
Sistema integrado, documentação.


Referências Cruzadas:

Para detalhes dos componentes testados, consulte Automação Cervejaria - Especificações e Configurações.
Para dependências entre funções, consulte Automação Cervejaria - Rastreabilidade.
Para pendências de compras, consulte Automação Cervejaria - Anotações, Pendências e Melhorias.

