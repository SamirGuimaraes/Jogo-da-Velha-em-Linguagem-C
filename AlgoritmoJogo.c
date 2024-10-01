#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char matrizJogo[3][3];
char jogador1[50], jogador2[50];
char jogadorComX[50], jogadorComO[50];
char caracter;

void criarMatriz(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            matrizJogo[i][j] = ' ';
        }
    }
}

void imprimirMatriz(){
    int a = 1, b = 1;
    for (int i = 0; i < 3; i++){
        b = 1;
        for (int j = 0; j < 3; j++){
            if (matrizJogo[i][j] == 'X' || matrizJogo[i][j] == 'O'){
                printf(" %c  ", matrizJogo[i][j]);
            }
            // Caso contrário, imprime a posição (como "11", "12", etc.)
            else {
                printf(" %d%d ", a, b);
            }
            b++;
        }
        printf("\n");
        a++;
    }
}

void inserirJogada(char *jogador, char simbolo){
    int linha, coluna;
    printf("%s, informe a linha que deseja marcar o %c: ", jogador, simbolo);
    scanf("%d", &linha);
    while(linha < 1 || linha > 3){
        printf("%s, insira apenas números entre 1 a 3: ", jogador);
        scanf("%d", &linha);
    }

    printf("%s, informe a coluna que deseja marcar o %c: ", jogador, simbolo);
    scanf("%d", &coluna);
    while(coluna < 1 || coluna > 3){
        printf("%s, insira apenas números entre 1 a 3: ", jogador);
        scanf("%d", &coluna);
    }

    linha--;
    coluna--;
    // Verifica se a posição está ocupada
    if (matrizJogo[linha][coluna] == 'X' || matrizJogo[linha][coluna] == 'O'){
        printf("\nPosição já ocupada! Tente novamente.\n");
        inserirJogada(jogador, simbolo);  // Chama a função novamente se a posição estiver ocupada
    } else {
        matrizJogo[linha][coluna] = simbolo;  // Marca a posição com o símbolo
    }
}

void inserirJogador(){

    printf("Qual o nome do primeiro jogador: ");
    scanf("%s", jogador1);
    printf("Qual o nome do segundo jogador: ");
    scanf("%s", jogador2);

    printf("\nSejam bem-vindos ao Jogo da Velha \nJogador 1- %s \nJogador 2- %s", jogador1, jogador2);
    printf("\n");
}

int decisaoX_O() {
    srand(time(NULL));   // S deve ser chamada uma única vez
    int r = rand() % 2;  // Gera 0 ou 1 aleatoriamente
    return r;
}

int posicaoPreenchida(int i, int j){
    if (matrizJogo[i][j] == 'X' || matrizJogo[i][j] == 'O')
        return 1;
    return 0;
}

int vitoriaLinha(){
    int contador = 1;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            if (posicaoPreenchida(i, j) && (matrizJogo[i][j] == matrizJogo[i][j+1]))
                contador++;
        }
        if (contador == 3)
            return 1;
        contador = 1;
    }
    return 0;
}

int vitoriaColuna(){
    int contador;
    for (int j = 0; j < 3; j++) { // Agora j percorre as colunas
        contador = 1; // Reinicia igual para cada coluna
        for (int i = 0; i < 2; i++) { // Percorre as linhas, mas limita até a penúltima
            if (posicaoPreenchida(i, j) && matrizJogo[i][j] == matrizJogo[i+1][j])
                contador++;
        }
        if (contador == 3)
            return 1;
    }
    return 0;
}

int vitoriaDiagPrincipal(){
    int contador = 1;
    for(int i = 0; i < 2; i++){
        if(posicaoPreenchida(i, i) && matrizJogo[i][i] == matrizJogo[i+1][i+1])
            contador++;
    }
     if (contador == 3)
            return 1;
    return 0;
}

int vitoriaDiagSecundaria(){
    int contador = 1;
    for(int i = 0; i < 2; i++){
        if(posicaoPreenchida(i,3 - i - 1) && matrizJogo[i+1][3 - i - 2] == matrizJogo[i][3 - i - 1])
            contador++;
    }
    if (contador == 3)
            return 1;
    return 0;
}

int verificaVitoria(){
  int resultadoFinal = 0;

  if (vitoriaLinha())
    resultadoFinal = 1;
  else if (vitoriaColuna())
    resultadoFinal = 1;
  else if (vitoriaDiagPrincipal())
    resultadoFinal = 1;
  else if (vitoriaDiagSecundaria())
    resultadoFinal = 1;

  return resultadoFinal;
}

void inicializaJogo(){
  criarMatriz();
  inserirJogador();

  int r = decisaoX_O();
  if (r == 0) {
      strcpy(jogadorComX, jogador1);
      strcpy(jogadorComO, jogador2);
  } else {
      strcpy(jogadorComX, jogador2);
      strcpy(jogadorComO, jogador1);
  }
  printf("\nApós um sorteio aleatório, foi decidido que:\n");
  printf("%s jogar com X e %s jogar com O.\n", jogadorComX, jogadorComO);
  printf("E por regra o primeiro a jogar será o jogador X.\n");
}

void executaJogo(){
  printf("\nSeja Bem-Vindo ao Jogo da Velha\n");
  imprimirMatriz();
  int count = 0;
  int vencedor = 0;

  while(count < 9){
      inserirJogada(jogadorComX, 'X'); // Substituição da chamada
      if (verificaVitoria()){
        imprimirMatriz();
        printf("Vitória do jogador %s\n", jogadorComX);
        vencedor = 1;
        break;
      }

      imprimirMatriz();
      count++;

      // Verifica se ainda há espaço para o jogador O
      if (count == 9) break;
      inserirJogada(jogadorComO, 'O'); // Substituição da chamada
      if (verificaVitoria()){
        imprimirMatriz();
        printf("Vitória do jogador %s\n", jogadorComO);
        vencedor = 1;
        break;
      }
      imprimirMatriz();
      count++;
    }

    if (count == 9 && vencedor == 0)
      printf("VELHA! O jogo terminou em empate!\n");
}

int main()
{
    int opcao;

    do{
      printf("\nJogo da Velha \nDigite 1 para iniciar jogo. \nDigite 2 para interromper procedimento.\n");
      scanf("%d", &opcao);

      switch(opcao){
        case 1:
          inicializaJogo();
          executaJogo();
          break;
        case 2:
          printf("Abortando procedimento abruptamente.");
          break;
        default:
          printf("Informe uma opção correta.\n");
          break;
      }
    }while(opcao != 2);

    return 0;
}
