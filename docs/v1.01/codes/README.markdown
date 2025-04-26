# README - Estrutura de Diretórios e Testes

Este documento descreve a estrutura dos diretórios de código no projeto e lista os testes associados a cada função, organizados em tabelas. Todos os testes estão localizados no diretório base `/docs/V1.01/codes/`, divididos por função.

## Estrutura dos Diretórios
Os códigos estão organizados em quatro subdiretórios, cada um correspondendo a uma função do projeto:
- **Controle_de_Fermentacao**: Testes para controle de processos de fermentação.
- **Balanca_de_Volume**: Testes para medição de volume por meio de uma balança.
- **Densimetro_Flutuante**: Testes para medição de densidade com densímetro flutuante.
- **Controle_e_Monitoramento**: Testes para monitoramento e controle de variáveis do sistema.

Cada subdiretório contém subpastas nomeadas conforme o teste (ex.: `T0_1_1`, `T4_2`), e cada teste possui dois arquivos:
- **.ino**: Código Arduino para o teste, com cabeçalho contendo `artifact_id`, função, versão, data, iteração, requisitos, descrição e diretório.
- **.markdown**: Documentação do teste, com seções de Metadados, Descrição, Setup, Resultados Esperados, Notas e Lista de Artifact IDs.

### Detalhes Gerais
- **Versão**: v1.0.1
- **Data**: 2025-04-20
- **Iteração**: 34
- **Status**: Pendente
- **Hardware**: Projetado para Arduino R4 Connect, com bibliotecas padrão.
- **Instruções**: Carregar os sketches no Arduino IDE, instalar bibliotecas necessárias e abrir o Serial Monitor (9600 baud) para verificar resultados. Usar visualização "Raw" no GitHub para evitar delays ao carregar `.ino`.

## Lista de Testes por Função

### Controle de Fermentação
| Teste   | Artifact ID                          | Descrição (Resumida)                              | Diretório                              |
|---------|--------------------------------------|--------------------------------------------------|----------------------------------------|
| T0.1.1  | 5148934c-c09f-4088-8bb3-af49cbf142bf | Inicialização do sensor de temperatura           | Controle_de_Fermentacao/T0_1_1         |
| T0.1.2  | e144b732-8ebf-4e1f-9a9a-9bd3b1808950 | Leitura de temperatura                           | Controle_de_Fermentacao/T0_1_2         |
| T0.1.3  | 45a0dfc9-2878-4812-ae74-3d98531f37c0 | Controle de aquecedor                            | Controle_de_Fermentacao/T0_1_3         |
| T0.1.4  | 0af662e9-cc12-46b7-a420-e5d147172f81 | Controle de resfriador                           | Controle_de_Fermentacao/T0_1_4         |
| T0.2    | f2c4643b-0120-4bae-b32c-e3254da9b993 | Calibração do sensor                             | Controle_de_Fermentacao/T0_2           |
| T0.3    | 0aef38a2-15df-4ff4-9265-8cc6fd8e66fd | Exibição no LCD                                  | Controle_de_Fermentacao/T0_3           |
| T0.4    | b46a3026-f024-42e1-9ec4-8e5554588a1c | Armazenamento de dados                           | Controle_de_Fermentacao/T0_4           |
| T1.1    | 6e0e2fa6-3fbc-4d81-994b-bebf44afbc51 | Controle automático de temperatura               | Controle_de_Fermentacao/T1_1           |
| T1.2    | 3494fc1b-d435-45d9-8628-9e1191e68234 | Ajuste manual de setpoint                        | Controle_de_Fermentacao/T1_2           |
| T2.1    | de329107-3a66-4112-80bb-58bf0dca6b72 | Monitoramento remoto via WiFi                    | Controle_de_Fermentacao/T2_1           |
| T3.1    | 890814c4-35fc-4571-9468-81340ca0be2f | Registro de eventos                              | Controle_de_Fermentacao/T3_1           |
| T4.1    | b2366c19-6651-4127-8413-9642773892a3 | Validação de estabilidade térmica               | Controle_de_Fermentacao/T4_1           |

### Balança de Volume
| Teste   | Artifact ID                          | Descrição (Resumida)                              | Diretório                              |
|---------|--------------------------------------|--------------------------------------------------|----------------------------------------|
| T0.1.1  | a33d4101-3eb3-4b33-91e9-3b9d15b77630 | Inicialização da célula de carga                 | Balanca_de_Volume/T0_1_1               |
| T0.1.2  | 1571700b-b50a-4ee7-9838-20741d90120c | Leitura de peso                                  | Balanca_de_Volume/T0_1_2               |
| T0.1.3  | 7b9603e3-df08-4c0d-adb5-293e8ef391ca | Calibração da balança                            | Balanca_de_Volume/T0_1_3               |
| T0.1.4  | de2c4e30-a29e-4173-b04d-bee48e4406c9 | Exibição de peso no LCD                          | Balanca_de_Volume/T0_1_4               |
| T0.2    | c0afaf04-d934-4c2c-aeac-60a0a4834fc8 | Cálculo de volume                                | Balanca_de_Volume/T0_2                 |
| T0.3    | c7c30809-5130-4d41-82e3-cd6817face86 | Armazenamento de medições                        | Balanca_de_Volume/T0_3                 |
| T1.1    | d0aaeaad-fdfa-4640-9c5f-303457c7646d | Ajuste de densidade                              | Balanca_de_Volume/T1_1                 |
| T1.2    | 05ebee9b-151e-4bcc-bb9f-870767719e5c | Interface de usuário                             | Balanca_de_Volume/T1_2                 |
| T2.1    | 9ba4d06b-7851-43a1-bc5e-1c61f115068a | Comunicação com sistema externo                  | Balanca_de_Volume/T2_1                 |
| T3.1    | 819109a0-5a5a-47cc-a892-8ec6128f4791 | Validação de precisão                            | Balanca_de_Volume/T3_1                 |

### Densímetro Flutuante
| Teste   | Artifact ID                          | Descrição (Resumida)                              | Diretório                              |
|---------|--------------------------------------|--------------------------------------------------|----------------------------------------|
| T0.1.1  | 0561d7ee-269b-4666-b230-7f8098353019 | Inicialização do sensor de densidade             | Densimetro_Flutuante/T0_1_1            |
| T0.1.2  | 22c3cdbe-3527-4688-8431-6f2114020132 | Leitura de posição do densímetro                 | Densimetro_Flutuante/T0_1_2            |
| T0.1.3  | 3b6b3d33-7492-47ad-9fa5-8edd13ec0d5e | Cálculo de densidade                             | Densimetro_Flutuante/T0_1_3            |
| T0.1.4  | 11eb892f-6a87-460c-ab94-e7e0fb92cd5b | Exibição de densidade no LCD                     | Densimetro_Flutuante/T0_1_4            |
| T0.2    | 8790c77d-e1e4-4b5f-846a-c1865b762004 | Calibração do densímetro                         | Densimetro_Flutuante/T0_2              |
| T0.3    | cd286597-86d8-470f-8ae3-76bf43a59a7f | Armazenamento de medições                        | Densimetro_Flutuante/T0_3              |
| T0.4    | c1891ed7-7286-4c61-8f79-2cdecbb355d5 | Comunicação de dados                              | Densimetro_Flutuante/T0_4              |
| T0.5    | 07591bc0-e90a-4f58-a1f4-1783e3f03f6b | Interface de usuário                             | Densimetro_Flutuante/T0_5              |
| T1.1    | 47c263d3-cf8a-43a6-b700-70cc4b6a0096 | Ajuste de parâmetros                             | Densimetro_Flutuante/T1_1              |
| T2.1    | a189da32-e594-4f2f-bc1a-764b13f83fdf | Monitoramento contínuo                           | Densimetro_Flutuante/T2_1              |
| T3.1    | 64c8fdd7-949e-4c77-b30a-4853866d5989 | Registro de eventos                              | Densimetro_Flutuante/T3_1              |
| T4.1    | 2429e396-92e8-4a52-a58d-1c301cd69acd | Validação com líquidos padrão                    | Densimetro_Flutuante/T4_1              |
| T4.2    | fb8d96f0-58f6-4201-9cc4-dfdc3f6575ca | Validação com líquidos de densidade conhecida    | Densimetro_Flutuante/T4_2              |

### Controle e Monitoramento
| Teste   | Artifact ID                          | Descrição (Resumida)                              | Diretório                              |
|---------|--------------------------------------|--------------------------------------------------|----------------------------------------|
| T0.1.1  | 1a5148be-b003-4276-8d1e-024aa5d998c0 | Inicialização do sistema de controle             | Controle_e_Monitoramento/T0_1_1        |
| T0.1.2  | daa0f8ad-47cf-4179-beb5-b4678c7d6bec | Monitoramento de temperatura                     | Controle_e_Monitoramento/T0_1_2        |
| T0.1.3  | 540da23e-139a-444b-8e62-ea86e2f4d580 | Controle de atuadores                            | Controle_e_Monitoramento/T0_1_3        |
| T0.2    | bf32b947-f819-4d47-8c88-aff04dc64a12 | Armazenamento de dados em EEPROM                 | Controle_e_Monitoramento/T0_2          |
| T0.3    | 75562dd6-a594-459c-b571-14ac81de3abd | Comunicação WiFi para monitoramento remoto       | Controle_e_Monitoramento/T0_3          |
| T1.1    | c1db1077-d4ae-4317-893e-a46a84aa957a | Controle baseado em limites configuráveis        | Controle_e_Monitoramento/T1_1          |
| T1.2    | 06b2a889-babf-4272-a08e-406699ef7094 | Registro de eventos em EEPROM                    | Controle_e_Monitoramento/T1_2          |
| T1.3    | ea976526-9cee-47e5-974a-cf674b66368c | Interface de usuário via LCD e botões            | Controle_e_Monitoramento/T1_3          |

## Notas
- Cada teste possui um arquivo `.ino` (código) e `.markdown` (documentação), localizados na respectiva subpasta.
- Os testes foram projetados para o Arduino R4 Connect, com status "Pendente" até validação em hardware.
- Alguns testes (ex.: T0.1.1 a T0.2 em Controle_e_Monitoramento) podem conter componentes placeholders, que devem ser revisados com o BOM durante a validação.
- Para executar os testes, consultar a seção "Setup" nos arquivos `.markdown` para conexões de hardware e bibliotecas necessárias.