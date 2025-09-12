#include <stdio.h>

int main() {
    //Definindo os tipos das variáveis
    float peso, altura, imc;
    
    //Solicitar o peso
    printf("Digite o seu peso, em kg: ");
    scanf("%f", &peso);
    
    //Solicitar a altura
    printf("Digite a sua altura, em metros: ");
    scanf("%f", &altura);
    
    // Calcular o IMC
    imc = peso / (altura * altura);
    
    // Exibir o resultado
    printf("Seu IMC é: %.2f\n", imc);

    return 0;
}