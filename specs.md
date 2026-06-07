# Projeto de Lógica de Programação

# Prof. Marcos Quiles

# 1. Informações Gerais

```
● Grupo: Máximo de 3 Pessoas
● Data de Entrega: 9 de junho de 2026
● Apresentação: 9 e 11 de junho de 2026
● O apresentador será sorteado no dia da apresentação, ou seja, todos devem estar
aptos a apresentar o trabalho. A nota será dada a partir da apresentação do código.
```
# 2. Objetivo do Trabalho

O objetivo deste projeto é consolidar os conhecimentos de lógica computacional através da
construção de um jogo interativo no terminal. Durante o desenvolvimento, os alunos deverão
aplicar na prática os conceitos fundamentais da disciplina: declaração de variáveis, estruturas
de controle de fluxo (condicionais e laços de repetição), manipulação de vetores e matrizes,
além da modularização do código através de funções.

# 3. Escopo dos Projetos

Cada equipe deverá escolher e implementar **apenas uma** das opções de jogos descritas
abaixo.

## Opção 1: Jogo da Velha com "Modo Computador" (IA Básica)

Desenvolver o clássico Jogo da Velha (tabuleiro 3x3) com a funcionalidade de permitir partidas
contra a máquina.
● **Representação:** Utilizar uma matriz 3x3 para representar o estado do tabuleiro.
● **Modos de Jogo:** O menu inicial deve permitir ao usuário escolher entre "Jogador vs
Jogador" e "Jogador vs Computador".


```
● Inteligência da Máquina:
○ Nível Básico (Obrigatório): O computador escolhe uma posição vazia no tabuleiro
de forma totalmente aleatória, utilizando funções de geração de números
randômicos.
○ Nível Intermediário (Bônus): O computador varre o tabuleiro e verifica se o jogador
está prestes a vencer (duas peças alinhadas e uma casa vazia). Se sim, ele realiza
a jogada defensiva para bloquear.
● Validações: O programa deve tratar erros de entrada, impedindo jogadas em posições já
ocupadas ou coordenadas fora dos limites da matriz.
```
## Opção 2: Batalha Naval

Desenvolver uma versão para um jogador do jogo de Batalha Naval (Jogador vs Tabuleiro).
● **Representação:** Utilizar duas matrizes bidimensionais (por exemplo, 8x8 ou 10x10). A
primeira matriz será o "gabarito" (onde os navios estão ocultos). A segunda matriz
representará o radar do jogador (a tela exibida, mostrando os locais onde houve tiros na
água, acertos e áreas ainda não exploradas).
● **Posicionamento da Frota:** O programa deve iniciar distribuindo um conjunto de navios
na matriz oculta. Isso pode ser feito de forma fixa ou, de preferência, de forma aleatória.
(Exemplo de frota: 1 navio de 3 posições e 3 submarinos de 1 posição).
● **Mecânica de Tiro:** Através de um laço de repetição, o jogador informa as coordenadas
(linha e coluna) do ataque. O sistema cruza os dados com o gabarito, informa se houve
acerto ou erro, e atualiza a matriz do radar em tela.
● **Condição de Encerramento:** O jogo termina com vitória quando o jogador afundar todas
as posições da frota, ou com derrota se esgotar um limite pré-determinado de tentativas.

# 4. Requisitos Técnicos Obrigatórios

O código-fonte entregue deverá demonstrar a aplicação direta dos seguintes conceitos:
**Conceito Exigido Aplicação Esperada no Projeto**
Matrizes e Vetores Estruturação do estado global do jogo
(tabuleiros, mapas e radares).


```
Conceito Exigido Aplicação Esperada no Projeto
Laços de Repetição Manutenção do loop principal do jogo
(turnos), varredura do tabuleiro para
verificação de condições de vitória e
validação de entradas contínuas.
Modularização (Funções) Divisão do código em módulos lógicos.
Exigência de funções para: imprimir o
tabuleiro, ler e validar a jogada, e verificar o
fim do jogo. O bloco main deve atuar apenas
como orquestrador.
```
# 5. Critérios de Avaliação

```
● Execução e Corretude: O jogo funciona de acordo com as regras estabelecidas? O
programa lida bem com entradas incorretas sem travar?
● Estruturação do Código: O código está bem modularizado? Foram evitadas
redundâncias estruturais e blocos de código excessivamente longos?
● Boas Práticas: Os nomes de variáveis e funções são descritivos? O código está
devidamente indentado? A lógica de passagem por referência foi aplicada corretamente?
```

