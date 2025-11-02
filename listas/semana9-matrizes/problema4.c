#include <stdio.h>
#include <string.h>

int main() {
    //Definindo as variáveis:
    int m, x, z, menor_custo;
    char cidade_conexao[] = "nenhuma"; // Cidade que será realizada a conexão, caso exista, caso não exista, a cidade de conexão será nenhuma 

    printf("Digite a quantidade total de passagens entre cidades: ");
    scanf("%d", &m); // Recebe a quantidade total de passagens

    if (m > 10 || m < 2)
    {
        return 0;
    } // m deve ser menor do que 10 e maior do que 2

    int viagens[m][m]; // Define a matriz quadrada de ordem m, em que as entradas são os custos das passagens

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
    } // Recebe os preços das passagens que compõem a matriz
    
    printf("Digite um inteiro que representa a cidade de origem: ");
    scanf("%d", &x); // Recebe a cidade de origem

    printf("Digite um inteiro que rpresenta a cidade de destino:");
    scanf("%d", &z); // Recebe a cidade de destino

    if ((x != z) && (x <= m) && (z <= m))
    {
        menor_custo = viagens[x][z]; // Por padrão, a viagem direta será considerada a de menor custo

        for (int k = 0; k < m; k++)
        {
            if ((viagens[x][k] + viagens[k][z]) < menor_custo)
            {
                memset(cidade_conexao, 0, sizeof(cidade_conexao)); // Limpa a string anteriormente armazenada no vetor da cidade de conexão
                snprintf(cidade_conexao, 2, "%d", k); // Irá armazenar a nova cidade de conexão
                
                menor_custo = viagens[x][k] + viagens[k][z]; 
            } // Se a soma dos custos da viagem da cidade x até a cidade k mais a viagem da cidade k até a cidade k, for menor do que o anteriormente encontrado, será o atual menor custo
            
        }
        
    } // Verifica qual será a(s) viagem(ns) de menor custo

    printf("O menor custo ao viajar da cidade %d até a cidade de destino %d terá conexão na cidade: %s. O custo será: R$%d", x, z, cidade_conexao, menor_custo); // Irá imprimir as cidades de origem, de conexão, de destino para que a viagem tenha o menor custo possível e qual será esse custo

    return 0;
    
}