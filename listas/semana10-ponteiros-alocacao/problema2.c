#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, valor;
    int qtd = 0;

    int * buscaNoVetor(int *v, int n, int valor, int *maior, int *qtd); //Protótipo

    printf("Digite a quantidade de números: \n");
    scanf("%d", &n); // Recebe a quantidade de números

    // Alocação dinâmica do vetor de entrada:
    int *v = (int *) malloc(n * sizeof(int));

    // Validação básica de alocação (boa prática)
    if (v == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Recebendo os elementos:
    for (int i = 0; i < n; i++)
    {
        printf("Digite o %d° número(índice %d): \n", i+1, i);
        scanf("%d", &v[i]);
    }

    printf("Digite o número que você deseja saber a quantidade de ocorrências:\n");
    scanf("%d", &valor); // Recebe o valor a ter as ocorrências registradas e contabilizadas

    int inutil;
    int *resultado_indices = buscaNoVetor(v, n, valor, &inutil, &qtd); // Chama a função 

    // Imprimindo as ocorrências:
    if (resultado_indices == NULL)
    {
        printf("Nenhuma ocorrencia.\n");
    } else {
        printf("%d\n", qtd);
        for (int i = 0; i < qtd; i++)
        {
            printf("%d ", resultado_indices[i]);
        } // Imprime os índices de cada ocorrência
        printf("\n");

        free(resultado_indices); //Libera a memória alocada na função.
    }
    free(v); //Libera memória do vetor de entrada

    return 0;
}

// Função de buscar e contabilizar o número desejado pelo usuário:
int * buscaNoVetor(int *v, int n, int valor, int *maior, int *qtd) {
    int cont = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == valor)
        {
            cont++;
        }   
    } // Varre de 1 até n para contar as ocorrências

    *qtd = cont; // Atualiza o valor apontado por qtd na main

    if (cont == 0)
    {
        return NULL;
    }

    int *indices = (int *) malloc(cont * sizeof(int)); //Aloca memória apenas para a quantidade de índices encontrados
    
    int j = 0; // Índice para o novo vetor
    for (int i = 0; i < n; i++)
    {
        if (v[i] == valor)
        {
            indices[j] = i;
            j++;
        }
    } // Varre até n novamente para salvar as posições
    
    return indices;
}