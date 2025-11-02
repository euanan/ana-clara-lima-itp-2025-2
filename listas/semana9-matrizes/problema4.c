#include <stdio.h>
#include <string.h>

int main() {
    //Definindo as variáveis:
    int m, x, z, menor_custo;
    int cidade_origem, cidade_destino;
    char cidade_conexao[] = "nenhuma";

    printf("Digite a quantidade total de viagens entre cidades: ");
    scanf("%d", &m);

    if (m > 10 || m < 2)
    {
        return 0;
    }

    int viagens[m][m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
            {
                viagens[i][j] = 0;
                continue;
            }
            
            printf("Digite o preço da passagem da cidade %d até a cidade %d: ", i, j);
            scanf("%d", &viagens[i][j]);
        }
    }
    
    printf("Digite um inteiro que representa a cidade de origem: ");
    scanf("%d", &x);

    cidade_origem = x;

    printf("Digite um inteiro que rpresenta a cidade de destino:");
    scanf("%d", &z);

    cidade_destino = z;

    if ((x != z) && (x <= m) && (z <= m))
    {
        menor_custo = viagens[x][z];

        for (int k = 0; k < m; k++)
        {
            if ((viagens[x][k] + viagens[k][z]) < menor_custo)
            {
                memset(cidade_conexao, 0, sizeof(cidade_conexao));
                snprintf(cidade_conexao, 2, "%d", k);
                
                menor_custo = viagens[x][k] + viagens[k][z];
            }
            
        }
        
    }

    printf("O menor custo ao viajar da cidade %d até a cidade de destino %d terá conexão na cidade: %s. O custo será: R$%d", x, z, cidade_conexao, menor_custo);

    return 0;
}