# Automação Cervejeira

## Índice

- Visão Geral
- Documentos
- Melhorias da v1.0.1
- Cronograma
- Diretórios
- Como Contribuir

## Visão Geral

Este projeto desenvolve um sistema de automação cervejeira para monitoramento e controle de processos, utilizando microcontroladores (Arduino, ESP32), sensores (DS18B20, HX711, ICM20948), e comunicação MQTT. O foco está nas funções de Controle de Fermentação, Balança de Volume, Densímetro Flutuante, e Controle e Monitoramento, com execução planejada para Maio a Outubro 2025.

**Objetivos**:

- Controlar temperatura com precisão (±0,5°C).
- Medir volume (±0,1-1 litro) e densidade (±0,001-0,005 g/cm³).
- Monitorar remotamente via MQTT e exibir dados em interface (LCD, Keypad).

## Documentos 📋

| **Nome** | **Descrição** | **Link** |
| --- | --- | --- |
| Especificações e Configurações | Define requisitos, BOM, e configurações das funções. | docs/v1.0.1/Automacao_Cervejaria_Especificacoes_v1.0.1_20250420.markdown |
| Pinouts e Conexões | Mapeia pinouts e conexões dos componentes, com tabelas, diagramas Mermaid, e subitem Código de Cores. | docs/v1.0.1/Automacao_Cervejaria_Pinouts_v1.0.1_20250420.markdown |
| Plano de Execução | Detalha testes para validar requisitos e componentes. | docs/v1.0.1/Automacao_Cervejaria_Plano_Execucao_v1.0.1_20250420.markdown |
| Verificação da Rastreabilidade | Valida rastreabilidade bidirecional, destacando pendências. | docs/v1.0.1/Automacao_Cervejaria_Verificacao_Rastreabilidade_v1.0.1_20250420.markdown |
| Anotações, Pendências e Melhorias | Consolida observações, tarefas, e sugestões. | docs/v1.0.1/Automacao_Cervejaria_Anotacoes_Pendencias_Melhorias_v1.0.1_20250420.markdown |

## Melhorias da v1.0.1 ✅

- **Estrutura**: Tabelas separadas por função (ex.: Requisitos, BOM, Testes, Rastreabilidade) para maior clareza.
- **Navegação**: Índice simplificado (exceto em Anotações, com subitens) e hiperlinks internos.
- **Formatações**: Uso de negrito, itálico, emojis (✅, 🔴, ⚠️) para destacar status.
- **Rastreabilidade**: Verificação bidirecional identificou 6 pendências em Controle e Monitoramento (Agosto 2025).
- **Consistência**: Documentos atualizados com base em v1.0.0, mantendo integridade dos dados.
- **Pinouts e Conexões**: Seção 4. Pinouts e Conexões removida de Especificações e migrada para o novo artefato Pinouts e Conexões, incluindo subitem Código de Cores com emojis (🔴, ⚫, ⚪, 🟡, 🔵) and descrições coloridas (ex.: `<span style="color:red">Alimentação (VCC, VOUT, VIN, V+)</span>`; cores ignoradas no GitHub devido a sanitização de CSS).

## Cronograma

- **Maio 2025**: Aquisição de ferramentas (€45,00) e calibração inicial.
- **Junho a Julho 2025**: Testes de Controle de Fermentação, Balança de Volume, Densímetro Flutuante.
- **Agosto 2025**: Testes de Controle e Monitoramento, incluindo interface (LCD, Keypad).
- **Setembro 2025**: Validação de segurança e otimização de circuitos.
- **Outubro 2025**: Validação final e documentação.

## Diretórios

- **docs/v1.0.1/**: Documentos atualizados (Especificações, Pinouts, Plano, Verificação, Anotações).
- **docs/v1.0.0/**: Documentos iniciais (Especificações, Plano, Rastreabilidade, Anotações).

## Como Contribuir

- **Revisão**: Leia os documentos em `docs/v1.0.1/` para entender o projeto, começando por Especificações e Pinouts.

- **Feedback**: Reporte problemas ou sugestões via Issues no GitHub.

- **Testes**: Contribua com validação de esquemáticos e montagem em protoboard, planejados para Maio/Junho 2025.

- **Nomenclatura de Arquivos**: Siga o padrão `<nome do repositorio>_<Nome_Do_Documento>_<vX.Y.Z>_<yyyymmdd>.markdown`. Exemplo: `Automacao_Cervejaria_Especificacoes_v1.0.1_20250420.markdown`, onde:

  - `<nome do repositorio>`: `Automacao_Cervejaria`.
  - `<Nome_Do_Documento>`: Nome do documento (ex.: `Especificacoes`, `Pinouts`).
  - `<vX.Y.Z>`: Versão (ex.: `v1.0.1`).
  - `<yyyymmdd>`: Data de criação ou atualização (ex.: `20250420` para 20/04/2025).

- **Versões e Revisões**:

  - **Novas Versões**: Crie para mudanças significativas (ex.: novo artefato como `Pinouts`, reestruturação).
  - **Revisões**: Aplique para correções menores (ex.: ajustes de texto, remoção de seção).
  - **Critérios de Versão**:
    - `X`: Mudanças incompatíveis ou reformulações completas (ex.: novo escopo do projeto).
    - `Y`: Novas funcionalidades ou melhorias relevantes (ex.: adição de subitem Código de Cores).
    - `Z`: Correções de bugs ou ajustes menores (ex.: atualização de links).

- **Armazenamento**: Salve novos documentos em `/docs/vX.Y.Z` (ex.: `/docs/v1.0.1/` para v1.0.1). Mantenha versões antigas em pastas separadas (ex.: `/docs/v1.0.0/`).

- **Artefatos da v1.0.1**:

  - Abaixo estão os `artifact_id` dos arquivos gerados para a v1.0.1, usados para rastreabilidade. Cada arquivo da v1.0.1 tem um `artifact_id` único, diferente dos da v1.0.0, pois são novos artefatos.

  | **Arquivo** | **artifact_id** |
  | --- | --- |
  | Automacao_Cervejaria_Especificacoes_v1.0.1_20250420.markdown | 21c0119f-54ea-4f1a-b0eb-a9d56b221cbd |
  | Automacao_Cervejaria_Pinouts_v1.0.1_20250420.markdown | a9b8c7d6-e5f4-4a3b-b2c1-d0e1f2g3h4i5 |
  | Automacao_Cervejaria_Plano_Execucao_v1.0.1_20250420.markdown | 876f7d44-cad0-4b20-9cf6-eb71267ca360 |
  | Automacao_Cervejaria_Verificacao_Rastreabilidade_v1.0.1_20250420.markdown | f304dded-4441-45e9-9cb1-24445eb19bea |
  | Automacao_Cervejaria_Anotacoes_Pendencias_Melhorias_v1.0.1_20250420.markdown | c11fe1ef-86c2-458a-890e-536ec1b62135 |
