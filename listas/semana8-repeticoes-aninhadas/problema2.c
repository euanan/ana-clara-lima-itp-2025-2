#include <stdio.h>
#include <string.h>

int main() {
    // Variáveis e vetores
    int quant_chuvas[12], temp_chuva;
    char meses[][10] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    char temp_mes[10];

    // Variável que armazena a posição do amior elemento:
    int indice_maior;


    // Recebendo as quantidades de chuva de cada um dos meses:
    for (int i = 0; i < 12; i++)
    {
        printf("Digite a quantidade de chuvas no mês de %s: ", meses[i]);
        scanf("%d", &quant_chuvas[i]);
    }

    //Ordenação decrescente:
    for (int j = 0; j < 12 - 1; j++)
    {
        indice_maior = j; //Assumimos que o maior elemento na posição atual 'j'

        // Laço que busca o maior elemento do resto do vetor (de j+1 até o fim):
        for (int k = j + 1; k < 12; k++)
        {
            //Condição para encontrar um valor maior que o atual (índice_maior):
           if (quant_chuvas[k] > quant_chuvas[indice_maior])
           {
            indice_maior = k;
           }
        }  
        // Se indice_maior for diferente de j, significa que encontramos um elemento maior
        if (indice_maior != j) {

            // Troca coordenada de inteiros (entre j e indice):
            temp_chuva = quant_chuvas[j];
            quant_chuvas[j] = quant_chuvas[indice_maior];
            quant_chuvas[indice_maior] = temp_chuva;

            // Troca coordenada de strings(entre j e indice_maior):
            strcpy(temp_mes, meses[j]); 
            strcpy(meses[j], meses[indice_maior]);
            strcpy(meses[indice_maior], temp_mes);
        }
    }
    // Imprimindo em ordem decrescente as quantidades de chuva e seus respectivos meses:
    for (int l = 0; l < 12; l++) 
    {
        printf("%s %d\n", meses[l], quant_chuvas[l]);
    }

    return 0;
    
}