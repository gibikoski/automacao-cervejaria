# White Paper - Estudo Adição de Função: Medição do Volume da Panela de Mostura

## 1. Introdução

Este documento apresenta uma análise preliminar para a adição de uma nova função ao projeto, focada na medição em tempo real do volume de água adicionado a uma panela de mostura. A função é projetada para operar temporariamente durante o enchimento da panela, com ativação/desativação simples, integração com sistemas de monitoramento existentes, e proteção contra o ambiente úmido da mostura. Futuramente, a função permitirá a automação do enchimento por meio de um atuador que interrompe o fluxo de água ao atingir um volume pré-definido. Este white paper consolida o conceito, descrição, utilização, componentes, requisitos, testes e análise de integração, servindo como base para futuras decisões de implementação.

## 2. Conceito Inicial

A função **Medição do Volume da Panela** visa medir o volume de água em tempo real durante o enchimento de uma panela de mostura, usando o sensor ultrassônico **RCWL-1670** conectado a um microprocessador (ex.: ESP32 ou Arduino R4 Connect). O sensor, posicionado temporariamente acima da panela via haste removível, mede a distância até a superfície da água, permitindo o cálculo do volume com base nas dimensões fixas da panela. A função é esporádica, limitada ao processo de enchimento, e pode ser implementada como um "modo temporário" em um microprocessador existente ou em um novo dispositivo dedicado. Futuramente, a função poderá controlar uma torneira inteligente que fecha automaticamente ao atingir um volume pré-estabelecido, com base nas medições do RCWL-1670.

### 2.1. Objetivos
- Medir o volume de água com precisão (±2%) durante o enchimento da panela.
- Exibir o volume em tempo real (ex.: via LCD ou Serial Monitor).
- Enviar dados de volume via WiFi para integração com outras funções (ex.: Controle e Monitoramento).
- Garantir operação temporária, com ativação/desativação simples (ex.: botão, comando WiFi, ou detecção do sensor).
- Proteger o sistema contra umidade (IP67) e corrosão, considerando o ambiente úmido da mostura.
- Preparar o sistema para futura automação com torneira inteligente.

## 3. Descrição da Função

A função opera da seguinte forma:

* O RCWL-1670, montado em uma haste removível, é posicionado acima da panela de mostura.
* O sensor mede a distância até a superfície da água (intervalo de 5–75 cm) a cada 500 ms.
* O microprocessador calcula o volume com base na distância medida e nas dimensões fixas da panela (ex.: altura, área da base).
* O volume é exibido em tempo real (ex.: LCD 16x2, Serial Monitor) e enviado via WiFi para um sistema externo (ex.: Controle e Monitoramento).
* A função é ativada/desativada manualmente (ex.: botão, comando WiFi, ou detecção de conexão do sensor), funcionando como um modo temporário.
* O sistema (sensor, placa, conexões, suporte) é protegido contra umidade (IP67) e corrosão para operar em ambiente úmido.
* Futuramente, o microprocessador controlará uma torneira inteligente para fechar o fluxo ao atingir um volume alvo (±2% de tolerância).

## 4. Utilização

A função é usada no início do processo de mostura, durante o enchimento da panela com água, que leva poucos minutos. O sensor RCWL-1670 é instalado temporariamente via haste removível, facilitando a montagem e remoção. O volume medido é monitorado em tempo real pelo operador (via LCD ou dispositivo remoto) para garantir a quantidade correta de água. A integração com outras funções (ex.: Controle e Monitoramento) permite registrar o volume ou usá-lo como entrada para processos subsequentes (ex.: fermentação). A futura torneira inteligente automatizará o enchimento, fechando o fluxo quando o volume alvo for atingido, reduzindo a intervenção manual.

### 4.1. Contexto
- **Ambiente**: Cozinha industrial ou cervejaria, com vapores, respingos e umidade elevada devido à mostura.
- **Duração**: Poucos minutos por uso, esporádico (ex.: 1–2 vezes por batch).
- **Usuários**: Operadores de mostura, que precisam de medições precisas e interface simples.
- **Integração**: Dados de volume podem ser usados por outras funções (ex.: Controle de Fermentação, Balança de Volume) para cálculos ou validação cruzada.

## 5. Componentes Propostos

- **Sensor Ultrassônico RCWL-1670**:
  - Sensor de distância à prova d'água (IP67), opera com 3–5V, mede distâncias de 5–75 cm com precisão de ±1 cm.
  - Conexões: VCC, GND, TRIG, ECHO.
- **Microprocessador**:
  - Dispositivo genérico com capacidade de processar dados do sensor, calcular volume, exibir resultados, e suportar WiFi para comunicação.
- **Suporte Temporário**:
  - Haste ou suporte removível (ex.: aço inoxidável 316 ou alumínio anodizado) para posicionar o sensor acima da panela.
  - Resistente à umidade/corrosão, com alinhamento vertical (±2°).
- **LCD 16x2 (opcional)**:
  - Exibe volume em tempo real, conectado via I2C ou paralelo.
- **Torneira Inteligente (futura)**:
  - Atuador (ex.: válvula solenóide, similar a [este modelo](https://www.aliexpress.com/item/1005008550993095.html)) controlado por sinal digital para abrir/fechar o fluxo de água.
- **Conexões e Fios**:
  - Conectores selados e fios com revestimento impermeável (ex.: silicone) para proteção IP67.
- **Caixa de Proteção**:
  - Caixa selada (IP67) para encapsular a placa do microprocessador e conexões.

## 6. Reutilização e Integração

A função pode ser implementada reutilizando um microprocessador existente (ex.: em **Controle e Monitoramento**) ou adicionando um novo dispositivo. Abaixo, a análise:

### 6.1. Reutilização de Microprocessador Existente
- **Cenário**: Usar um microprocessador já presente (ex.: em **Controle e Monitoramento**, que suporta WiFi).
- **Vantagens**:
  - Reduz custo e complexidade, evitando hardware adicional.
  - Aproveita WiFi para integração com **T0.3** (Controle e Monitoramento).
  - RCWL-1670 usa poucos pinos (VCC, GND, TRIG, ECHO), permitindo compartilhamento com LCD, relés, etc.
  - Modo temporário ativado por botão, comando WiFi, ou detecção do sensor, sem interferir nas funções principais.
- **Desafios**:
  - **Conflito de Pinos**: Pinos usados por outras funções (ex.: LCD, relés) podem estar ocupados. Solução: Usar pinos livres ou multiplexar.
  - **Carga de Processamento**: Tarefas intensivas (ex.: WiFi em **T0.3**) podem causar atrasos. A medição de volume é leve (leituras a cada 500 ms), mas exige testes.
  - **Energia**: O microprocessador deve fornecer 3–5V estável para o RCWL-1670, compatível com a alimentação padrão.
- **Recomendação**: Preferível se o projeto já possui um microprocessador com pinos livres, implementando a medição como modo temporário.

### 6.2. Adição de Novo Microprocessador
- **Cenário**: Introduzir um microprocessador dedicado para a função.
- **Vantagens**:
  - Evita conflitos com funções existentes, garantindo isolamento.
  - Simplifica o desenvolvimento, com o microprocessador focado na medição e futura torneira inteligente.
  - Permite posicionamento independente, ideal para a haste removível.
- **Desafios**:
  - Aumenta custo e complexidade (novo hardware, integração via WiFi/I2C).
  - Exige fonte de energia adicional (ex.: bateria, USB).
- **Recomendação**: Viável se o microprocessador existente não tiver pinos livres ou se a função exigir isolamento.

### 6.3. Integração com Outras Funções
- **Controle e Monitoramento**:
  - Enviar volume via WiFi (**T0.3**).
  - Registrar volume na EEPROM (**T1.2**).
  - Exibir volume no LCD (**T1.3**).
- **Controle de Fermentação**:
  - Usar volume como entrada para parâmetros de fermentação (**T1.2**).
- **Balança de Volume**:
  - Comparar volume medido com cálculo da balança (**T0.2**) para validação cruzada.
- **Densímetro Flutuante**:
  - Correlacionar volume com densidade (**T0.1.3**).
- **Torneira Inteligente (futura)**:
  - Integrar com **T1.1** (Controle e Monitoramento) para limites configuráveis.

### 6.4. Conclusão
Reutilizar um microprocessador existente é a abordagem preferida, com a medição de volume como modo temporário ativado por botão, comando WiFi, ou detecção do sensor. Um microprocessador dedicado é uma alternativa se houver conflitos de pinos ou necessidade de isolamento. A escolha final depende da disponibilidade de pinos e da presença de um microprocessador com WiFi no projeto.

## 7. Requisitos

### 7.1. Requisitos Principais (RPs)

| ID   | Descrição                                                                                                           |
|------|---------------------------------------------------------------------------------------------------------------------|
| RP1  | O sensor RCWL-1670 deve medir a distância até a superfície da água na panela com precisão de ±1 cm, em um intervalo de 5 cm a 75 cm, em tempo real (leituras a cada 500 ms). |
| RP2  | O microprocessador deve calcular o volume de água na panela com base na distância medida pelo RCWL-1670 e nas dimensões fixas da panela, com erro máximo de ±2% do volume real. |
| RP3  | O sistema deve exibir o volume calculado em tempo real, via Serial Monitor ou LCD 16x2, com atualizações a cada 500 ms. |
| RP4  | A função de medição de volume deve ser ativada/desativada manualmente (ex.: via interface de software ou hardware) no microprocessador, funcionando como um modo temporário sem interferir nas funções principais. |
| RP5  | O microprocessador deve enviar o volume medido para um sistema externo (ex.: Controle e Monitoramento) via WiFi, com taxa de atualização de 1 segundo. |
| RP6  | O RCWL-1670 deve ser posicionado via haste/suporte removível, garantindo alinhamento vertical com a superfície da água e facilidade de instalação/remoção. |
| RP7  | O microprocessador deve ser capaz de controlar uma torneira inteligente (atuador) para fechar o fluxo de água quando o volume pré-estabelecido for atingido, com tolerância de ±2% do volume alvo. |

### 7.2. Requisitos Derivados (RDs)

| ID    | Descrição                                                                                                           |
|-------|---------------------------------------------------------------------------------------------------------------------|
| RD1.2 | O ambiente ao redor do sensor deve estar livre de obstáculos (ex.: paredes da panela, vapores densos) dentro do cone de medição do RCWL-1670 (ângulo de ~15°), para evitar reflexões espúrias. |
| RD2.1 | As dimensões fixas da panela (altura, diâmetro ou área da base) devem ser definidas com precisão de ±1 mm, para garantir o cálculo de volume com erro ≤ ±2%. |
| RD2.2 | O microprocessador deve compensar a velocidade do som (usada no cálculo de distância) com base na temperatura ambiente (ex.: 20–40°C), para manter o erro de volume ≤ ±2%. |
| RD3.1 | O microprocessador deve suportar conexão com um LCD 16x2 (via I2C ou paralelo) para exibir o volume, usando pinos disponíveis sem conflito com o RCWL-1670. |
| RD4.1 | O microprocessador deve implementar uma interface via software ou hardware (ex.: botão, comando WiFi, ou detecção de conexão do sensor) para ativar/desativar o modo de medição de volume, com debounce de 50 ms para evitar falsos acionamentos. |
| RD6.1 | O suporte do RCWL-1670 deve manter o sensor alinhado verticalmente com desvio máximo de ±2° em relação à superfície da água, mesmo com vibrações leves. |
| RD6.2 | O conjunto (sensor RCWL-1670, placa do microprocessador, conexões e fios) deve ter proteção IP67 contra umidade e respingos, usando conectores selados, caixa selada e fios impermeáveis. |
| RD6.3 | O suporte do RCWL-1670 deve ser resistente à umidade e corrosão, usando materiais como aço inoxidável 316 ou alumínio anodizado, para operar em ambiente úmido sem degradação. |
| RD7.1 | O microprocessador deve reservar pelo menos 1 pino digital para controlar a torneira inteligente, com corrente suficiente (ex.: via relé ou driver) para acionamento. |

## 8. Testes Propostos

### 8.1. Tabela de Testes

| Teste   | Descrição Breve                                                                 | Requisitos Cobertos      |
|---------|--------------------------------------------------------------------------------|--------------------------|
| T0.1.1  | Inicializa o RCWL-1670 e verifica funcionamento básico                          | RP1                      |
| T0.1.2  | Testa a medição de distância com precisão de ±1 cm                              | RP1, RD1.2               |
| T0.1.3  | Calcula o volume com base na distância e dimensões fixas da panela              | RP2, RD2.1, RD2.2        |
| T0.2    | Exibe o volume calculado em um LCD 16x2                                        | RP3, RD3.1               |
| T0.3    | Ativa/desativa o modo temporário de medição via interface SW/HW                | RP4, RD4.1               |
| T1.1    | Envia o volume medido via WiFi para um sistema externo                         | RP5                      |
| T1.2    | Verifica a estabilidade, alinhamento e resistência à umidade do suporte        | RP6, RD6.1, RD6.3        |
| T1.3    | Verifica a proteção IP67 do conjunto (sensor, placa, conexões)                 | RD6.2                    |
| T2.1    | Simula o controle de uma torneira inteligente ao atingir o volume alvo          | RP7, RD7.1               |
| T3.1    | Integra a medição de volume com Controle e Monitoramento (exibição e WiFi)      | RP3, RP5                 |
| T4.1    | Valida o sistema completo (medição, cálculo, exibição, WiFi) em uma panela real | RP1, RP2, RP3, RP5       |

### 8.2. Descrição Detalhada dos Testes

1. **T0.1.1: Inicialização do RCWL-1670**
   - **Requisito**: RP1
   - **Descrição**: Verifica se o sensor RCWL-1670 é inicializado corretamente pelo microprocessador, confirmando funcionamento básico.
   - **Setup**:
     - Conectar RCWL-1670 ao microprocessador: VCC a 3.3V/5V, GND, TRIG a GPIO 5, ECHO a GPIO 18.
     - Alimentar microprocessador via USB ou fonte 5V.
     - Código com biblioteca `NewPing` para inicializar o sensor e verificar comunicação.
   - **Resultados Esperados**:
     - Serial Monitor: "RCWL-1670 inicializado com sucesso".
     - Sensor responde a comandos básicos (ex.: ping inicial), sem erros de timeout.

2. **T0.1.2: Leitura de Distância com RCWL-1670**
   - **Requisito**: RP1, RD1.2
   - **Descrição**: Testa a medição de distância em um ambiente controlado, garantindo precisão de ±1 cm no intervalo de 5–75 cm.
   - **Setup**:
     - Posicionar RCWL-1670 a 50 cm de uma superfície plana (ex.: tampa da panela).
     - Garantir área livre de obstáculos no cone de medição (~15°).
     - Código para ler distância a cada 500 ms usando `NewPing`.
   - **Resultados Esperados**:
     - Serial Monitor: "Distância: [valor] cm" (ex.: 50.0 ± 1 cm).
     - Testar em 3 distâncias (ex.: 10 cm, 50 cm, 70 cm) com erro ≤ ±1 cm.
     - Nenhuma leitura inválida (ex.: 0 cm ou > 75 cm) em ambiente limpo.

3. **T0.1.3: Cálculo de Volume**
   - **Requisito**: RP2, RD2.1, RD2.2
   - **Descrição**: Calcula o volume com base na distância medida e dimensões fixas da panela, com compensação de temperatura.
   - **Setup**:
     - Configurar dimensões fixas da panela no código (ex.: altura 40 cm, área da base 500 cm², a definir).
     - Usar potenciômetro no pino A0 para simular temperatura (20–40°C).
     - Posicionar RCWL-1670 a 30 cm da base (simulando 10 cm de água).
     - Código para calcular volume: `volume = área_base * (altura_panela - distância)`.
   - **Resultados Esperados**:
     - Serial Monitor: "Volume: [valor] L" (ex.: 5.0 L ± 2% para 10 cm de altura).
     - Testar com 3 alturas (ex.: 10 cm, 20 cm, 30 cm) e verificar erro ≤ ±2%.
     - Compensação de temperatura aplicada (ex.: ajuste de 0.6 m/s por °C).

4. **T0.2: Exibição de Volume no LCD**
   - **Requisito**: RP3, RD3.1
   - **Descrição**: Exibe o volume calculado em um LCD 16x2 conectado ao microprocessador.
   - **Setup**:
     - Conectar LCD 16x2 ao microprocessador (ex.: I2C com SDA a GPIO 21, SCL a GPIO 22, ou paralelo com pinos 12, 11, 5, 4, 3, 2).
     - Configurar RCWL-1670 como em T0.1.2.
     - Código para exibir volume a cada 500 ms usando biblioteca `LiquidCrystal` ou `LiquidCrystal_I2C`.
   - **Resultados Esperados**:
     - LCD: Linha 1: "Volume:", Linha 2: "[valor] L" (ex.: 5.0 L).
     - Serial Monitor: Mesmo valor exibido no LCD, com atualizações a cada 500 ms.

5. **T0.3: Ativação do Modo Temporário**
   - **Requisito**: RP4, RD4.1
   - **Descrição**: Testa a ativação/desativação do modo de medição de volume via interface de software ou hardware (ex.: botão, comando WiFi, ou detecção de conexão do sensor).
   - **Setup**:
     - Conectar botão ao GPIO 4 (pull-up interno) ou configurar detecção de sensor (ex.: monitorar tensão no pino ECHO).
     - Configurar RCWL-1670 e LCD como em T0.2.
     - Código para alternar modo (medição vs. inativo) com debounce de 50 ms ou detecção de conexão do sensor.
   - **Resultados Esperados**:
     - Pressionar botão/conectar sensor: LCD mostra "Modo: Medição" e exibe volume.
     - Pressionar novamente/desconectar: LCD mostra "Modo: Inativo" e para medições.
     - Serial Monitor: "Modo alterado: [Medição/Inativo]".
     - Sem falsos acionamentos (ex.: devido a ruído no botão).

6. **T1.1: Comunicação WiFi do Volume**
   - **Requisito**: RP5
   - **Descrição**: Envia o volume medido via WiFi para um sistema externo (ex.: Controle e Monitoramento).
   - **Setup**:
     - Configurar RCWL-1670 e LCD como em T0.2.
     - Conectar microprocessador a uma rede WiFi (SSID e senha no código).
     - Código para enviar volume a cada 1 s via UDP ou HTTP (ex.: para um servidor ou Serial Monitor em outro dispositivo).
   - **Resultados Esperados**:
     - Serial Monitor: "WiFi conectado, IP: [endereço]" e "Volume enviado: [valor] L".
     - Sistema externo recebe volume com latência < 100 ms e sem perdas significativas.

7. **T1.2: Validação do Suporte Temporário**
   - **Requisito**: RP6, RD6.1, RD6.3
   - **Descrição**: Verifica a estabilidade, alinhamento e resistência à umidade/corrosão do suporte removível do RCWL-1670.
   - **Setup**:
     - Montar RCWL-1670 em haste removível (ex.: aço inoxidável 316), posicionada a 50 cm da água.
     - Simular vibrações leves (ex.: tocar a haste manualmente) e exposição à umidade (ex.: borrifar água).
     - Código para medir distância a cada 500 ms.
   - **Resultados Esperados**:
     - Distância medida: 50.0 ± 1 cm, mesmo com vibrações.
     - Alinhamento visual: Desvio ≤ ±2° da vertical.
     - Suporte sem sinais de corrosão após exposição à umidade (inspeção visual).

8. **T1.3: Validação da Proteção IP67**
   - **Requisito**: RD6.2
   - **Descrição**: Verifica se o conjunto (sensor RCWL-1670, placa do microprocessador, conexões, fios) atende à proteção IP67 contra umidade e respingos.
   - **Setup**:
     - Montar o sistema completo (RCWL-1670, microprocessador em caixa selada, conectores selados, fios impermeáveis).
     - Expor o sistema a respingos de água (simulando mostura) e imersão temporária (1 m por 30 min).
     - Código para medir distância continuamente durante o teste.
   - **Resultados Esperados**:
     - Sistema opera normalmente após exposição (distância: 50.0 ± 1 cm).
     - Nenhuma infiltração de água na caixa ou conectores (inspeção visual).

9. **T2.1: Controle Simulado de Torneira Inteligente**
   - **Requisito**: RP7, RD7.1
   - **Descrição**: Simula o controle de uma torneira inteligente (ex.: válvula solenóide) que fecha ao atingir um volume pré-estabelecido.
   - **Setup**:
     - Conectar LED ou relé ao GPIO 15 para simular torneira.
     - Configurar RCWL-1670 e LCD como em T0.2.
     - Definir volume alvo (ex.: 10 L) no código.
     - Código para desligar LED/relé quando volume ≥ alvo.
   - **Resultados Esperados**:
     - LCD: Mostra volume em tempo real.
     - Quando volume ≥ 10 L: LED/relé desliga (torneira "fecha").
     - Serial Monitor: "Volume alvo atingido: 10 L, torneira fechada".
     - Tolerância: Volume final dentro de ±2% (ex.: 10.0 ± 0.2 L).

10. **T3.1: Integração com Controle e Monitoramento**
    - **Requisito**: RP3, RP5
    - **Descrição**: Integra a medição de volume com a função **Controle e Monitoramento** (ex.: exibição no LCD e envio via WiFi).
    - **Setup**:
      - Configurar RCWL-1670, LCD e WiFi como em T1.1.
      - Usar microprocessador de **Controle e Monitoramento** (se reutilizado).
      - Código para enviar volume via WiFi e exibir no LCD do sistema (ex.: adaptar T1.3 de Controle e Monitoramento).
    - **Resultados Esperados**:
      - LCD de **Controle e Monitoramento**: Mostra "Volume Panela: [valor] L".
      - Serial Monitor: Confirma envio/recebimento do volume via WiFi.
      - Integração sem conflitos com outras funções (ex.: monitoramento de temperatura).

11. **T4.1: Validação Sistêmica do Volume**
    - **Requisito**: RP1, RP2, RP3, RP5
    - **Descrição**: Testa o sistema completo (medição, cálculo, exibição, WiFi) em uma panela real.
    - **Setup**:
      - Montar RCWL-1670 em suporte, acima de uma panela com dimensões fixas (ex.: altura 40 cm, área da base 500 cm², a definir).
      - Conectar LCD e configurar WiFi.
      - Encher a panela lentamente com água (ex.: 5 L, 10 L, 15 L).
      - Código para medir, calcular, exibir e enviar volume.
    - **Resultados Esperados**:
      - LCD e Serial Monitor: Mostram volume com erro ≤ ±2% (ex.: 10.0 ± 0.2 L).
      - Sistema externo: Recebe volume via WiFi com latência < 100 ms.
      - Funcionamento contínuo durante o enchimento (ex.: 5 minutos).

## 9. Próximos Passos

### 9.1. Análise de Impacto
Revisar projeto principal para incluir nova função, RPs, RDs, testes, BOM, matriz de rastreabilidade e cobertura e demais documentos relacionados.

### 9.2. Validação
Revisar requisitos e testes para ajustes - se necessário.

### 9.3. Implementação
- Desenvolver códigos para os 11 testes, no formato das funções existentes.
- Prototipar o suporte (ex.: aço inoxidável) e a caixa selada para testes de umidade.

### 9.4. Integração
- Planejar integração com **Controle e Monitoramento** e outras funções.
- Especificar a torneira inteligente (ex.: válvula solenóide) para testes futuros.

Este white paper fornece uma base sólida para a nova função, pronta para refinamento e implementação.