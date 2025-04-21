# Índice de Artefatos - Automação Cervejeira v1.0.1

## Introdução

Este documento centraliza os metadados de todos os artefatos do projeto **Automação Cervejeira** na versão v1.0.1, incluindo arquivos de documentação em `docs/v1.0.1/`. Ele lista nomes, caminhos, `artifact_id`, versões, datas, iterações da conversa, status, e notas, facilitando o rastreamento e a manutenção. O índice deve ser atualizado sempre que novos artefatos forem criados ou existentes forem modificados.

Consulte o [README.markdown](../../README.markdown) para uma visão geral do projeto e a lista de documentos.

## Tabela de Artefatos

| Arquivo | Caminho | artifact_id | Versão | Data | Iteração | Status | Notas |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Automacao_Cervejaria_Especificacoes_v1.0.1_20250420.markdown | docs/v1.0.1/ | 21c0119f-54ea-4f1a-b0eb-a9d56b221cbd | v1.0.1 | 20/04/2025 | 30 | Validado | Define requisitos, BOM, e configurações. |
| Automacao_Cervejaria_Pinouts_v1.0.1_20250420.markdown | docs/v1.0.1/ | a9b8c7d6-e5f4-4a3b-b2c1-d0e1f2g3h4i5 | v1.0.1 | 20/04/2025 | 32 | Validado | Atualizado com Metadados na iteração 32. Inclui Código de Cores. |
| Automacao_Cervejaria_Plano_Execucao_v1.0.1_20250420.markdown | docs/v1.0.1/ | 876f7d44-cad0-4b20-9cf6-eb71267ca360 | v1.0.1 | 20/04/2025 | 33 | Validado | Detalha testes para validação. Revisão do cronograma (Mês 1 como Maio 2025) e mitigação do protetor silicone. |
| Automacao_Cervejaria_Verificacao_Rastreabilidade_v1.0.1_20250420.markdown | docs/v1.0.1/ | f304dded-4441-45e9-9cb1-24445eb19bea | v1.0.1 | 20/04/2025 | 30 | Validado | Valida rastreabilidade bidirecional. |
| Automacao_Cervejaria_Anotacoes_Pendencias_Melhorias_v1.0.1_20250420.markdown | docs/v1.0.1/ | c11fe1ef-86c2-458a-890e-536ec1b62135 | v1.0.1 | 20/04/2025 | 33 | Validado | Consolida observações e tarefas. Removido emoji 🔴 nas pendências. |
| INDEX.markdown | docs/v1.0.1/ | b2f9e8a7-6c3d-4e2b-9a1c-3f7d5e9b0c2a | v1.0.1 | 20/04/2025 | 33 | Validado | Centraliza metadados de artefatos. Incluído como artefato rastreável na v1.0.1. |
| README.markdown | docs/v1.0.1/ | d4a1c9f8-5b2e-4f1c-8d3b-6e9f7a0c3d5b | v1.0.1 | 20/04/2025 | 33 | Validado | Fornece visão geral do projeto e lista de documentos. Incluído como artefato rastreável na v1.0.1. |

## Instruções para Uso

1. **Adicionar um Novo Artefato**:
   - Crie o arquivo em `docs/v1.0.1/` (ex.: `Automacao_Cervejaria_NovoDocumento_v1.0.1_20250420.markdown`).
   - Gere um novo `artifact_id` (UUID único).
   - Adicione uma linha à tabela com: nome do arquivo, caminho, `artifact_id`, versão, data, iteração da conversa, status (ex.: Pendente), e notas.
   - Atualize o `README.markdown` para incluir o novo documento na seção **Documentos**.

2. **Atualizar um Artefato Existente**:
   - Modifique o arquivo em `docs/v1.0.1/`.
   - Mantenha o mesmo `artifact_id`.
   - Atualize a tabela com a nova iteração, status (ex.: Validado), e notas (ex.: "Corrigido na iteração 33").
   - Verifique se o `README.markdown` reflete as mudanças.

3. **Validar o Índice**:
   - Confirme que todos os `artifact_id` são únicos e correspondem aos documentos.
   - Verifique se os caminhos e versões estão corretos.
   - Reporte erros ou sugestões via Issues no GitHub.

## Notas

- Artefatos da v1.0.0 (ex.: `Automacao_Cervejaria_Rastreabilidade_v1.0.0_20250420.markdown`) não estão listados, pois são obsoletos. Se necessário, inclua-os com status "Obsoleto".
- Para versões futuras (ex.: v1.0.2, v2.0.0), crie um novo `INDEX.markdown` na pasta correspondente (ex.: `docs/v1.0.2/`).
- Mantenha a codificação UTF-8 e quebras de linha Unix (\n).
- INDEX e README incluídos como artefatos rastreáveis na v1.0.1 para maior consistência.