#include <stdio.h>
#include <math.h>

int main() {
    //Definindo as variáveis:
    float x, y, xalvo, yalvo, comprimentomaxteia, distanciaalvohomem;
    int nalvos;
    int todos_alcancados = 1;

    //Recebendo os dados do usuário:
    printf("Digite a coordenada inicial do homem aranha: x: \n");
    scanf("%f", &x);
    printf("Digite a coordenada inicial do homem aranha: y: \n");
    scanf("%f", &y);
    printf("Digite o comprimento máximo da teia: \n");
    scanf("%f", &comprimentomaxteia);
    printf("Quantidade de alvos onde ele vai lançar a teia: \n");
    scanf("%d", &nalvos);

    for (int i = 1; i <= nalvos; i++) {
        //Recebendo as coordenadas de cada alvo:
        printf("Coordenada do alvo %d: x: \n", i);
        scanf("%f", &xalvo);
        printf("Coordenada do alvo %d: y: \n", i); 
        scanf("%f", &yalvo);

        //Calculando a distância entre a coordenada do homem aranha e o alvo:
        distanciaalvohomem = sqrt(pow(x-xalvo, 2) + pow(yalvo - y, 2));


        //Calculando as novas coordenadas do homem aranha, se a distância entre o alvo e o homem aranha é menor do que o comprimento máximo da teia:
        if(distanciaalvohomem <= comprimentomaxteia) {
            x = (2 * xalvo) - x;
        }
        else {
            //Quantidade de alvos não acertados:
            todos_alcancados = 0;
            break;
        }
    }
    printf("As coordenadas finais do homem aranha são (%.2f, %.2f)\n", x, y);
        
    if (todos_alcancados) {
        printf("S\n");
    } else {
        printf("N\n");
    }
    
    return 0;

}