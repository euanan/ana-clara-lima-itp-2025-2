#include <stdio.h>

int main() {
    // Definindo as variáveis:
    int m;
    int quant_partidas_empatadas = 0; 

    // Recebendo a quantidaded e times:
    printf("Digite a quantidade de times: ");
    if (scanf("%d", &m) != 1) 
    {
        return 0;
    }

    // m deve ser maior ou igual a 1 e menor ou igual a 20:
    if (m > 20 || m < 1)
    {
        return 0;
    }

    int gols[m][m]; // a matriz quadrada de ordem m é definida

    // Recebendo a quantidade de gols do time i contra o time j:
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Digite a quantidade de gols que o time %d fez contra o time %d: ", i, j);
            if (scanf("%d", &gols[i][j]) != 1)
            {
                return 0;
            }

            if (i == j)
            {
                gols[i][j] = 0;
            }
            
        }
    }
    // Percorrendo as quantidades de gols e verificando os empates:
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if ((gols[i][j] == gols[j][i]) && (i != j))
            {
                quant_partidas_empatadas++;
            }
            
        }
        
    }
    
    printf("%d partidas terminaram empatadas.", quant_partidas_empatadas); // Imprime a quantidade de partidas que terminaram empatadas
    
    return 0;
}