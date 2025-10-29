#include <stdio.h>
#include <string.h>

int main() {
    int quant_chuvas[12], quant_chuva_ordenadas[13][4], temp_chuva, temp_chuvas;
    char meses[][9] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    char temp_mes[9];

    for (int i = 0; i < 12; i++)
    {
        printf("Digite a quantidade de chuvas no mês de %s: ", meses[i]);
        scanf("%d", &quant_chuvas[i]);
    }
    for (int j = 0; j < 12 - 1; j++)
    {
        for (int k = 0; k < 12 - 1 - j; k++)
        {
           if (quant_chuvas[k] < quant_chuvas[k + 1])
           {
            temp_chuva = quant_chuvas[k];
            quant_chuvas[k] = quant_chuvas[k + 1];
            quant_chuvas[k + 1] = temp_chuva;

            strcpy(temp_mes, meses[k]); 
            strcpy(meses[k], meses[k + 1]);
            strcpy(meses[k + 1], temp_mes);
           }
        }  
    }
    for (int l = 0; l < 12; l++) 
    {
        printf("%s %d\n", meses[l], quant_chuvas[l]);
    }

    return 0;
}