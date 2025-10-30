#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Função que verifica se um token é uma data:
int eh_data(const char *token) {
    // A data deve ter exatamente 5 caracteres (DD/MM):
    if(strlen(token) != 5) {
        return 0;
    }
    // Verifica se "/" está na posição 2
    return (token[2] == '/');
}

int main() {
    // Variáveis e vetores:
    char nome_aluno[11];
    char frequencias[1001];
    int total_aulas = 0;
    int num_presencas_alunos = 0;
    int faltas_aluno;

    // Consideramos que a entrada seguirá a ordem Aluno \n Frequência.

    printf("Digite o nome do aluno: ");
    scanf("%s", nome_aluno);

    printf("Digite a string de frequências (max 1000 caracteres): \n");
    getchar(); // Consome o \n residual do scanf anterior
    fgets(frequencias, 1001, stdin); // Lê a linha inteira

    // Remove o "\n" lido por fgets, se houver:
    frequencias[strcspn(frequencias, "\n")] = 0;

    // Tokenização da string usando o espaço como delimitador:
    char *token = strtok(frequencias, " ");

    // Processamento da string:

    while (token != NULL)
    {
        if (eh_data(token)) {
            // Se o token for uma data, uma nova aula começou
            total_aulas++;

            // O próximo token é o primeiro aulo presente
            token = strtok(NULL, " ");

            // Contagem de presenças na aula atual:
            while (token != NULL && !eh_data(token)) {

                //Comparando o nome do aluno presente com o aluno procurado:
                if (strcmp(token, nome_aluno) == 0) {
                    num_presencas_alunos++;
                    break;
                }

                token = strtok(NULL, " "); // pega o próximo token (outro aluno ou próxima data)
            }
        } else {
            // Caso o primeiro token da string não seja uma data (início inesperado), avança
            token = strtok(NULL, " ");
        }
    }

    // Cálculo de ausências:
    faltas_aluno = total_aulas - num_presencas_alunos;

    printf("%d \n", faltas_aluno); // Imprime a quantidade de falta do aluno

    return 0;

}
    