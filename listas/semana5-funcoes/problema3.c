#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//Função para calcular a altura do terreno:
float calcular_altura(float x, float y) {
    float altura_superficie = sin(cos(y) + x) + cos(y + sin(x));
    return altura_superficie;
}

//Função para verificar se um ponto é seguro:
bool pontoseguro(float x, float y) {
    float altura = calcular_altura(x, y);

    if (altura <= 0 || altura >= 2) {
        return false;
    }
    return true;
}

bool sondasegura(float x, float y) {
    if (!pontoseguro(x, y)) {
        return false;
    }

    //Pontos verdes
    float pontos[4][2] = {
        {x + 0.2, y + 0.2},  //superior direito
        {x - 0.2, y - 0.2},  //inferior esquerdo
        {x + 0.2, y - 0.2},  //inferior direito
        {x - 0.2, y + 0.2}   //superior esquerdo
    };

    //Verificando cada ponto verde
    for (int i = 0; i < 4; i++) {
        if (!pontoseguro(pontos[i][0], pontos[i][1])) {
            return false;
        }
    }
    
    return true;
}
int main() {
    float x, y;
    
    //Lendo das coordenadas:
    printf("Digite as coordenadas de pouso (x): ");
    scanf("%f", &x);
    printf("Digite as coordenadas de pouso (y): ");
    scanf("%f", &y);
    
    //Verificando se o ponto principal é seguro:
    if (!sondasegura(x, y)) {
        printf("troque de coordenada\n");
        return 0;
    }
    //Contando quantos pontos vizinhos são seguros:
    float vizinhos[4][2] = {
        {x + 2, y},    //direita
        {x - 2, y},    //esquerda
        {x, y - 2},    //abaixo
        {x, y + 2}     //acima
    };
    
    int pontos_seguros_vizinhos = 0;
    for (int i = 0; i < 4; i++) {
        if (sondasegura(vizinhos[i][0], vizinhos[i][1])) {
            pontos_seguros_vizinhos++;
        }
    }

    if (pontos_seguros_vizinhos <= 1) {
        printf("inseguro\n");
    } else if (pontos_seguros_vizinhos <= 3) {
        printf("relativamente seguro\n");
    } else {
        printf("seguro\n");
    }
    
    return 0;
}