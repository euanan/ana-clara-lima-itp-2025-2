#include <stdio.h>

int main() {
    int n;
    
    scanf("%d", &n);
    
    int terreno[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &terreno[i]);
    }
    
    //Encontrando a altura máxima:
    int max = terreno[0];
    for (int i = 1; i < n; i++) {
        if (terreno[i] > max) {
            max = terreno[i];
        }
    }
    
    //Encontrando a primeira e a última ocorrência do máximo:
    int primeira = -1, ultima = -1;
    
    for (int i = 0; i < n; i++) {
        if (terreno[i] == max) {
            if (primeira == -1) {
                primeira = i;
            }
            ultima = i;
        }
    }
    
    //comprimento = distância entre primeira e última ocorrência - 1
    int comprimento = ultima - primeira - 1;
    
    printf("%d\n", comprimento);
    
    return 0;
}