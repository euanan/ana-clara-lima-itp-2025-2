#include <stdio.h>
#include <string.h>

int main() {
    //Definindo os vetores:
    char placa[9]; //Vetor que iá armazenar os caracteres da placa
    char formato[11]; //Vetor que irá armazenar o formato

    printf("Detector de placas de carros\n");
    printf("Digite os caracteres da placa:\n");
    scanf("%s", placa);

    // Verificando a validez dos 3 primeiros caracteres:
    for (int i = 0; i < 3; i++)
    {
        if( placa[i] < 65 || placa[i] > 90) {
            printf("inválido");
            return 0;
        } 
    }

    // Definindo o formato da placa e se é válida:
    if (placa[3] == '-')
    {
        strcpy(formato, "brasileiro");

        // Verificando a validez da placa, de acordo com a coerência dos 4 últimos caracteres e o formato:
        for (int i = 4; i < 8; i++)
        {
            if (!(placa[i] >= 48 && placa[i] <= 57))
            {
            printf("inválido");
            return 0;
            }
        }
    }
    else if (placa[3] >= 48 && placa[3] <= 57)
    {
        strcpy(formato, "mercosul");

        // Verificando a validez da placa, de acordo com a coerência do caractere de índice 4 com o formato:
        if (placa[4] < 65 || placa[4] > 90)
        {
            printf("inválido");
            return 0;
        }
        for (int i = 5; i < 7; i++)
        {
            if (!(placa[i] >= 48 && placa[i] <= 57))
            {
                printf("inválido");
                return 0;
            }
        }
    } else {
        printf("inválido");
        return 0;
    }

    printf("%s", formato);

    return 0;

}