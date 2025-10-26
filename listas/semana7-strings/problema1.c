#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    //Definindo as variáveis e vetor
    char palavra[20]; //Vetor que irá armazenar a palavra
    int indice; //Índice, a ser fornecido pelo usuário, da palavra para ser verificado
    int count_bomb_adjacent = 0; //Variável que irá armazenar a quantidade de bombas adjacentes
    int tamanho_palavra; //Variável que irá armazenar a quantidade de caracteres da palavra
    bool palavra_valida = true; //Variável booleana, que será alterada para false caso for encontrado algum caractere inválido

    printf("Digite uma palavra com até 20 caracteres composta somente por . e x, onde o primeiro representa um espaço vazio e o segundo representa uma bomba:\n");
    scanf("%s", palavra); //Recebe a palavra do usuário.Foi utilizado scanf pois a string deve conter somente os caracteres "x" ou "." e não deve conter espaços


    printf("Digite o índice na palavra a ser verificado(considere o primeiro índice como 0):\n");
    scanf("%d", &indice); // Recebe o índice, fornecido pelo usuário, do caractere a ser analisado

    tamanho_palavra = strlen(palavra); // Define o tamanho da palavra como sendo a função que conta a quantidade de caracteres da palavra fornecida pelo usuário
    
    // Índices menores do que zero ou maiores do que a quantidade total de caracteres serão inválidos:
    if(indice < 0 || indice >= strlen(palavra)) {
        printf("Índice inválido.");
        return 0;
    }

    // Se há caracteres diferentes de "." e "x" na palavra fornecida, a palavra será considerada inválida:
    for (int i = 0; i < strlen(palavra); i++)
    {
        if(palavra[i] != '.' && palavra[i] != 'x') {
            palavra_valida = false;
            printf("Palavra inválida!\n");
            return 0;
        }
    } // Cada caractere da palavra será analisado
    // Se a palavra é válida:
    if(palavra_valida == true) {
        if(palavra[indice] == 'x') {
            printf("bum!");
            return 0;
        } // Se o caractere do índice informado pelo usuário for igual a "x", é uma bomba e, portanto, será impresso "bum! para o usuário"
        //Se não:
        else if(palavra[indice] == '.') {
            if(indice > 0 && palavra[indice-1] == 'x') {
                count_bomb_adjacent += 1;
            } // Se o índice for maior do que 0, então o caractere de índice inferior será analisado, caso o caractere de índice inferior seja "x", ou seja, representa uma bomba, será contabilizada a presença dessa bomba adjacente ao caractere ".", de índice fornecido pelo usuário
            if(indice < tamanho_palavra - 1 && palavra[indice + 1] == 'x') {
                count_bomb_adjacent += 1;
            }  //Se o índice

        printf("Há %d bombas adjacentes ao índice %d.\n", count_bomb_adjacent, indice); //Imprime a quantidade de bombas adjacentes ao caractere, se o caractere do índice for "." 

        }
    }

    return 0;

}

