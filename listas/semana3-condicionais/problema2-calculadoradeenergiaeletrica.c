#include <stdio.h>
#include <string.h> 
#include <ctype.h>

int main() {

    //Definindo as variáveis
    float consumo, valortotalkwh;
    char tipo[2];

    //Tipos de consumidores
    char residencial[] = "R";
    char comercial[] = "C";
    char industrial[] = "I";

    //Recebendo os dados do usuário 
    printf("Digite o seu consumo, em kWh: ");
    scanf("%f", &consumo);
    printf("Qual tipo de consumidor você é? (R para residencial, C para comercial, I para industrial)");
    scanf("%1s", tipo);

    //Condições e cálculos
    //strcmp retorna 0 se as strings forem iguais
    if (strcmp(tipo, residencial) == 0) {
        valortotalkwh = consumo * 0.6;
    }
    else if (strcmp(tipo, comercial) == 0) {
        valortotalkwh = consumo * 0.48;
    }
    else if (strcmp(tipo, industrial) == 0)
    {
        valortotalkwh = consumo * 1.29;
    }

    //Imprime o valor total da conta
    printf("Valor total da conta: R$ %.2f.\n", valortotalkwh);

    return 0;
    
}