#include <stdio.h> //Para utilizar printf e scanf

//Funções
void convertercomprimento();
void convertertemperatura();

int main() {
    int opcao; //Variável utilizada para armazenar a escolha do usuário

    printf("CONVERSOR DE UNIDADE DE MEDIDAS");

    do {
        //Mostra as opções do menu:
        printf("\n1. Converter Comprimento\n");
        printf("2. Converter Temperatura\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
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
                printf("Saindo...\n");
                break;
            default: //Se nenhum dos cases anteriores for executado, ele será
                printf("Opcao invalida!\n");
        }

        if (opcao != 3) {
        printf("\nPressione Enter para continuar.");
        getchar(); //Limpa o Enter do scanf anterior
        getchar(); //Espera o usuário pressionar Enter
        }

    } while(opcao != 3); //Irá repetir o menu até o usuário escolher "sair"

    return 0; //Indica que o programa terminou com sucesso
}

//Implementação da função
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
    } else if (escolha == 2) {
        resultado = valor / 100;
        printf("%.2f centimetros = %.2f metros\n", valor, resultado);
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
    } else if (escolha == 2) {
        resultado = (valor - 32) * 5 / 9;
        printf("%.2f°F = %.2f°C\n", valor, resultado);
    } else {
        printf("Opcao invalida.\n");
    }
}