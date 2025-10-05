#include <stdio.h>
#include <math.h>

int main() {
    //Definindo as variáveis:
    int valor_a, valor_b, soma, diferenca, produto, resto_da_divisao;
    float media_aritmetica, divisao_real;

    //Recebendo os valores para realizar as operações:
    printf("Insira um número inteiro: ");
    scanf("%d", &valor_a);
    printf("Insira outro número inteiro: ");
    scanf("%d", &valor_b);

    //Operações aritméticas básicas:
    soma = valor_a + valor_b;
    diferenca = valor_a - valor_b;
    produto = valor_a * valor_b;
    divisao_real = (float)valor_a / valor_b;
    resto_da_divisao = valor_a % valor_b;
    media_aritmetica = (float)(valor_a + valor_b) / 2;

    //Imprimindo os resultados das operações:
    printf("A soma dos números %d e %d é: %d\n",valor_a, valor_b, soma);
    printf("A diferença entre %d e %d é: %d\n", valor_a, valor_b, diferenca);
    printf("O produto entre %d e %d: %d\n", valor_a, valor_b, produto);
    printf("A divisão real entre %d e %d: %.2f\n", valor_a, valor_b, divisao_real);
    printf("O resto da divisão inteira entre %d e %d: %d\n", valor_a, valor_b, resto_da_divisao);
    printf("A média aritmética entre %d e %d: %.2f\n", valor_a, valor_b, media_aritmetica);

    return 0;

}