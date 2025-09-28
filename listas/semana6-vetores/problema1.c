#include <stdio.h>
#include <stdbool.h>

bool resposta_correta(int gabarito, int resposta) {
    if (gabarito == resposta) return true;
    if (gabarito != resposta) return false;
}

int correcao_provas(int num_respostas, int gabarito_questoes[], int respostas_alunos[]) {
    int contagem_respostas_corretas = 0;

    for (int i = 0; i < num_respostas; i++)
    {
        if (resposta_correta(gabarito_questoes[i], respostas_alunos[i])) {
        contagem_respostas_corretas += 1;
        } 
    }

    return contagem_respostas_corretas; 

}

int main() {
    int num_questoes, acertos;

    //Vetores com tamanho máximo:
    int gabarito_questoes[20];
    int respostas_alunos[20];

    printf("Digite o número de questões: ");
    scanf("%d", &num_questoes);

    if (num_questoes < 1 || num_questoes > 20) {
        printf("Número de questões inválido. Deve ser entre 1 e 20.\n");
        return 1;
    }

    for (int i = 0; i < num_questoes; i++) 
    {
        printf("Digite a resposta correta da questão %d: \n", i);
        scanf("%d", &gabarito_questoes[i]);

        printf("Digite a resposta do aluno da questão %d: \n", i);
        scanf("%d", &respostas_alunos[i]);
    }

    acertos = correcao_provas(num_questoes, gabarito_questoes,respostas_alunos);
    
    printf("O aluno obteve %d acertos.\n", acertos);
    
     if (acertos == 1) {
        printf("%d acerto\n", acertos);
    } else {
        printf("%d acertos\n", acertos);
    }
    
    return 0;
}