#include <stdio.h>

int main() {
    //Variáveis e vetores:
    int m, n; // N° de linhas e colunas, respectivamente
    //Contadores:
    int solos_cobertos = 0;
    int solos_nao_cobertos = 0;
    int irrigadores_proximos = 0;

    // Recebendo o n° de linhas e colunas da matriz:
    printf("Digite o número de linhas: ");
    scanf("%d", &m);
    if (m > 10) {
        return 0;
    }
    printf("Digite o número de colunas: ");
    scanf("%d", &n);
    if (n > 10) {
        return 0;
    }

    //Definindo a matriz com as linhas e colunas fornecidas pelo usuário:
    int setores[m][n];

    //Preenchendo a matriz com valores fornecidos pelo usuário:
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Digite um inteiro da linha %d e coluna %d: ", i+1, j+1);
            scanf("%d", &setores[i][j]);

            if (setores[i][j] >2 || setores[i][j] < 0)
            {
                return 0;
            } // Se os valores fornecidos pelo usuário forem diferentes de 0, 1 ou 2, são inválidos
        }
    }
    //Percorrendo os elementos da matriz:
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Se o elemento é um setor fértil, é verificado se há pelo menos um irrigados que cubra esse sol 
            if (setores[i][j] == 1)
            {
                if (setores[i-1][j] == 2)
                {
                    irrigadores_proximos++;
                }
                if (setores[i+1][j] == 2)
                {
                    irrigadores_proximos++;
                }
                if (setores[i][j-1] == 2)
                {
                    irrigadores_proximos++;
                }
                if (setores[i][j+1] == 2)
                {
                    irrigadores_proximos++;
                }
                // Se há pelo menos um irrigador que cobre o solo fértil, será contabilizado:
                if (irrigadores_proximos > 0)
                {
                    solos_cobertos++;
                } 
                // Os solos férteis não cobertos, por pelo menos um irrigador, também será contabilizado:
                if (irrigadores_proximos == 0)
                {
                    solos_nao_cobertos++;
                }
                irrigadores_proximos = 0; 
            }
            
        }
    }
    
    //Imprime os solos férteis cobertos e os solos férteis não cobertos por irrigadores:
    printf("Solos cobertos: %d\n", solos_cobertos);
    printf("Solos não cobertos: %d", solos_nao_cobertos);

    return 0;
}