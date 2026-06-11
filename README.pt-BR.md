# Jogo da Velha

Este repositório hospeda o código-fonte do **Jogo da Velha** desenvolvido como parte do trabalho da unidade curricular de **Lógica de Programação** lecionada pelo Prof. Marcos G. Quiles.

### Integrantes do Grupo

| Nome Completo           |
| :---                    |
| Arthur M. Agassi        |
| Mateus G. P. Campos     |
| Matheus A. Ambrosio     |

---

## Descrição do Projeto

**Jogo da Velha** é uma aplicação interativa desenvolvida em **C** para demonstrar a aplicação de conceitos fundamentais de lógica computacional: variáveis, estruturas de controle de fluxo, matrizes e modularização através de funções.

## Funcionalidades Principais

*   **Modo Jogador vs Jogador**: Dois jogadores podem jogar alternadamente
*   **Modo Jogador vs Computador**: O jogador enfrenta o computador com IA básica
*   **Inteligência Artificial**: 
    - **Nível Básico**: Computador escolhe posição aleatória
    - **Nível Intermediário** (Bônus): Computador detecta e bloqueia ameaças
*   **Validação de Entrada**: Tratamento de erros para movimentos inválidos
*   **Interface Terminal**: Tabuleiro visual 3x3 com feedback em tempo real

---

## Tecnologias e Ferramentas

| Categoria              | Tecnologia | Descrição                                                                              |
| :---                   | :---       | :---                                                                                   |
| **Linguagem**          | C          | Linguagem de programação para implementação de lógica computacional                    |
| **Compilador**         | GCC        | Compilador padrão para C em sistemas Unix-like                                        |
| **Controle de Versão** | Git        | Sistema de controle de versão distribuído para gerenciamento do código                |

---

## Conceitos Aplicados

Conforme requisitos do projeto, o código implementa:

*   **Matrizes**: Representação do tabuleiro 3x3
*   **Laços de Repetição**: Loop principal do jogo e varredura do tabuleiro
*   **Modularização**: Divisão em funções para impressão, validação e lógica do jogo
*   **Estruturas de Controle**: Condicionais para regras e vitória

---

## Instalação e Execução

### Pré-requisitos

*   GCC ou compilador C compatível
*   Git (opcional, para clonar o repositório)

### 1. Clonar o Repositório

```bash
git clone https://github.com/mgpcampos/tic-tac-toe.git
cd tic-tac-toe/
```

### 2. Compilar o Código

```bash
gcc -o jogo main.c
```

### 3. Executar o Jogo

```bash
./jogo
```

No Windows:
```bash
jogo.exe
```

---

## Como Jogar

1. Ao iniciar, escolha o modo de jogo:
   - **1**: Jogador vs Jogador
   - **2**: Jogador vs Computador

2. Depois, selecione o nível de dificuldade:
   - **1**: Nível Básico (Movimentos Aleatórios)
   - **2**: Nível Intermediário (Bloqueia Ameaças)

3. O tabuleiro é numerado de 1 a 9:
   ```
   1 | 2 | 3
   ---------
   4 | 5 | 6
   ---------
   7 | 8 | 9
   ```

4. Os jogadores alternam turnos, inserindo o número da posição desejada
5. O jogo termina em vitória ou empate

---

## Estrutura do Projeto

```
tic-tac-toe/
├── main.c              # Código-fonte principal do jogo
├── LICENSE             # Licença do projeto
├── README.md           # Documentação em inglês
├── README.pt-BR.md     # Documentação em português
└── .gitignore          # Arquivo Git para ignorar arquivos compilados
```