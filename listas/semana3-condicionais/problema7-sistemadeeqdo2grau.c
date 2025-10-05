#include <stdio.h>
#include <math.h>

int main() {
    //Definindo as variáveis dos coeficientes:
    float a, b, c, discriminante, raiz1, raiz2;

    //Recebendo os coeficientes:
    printf("Insira o coeficiente a:\n");
    scanf("%f", &a);
    printf("Insira o coeficiente b:\n");
    scanf("%f", &b);
    printf("Insira o coeficiente c:\n");
    scanf("%f", &c);

    //Verificando se é uma equação do 2° grau:
    if (a == 0) {
        printf("Não é uma equação do 2° grau");
        return 0;
    }
    else {
        //Calculando o discriminante:
        discriminante = pow(b, 2) - (4 * a * c);

        //Determinando a quantidade de raízes:
        if (discriminante > 0) {
            raiz1 = (-b + sqrt(discriminante)) / (2 * a);
            printf("Duas raízes reais: %.2f e %.2f\n");
        }
        else if (discriminante == 0) {
            raiz1 = (-b / (2 * a));
            printf("Uma raiz real: %.2f\n", raiz1);
        }
        else if (discriminante < 0) {
            printf("A equação do 2° grau não possui raízes reais.\n");
        }
    }

    return 0;

}