# README - Tarefa Individual

## Clock e Temporizadores - Unidade 4 | Capítulo 5 – C5O123A

Este repositório contém a implementação das atividades propostas na disciplina, utilizando o microcontrolador **Raspberry Pi Pico W** e a ferramenta **BitDogLab** para simulação.

---

## 📌 Atividade 1: Temporizador Periódico

### 🔹 Descrição
Implementação de um **semáforo** utilizando a função `add_repeating_timer_ms()` do Pico SDK. O sistema alterna entre três LEDs (vermelho, amarelo e verde), com um atraso de **3 segundos** para cada mudança de estado.

### 🔹 Requisitos
- O semáforo inicia no **vermelho**, alternando para **amarelo** e depois **verde**.
- Cada estado dura **3 segundos** antes da mudança para o próximo.
- A transição dos LEDs é implementada dentro da função `repeating_timer_callback()`.
- A cada **1 segundo**, uma mensagem é impressa na porta serial.
- Simulação realizada no **BitDogLab** com os LEDs conectados aos GPIOs **11, 12 e 13**.

### 🔹 Código
O código-fonte da Atividade 1 está disponível em [`atividade1-temporizador-periodico.c`](atividade1-temporizador-periodico\atividade1-temporizador-periodico.c).

---

## 📌 Atividade 2: Temporizador de um Disparo (One Shot)

### 🔹 Descrição
Sistema de temporização acionado por um **botão (pushbutton)**, que liga três LEDs (azul, vermelho e verde). Após o acionamento, os LEDs desligam **um por um**, a cada **3 segundos**.

### 🔹 Requisitos
- Ao pressionar o **botão**, os três LEDs acendem simultaneamente.
- Após **3 segundos**, um LED se apaga, seguido pelos outros, até desligar todos.
- Durante a execução, o botão não pode reiniciar a sequência.
- A função `turn_off_callback()` gerencia a transição dos LEDs.
- Simulação realizada no **BitDogLab** com os LEDs conectados aos GPIOs **11, 12 e 13** e o botão ao **GPIO 5**.

### 🔹 Código
O código-fonte da Atividade 2 está disponível em [`atividade2-temporizador-one-shot.c`](atividade2-temporizador-one-shot\atividade2-temporizador-one-shot.c).

---

## 🛠️ Como Executar
1. Clone o repositório:
   ```sh
   git clone https://github.com/ThiagoMachado2/tarefa-clock-temporizadores
   ```
2. Abra apenas a pasta da atividade desejada no VS Code.   
3. Compile e carregue os códigos no **VS Code** integrado com **Wokwi** e **Pico SDK**.
4. Execute a simulação no Wokwi.

---
