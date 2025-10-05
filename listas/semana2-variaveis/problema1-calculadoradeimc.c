#include <stdio.h>

int main() {
    //Definindo os tipos das variáveis:
    float peso, altura, imc;
    
    //Solicita o peso:
    printf("Digite o seu peso, em kg: ");
    scanf("%f", &peso);
    
    //Solicita a altura:
    printf("Digite a sua altura, em metros: ");
    scanf("%f", &altura);
    
    //Calcularndo o IMC:
    imc = peso / (altura * altura);
    
    //Exibe o resultado:
    printf("Seu IMC é: %.2f\n", imc);

    return 0;
}