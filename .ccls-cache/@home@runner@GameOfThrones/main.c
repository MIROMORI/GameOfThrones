#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  srand(time(NULL));
  char westeros[10][10];
  int snowLife = 100;
  int cerseiLife = 100;
  int nightKingLife = 200;
  int enemies = 20;
  int obstacles = 10;
  int potions = 10;
  int healPerPotion = 5;
  //indice da matriz em que o snow se localiza nos eixos x e y
  int xSnowLocation = 0;
  int ySnowLocation = 0;

  //preenche a matriz do cenario(westeros) com "."
  for(int linha = 0; linha < 10; linha++){
    for(int coluna = 0; coluna < 10; coluna++){
      westeros[linha][coluna] = '.';
    }
  }
  //insere os personagens no cenario
  westeros[0][0] = 'w';
  westeros[4][4] = 'c';
  westeros[9][9] = 'n';
  //printa o conteudo da matriz westeros
  for(int linha = 0; linha < 10; linha++){
    printf("\n");
    for(int coluna = 0; coluna < 10; coluna++){
      printf("%c", westeros[linha][coluna]);
    }
  }
  //logica do jogo
  do{
    char tecla;
    printf("\nUse WASD para mover snow: ");
    scanf("%c", &tecla);
    switch(tecla){
     case 'w':
       //colisao com o cenario
       if(ySnowLocation > 0){
         westeros[ySnowLocation][xSnowLocation] = '.';
         ySnowLocation--;
         westeros[ySnowLocation][xSnowLocation] = 'w';
       }
       //printa o cenario 
       for(int linha = 0; linha < 10; linha++){
         printf("\n");
         for(int coluna = 0; coluna < 10; coluna++){
           printf("%c", westeros[linha][coluna]);
         }
       }
      break;

      case 's':
       if(ySnowLocation < 9){
         westeros[ySnowLocation][xSnowLocation] = '.';
         ySnowLocation++;
         westeros[ySnowLocation][xSnowLocation] = 'w';
       }
       for(int linha = 0; linha < 10; linha++){
         printf("\n");
         for(int coluna = 0; coluna < 10; coluna++){
           printf("%c", westeros[linha][coluna]);
         }
       }
      break;

      case 'a':
       if(xSnowLocation > 0){
         westeros[ySnowLocation][xSnowLocation] = '.';
         xSnowLocation--;
         westeros[ySnowLocation][xSnowLocation] = 'w';
       }
       for(int linha = 0; linha < 10; linha++){
         printf("\n");
         for(int coluna = 0; coluna < 10; coluna++){
           printf("%c", westeros[linha][coluna]);
         }
       }
      break;

      case 'd':
       if(xSnowLocation < 9){
         westeros[ySnowLocation][xSnowLocation] = '.';
         xSnowLocation++;
         westeros[ySnowLocation][xSnowLocation] = 'w';
       }
       for(int linha = 0; linha < 10; linha++){
         printf("\n");
         for(int coluna = 0; coluna < 10; coluna++){
           printf("%c", westeros[linha][coluna]);
         }
       }
      break;
    }
    //Interact with cersei
    //verifica se snow encontrou cersei, só é executado se o hp de cersei for diferente que zero(para evitar que o código fique se repetindo)
    if(xSnowLocation == 4 && ySnowLocation == 4 && cerseiLife != 0){
      int valoresPersuasao[5];
      int persuasoesMaioresIguaisASeis = 0;
      printf("\nSnow chegou à Cersei");
      //roda os valores aleatorios de persuasao e verifica se snow conseguiu persuadir cersei
      for(int tentativas = 0; tentativas < 5; tentativas++){
        valoresPersuasao[tentativas] = (rand() % 10) + 1;
        printf("\nPersuasao %d: %d", tentativas + 1, valoresPersuasao[tentativas]);
        if(valoresPersuasao[tentativas] >= 6){
          persuasoesMaioresIguaisASeis++;
        }
      }
      //caso snow tenha sucesso
      if(persuasoesMaioresIguaisASeis == 3){
        printf("\nSnow persuadiu Cersei a se juntar a ele. HP de Snow +100");
        cerseiLife = 0;
        snowLife += 100;
      } else{ //caso snow falhe (falta implementar a batalha)
        printf("\nSnow nao conseguiu persuadir Cersei, uma guerra começa");
      }
      
    }
  }while(snowLife > 0 && nightKingLife > 0); //finaliza quando snow ou night king morre
}