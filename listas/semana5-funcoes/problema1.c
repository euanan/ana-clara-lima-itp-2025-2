#include <stdio.h>

void formatos_horas(int horas[], int minutos[], int numero_rondas, int formato_horarios) {
    for (int i = 0; i < numero_rondas; i++) {
        printf("Ronda %d: ", i + 1);

        if (formato_horarios == 0) {
            //Formato 24h
            printf("%02d:%02d\n", horas[i], minutos[i]);
            } else {
            //Formato 12h
            char *turno;
            int horas12;
            
            if (horas[i] == 0) {
                horas12 = 12;
                turno = "AM";
            } else if (horas[i] == 12) {
                horas12 = 12;
                turno = "PM";
            } else if (horas[i] < 12) {
                horas12 = horas[i];
                turno = "AM";
            } else {
                horas12 = horas[i] - 12;
                turno = "PM";
            }

             printf("%02d:%02d %s\n", horas12, minutos[i], turno);
        }
    }
}

//Função para ajustar os horários(minutos maiores do que 59 e horas maiores do que 23)
void ajustarhorario(int *horas, int *minutos) {
    *horas += *minutos / 60;
    *minutos = *minutos % 60;
    *horas = *horas % 24;
}

int main() {
int numero_rondas, formato_horarios;

    printf("Digite o número de rondas: \n");
    scanf("%d", &numero_rondas);

    if (numero_rondas <= 0) {
        printf("Número de rondas deve ser positivo!\n");
        return 1;
    }

    //Declarando vetores com tamanho variável
    int horas[numero_rondas];
    int minutos[numero_rondas];

    for (int i = 0; i < numero_rondas; i++){
        printf("\n Ronda %d:", i + 1);

        printf("Digite a hora(no formato 24h): ");
        scanf("%d", &horas[i]);

        printf("Digite a os minutos: ");
        scanf("%d", &minutos[i]);

    if (horas[i] < 0 || minutos[i] < 0) {
        printf("Os horários não podem ser negativos.\n");
        return 1;
    }

    //Ajustar os horários, se necessário
    ajustarhorario(&horas[i], &minutos[i]);
}

printf("Digite 0 para que os horários sejam escritos no formato 24h e 1 no formato 12h:");
scanf("%d", &formato_horarios);
            
    if (formato_horarios != 0 && formato_horarios != 1) {
        printf("Formato inválido. Use 0 ou 1.");
            return 1;
    }

    printf("Horários das rondas:\n");
    formatos_horas(horas, minutos, numero_rondas, formato_horarios);

    return 0;
        
}