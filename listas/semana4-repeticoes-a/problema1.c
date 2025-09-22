#include <stdio.h>

int main() {
    //Definindo as variéveis:
    float comprimentofolha, largurafolha, comprimentobolso;
    //Variável que irá armazenar a quantidade de vezes que a folha foi dobrada:
    int dobraduras = 0;

    //Recebendo os dados do usuário:
    printf("Digite o comprimento da folha, em centímetros: \n");
    scanf("%f", &comprimentofolha);
    printf("Digite a largura da folha, em centímetros: \n");
    scanf("%f", &largurafolha);
    printf("Digite o comprimento do bolso, em centrímetros: \n");
    scanf("%f", &comprimentobolso);

    //Loop:
    while(comprimentofolha > comprimentobolso || largurafolha > comprimentobolso) {
        //Se o comprimento da folha for maior do que o comprimento do bolso, o lado da folha, correspondente ao comprimento, deverá ser dobrado(comprimento dividido por 2) e essa dobradura será contabilizada:
        if (comprimentofolha > comprimentobolso) {
            comprimentofolha /= 2;
            dobraduras += 1;
        } 
        //Se a largura da folha for maior do que o comprimento do bolso, o lado da folha, correspondente à largura, deverá ser dobrado(largura dividida por 2) e essa dobradura será contabilizada:
        if (largurafolha > comprimentobolso) {
            largurafolha /= 2;
            dobraduras += 1;
        }
    }

    //Imprime o número de vezes que a folha deverá ser sobrada para caber no bolso:
    printf("A folha deverá ser dobrada %d vezes.\n", dobraduras);

    return 0;

}