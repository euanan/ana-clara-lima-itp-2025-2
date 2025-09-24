#include <stdio.h>

int main() {
    //Definindo as variáveis:
    float p, q;
    int melhor_x = 0, melhor_y = 0;
    float melhor_razao = 0.0;

    //Recebendo os dados do usuário: 
    printf("Digite o preco de venda p: \n");
    scanf("%f", &p);
    printf("Digite o preco de producao q: \n");
    scanf("%f", &q);

    for (int x = 2; x <= 10; x++) {
        for (int y = 1; y < x; y++) {
            if (y * p >= x * q) { 
                float razao = (float)x / y;
                if (razao > melhor_razao) {
                    melhor_razao = razao;
                    melhor_x = x;
                    melhor_y = y;
                }
            }
        }
    }

    //Imprimindo a melhor promoção:
    printf("A melhor promocao é: leve %d pague %d\n", melhor_x, melhor_y);

    return 0;

}