#include <stdio.h> //Para utilizar printf e scanf
#include <string.h>

//Vetores para histórico
double historico_valores[10];       //Vetor para valores de entrada
double historico_resultados[10];    //Vetor para resultados
char historico_tipos[10][50];       //Vetor de strings para tipos
int total_conversoes = 0;           //Contador

//Funções
void convertercomprimento();
void convertertemperatura();


void mostrar_historico() {
    printf("\nHISTORICO (%d conversoes)\n", total_conversoes);
    
    if(total_conversoes == 0) {
        printf("Nenhuma conversao realizada.\n");
        return;
    }
    
    //Repetição: Percorre vetor do histórico
    for(int i = 0; i < total_conversoes; i++) {
        printf("%d. %s | Entrada: %.2f | Saida: %.2f\n", 
               i + 1, 
               historico_tipos[i], 
               historico_valores[i], 
               historico_resultados[i]);
    }
}

int main() {
    int opcao; //Variável utilizada para armazenar a escolha do usuário

    //Vetor de strings para menu
    char *menu_opcoes[] = {
        "Converter Comprimento",
        "Converter Temperatura",
        "Ver Historico",
        "Sair"
    };

    printf("CONVERSOR DE UNIDADE DE MEDIDAS");

    do {
        printf("\nMenu Principal\n");

        //Repetição: Mostra menu usando vetor
        for(int i = 0; i < 4; i++) {
            printf("%d. %s\n", i + 1, menu_opcoes[i]);
        }
        //Lê a escolha do usuário:
        scanf("%d", &opcao);

        //Switch-case utilizado para direcionar as opções
        switch (opcao)
        {
            case 1: //Se a opção for 1, o código abaixo será executado
                printf("Voce escolheu Comprimento!\n");
                convertercomprimento(); //Chama a função para converter comprimento
                break; //Sai do switch
            case 2:
                printf("Voce escolheu Temperatura!\n");
                convertertemperatura(); //Chama a função para converter temperatura
                break;
            case 3:
                mostrar_historico();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default: //Se nenhum dos cases anteriores for executado, ele será
                printf("Opcao invalida!\n");
        }

        if (opcao != 4) {
        printf("\nPressione Enter para continuar.");
        getchar(); //Limpa o Enter do scanf anterior
        getchar(); //Espera o usuário pressionar Enter
        }

    } while(opcao != 4); //Irá repetir o menu até o usuário escolher "sair"

    return 0; //Indica que o programa terminou com sucesso
}

void convertercomprimento() {
    int escolha;
    double valor, resultado;//Variáveis para números decimais

    printf("\n CONVERSOR DE COMPRIMENTO \n");
    printf("1. Metros para Centimetros\n");
    printf("2. Centimetros para Metros\n");
    printf("Digite a sua escolha: ");
    scanf("%d", &escolha);

    printf("Digite o valor que voce deseja converter: ");
    scanf("%lf", &valor); //lê números decimais

    if (escolha == 1) {
        resultado = valor * 100;
        printf("%.2f metros = %.2f centimetros\n", valor, resultado);

        //Adiciona ao vetor de histórico
        historico_valores[total_conversoes] = valor;
        historico_resultados[total_conversoes] = resultado;
        strcpy(historico_tipos[total_conversoes], "m -> cm");
        total_conversoes++;

    } else if (escolha == 2) {
        resultado = valor / 100;
        printf("%.2f centimetros = %.2f metros\n", valor, resultado);

        //Adiciona ao vetor de histórico
        historico_valores[total_conversoes] = valor;
        historico_resultados[total_conversoes] = resultado;
        strcpy(historico_tipos[total_conversoes], "cm -> m");
        total_conversoes++;

    } else {
        printf("Opcao invalida.\n");
    }
}

void convertertemperatura() {
    int escolha;
    double valor, resultado;
    
    printf("\n CONVERSOR DE TEMPERATURA \n");
    printf("1. Celsius para Fahrenheit\n");
    printf("2. Fahrenheit para Celsius\n");
    printf("Escolha: ");
    scanf("%d", &escolha);
    
    printf("Digite o valor que voce deseja converter: ");
    scanf("%lf", &valor);

    if (escolha == 1) {
        resultado = (valor * 9 / 5) + 32;
        printf("%.2f°C = %.2f°F\n", valor, resultado);

        //Adiciona ao vetor de histórico
        historico_valores[total_conversoes] = valor;
        historico_resultados[total_conversoes] = resultado;
        strcpy(historico_tipos[total_conversoes], "°C -> °F");
        total_conversoes++;

    } else if (escolha == 2) {
        resultado = (valor - 32) * 5 / 9;
        printf("%.2f°F = %.2f°C\n", valor, resultado);

        //Adiciona ao vetor de histórico
        historico_valores[total_conversoes] = valor;
        historico_resultados[total_conversoes] = resultado;
        strcpy(historico_tipos[total_conversoes], "°F -> °C");
        total_conversoes++;

    } else {
        printf("Opcao invalida.\n");
    }
}