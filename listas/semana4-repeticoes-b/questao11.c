#include <stdio.h>
#include <stdbool.h>

#define N 4

//Função para verificar se é seguro colocar rainha na posição:
bool seguro(int tabuleiro[N][N], int linha, int col) {
    int i, j;
    
    //Verificando mesma coluna acima:
    for (i = 0; i < linha; i++) {
        if (tabuleiro[i][col] == 1) {
            return false;
        }
    }
    
    //Verificando diagonal superior esquerda:
    for (i = linha, j = col; i >= 0 && j >= 0; i--, j--) {
        if (tabuleiro[i][j] == 1) {
            return false;
        }
    }
    
    //Verificando diagonal superior direita:
    for (i = linha, j = col; i >= 0 && j < N; i--, j++) {
        if (tabuleiro[i][j] == 1) {
            return false;
        }
    }
    
    return true;
}

//Função recursiva de backtracking:
void resolver4Rainhas(int tabuleiro[N][N], int linha, int *solucoes) {
    // Se todas as rainhas foram colocadas
    if (linha == N) {
        (*solucoes)++;
        
        //Imprimindo o tabuleiro:
        printf("Solucao %d:\n", *solucoes);
        printf("  a b c d\n");
        for (int i = 0; i < N; i++) {
            printf("%d ", i + 1);
            for (int j = 0; j < N; j++) {
                if (tabuleiro[i][j] == 1) {
                    printf("R ");
                } else {
                    printf(". ");
                }
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    
    //Tentando colocar rainha em cada coluna da linha atual:
    for (int col = 0; col < N; col++) {
        if (seguro(tabuleiro, linha, col)) {
            // Coloca rainha
            tabuleiro[linha][col] = 1;
            
            //Recursão para próxima linha
            resolver4Rainhas(tabuleiro, linha + 1, solucoes);
            
            //Backtracking - remove rainha
            tabuleiro[linha][col] = 0;
        }
    }
}

int main() {
    int tabuleiro[N][N] = {0};  // 0 = vazio, 1 = rainha
    int solucoes = 0;
    
    printf("Solucoes para o problema das 4 rainhas (4x4):\n\n");
    
    resolver4Rainhas(tabuleiro, 0, &solucoes);
    
    printf("Total de solucoes encontradas: %d\n", solucoes);
    
    return 0;
}