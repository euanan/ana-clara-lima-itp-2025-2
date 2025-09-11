#include <stdio.h>

float main() {
    float celsius, fahrenheit, kelvin;

    //Recebendo o valor em Celsius
    printf("Digite a temperatura, em Celsius: ");
    scanf("%f", &celsius);

    //Fórmulas
    fahrenheit = (celsius * 9/5) + 32;
    kelvin = celsius + 273.15;

    //Exibe as temperaturas correspondente a Celsius, em Fahrenheit e Kelvin
    printf("A temperatura %.1f em graus Celsius corresponde a %.1f Fahrenheit e %.1f Kelvin.\n", celsius, fahrenheit, kelvin);

    return 0;

}