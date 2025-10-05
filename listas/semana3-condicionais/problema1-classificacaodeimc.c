#include <stdio.h>

int main() {
    //Definindo as variáveis:
    float peso, altura, imc;
    
    //Solicitando o peso:
    printf("Digite o seu peso, em kg: ");
    scanf("%f", &peso);
    
    //Solicitando a altura:
    printf("Digite a sua altura, em metros: ");
    scanf("%f", &altura);
    
    //Calculando o IMC:
    imc = peso / (altura * altura);
    
    //Exibe o resultado:
    printf("Seu IMC é: %.2f\n", imc);

    if (imc < 18.5) {
        printf("Você está abaixo do peso.\n");
    }
    else if (18.5 < imc && imc < 24.9) {
        printf("Você possui o peso normal.\n");
    }
    else if (25.0 < imc && imc < 29.9) {
        printf("Você possui sobrepeso.\n");
    }
    else if (30.0 <= imc) {
        printf("Você possui obesidade.\n");
    }

    return 0;
}