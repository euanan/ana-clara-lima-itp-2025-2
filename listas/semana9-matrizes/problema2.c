#include <stdio.h>

int main() {
    // Definindo as variáveis
    int m, i, j, x; // seja m a quantidade de usuários cadastrados e o n° de linhas e colunas, seja i e j os índices dase ntradas da matriz quadrada de ordem m
    int sugestoes_amizades = 0;
    int quant_amigos = 0;

    printf("Digite a quantidade de usuários cadastrados na rede social: ");
    scanf("%d", &m);

    if (m > 100 || m <= 0)
    {
        return 0;
    } // m deve ser maior do que 0 e menor ou igual a 100

    int usuarios[m][m]; // a matriz quadrada de ordem m é definida

    // A existência das amizades entre os usuários é fornecida pelo usuário:
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Digite 1 se o usuário %d for amigo do usuário %d e 0 caso contrário: ", i+1, j+1);
            scanf("%d", &usuarios[i][j]);

            usuarios[j][i] = usuarios[i][j];

            if (i == j)
            {
                usuarios[i][j] = 0;
            }
        }
    }

    printf("Digite um número inteiro que se refira à linha e coluna do usuário: "); 
    scanf("%d", &x);
    for (int k = 0; k < m; k++)
    {
        if (usuarios[x-1][k] == 1)
        {
            quant_amigos++; // Contabiliza a quantidade de amigos

            for (int l = 0; l < m; l++)
            {
               if (usuarios[l][k] == 1)
               {
                sugestoes_amizades++; // Contabiliza as amizades das amizades do usuário(sugestões de amizade)
               }
            }
            
        }
        if (usuarios[k][x-1] == 1) 
        {
            quant_amigos++; // Contabiliza a quantidade de amigos

            for (int l = 0; l < m; l++)
            {
               if (usuarios[l][k] == 1)
               {
                sugestoes_amizades++; // Contabiliza as amizades das amizades do usuário(sugestões de amizade)
               }
            }
        }
    }

    printf("%d", sugestoes_amizades - quant_amigos); // Imprime a quantidade de sugestões de amizades
    
    return 0;
    
}