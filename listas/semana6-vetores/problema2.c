#include <stdio.h>

int main() {
    //Definindo as variáveis de acordo com o enunciado do problema, sendo m a quantidade de figurinhas da coleção completa e n a quantidade de figurinhas possuídas:
    int m, n;
    
    printf("Digite a quantidade de figurinhas da coleção completa: \n");
    scanf("%d", &m);

    if (m > 1000 || m < 1) {
        printf("A quantidade de figurinhas deve ser entre 1 e 1000.\n");
        return 1;
    }

    printf("Digite a quantidade de figurinhas que você possui: \n");
    scanf("%d", &n);

    if (n > m || n < 0) {
        printf("Quantidade inválida de figurinhas possuídas.\n");
        return 1;
    }

    //Vetor para marcar quais figurinhas foram armazenadas:
    int possui[m + 1];

    //Inicializa o vetor com 0 (não possui)
    for (int i = 1; i <= m; i++) {
        possui[i] = 0;
    }

    int figurinha; //variável para ler cada figurinha

    //Recebendo as figurinhas do usuário:
    for (int i = 0; i < n; i++) {
        printf("Digite o número da figurinha:\n");
        scanf("%d", &figurinha);

        if (figurinha >= 1 && figurinha <= m) {
            possui[figurinha] = 1;
        } else {
            printf("Figurinha %d inválida! Deve estar entre 1 e %d\n", figurinha, m);
            i--; //Repete esta entrada
        }
    }

    //Imprimindo as figurinhas que faltam:
    printf("\nFigurinhas que faltam:\n");
    int faltam = 0;
    for (int i = 1; i <= m; i++) {
        if (possui[i] == 0) {
            printf("%d ", i);
            faltam++;
        }
    }

    return 0;

}  