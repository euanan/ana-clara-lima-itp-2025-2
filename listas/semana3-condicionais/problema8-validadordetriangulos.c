#include <stdio.h>
#include <string.h> 
#include <math.h>

int main() {
    // Definindo as variáveis
    float ladoa, ladob, ladoc;
    char tipotriangulo[20];
    char classifangulos[20];

    // Recebendo os dados do usuário
    printf("Digite os três lados do triângulo: ");
    scanf("%f %f %f", &ladoa, &ladob, &ladoc);

    // Verificando validade do triângulo (utilizando a desigualdade triangular)
    if ((ladoa < ladob + ladoc) && (ladob < ladoa + ladoc) && (ladoc < ladoa + ladob)) {
        
        // Classificação quanto aos lados
        if (ladoa == ladob && ladob == ladoc) {
            strcpy(tipotriangulo, "Equilátero");
        }
        else if (ladoa == ladob || ladoa == ladoc || ladob == ladoc) {
            strcpy(tipotriangulo, "Isósceles");
        }
        else {
            strcpy(tipotriangulo, "Escaleno");
        }

        // Determinando o maior lado
        float maior = ladoa;
        float b = ladob, c = ladoc;
        if (ladob > maior) { maior = ladob; b = ladoa; c = ladoc; }
        if (ladoc > maior) { maior = ladoc; b = ladoa; c = ladob; }

        // Classificando os triângulos quanto aos ângulos
        if (fabs(maior*maior - (b*b + c*c)) < 1e-6) {
            strcpy(classifangulos, "Retângulo");
        }
        else if (maior*maior < (b*b + c*c)) {
            strcpy(classifangulos, "Acutângulo");
        }
        else {
            strcpy(classifangulos, "Obtusângulo");
        }

        // Exibindo o resultado
        printf("O triângulo é %s e %s.\n", tipotriangulo, classifangulos);
    }
    else {
        printf("Os lados informados não formam um triângulo.\n");
    }

    return 0;
}
