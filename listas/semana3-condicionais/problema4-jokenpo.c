#include <stdio.h>
#include <string.h> 
#include <ctype.h>

int main() {
    //Definindo as variáveis
    char jogada1[2], jogada2[2];

    //Jogadas dos jogadores
    char pedra[] = "P";
    char papel[] = "A";
    char tesoura[] = "T";

    //Recebe os dados do usuário
    printf("Insira a jogada do jogador 1(P para pedra, A para papel, T para tesoura): ");
    scanf(" %1s", &jogada1);
    printf("Insira a jogada do jogador 2(P para pedra, A para papel, T para tesoura): ");
    scanf(" %1s", &jogada2);

    //Condições para o jogador vencer
    //Validação das jogadas
    if ((strcmp(jogada1, pedra) != 0 && strcmp(jogada1, papel) != 0 && strcmp(jogada1, tesoura) != 0) ||
        (strcmp(jogada2, pedra) != 0 && strcmp(jogada2, papel) != 0 && strcmp(jogada2, tesoura) != 0)) {
        printf("Jogada inválida!\n");
        return 0;
    }

    else {
        //Condições para o jogador 1 vencer
        if (strcmp(jogada1, pedra) == 0 && strcmp(jogada2, tesoura) == 0) {
            printf("O jogador 1 vence.\n");
        }
        else if (strcmp(jogada1, tesoura) == 0 && strcmp(jogada2, papel) == 0) {
            printf("O jogador 1 vence.\n");
        }
        else if (strcmp(jogada1, papel) == 0 && strcmp(jogada2, pedra) == 0) {
            printf("O jogador 1 vence.");
        }

        //Condições para o jogador 2 vencer
        else if (strcmp(jogada2, pedra) == 0 && strcmp(jogada1, tesoura) == 0) {
            printf("O jogador 2 vence.\n");
        }
        else if (strcmp(jogada2, tesoura) == 0 && strcmp(jogada1, papel) == 0) {
            printf("O jogador 2 vence.");
        }
        else if (strcmp(jogada2, papel) == 0 && strcmp(jogada1, pedra) == 0) {
            printf("O jogador 2 vence.");
        }
        //Caso de empate
        else if (strcmp(jogada1, jogada2) == 0) {
            printf("Houve empate.");
        }
    }
    
    return 0;

}