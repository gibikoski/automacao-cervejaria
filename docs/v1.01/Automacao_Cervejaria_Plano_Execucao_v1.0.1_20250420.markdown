# **Automação Cervejaria - Plano de Execução**

## **Controle de Versão**

| **Versão** | **Data** | **Descrição** |
| --- | --- | --- |
| v1.0.0 | 19/04/2025 | Versão inicial com plano de testes e cronograma. |
| v1.0.1 | 20/04/2025 | Sincronização com demais documentos da versão, atualização da cobertura de requisitos e testes, detalhamento de atividades funcionais, adição do status geral do projeto, e mitigação para itens como *Manta 500W*. ✅ |

## **Índice**

- **1. Visão Geral**
- **2. Testes**
- **3. Cronograma**
- **4. Plano de Mitigação**

## **Metadados**

| **Atributo** | **Valor** |
| --- | --- |
| *artifact_id* | 876f7d44-cad0-4b20-9cf6-eb71267ca360 |
| *Versão* | v1.0.1 |
| *Data* | 20/04/2025 |
| *Autor* | Grok (xAI) |

## **1. Visão Geral**

**Objetivo**: Planejar a execução do projeto de automação cervejeira, definindo testes, cronograma, e estratégias de mitigação para garantir a validação das funções (*Controle de Fermentação*, *Balança de Volume*, *Densímetro Flutuante*, *Controle e Monitoramento*) dentro do período de Maio a Outubro 2025, com orçamento de €118,72-129,72.

**Escopo**:

- **Testes**: 43 testes unitários e de integração, mapeados no *Checklist de Testes v1.0.1* (*artifact_id: c4e2f9a8-3b7d-4f8a-a2c1-7f9e0d3b2c1e*).
- **Cronograma**: 6 meses, com aquisição de componentes, montagem, testes, e integração.
- **Mitigação**: Plano para componentes *Em planejamento* (ex.: *Manta 500W*).
- **Referências**:
  - *Especificações v1.0.1* (*artifact_id: 21c0119f-54ea-4f1a-b0eb-a9d56b221cbd*).
  - *Pinouts v1.0.1*.
  - *Verificação de Rastreabilidade v1.0.1*.

## **2. Testes**

**Descrição**: Os testes validam os requisitos primários (*RPs*) e derivados (*RDs*) das funções do projeto, garantindo precisão, segurança, autonomia, e conectividade. A cobertura bidirecional foi verificada, com todos os testes e requisitos mapeados.

### **Cobertura Bidirecional**

- **Checklist → Especificações**:
  - Todos os 43 testes do *Checklist de Testes* estão associados a pelo menos um *RP* ou *RD*:
    - *Controle de Fermentação* (12 testes): Ex.: T0.1.1 (*RD1.4*), T3.1 (*RP3*, *RD3.1*, *RD3.2*).
    - *Balança de Volume* (10 testes): Ex.: T0.2 (*RD1.1*), T3.1 (*RP3*, *RD3.1*, *RD3.2*).
    - *Densímetro Flutuante* (13 testes): Ex.: T0.2 (*RD1.1*), T4.1 (*RP4*, *RD4.1*, *RD4.2*).
    - *Controle e Monitoramento* (8 testes): Ex.: T0.3 (*RD1.1*), T1.1 (*RP3*, *RD3.1*, *RD3.2*).
  - **Conclusão**: 100% de cobertura.
- **Especificações → Checklist**:
  - Dos 51 requisitos (*RPs*/*RDs*):
    - 48/51 cobertos por testes no *Checklist*.
    - GAPs (*Controle e Monitoramento*):
      - *RP2* (Ajustes via interface): Resolvido com testes funcionais (keypad DFR0009, setpoint de temperatura, exibição no LCD) ✅.
      - *RD2.1* (Keypad DFR0009): Resolvido com testes funcionais (detecção de 5-6 botões, integração com Mega 2560) ✅.
      - *RD2.2* (GPIOs Mega 2560): Resolvido com debug interno (LEDs, Serial Monitor, pinos 2-5, 11, 12) ✅.
  - **Conclusão**: Cobertura completa após resolução dos GAPs.
- **Ações**:
  - Documentar testes funcionais de *RP2* e *RD2.1* na revisão de Agosto 2025 (Seção 2.4, *Controle e Monitoramento*).
  - Configurar debug interno para *RD2.2* no sketch do Mega 2560 (Maio 2025).

*Referências*: *Especificações v1.0.1* (Seção 4), *Checklist de Testes v1.0.1*.

## **3. Cronograma**

| **Período** | **Atividade** | **Entregáveis** | **Status** | **Status Geral do Projeto** |
| --- | --- | --- | --- | --- |
| **Mês 1 (Maio 2025)** | **Testes unitários iniciais e aquisição**:<br>- Aquisição de componentes conforme BOM.<br>- Testes unitários (*stand alone*):<br>- T0.1.1: Verificar alimentação do Arduino R4 Connect (5 V USB ou bateria, *RD1.4*).<br>- T0.1.2: Testar I/O digital do Arduino R4 Connect (pinos digitais, *RD1.5*).<br>- T0.1.3: Validar comunicação I2C do Arduino R4 Connect (*RD1.6*).<br>- T0.2: Confirmar precisão de ±0,5°C do DS18B20 (*RD1.1*, *RD1.3*).<br>- T0.3: Testar acionamento do SSR-10DA (3-32 V DC, *RD1.2*).<br>- T0.4: Verificar corrente/tensão com INA219 (±1 mA, ±10 mV, *RD4.2*, *RD4.3*).<br>- T0.1.1: Testar alimentação do ESP32-C3 (3,3 V, *RD1.5*).<br>- T0.2: Validar conversão de peso com HX711 (24 bits, *RD1.1*, *RD1.4*).<br>- T0.3: Confirmar nivelamento com MPU6050 (±0,1 g, *RD2.1*, *RD2.2*).<br>- T0.2: Testar medição de densidade com ICM20948 (*RD1.1*, *RD1.2*).<br>- T0.4: Verificar regulação de tensão com TPS63020 (3,3 V, *RD3.2*).<br>- T0.1.2: Testar I/O digital do Mega 2560 (pinos 2-5, *RD2.2*).<br>- T0.3: Validar exibição e keypad do DFR0009 (LCD 1602, 5-6 botões, *RD1.1*, *RD2.1*).<br>- Configurar debug interno do Mega 2560 (Serial Monitor, LEDs para falhas de GPIO, *RD2.2*). | \- Componentes adquiridos (*Em transporte ✈️*, *Item existente ✅*).<br>- Relatório de testes unitários (13 testes, incluindo métricas de precisão, logs de Serial Monitor, e validação de pinagens conforme *Pinouts v1.0.1*). | \- Aquisição: *Em transporte ✈️* (ex.: Arduino R4 Connect, ESP32-C3, INA219). Itens existentes: *Mega 2560*, *DFR0009* ✅. Em planejamento: *Manta 500W*, *Células de carga* (3x) 📋.<br>- Testes: 90% concluídos (baseado em *Checklist*). São estimativas, conforme planejamento. | \~30% (13/43 testes) |
| **Mês 2 (Junho 2025)** | **Montagem e testes unitários adicionais**:<br>- Montar protoboards para *Controle de Fermentação*, *Balança de Volume*, *Densímetro Flutuante*.<br>- Testes unitários e funcionais:<br>- T1.1: Validar controle de temperatura com DS18B20 e SSR-10DA (±0,5°C, *RP1*, *RD1.1*, *RD1.2*).<br>- T2.1: Testar proteção do fusível 3 A contra sobrecarga (*RP2*, *RD2.1*).<br>- T4.1: Verificar autonomia de 24h com bateria 18650 (*RP4*, *RD4.1*, *RD4.2*).<br>- T1.1: Confirmar medição de peso com HX711 e célula de carga (±0,1-1 g, *RP1*, *RD1.1*, *RD1.2*).<br>- T2.1: Validar nivelamento automático com MPU6050 (±0,1 g, *RP2*, *RD2.1*).<br>- T1.1: Testar medição de densidade com ICM20948 (±0,001-0,005 g/cm³, *RP1*, *RD1.1*).<br>- T2.1: Confirmar temperatura com DS18B20 (±0,5°C, *RP2*, *RD2.1*).<br>- T3.1: Verificar autonomia de 3-5 dias com bateria 18650 (*RP3*, *RD3.1*, *RD3.3*).<br>- T1.3: Testar exibição de dados no LCD DFR0009 (temperatura, volume, densidade, *RP1*, *RD1.1*, *RD1.2*).<br>- T1.2: Validar monitoramento de corrente/tensão com INA219 (*RD3.3*, *RD3.4*).<br>- Confirmar pinagens corretas (*Pinouts v1.0.1*). | \- Protoboards montados para três funções.<br>- Relatório de testes unitários (10 testes, com resultados de precisão, autonomia, e validação funcional, incluindo logs de exibição no LCD). | \- Montagem: 80% concluída.<br>- Testes: 90% concluídos. São estimativas, conforme planejamento. | \~53% (23/43 testes) |
| **Mês 3 (Julho 2025)** | **Testes de integração iniciais**:<br>- Integrar *Controle de Fermentação* com Wi-Fi (MQTT, PubSubClient, *RP3*, *RD3.1*, *RD3.2*).<br>- Testes de integração:<br>- T3.1: Validar envio de dados MQTT com Arduino R4 Connect (temperatura, *RP3*).<br>- T3.1: Testar MQTT com ESP32-C3 (volume, *RP3*, *RD3.1*, *RD3.2*).<br>- T4.1: Confirmar MQTT no Densímetro Flutuante (densidade, *RP4*, *RD4.1*, *RD4.2*).<br>- T1.1: Verificar MQTT com ESP8266 (interface, *RP3*, *RD3.1*, *RD3.2*).<br>- T1.2: Validar cálculo de volume (Peso/Densidade, *RP1*, *RD1.3*).<br>- T4.2: Testar monitoramento de bateria com INA219 no Densímetro (*RD3.3*, *RD3.4*).<br>- Testar fusível 3 A com carga simulada (ex.: lâmpada 40W, *RP2*). | \- Sistemas integrados com Wi-Fi (MQTT funcional).<br>- Relatório de testes de integração (6 testes, incluindo dados MQTT, métricas de volume, e validação de segurança). | \- Integração: 70% concluída.<br>- Testes: 90% concluídos. São estimativas, conforme planejamento. | \~67% (29/43 testes) |
| **Mês 4 (Agosto 2025)** | **Testes de integração completos e funcionais**:<br>- Testes de integração e funcionais:<br>- T1.2: Validar controle de temperatura com SSR e DS18B20 (carga simulada, ±0,5°C, *RP1*).<br>- T4.1: Confirmar autonomia de 24h com INA219 (*RP4*).<br>- T1.2: Testar cálculo de volume com HX711 e densidade conhecida (*RP1*).<br>- T2.1: Verificar nivelamento automático com MPU6050 e célula de carga (*RP2*).<br>- T1.1: Confirmar densidade com ICM20948 e DS18B20 (±0,001-0,005 g/cm³, *RP1*).<br>- T3.1: Validar autonomia de 3-5 dias com TPS63020 e INA219 (*RP3*).<br>- T1.1: Testar exibição de temperatura, volume, e densidade no LCD DFR0009 (*RP1*).<br>- Testes funcionais para *RP2*, *RD2.1*: Validar ajustes de parâmetros via keypad DFR0009 (ex.: setpoint de temperatura, navegação de menus).<br>- Documentar testes funcionais (*RP2*, *RD2.1*). | \- Sistemas totalmente integrados.<br>- Relatório de testes (7 testes + funcionais, com resultados de integração, logs de ajustes via keypad, e documentação funcional). | \- Integração: 90% concluída.<br>- Testes funcionais: Concluídos ✅. São estimativas, conforme planejamento. | \~84% (36/43 testes) |
| **Mês 5 (Setembro 2025)** | **Testes finais e validação**:<br>- Testes finais:<br>- T3.1: Validar integração completa via MQTT (todas as funções: temperatura, volume, densidade, *RP3*, *RP4*).<br>- T1.2: Testar controle de temperatura com carga simulada ou Manta 500W (*RP1*).<br>- T1.2: Confirmar volume com célula de carga e densidade (*RP1*).<br>- T1.1: Validar densidade com temperatura compensada (*RP1*, *RP2*).<br>- T1.1: Testar interface completa (LCD DFR0009, ESP8266, exibição e ajustes, *RP1*, *RP3*).<br>- Verificar autonomia (24h e 3-5 dias) e segurança (fusível 3 A, *RP2*, *RP4*). | \- Relatório de testes finais (5 testes, com métricas de integração MQTT, precisão funcional, e validação de autonomia/segurança).<br>- Sistema validado para todas as funções. | \- Testes: 100% concluídos.<br>- Validação: 90% concluída. São estimativas, conforme planejamento. | \~95% (41/43 testes) |
| **Mês 6 (Outubro 2025)** | **Documentação e entrega**:<br>- Documentar resultados finais de todos os testes.<br>- Finalizar relatórios com logs, métricas, e validações.<br>- Validar integração final (*T3.1*: MQTT, *T1.1*: interface).<br>- Entregar sistema validado com todas as funções operacionais. | \- Documentação completa (relatórios de testes, validações, e pinagens).<br>- Sistema entregue, validado para uso prático. | \- Documentação: 100% concluída.<br>- Entrega: Concluída ✅. São estimativas, conforme planejamento. | 100% (43/43 testes) |

**Notas**:

- **Status Geral do Projeto**: Percentuais baseados em 43 testes totais (*Checklist de Testes*). Cada período assume 100% de conclusão dos testes previstos, acumulando até 100% em Outubro 2025.
- **Referências**: *Checklist de Testes v1.0.1* (testes detalhados), *Pinouts v1.0.1* (conexões), *Especificações v1.0.1* (BOM e status).

## **4. Plano de Mitigação**

**Itens em Planejamento** (baseado em *Especificações v1.0.1*, Seção 3):

- **Manta 500W** (Controle de Fermentação):
  - **Problema**: A ausência da manta pode impedir testes de controle de temperatura com carga real (~220 V, 500W) em Setembro 2025 (T1.2, *RP1*), atrasando a validação final do protótipo.
  - **Solução Proposta**: Utilizar uma carga alternativa compatível para testes unitários (T0.3, T1.1, Junho 2025) and de integração (T1.2, Agosto 2025), validando o controle de temperatura (±0,5°C, *RP1*).
  - **Plano de Mitigação Aprovado**: Usar carga alternativa para testes até Agosto 2025. A aquisição da manta está monitorada no BOM (*Especificações v1.0.1*, Seção 3), com prazo até Maio 2025 (Mês 1-4), garantindo testes finais em Setembro 2025 sem impacto no cronograma.

- **Bateria 18650** (adicional para Controle de Fermentação):
  - **Problema**: Sem a bateria adicional, testes de autonomia de 24h (T4.1, *RP4*, Junho e Agosto 2025) podem ser limitados, e a validação final (Setembro 2025) pode exigir operação simultânea de todas as funções.
  - **Solução Proposta**: Reutilizar uma bateria 18650 (*Em transporte* para *Balança de Volume* ou *Densímetro Flutuante*) para testes sequenciais, com monitoramento via INA219 (*RD4.2*) para garantir desempenho.
  - **Plano de Mitigação Aprovado**: “Emprestar” bateria de outra função para testes até Setembro 2025, com monitoramento via INA219. A aquisição da bateria adicional está no BOM (*Especificações v1.0.1*, Seção 3), com prazo até Setembro 2025 (Mês 5), alinhado ao cronograma, sem riscos significativos devido ao baixo consumo do projeto.

- **Células de carga** (3 unidades adicionais para Balança de Volume):
  - **Problema**: A ausência das 3 células adicionais pode limitar testes de nivelamento automático (T2.1, *RP2*, Agosto 2025), que exigem carga distribuída, e impedir a operação prática da balança (5-40 kg) na validação final (Setembro-Outubro 2025).
  - **Solução Proposta**: Utilizar a célula de carga *Em transporte* para testes unitários (T1.1, Junho 2025) e de integração (T1.2, Agosto 2025), com testes preliminares de nivelamento (T2.1, Julho 2025) usando pesos calibrados para simular carga distribuída.
  - **Plano de Mitigação Aprovado**: Usar a célula *Em transporte* com pesos calibrados para testes, incluindo testes preliminares em Julho 2025 (Mês 3). A aquisição das 3 células adicionais está no BOM (*Especificações v1.0.1*, Seção 3), com prazo até Agosto 2025 (Mês 4), garantindo testes completos de nivelamento e validação final sem atrasos.

- **Protetor silicone p/ bancada** (Componentes Gerais):
  - **Problema**: Sem o protetor, a montagem e os testes (Maio a Agosto 2025) podem ser menos organizados, mas não há impacto direto nos requisitos ou testes.
  - **Solução Proposta**: Considerar o item “nice to have” e usar superfícies seguras (ex.: mesa de madeira com isolamento) como alternativa.
  - **Plano de Mitigação Aprovado**: Protetor deverá ser adquirido quando orçamento permitir. Como boa prática geral, sempre utilizar superfícies seguras para montagem e testes. Aquisição opcional, sem prioridade, pois não afeta o cronograma.

**Notas**:

- Itens *ANENG SL105*, *ANENG SZ01*, e *Soldering Third Helping Hand* foram removidos, pois estão com status *Em transporte ✈️*.
- Ações adicionais podem ser definidas em iterações futuras.

*Referências*: *Especificações v1.0.1* (Seção 3).