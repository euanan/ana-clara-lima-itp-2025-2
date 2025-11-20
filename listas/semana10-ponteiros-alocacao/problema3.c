#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *misturar(char *str1, char *str2); // Protótipo

int main() {
    char str1[100]; //Array que irá armazenar a string 1
    char str2[100]; //Array que irá armazenar a string 2

    printf("Digite a primeira string:\n");
    fgets(str1, 100, stdin); //Recebe a primeira string

    printf("Digite a segunda string:\n");
    fgets(str2, 100, stdin); //Recebe a segunda string

    // Removendo o caractere de nova linha '\n' lido por fgets
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    char *str_misturada = misturar(str1, str2); //Chama a função misturar

    if (str_misturada != NULL)
    {
        printf("%s", str_misturada);
        free(str_misturada);
        str_misturada = NULL;
    } else {
        printf("Erro na alocção de memória.\n");
    } //Imprime a nova string gerada
   
    return 0;
}

char *misturar(char *str1, char *str2) {
    int tamanho_str1 = strlen(str1);
    int tamanho_str2 = strlen(str2);
    int tamanho_total = tamanho_str1 + tamanho_str2 + 1; // +1 para "\0"

    char *str3 = (char *)malloc(tamanho_total * sizeof(char)); // Alocação dinâmica
    if (!str3) return NULL;


    int cont = 0;
    int i = 0;

    while (i < tamanho_str1 && i < tamanho_str2) {
        str3[cont++] = str1[i];
        str3[cont++] = str2[i];
        i++;
    } // Alterna enquanto houver letras nas duas

    // Copiando o restante da maior:
    while (i < tamanho_str1) {
        str3[cont++] = str1[i++];
    } 

    while (i < tamanho_str2) {
        str3[cont++] = str2[i++];
    }

    str3[cont] = '\0';
    
    return str3;
}