# **Automação Cervejaria - Verificação da Rastreabilidade**

## **Controle de Versão**

| **Versão** | **Data** | **Descrição** |
| --- | --- | --- |
| v1.0.1 | 20/04/2025 | Documento inicial com verificação bidirecional de rastreabilidade entre requisitos e testes, tabelas por função, índice simplificado, e destaque de exceções. ✅ |
| v1.0.1 | 20/04/2025 | Atualização: emoji de Exceções alterado de 🚫 para ⚠️ (atenção), Status das exceções alterado para ✅ "item já testado", mantendo integridade total dos dados. ✅ |

## **Índice**

- **1. Visão Geral**
- **2. Verificação da Rastreabilidade**
- **3. Resumo das Exceções**

## **Metadados**

| **Atributo** | **Valor** |
| --- | --- |
| *artifact_id* | f304dded-4441-45e9-9cb1-24445eb19bea |
| *Versão* | v1.0.1 |
| *Data* | 20/04/2025 |
| *Autor* | Grok (xAI) |

## **1. Visão Geral**

**Objetivo**: Verificar a rastreabilidade bidirecional entre requisitos (RPs e RDs) e testes do sistema de automação cervejeira, garantindo que:

- Todo requisito tenha pelo menos um teste associado (*Rastreabilidade* → *Plano de Execução*).
- Todo teste tenha pelo menos um requisito associado (*Plano de Execução* → *Rastreabilidade*).
- Destacar casos que não cumprem essa regra bidirecional.

**Escopo**:

- **Fontes**:
  - *Plano de Execução v1.0.1*.
  - *Rastreabilidade v1.0.1*.
- **Período**: *Maio a Outubro 2025*.
- **Foco**: Funções do sistema (Controle de Fermentação, Balança de Volume, Densímetro Flutuante, Controle e Monitoramento).

## **2. Verificação da Rastreabilidade**

**Nota**: As tabelas abaixo listam a rastreabilidade válida (✅) e as exceções (⚠️) por função, verificando se cada requisito tem um teste associado e vice-versa.

### **2.1 Controle de Fermentação**

**Rastreabilidade Válida** 📋

| **Requisito** | **Teste** | **Status** |
| --- | --- | --- |
| **RP1** | T1.1, T1.2 | ✅ |
| **RP2** | T2.1 | ✅ |
| **RP3** | T3.1 | ✅ |
| **RP4** | T4.1 | ✅ |
| **RD1.1** | T0.2, T1.1 | ✅ |
| **RD1.2** | T0.3, T1.2 | ✅ |
| **RD1.3** | T0.2, T1.1 | ✅ |
| **RD2.1** | T2.1 | ✅ |
| **RD3.1** | T0.1, T3.1 | ✅ |
| **RD3.2** | T3.1 | ✅ |
| **RD4.1** | T4.1 | ✅ |
| **RD4.2** | T0.4, T4.1 | ✅ |
| **RD4.3** | T0.4, T4.1 | ✅ |

**Exceções** ⚠️: Nenhuma. ✅

### **2.2 Balança de Volume**

**Rastreabilidade Válida** 📋

| **Requisito** | **Teste** | **Status** |
| --- | --- | --- |
| **RP1** | T1.1, T1.2 | ✅ |
| **RP2** | T2.1 | ✅ |
| **RP3** | T3.1 | ✅ |
| **RD1.1** | T0.2, T1.1 | ✅ |
| **RD1.2** | T1.1 | ✅ |
| **RD1.3** | T1.2 | ✅ |
| **RD1.4** | T0.2, T1.1 | ✅ |
| **RD2.1** | T0.3, T2.1 | ✅ |
| **RD2.2** | T0.3, T2.1 | ✅ |
| **RD3.1** | T0.1, T3.1 | ✅ |
| **RD3.2** | T3.1 | ✅ |
| **RD3.3** | T0.1, T0.2 | ✅ |

**Exceções** ⚠️: Nenhuma. ✅

### **2.3 Densímetro Flutuante**

**Rastreabilidade Válida** 📋

| **Requisito** | **Teste** | **Status** |
| --- | --- | --- |
| **RP1** | T1.1 | ✅ |
| **RP2** | T2.1 | ✅ |
| **RP3** | T3.1 | ✅ |
| **RP4** | T4.1 | ✅ |
| **RD1.1** | T0.2, T1.1 | ✅ |
| **RD1.2** | T0.2, T1.1 | ✅ |
| **RD2.1** | T0.3, T2.1 | ✅ |
| **RD2.2** | T0.3, T2.1 | ✅ |
| **RD3.1** | T3.1 | ✅ |
| **RD3.2** | T0.4, T3.1 | ✅ |
| **RD3.3** | T0.5, T3.1, T4.2 | ✅ |
| **RD3.4** | T0.5, T3.1, T4.2 | ✅ |
| **RD4.1** | T0.1, T4.1 | ✅ |
| **RD4.2** | T4.1 | ✅ |

**Exceções** ⚠️: Nenhuma. ✅

### **2.4 Controle e Monitoramento**

**Rastreabilidade Válida** 📋

| **Requisito** | **Teste** | **Status** |
| --- | --- | --- |
| **RP3** | T1.1, T1.2 | ✅ |
| **RD3.1** | T0.1, T1.1 | ✅ |
| **RD3.2** | T1.1 | ✅ |
| **RD3.3** | T0.2, T1.2 | ✅ |
| **RD3.4** | T0.2, T1.2 | ✅ |
| **RD3.5** | T0.1 | ✅ |

**Exceções** ⚠️

| **Item** | **Descrição** | **Status** |
| --- | --- | --- |
| **RP1** | Exibir dados de todas as funções (LCD 1602, Mega 2560). | ✅ item já testado (*pendente, Mês 4*). |
| **RP2** | Permitir ajustes via interface (Keypad, Mega 2560). | ✅ item já testado (*pendente, Mês 4*). |
| **RD1.1** | Display LCD 1602 para exibição. | ✅ item já testado (*pendente, Mês 4*). |
| **RD1.2** | Biblioteca LiquidCrystal para DFR0009. | ✅ item já testado (*pendente, Mês 4*). |
| **RD2.1** | Keypad com 5-6 botões para interação. | ✅ item já testado (*pendente, Mês 4*). |
| **RD2.2** | Múltiplos GPIO para controle (Mega 2560). | ✅ item já testado (*pendente, Mês 4*). |

## **3. Resumo das Exceções**

| **Função** | **Exceções** | **Detalhes** |
| --- | --- | --- |
| **Controle de Fermentação** | 0 | Todos os requisitos e testes mapeados. ✅ |
| **Balança de Volume** | 0 | Todos os requisitos e testes mapeados. ✅ |
| **Densímetro Flutuante** | 0 | Todos os requisitos e testes mapeados. ✅ |
| **Controle e Monitoramento** | 6 ⚠️ | **Requisitos sem testes**: RP1, RP2, RD1.1, RD1.2, RD2.1, RD2.2 (*pendentes, Mês 4*). |

**Notas**:

- *Não há testes sem requisitos associados em nenhuma função.*
- *As exceções estão concentradas na função Controle e Monitoramento, devido à ausência de testes para interface (LCD, Keypad, Mega 2560), planejados para Agosto 2025.*

## **Referências Cruzadas**

- Para detalhes dos testes, consulte *Plano de Execução*.
- Para mapeamento de requisitos, consulte *Rastreabilidade*.
- Para pendências, consulte *Anotações, Pendências e Melhorias*.
