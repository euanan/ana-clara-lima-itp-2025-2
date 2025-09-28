#include <stdio.h>

#define NUM_ILHAS 10

int main() {
    int sugestoes[NUM_ILHAS];
    int visitadas[NUM_ILHAS] = {0}; // 0 = não visitada, 1 = visitada
    
    //Lendo as sugestões dos nativos:
    printf("Digite as 10 sugestões (ilhas 0 a 9): ");
    for (int i = 0; i < NUM_ILHAS; i++) {
        scanf("%d", &sugestoes[i]);
    }
    
    int ilha_atual = 0;
    
    //Seguindo o caminho até encontrar uma ilha visitada pela segunda vez:
    while (1) {
        //Se já visitou esta ilha, encontramos a resposta
        if (visitadas[ilha_atual] == 1) {
            printf("%d\n", ilha_atual);
            break;
        }
        
        //Marca a ilha atual como visitada
        visitadas[ilha_atual] = 1;
        
        //Vai para a próxima ilha conforme sugestão dos nativos
        ilha_atual = sugestoes[ilha_atual];
    }
    
    return 0;
}