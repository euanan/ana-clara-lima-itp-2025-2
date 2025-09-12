#include <stdio.h>
#include <windows.h> // Para SetConsoleOutputCP()

int main() {
    //Configurando o console para UFT-8 (Windows)
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
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