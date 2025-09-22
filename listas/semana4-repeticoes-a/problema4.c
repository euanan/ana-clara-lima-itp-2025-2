#include <stdio.h>
#include <math.h>

int main() {
    //Definindo as variáveis:
    float xdardo, ydardo, distancia;
    int pontuacao = 0;

    for (int i = 1; i <= 10; i++) {
        printf("Digite a coordenada do lançamento %d: x: ", i);
        scanf("%f", &xdardo);
        printf("Digite a coordenada do lançamento %d: y: ", i);
        scanf("%f", &ydardo);

        //Calculando a distância entre o alvo e o dardo lançado:
        distancia = sqrt(pow(xdardo, 2) + pow(ydardo, 2));

        //Pontuação:
        if(distancia >= 0 && distancia <= 1) {
            pontuacao += 15;
        }
        if(distancia > 1 && distancia <= 2) {
            pontuacao += 9;
        }
        if(distancia > 2 && distancia <= 3) {
            pontuacao += 6;
        }
        if(distancia > 3){
            pontuacao += 0;
        };
    }
    
    printf("Pontuação total: %d", pontuacao);

    return 0;
    
}