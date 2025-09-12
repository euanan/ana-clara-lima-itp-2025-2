#include <stdio.h>

int main() {
    //Definindo as variáveis
    float valordacompra, valordesconto, valorfinal, porcentagemdesconto;

    //Recebendo o valor da compra do usuário
    printf("Insira o valor da compra, em Reais:\n");
    scanf("%f", &valordacompra);

    //Condições para os descontos
    if (valordacompra <= 100) {
        valordesconto = 0;
        valorfinal = valordacompra;
        porcentagemdesconto = 0;
    }
    else if (valordacompra >= 100.01 && valordacompra <= 500) {
        porcentagemdesconto = 10;
        valordesconto = valordacompra * (porcentagemdesconto / 100);
        valorfinal = valordacompra * 0.9;
    }
    else if (valordacompra >= 500.01 && valordacompra <= 1000) {
        porcentagemdesconto = 15;
        valordesconto = valordacompra * (porcentagemdesconto / 100);
        valorfinal = valordacompra * 0.85;
    }
    else if (valordacompra > 1000) {
        porcentagemdesconto = 20;
        valordesconto = valordacompra * (porcentagemdesconto / 100);
        valorfinal = valordacompra * 0.80;
    }
    printf("Valor do desconto: R$ %.2f\n.", valordesconto);
    printf("Valor final a ser pago: R$ %.2f\n.", valorfinal);
    printf("Porcentagem do desconto aplicada: %.0f \n.", porcentagemdesconto);

    return 0;

}