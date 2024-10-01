# Jogo da Velha em C

Este projeto implementa um **Jogo da Velha** utilizando a linguagem C, jogado por dois jogadores no terminal. O código foi desenvolvido para gerenciar o fluxo do jogo, garantir que as regras sejam seguidas e detectar quando ocorre uma vitória ou empate.

## Funcionalidades

- Dois jogadores podem participar do jogo.
- O jogador que usar "X" começa jogando, e o outro usará "O".
- O código gerencia a alternância de turnos e verifica as condições de vitória ou empate.
- O jogo termina assim que um jogador ganha ou não houver mais jogadas possíveis.

## Estrutura do Código

### Variáveis Globais

O código define as seguintes variáveis globais:

- `char matrizJogo[3][3]`: Matriz 3x3 que representa o tabuleiro do Jogo da Velha.
- `char jogador1[50], jogador2[50]`: Nomes dos jogadores.
- `char jogadorComX[50], jogadorComO[50]`: Armazena qual jogador está jogando com "X" e qual com "O".
- `char caracter`: Variável auxiliar para os turnos (não utilizada diretamente).

### Funções

#### 1. `void criarMatriz()`

Inicializa a matriz do jogo com espaços em branco (`' '`) para indicar que todas as posições estão vazias.

#### 2. `void imprimirMatriz()`

Imprime a matriz atual do jogo no terminal. As posições disponíveis são exibidas como números correspondentes às coordenadas (exemplo: "11", "12", etc.), enquanto as posições marcadas por "X" ou "O" são exibidas com o respectivo símbolo.

#### 3. `void inserirX()` e `void inserirO()`

Essas funções permitem que os jogadores marquem suas jogadas no tabuleiro. Elas:
- Solicitam ao jogador a linha e coluna onde deseja marcar o "X" ou "O".
- Verificam se a posição escolhida está dentro dos limites e se já não foi preenchida.
- Caso a posição já esteja ocupada, solicita ao jogador que tente novamente.

#### 4. `void inserirJogador()`

Solicita o nome dos dois jogadores e exibe uma mensagem de boas-vindas.

#### 5. `int decisaoX_O()`

Gera um valor aleatório (0 ou 1) para decidir qual jogador ficará com "X" e qual ficará com "O". Esta função usa `rand()` para fazer o sorteio.

#### 6. `int posicaoPreenchida(int i, int j)`

Verifica se uma posição específica da matriz do jogo já foi preenchida com "X" ou "O". Retorna `1` se estiver preenchida e `0` se estiver vazia.

#### 7. Funções de Verificação de Vitória

- **`int vitoriaLinha()`**: Verifica se todas as posições de uma mesma linha têm o mesmo símbolo (ou "X" ou "O") e estão preenchidas.
- **`int vitoriaColuna()`**: Verifica se todas as posições de uma mesma coluna têm o mesmo símbolo.
- **`int vitoriaDiagPrincipal()`**: Verifica se a diagonal principal (da posição 00 até 22) tem todos os mesmos símbolos.
- **`int vitoriaDiagSecundaria()`**: Verifica se a diagonal secundária (da posição 02 até 20) tem todos os mesmos símbolos.

Essas funções retornam `1` se uma condição de vitória for encontrada e `0` caso contrário.

#### 8. `int verificaVitoria()`

Essa função é chamada após cada jogada para verificar se um jogador venceu. Ela utiliza as funções de verificação de linha, coluna e diagonais. Se uma dessas funções retornar `1`, o jogo termina com uma vitória.

#### 9. `void inicializaJogo()`

- Inicializa o tabuleiro do jogo.
- Solicita os nomes dos jogadores.
- Decide aleatoriamente qual jogador será "X" e qual será "O".
- Exibe uma mensagem informando qual jogador começará a partida.

#### 10. `void executaJogo()`

Executa o loop principal do jogo:
- Alterna entre os jogadores para marcar suas jogadas no tabuleiro.
- Após cada jogada, verifica se houve vitória ou empate.
- Caso haja um vencedor ou um empate (todas as 9 posições preenchidas sem vencedor), o jogo termina.

#### 11. `int main()`

O ponto de entrada do programa. Ele exibe o menu inicial e permite ao usuário:
- Iniciar o jogo.
- Encerrar o programa.

O jogo é reiniciado enquanto o jogador não escolher a opção de sair.
