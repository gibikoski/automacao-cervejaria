# **Automação Cervejaria - Anotações, Pendências e Melhorias**

## **Controle de Versão**

| **Versão** | **Data** | **Descrição** |
| --- | --- | --- |
| v1.0.0 | 19/04/2025 | Versão inicial com anotações, pendências e melhorias do projeto. |
| v1.0.1 | 20/04/2025 | Atualização: nova seção 2.1 v1.0.1 com anotações, pendências e melhorias dos arquivos v1.0.1, conteúdo v1.0.0 movido para 2.2 v1.0.0, índice com subitens, tabelas por função, formatações avançadas (**negrito**, *itálico*, emojis), hiperlinks internos. ✅ |
| v1.0.1 | 20/04/2025 | Adicionada melhoria M1.6 em 2.1 v1.0.1 para planejar diagramas Mermaid na *v1.0.2* (Fluxo de Rastreabilidade, Conexões, Cronograma). ✅ |

## **Índice**

- **1. Visão Geral**
- **2. Anotações, Pendências e Melhorias**
  - **2.1 v1.0.1**
  - **2.2 v1.0.0**
- **3. Referências Cruzadas**

## **Metadados**

| **Atributo** | **Valor** |
| --- | --- |
| *artifact_id* | c11fe1ef-86c2-458a-890e-536ec1b62135 |
| *Versão* | v1.0.1 |
| *Data* | 20/04/2025 |
| *Autor* | Grok (xAI) |

## **1. Visão Geral**

**Objetivo**: Consolidar anotações, pendências e melhorias do projeto de automação cervejeira, incluindo observações técnicas, tarefas a realizar, e sugestões de aprimoramento, com base nos documentos v1.0.0 e v1.0.1.

**Escopo**:

- **Período**: *Maio a Outubro 2025*.
- **Foco**: Documentar itens relevantes para todas as funções (Controle de Fermentação, Balança de Volume, Densímetro Flutuante, Controle e Monitoramento).
- **Nota**: A seção *2.1 v1.0.1* inclui itens dos arquivos v1.0.1, enquanto *2.2 v1.0.0* preserva o conteúdo original.

*Referências Cruzadas*:

- Para requisitos e componentes, consulte [*Especificações e Configurações*](docs/v1.0.1/Automacao_Cervejaria_Especificacoes_v1.0.1_20250420.md).
- Para testes, consulte [*Plano de Execução*](docs/v1.0.1/Automacao_Cervejaria_Plano_Execucao_v1.0.1_20250420.md).
- Para rastreabilidade, consulte [*Verificação da Rastreabilidade*](docs/v1.0.1/Automacao_Cervejaria_Verificacao_Rastreabilidade_v1.0.1_20250420.md).

## **2. Anotações, Pendências e Melhorias**

**Nota**: As subseções abaixo organizam os itens por versão, com tabelas separadas por função ou categoria, mantendo a integridade dos dados originais.

### **2.1 v1.0.1**

**Anotações** 📋

| **Item** | **Função** | **Descrição** | **Origem** |
| --- | --- | --- | --- |
| A1.1 | Controle de Fermentação | Não conectar carga AC (220 V) no teste T0.3 (*SSR-10DA*). | *Plano de Execução* (2.1, Notas) |
| A1.2 | Controle de Fermentação | Risco potencial (sobrecarga na lâmpada) no teste T1.2; usar carga de baixa potência (*€5,00*). | *Plano de Execução* (2.1, Notas) |
| A1.3 | Controle de Fermentação | Não conectar SSR-10DA a cargas AC diretamente no teste inicial (*T0.3*). | *Especificações* (2.1) |
| A2.1 | Balança de Volume | HX711 requer calibração inicial com pesos conhecidos (*€30,00*) antes dos testes (*T1.1*). | *Especificações* (2.2) |
| A3.1 | Densímetro Flutuante | ICM20948 deve ser testado em líquidos calibrados (*€10,00*) para garantir precisão (*T1.1*). | *Especificações* (2.3) |
| A4.1 | Controle e Monitoramento | Mega 2560 suporta múltiplos GPIO, but testes de interface (LCD, Keypad) pendentes (*Mês 4*). | *Especificações* (2.4) |
| A4.2 | Controle e Monitoramento | Não há testes sem requisitos associados, indicando boa cobertura inicial do *Plano de Execução*. | *Verificação* (3, Notas) |
| A4.3 | Controle e Monitoramento | Exceções concentradas em Controle e Monitoramento devido à ausência de testes para interface (LCD, Keypad, Mega 2560). | *Verificação* (3, Notas) |
| A5.1 | Geral | Testes longos substituídos por alternativas curtas (ex.: autonomia da bateria em 2 horas, *T4.1*). | *Plano de Execução* (2, Nota) |
| A5.2 | Geral | Setups econômicos fornecidos (ex.: multímetro básico *€5,00*, Wi-Fi doméstico). | *Plano de Execução* (2, Setup) |

**Pendências** 📋

| **Item** | **Função** | **Descrição** | **Prazo** | **Origem** |
| --- | --- | --- | --- | --- |
| P1.1 | Controle de Fermentação | Executar testes T1.2, T2.1, T3.1, T4.1. | *Junho 2025* 🔴 | *Plano de Execução* (2.1) |
| P2.1 | Balança de Volume | Executar testes T1.2, T2.1, T3.1. | *Junho 2025* 🔴 | *Plano de Execução* (2.2) |
| P3.1 | Densímetro Flutuante | Executar testes T1.1, T2.1, T3.1, T4.1, T4.2. | *Julho 2025* 🔴 | *Plano de Execução* (2.3) |
| P4.1 | Controle e Monitoramento | Executar testes T1.1, T1.2. | *Agosto 2025* 🔴 | *Plano de Execução* (2.4) |
| P4.2 | Controle e Monitoramento | Definir testes para RP1, RP2, RD1.1, RD1.2, RD2.1, RD2.2 (LCD, Keypad, Mega 2560). | *Agosto 2025* 🔴 | *Verificação* (3, Resumo) |
| P4.3 | Controle e Monitoramento | Definir pinagem final para DFR0009 (LCD e Keypad) antes dos testes de interface. | *Agosto 2025* 🔴 | *Especificações* (2.4) |
| P5.1 | Geral | Adquirir ferramentas do BOM (ferro de solda *€25,00*, multímetro RM113D *€15,00*, protetor silicone *€5,00*). | *Maio 2025* ✅ | *Especificações* (2, BOM) |
| P5.2 | Geral | Validar segurança e otimizar circuitos. | *Setembro 2025* 🔴 | *Plano de Execução* (3, Cronograma) |
| P5.3 | Geral | Concluir validação final e documentação. | *Outubro 2025* 🔴 | *Plano de Execução* (3, Cronograma) |

**Melhorias** 📋

| **Item** | **Função** | **Descrição** | **Origem** |
| --- | --- | --- | --- |
| M1.1 | Geral | Tabelas separadas por função (Requisitos, BOM, Pinouts, Testes) melhoram clareza em relação a v1.0.0. | *Especificações*, *Plano* (Controle de Versão) |
| M1.2 | Geral | Índice simplificado sem subitens (exceto aqui) facilita navegação no GitHub. | *Especificações*, *Plano*, *Verificação* (Índice) |
| M1.3 | Geral | Uso de emojis (✅, 🔴, ⚠️) para períodos e status destaca informações críticas. | *Plano*, *Verificação* (Controle de Versão) |
| M1.4 | Geral | Hiperlinks internos testados para navegação no GitHub. | *Plano*, *Verificação* (Índice) |
| M1.5 | Geral | Tabelas por função para rastreabilidade válida e exceções facilitam análise. | *Verificação* (Controle de Versão) |
| M1.6 | Geral | Planejar diagramas Mermaid para *v1.0.2*: Fluxo de Rastreabilidade (*Verificação da Rastreabilidade*), Diagrama de Conexões (*Especificações*), Cronograma (*Plano de Execução* ou *README*). | Solicitação do usuário |

### **2.2 v1.0.0**

**Anotações** 📋

| **Item** | **Função** | **Descrição** |
| --- | --- | --- |
| A1 | Controle de Fermentação | DS18B20 deve ser configurado com pull-up de 4,7 kΩ para operação estável no barramento 1-Wire. |
| A2 | Controle de Fermentação | SSR-10DA suporta cargas até 10 A, mas testes iniciais devem usar cargas de baixa potência (ex.: lâmpada 40 W). |
| A3 | Balança de Volume | Células de carga requerem plataforma estável para medições precisas; evitar vibrações externas. |
| A4 | Densímetro Flutuante | Bateria 18650 deve ser protegida contra descarga excessiva (TPS63020 ajustado para corte em 3,0 V). |
| A5 | Controle e Monitoramento | ESP8266 pode sofrer interferência em redes Wi-Fi congestionadas; testar em canal limpo (ex.: canal 11). |
| A6 | Geral | Home Assistant requer configuração prévia de MQTT broker (ex.: Mosquitto) antes dos testes T3.1 e T4.1. |

**Pendências** 📋

| **Item** | **Função** | **Descrição** | **Prazo** |
| --- | --- | --- | --- |
| P1 | Geral | Confirmar fornecedores para componentes do BOM (ex.: DS18B20, HX711, ICM20948). | *Maio 2025* |
| P2 | Geral | Adquirir multímetro RM113D (*€15,00*) e protoboard (*€3,00*) para testes iniciais. | *Maio 2025* |
| P3 | Controle de Fermentação | Validar fusível 3 A em teste T2.1 antes de conectar manta de aquecimento 500 W. | *Junho 2025* |
| P4 | Balança de Volume | Calibrar HX711 com pesos de 1 kg, 5 kg, 20 kg antes do teste T1.1. | *Maio 2025* |
| P5 | Densímetro Flutuante | Testar ICM20948 em líquidos de densidade conhecida (*€10,00*) para T1.1. | *Julho 2025* |
| P6 | Controle e Monitoramento | Definir layout do LCD 1602 e Keypad para interface antes de *Agosto 2025*. | *Agosto 2025* |

**Melhorias** 📋

| **Item** | **Função** | **Descrição** |
| --- | --- | --- |
| M1 | Geral | Estruturar documentação em Markdown com tabelas para facilitar leitura no GitHub. |
| M2 | Geral | Incluir custos estimados (*€*) em todos os setups e componentes para controle orçamentário. |
| M3 | Controle de Fermentação | Usar biblioteca Adafruit_INA219 para monitoramento de bateria em T4.1, reduzindo complexidade. |
| M4 | Balança de Volume | Implementar algoritmo de filtro de ruído para HX711, melhorando precisão em T1.1. |
| M5 | Densímetro Flutuante | Adicionar sensor de temperatura DS18B20 ao densímetro para corrigir densidade (*T2.1*). |
| M6 | Controle e Monitoramento | Explorar interface alternativa (ex.: OLED) para DFR0009, caso LCD 1602 tenha limitações. |

## **3. Referências Cruzadas**

- Para requisitos e componentes, consulte [*Especificações e Configurações*](docs/v1.0.1/Automacao_Cervejaria_Especificacoes_v1.0.1_20250420.md).
- Para testes, consulte [*Plano de Execução*](docs/v1.0.1/Automacao_Cervejaria_Plano_Execucao_v1.0.1_20250420.md).
- Para rastreabilidade, consulte [*Verificação da Rastreabilidade*](docs/v1.0.1/Automacao_Cervejaria_Verificacao_Rastreabilidade_v1.0.1_20250420.md).
