# T4_1_Sistema_Completo_Controle_Fermentacao  
**Função**: Controle de Fermentação  
**Artifact ID**: b2366c19-6651-4127-8413-9642773892a3  

## Metadados  
- **Versão**: v1.0.1  
- **Data**: 2025-04-20  
- **Iteração**: 34  
- **Status**: Pendente  
- **Requisitos**: RD8.1 (Sistema Completo)  
- **Código Associado**: [T4_1_Sistema_Completo_Controle_Fermentacao.ino](./T4_1_Sistema_Completo_Controle_Fermentacao.ino)  
- **Diretório**: docs/V1.01/codes/Controle_de_Fermentacao/T4_1  

## Descrição  
Este teste integra leitura de temperatura (DS18B20), corrente (INA219), controle do relé SSR-10DA e envio de dados via WiFi, simulando um sistema completo de controle de fermentação.  

## Setup  
- Conectar o Arduino R4 Connect via USB ou fonte 7-12V.  
- Conectar o DS18B20:  
  - Dados (DQ) ao pino 10, resistor pull-up 4.7 kΩ entre DQ e VCC (3.3V/5V).  
  - VCC ao 3.3V/5V, GND ao GND.  
- Conectar o INA219:  
  - SDA ao pino A4, SCL ao pino A5, VCC ao 3.3V/5V, GND ao GND.  
  - Carga de teste (ex.: resistor) em série com Vin+/Vin-.  
- Conectar o relé SSR-10DA:  
  - Terminal de controle (+) ao pino 9, (-) ao GND.  
  - Lado de carga (opcional): conectar carga (ex.: lâmpada) com alimentação externa (220V AC, com cuidado).  
- Editar o código para incluir SSID e senha WiFi.  
- Instalar bibliotecas `OneWire`, `DallasTemperature`, e `Adafruit_INA219`.  
- Carregar o sketch e abrir o Serial Monitor (9600 baud).  

## Resultados Esperados  
- Serial Monitor exibe:  
  - "Teste T4.1 - Sistema Completo Controle Fermentação Iniciado".  
  - WiFi: "WiFi conectado. IP: [ex.: 192.168.1.100]".  
  - A cada 5 segundos:  
    - Ex.: "Temperatura: 26.5 °C | Corrente: 150.0 mA | Tensão: 5.0 V".  
    - "Relé SSR-10DA: LIGADO" (se temp > 25°C) ou "DESLIGADO".  
    - "Dados enviados (simulado): Temp=26.5°C, Corrente=150.0mA".  
  - Erros: "Nenhum sensor DS18B20 encontrado!" ou "Erro: Falha ao inicializar o INA219!".  
- Carga (se conectada) liga/desliga conforme o relé.  

## Notas  
- Verificar conexões, WiFi, e alimentação se houver falhas.  
- Valida o requisito RD8.1 (sistema completo).  
- Manipular alta tensão com cuidado.  

## Lista de Artifact IDs (Verificação)  
- **Controle de Fermentação**  
  - T0.1.1: 5148934c-c09f-4088-8bb3-af49cbf142bf  
  - T0.1.2: e144b732-8ebf-4e1f-9a9a-9bd3b1808950  
  - T0.1.3: 45a0dfc9-2878-4812-ae74-3d98531f37c0  
  - T0.1.4: 0af662e9-cc12-46b7-a420-e5d147172f81  
  - T0.2: f2c4643b-0120-4bae-b32c-e3254da9b993  
  - T0.3: 0aef38a2-15df-4ff4-9265-8cc6fd8e66fd  
  - T0.4: b46a3026-f024-42e1-9ec4-8e5554588a1c  
  - T1.1: 6e0e2fa6-3fbc-4d81-994b-bebf44afbc51  
  - T1.2: 3494fc1b-d435-45d9-8628-9e1191e68234  
  - T2.1: de329107-3a66-4112-80bb-58bf0dca6b72  
  - T3.1: 890814c4-35fc-4571-9468-81340ca0be2f  
  - T4.1: b2366c19-6651-4127-8413-9642773892a3  

- **Balança de Volume**  
  - T0.1.1: a33d4101-3eb3-4b33-91e9-3b9d15b77630  
  - T0.1.2: 1571700b-b50a-4ee7-9838-20741d90120c  
  - T0.1.3: 7b9603e3-df08-4c0d-adb5-293e8ef391ca  
  - T0.1.4: de2c4e30-a29e-4173-b04d-bee48e4406c9  
  - T0.2: c0afaf04-d934-4c2c-aeac-60a0a4834fc8  
  - T0.3: c7c30809-5130-4d41-82e3-cd6817face86  
  - T1.1: d0aaeaad-fdfa-4640-9c5f-303457c7646d  
  - T1.2: 05ebee9b-151e-4bcc-bb9f-870767719e5c  
  - T2.1: 9ba4d06b-7851-43a1-bc5e-1c61f115068a  
  - T3.1: 819109a0-5a5a-47cc-a892-8ec6128f4791  

- **Densímetro Flutuante**  
  - T0.1.1: 0561d7ee-269b-4666-b230-7f8098353019  
  - T0.1.2: 22c3cdbe-3527-4688-8431-6f2114020132  
  - T0.1.3: 3b6b3d33-7492-47ad-9fa5-8edd13ec0d5e  
  - T0.1.4: 11eb892f-6a87-460c-ab94-e7e0fb92cd5b  
  - T0.2: 8790c77d-e1e4-4b5f-846a-c1865b762004  
  - T0.3: cd286597-86d8-470f-8ae3-76bf43a59a7f  
  - T0.4: c1891ed7-7286-4c61-8f79-2cdecbb355d5  
  - T0.5: 07591bc0-e90a-4f58-a1f4-1783e3f03f6b  
  - T1.1: 47c263d3-cf8a-43a6-b700-70cc4b6a0096  
  - T2.1: a189da32-e594-4f2f-bc1a-764b13f83fdf  
  - T3.1: 64c8fdd7-949e-4c77-b30a-4853866d5989  
  - T4.1: 2429e396-92e8-4a52-a58d-1c301cd69acd  
  - T4.2: fb8d96f0-58f6-4201-9cc4-dfdc3f6575ca  

- **Controle e Monitoramento**  
  - T0.1.1: 1a5148be-b003-4276-8d1e-024aa5d998c0  
  - T0.1.2: daa0f8ad-47cf-4179-beb5-b4678c7d6bec  
  - T0.1.3: 540da23e-139a-444b-8e62-ea86e2f4d580  
  - T0.2: bf32b947-f819-4d47-8c88-aff04dc64a12  
  - T0.3: 75562dd6-a594-459c-b571-14ac81de3abd  
  - T1.1: c1db1077-d4ae-4317-893e-a46a84aa957a  
  - T1.2: 06b2a889-babf-4272-a08e-406699ef7094  
  - T1.3: ea976526-9cee-47e5-974a-cf674b66368c