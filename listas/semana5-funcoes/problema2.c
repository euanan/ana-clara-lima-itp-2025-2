#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool eprimo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int limite = sqrt(n);
    for (int i = 3; i <= limite; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


void triosprimos(){
for (int i = 2; i < 49994; i++)
{
    int primo1 = i;
    int primo2 = i + 2;
    int primo3 = i + 6;

    if (eprimo(primo1) && eprimo(primo2) && eprimo(primo3)) {
        printf("(%d, %d, %d)\n", primo1, primo2, primo3);
    }
}
}

int main() {
    printf("Trios de números primos:\n");
    triosprimos();
    return 0;
}
