# Automação Cervejeira

## Índice

- Visão Geral
- Documentos
- Melhorias da v1.0.1
- Diretórios
- Como Contribuir

## Visão Geral

Este projeto desenvolve um sistema de automação cervejeira para monitoramento e controle de processos, utilizando microcontroladores (Arduino, ESP32), sensores (DS18B20, HX711, ICM20948), e comunicação MQTT. O foco está nas funções de Controle de Fermentação, Balança de Volume, Densímetro Flutuante, e Controle e Monitoramento, com execução planejada para Maio a Outubro 2025.

**Objetivos**:

- Controlar temperatura com precisão (±0,5°C) utilizando DS18B20 e SSR-10DA para aquecimento/refrigeração.
- Medir volume (±0,1-1 litro) com células de carga e HX711 para balança de precisão.
- Medir densidade (±0,001-0,005 g/cm³) utilizando o densímetro flutuante com ICM20948 e monitoramento de temperatura via DS18B20.
- Monitorar remotamente via MQTT e exibir dados em interface (LCD, Keypad).

## Documentos 📋

| **Nome** | **Descrição** | **Link** |
| --- | --- | --- |
| Especificações e Configurações | Define requisitos, BOM, e configurações das funções. | docs/v1.0.1/Automacao_Cervejaria_Especificacoes_v1.0.1_20250420.markdown |
| Pinouts e Conexões | Mapeia pinouts e conexões dos componentes, com tabelas, diagramas Mermaid, e subitem Código de Cores. | docs/v1.0.1/Automacao_Cervejaria_Pinouts_v1.0.1_20250420.markdown |
| Plano de Execução | Detalha testes para validar requisitos e componentes. Revisado com cronograma ajustado (Mês 1 como Maio 2025) e mitigação do protetor silicone. | docs/v1.0.1/Automacao_Cervejaria_Plano_Execucao_v1.0.1_20250420.markdown |
| Verificação da Rastreabilidade | Valida rastreabilidade bidirecional, destacando pendências. | docs/v1.0.1/Automacao_Cervejaria_Verificacao_Rastreabilidade_v1.0.1_20250420.markdown |
| Anotações, Pendências e Melhorias | Consolida observações, tarefas, e sugestões. Revisado com remoção de emoji 🔴 nas pendências. | docs/v1.0.1/Automacao_Cervejaria_Anotacoes_Pendencias_Melhorias_v1.0.1_20250420.markdown |
| Índice de Artefatos | Centraliza metadados de todos os artefatos da v1.0.1. | docs/v1.0.1/INDEX.markdown |

## Melhorias da v1.0.1 ✅

- **Estrutura**: Tabelas separadas por função (ex.: Requisitos, BOM, Testes, Rastreabilidade) para maior clareza.
- **Navegação**: Índice simplificado (exceto em Anotações, com subitens) e hiperlinks internos.
- **Formatações**: Uso de negrito, itálico, emojis (✅, 🔴, ⚠️) para destacar status.
- **Rastreabilidade**: Verificação bidirecional identificou 6 pendências em Controle e Monitoramento (Agosto 2025), resolvidas com testes funcionais.
- **Consistência**: Documentos atualizados com base em v1.0.0, mantendo integridade dos dados.
- **Pinouts e Conexões**: Seção 4. Pinouts e Conexões removida de Especificações e migrada para o novo artefato Pinouts e Conexões, incluindo subitem Código de Cores com emojis (🔴, ⚫, ⚪, 🟡, 🔵) e descrições coloridas (ex.: `<span style="color:red">Alimentação (VCC, VOUT, VIN, V+)</span>`; cores ignoradas no GitHub devido a sanitização de CSS).
- **Cronograma**: Ajustado no *Plano de Execução* para alinhar Mês 1 como Maio 2025.
- **Mitigação**: Revisão da mitigação do protetor silicone no *Plano de Execução*, agora condicional ao orçamento.
- **Pendências**: Remoção do emoji 🔴 nas pendências do *Anotações, Pendências e Melhorias* para maior clareza.

## Diretórios

- **docs/v1.01/**: Documentos atualizados (Especificações, Pinouts, Plano, Verificação, Anotações, Índice).
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