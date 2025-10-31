#include <stdio.h>

int main(){
    // Variáveis:
    int quant_pilotos;

    printf("Digite a quantidade de pilotos: ");
    scanf("%d", &quant_pilotos);
    if (!(quant_pilotos >= 1 && quant_pilotos <= 20)) 
    {
        printf("Quantidade de pilotos inválida.\n");
        return 0;
    }

    int ordem_largada[quant_pilotos];
    int pos_chegada[quant_pilotos + 1];

    // Recebendo a ordem de largada:
    printf("Digite a ordem de largada:\n");
    for (int i = 0; i < quant_pilotos; i++)
    {
        printf("%d° posição: ", i+1);
        scanf("%d", &ordem_largada[i]);
    }
    // Recebendo a ordem de chegada:
    printf("Digite a ordem de chegada:\n");
    for (int j = 0; j < quant_pilotos; j++)
    {
        int piloto_na_posicao;
        printf("%d° posição: ", j+1);
        scanf("%d", &piloto_na_posicao);

        pos_chegada[piloto_na_posicao] = j + 1;
    }
    
    int max_ganho = -21; //Variável que irá armazenar o maior número de posições ganhas encontrado até agora. O ganho mínimo possível é negativo (quando o piloto perde posições)
    int piloto_ganhador = 0; // Armazena o identificador do piloto que alcançou o max_ganho, inicialmente 0 é 'nenhum ganhador'
    int houve_empate = 0; //flag para indicar que dois ou mais pilotos emparataram, 0 = false, 1 = true

    for (int k = 0; k < quant_pilotos; k++) 
    {
        int piloto_atual = ordem_largada[k];
        int pos_largada = k + 1;
        int pos_chegada_atual = pos_chegada[piloto_atual]; // Posição final do piloto atual

        //Cálculo da diferença(ganho)
        //Ganho = posição inicial - posição final
        int ganho_atual = pos_largada - pos_chegada_atual;

        //Comparação e empate:
        if (ganho_atual > max_ganho) {
        // Novo ganho máximo encontrado
        max_ganho = ganho_atual;
        piloto_ganhador = piloto_atual;
        houve_empate = 0; // Reseta a flag de empate
        } else if (ganho_atual == max_ganho && ganho_atual > 0) {
        // Empate no ganho máximo, mas só se o ganho for positivo (Piloto ganhou posições)
        houve_empate = 1;
        }
    }
    // Imprimindo o resultado final:
    if (max_ganho <= 0) {
        // Se o maior "ganho" for 0 ou negativo, significa que ninguém ganhou posições.
        printf("empate\n");
    } else if (houve_empate == 1) {
        // Se houve empate entre pilotos com ganho > 0
        printf("empate\n");
    } else {
        // Se houve um único piloto com o maior ganho > 0
        printf("%d\n", piloto_ganhador);
    }

    return 0;

}

