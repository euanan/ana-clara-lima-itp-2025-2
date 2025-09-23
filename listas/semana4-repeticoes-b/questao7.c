#include <stdio.h>
#include <math.h>

//Função para verificar se um número é primo
int eh_primo(int n) {
    if (n <= 1) return 0; 
    if (n == 2) return 1; 
    if (n % 2 == 0) return 0; //números pares maiores que 2 não são primos
    
    //Verifica divisores ímpares até a raiz quadrada
    int raiz = sqrt(n);
    for (int i = 3; i <= raiz; i += 2) {
        if (n % i == 0) {
            return 0; //se um divisor for encontrado, não é primo
        }
    }
    
    return 1; // é primo

}

int main() {
    //Definindo as variáveis:
    int a, b;

    //Recebendo os dados do usuário:
    printf("Digite um número inteiro: \n");
    scanf("%d", &a);
    printf("Digite outro número inteiro: \n");
    scanf("%d", &b);

    if(a <= b) {
        printf("Erro: O primeiro numero deve ser maior que o segundo.\n");
        return 1;
    }

    printf("\nNumeros primos entre %d e %d:\n", b, a);
    int primoencontrado = 0;

    if(a > b) {
        for (int i = b; i < a; i++){
            if (eh_primo(i)) {
            printf("%d ", i);
            primoencontrado = 1;
            }  
        } 
    }
    if (!primoencontrado) {
        printf("Nenhum primo encontrado.");
    }
    printf("\n");

    return 0;
    }