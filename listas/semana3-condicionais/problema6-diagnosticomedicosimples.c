#include <stdio.h>
#include <string.h> 
#include <ctype.h>

int main() {
    //Definindo as variáveis
    char febre, dordecabeca, dornocorpo, tosse;

    //Sintomas
    printf("Tem febre? (S/N): ");
    scanf(" %c", &febre);

    printf("Tem dor de cabeça? (S/N): ");
    scanf(" %c", &dordecabeca);

    printf("Tem dor no corpo? (S/N): ");
    scanf(" %c", &dornocorpo);

    printf("Tem tosse? (S/N): ");
    scanf(" %c", &tosse);

    //Diagnóstico com base nas respostas
    if (febre == 'S' && dordecabeca == 'S' && dornocorpo == 'S')
    {
        printf("Possível gripe.\n");
    }
    else if (tosse == 'S' && febre == 'S') {
        printf("Possível resfriado.\n");
    
    }
    else if (dordecabeca == 'S' && febre == 'N' && dornocorpo == 'N' && tosse == 'N') {
        printf("Possível enxaqueca.\n");
    }
    else if (febre == 'S' && dordecabeca == 'N' && dornocorpo == 'N' && tosse == 'N') {
        printf("Consulte um médico.\n");
    }
    else if (febre == 'N' && dordecabeca == 'N' && dornocorpo == 'N') {
        printf("Você parece estra bem.\n");
    }
    else {
        printf("Consulte um médico para avaliação.\n");
    }

    return 0;

}