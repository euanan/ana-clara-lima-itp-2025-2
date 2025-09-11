#include <stdio.h>
#include <math.h>

int main() {
    //Definindo as variáveis
    float capital, taxa, tempo, montante;

    //Recebendo os dados do usuário
    printf("Insira o capital inicial(R$): ");
    scanf("%f", &capital);
    printf("Insira a taxa em juros(em porcentagem): ");
    scanf("%f", &taxa);
    printf("Insira o tempo(em anos): ");
    scanf("%f", &tempo);

    //Convertendo a taxa para decimal
    taxa = taxa / 100;

    //Calculando juros compostos através da fórmula

    montante = capital * (pow(1+ taxa, tempo));

    //Imprimindo o resultado
    printf("Montante final resultante: R$ %.2f\n", montante);

    return 0;

}