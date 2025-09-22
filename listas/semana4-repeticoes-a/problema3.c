#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Declaração das funções
int calc_divisores_proprios(int numero);
int processar_num_a(int a);
int processar_num_b(int b);
int verificar_rel_a_para_b(int soma_a, int b);
int verificar_rel_b_para_a(int soma_b, int a);

int main() {
    int a, b;
    
    //Recebendo os números a e b
    printf("Digite um número inteiro: ");
    scanf("%d", &a);
    printf("Digite outro número inteiro: ");
    scanf("%d", &b);
    
    //Processamento individual de cada número
    int resultado_a = processar_num_a(a);
    int resultado_b = processar_num_b(b);
    
    //Verificação individual das relações
    int relacao_ab = verificar_rel_a_para_b(resultado_a, b);
    int relacao_ba = verificar_rel_b_para_a(resultado_b, a);
    
    //Decisão final
    if (relacao_ab && relacao_ba) {
        printf("S\n");
    } else {
        printf("N\n");
    }
    
    return 0;
}

//Calculando os divisores próprios
int calc_divisores_proprios(int numero) {
    if (numero <= 1) return 0;
    
    int soma = 1;
    int raiz = sqrt(numero);
    
    for (int i = 2; i <= raiz; i++) {
        if (numero % i == 0) {
            soma += i;
            if (i != numero / i) {
                soma += numero / i;
            }
        }
    }
    
    return soma;
}

int processar_num_a(int a) {
    return calc_divisores_proprios(a);
}

int processar_num_b(int b) {
    return calc_divisores_proprios(b);
}

int verificar_rel_a_para_b(int soma_a, int b) {
    return abs(soma_a - b) <= 2;
}

int verificar_rel_b_para_a(int soma_b, int a) {
    return abs(soma_b - a) <= 2;
}