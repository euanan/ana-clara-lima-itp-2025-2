#include <stdio.h>

int main() {
    //Definindo as variáveis:
    int a, b, c;
    
    printf("Trios pitagoricos (a, b, c) com maximo < 1000:\n");
    
    for (a = 1; a < 1000; a++) {
        for (b = a; b < 1000; b++) { 
            for (c = b; c < 1000; c++) {  //c começa de b para ser o maior
                if (a*a + b*b == c*c) {
                    printf("(%d, %d, %d)\n", a, b, c);
                }
            }
        }
    }
    
    return 0;
}