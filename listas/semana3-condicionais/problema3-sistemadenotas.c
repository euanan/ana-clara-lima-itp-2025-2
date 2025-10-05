#include <stdio.h>

int main() {
    //Definindo as variáveis:
    float nota1, nota2, nota3, mediaaritmetica, mediafinal, notafinal;

    //Recebendo os dados do usuário:
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    //Calculando a média aritmética das 3 notas fornecidas pelo usuário:
     mediaaritmetica = (nota1 + nota2 + nota3) / 3;

     //Impressão da situação do aluno, de acordo com a média aritmética:
    if (mediaaritmetica >= 7.0) {
        printf("Você foi aprovado por média.\n");
     }
     else if (mediaaritmetica >= 4.0 && mediaaritmetica < 7.0) {
        // calculo da nota final necessaria:
        //média final = (média + nota final)/2 ≥ 5,0
        // (mediaaritmetica + notafinal_necesaria) / 2 ≥ 5.0
        // mediaaritmetica + notafinal_necesaria ≥ 10.0
        // notafinal_necesaria ≥ 10.0 - mediaaritmetica
        notafinal = 10.0 - mediaaritmetica;
        
        printf("Você está em recuperação e precisa tirar pelo menos %.1f na recuperação.\n", notafinal);
    }
    else if (mediaaritmetica < 4.0) {
        printf("Você foi reprovado por média.\n");
     }

     return 0;
}