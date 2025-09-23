#include <stdio.h>

int main() {
    //Definindo as variáveis:
    float preco1, preco2, quantia, total, resto;
    int i, j, possivel, melhori, melhorj;
    float menor_resto = -1;
    int combinacoes_viaveis = 0;

    //Recebendo os dados do usuário:
    printf("Digite o preco do primeiro fornecedor:");
    scanf("%f", &preco1);
    printf("Digite o preco do segundo fornecedor:");
    scanf("%f", &preco2);
    printf("Digite a quantia disponivel:");
    scanf("%f", &quantia);
    printf("\n");

    //Testando todas as combinações possíveis (0 a 10 unidades de cada):
    for (i = 0; i <= 10; i++) {
        for (j = 0; j <= 10; j++) {
            //Calculando o total gasto:
            total = (i * preco1) + (j * preco2);
            
            //Verificando se a compra é possível:
            if (total <= quantia) {
                resto = quantia - total;
                combinacoes_viaveis++;

                //Encontrado a combinação com menor resto:
                if (menor_resto == -1 || resto < menor_resto) {
                    menor_resto = resto;
                    melhori = i;
                    melhorj = j;
                }
            }
        }
    }

    //Imprimindo o resultado:
    if (combinacoes_viaveis > 0) {
        printf("Resta menos comprando %d do primeiro e %d do segundo\n", 
               melhori, melhorj);
    } else {
        printf("Nenhuma combinação é viável com a quantia disponível.\n");
    }

    return 0;
    
}