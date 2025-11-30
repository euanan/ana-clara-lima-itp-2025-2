//Codificador/Decodificador Simples(Cifra de Substituição)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO_ALFABETO 26
#define MAX_INPUT_BUFFER 1024

//Matriz de mapeamento(chave da cifra):
// Linha 0: Alfabeto Original;
//Linha 1: Alfabeto Cifrado.
char mapa_cifra[2][TAMANHO_ALFABETO] = {
    // Linha 0: Alfabeto Original
    {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
    // Linha 1: Alfabeto Cifrado (a chave)
    {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'}
};

// protótipos das funções:
char* ler_entrada();
char* cifrar(const char *texto);
char* decifrar(const char *texto_cifrado); 

// Função 1: Leitura dinâmica
char* ler_entrada() {
    char buffer[MAX_INPUT_BUFFER];
    char *entrada_dinamica = NULL;

    printf("\nDigite o texto:\n ");

    if (fgets(buffer, MAX_INPUT_BUFFER, stdin) == NULL)
    {
        return NULL;
    } // Lê a entrada
    
    // Removendo o '\n' se presente:
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
        len--;
    }

    // Alocação Dinâmica: Aloca o tamanho exato para a string lida:
    entrada_dinamica = (char *)malloc((len + 1) * sizeof(char));

    // Ponteiros Básicos: Verifica o sucesso da alocação:
    if (entrada_dinamica == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória para entrada.\n");
        return NULL;
    }
    
    // Strings: Copia o conteúdo para a memória alocada
    strcpy(entrada_dinamica, buffer);
    
    return entrada_dinamica; // Retorna o ponteiro
}

// Função 2: Cifrar
// Função de Cifragem: Intrega Alocação Dinâmica(a função retornará um ponteiro char*), o uso de Ponteiros e Repetição Aninhada
// Implementação da função de cifragem:
char* cifrar(const char *texto) {
    size_t tamanho = strlen(texto); // Alocação dinâmica do buffer de saída

    char *texto_cifrado = (char *)malloc((tamanho + 1) * sizeof(char)); // Alocação dinâmica da memória para a string de saída

    //Ponteiros: Utilizados na verificação de falha na alocação (NULL):
    if (texto_cifrado == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória para cifragem.\n");
        return NULL;
    }

    //Ponteiros/Strings: utilizados na manipulação do texto:
    //Repetição aninhada:
    // loop externo: Percorre cada caractere do texto original:
    for (size_t i = 0; i < tamanho; i++)
    {
        // Conversão para maiúscula para facilitar:
        char letra = toupper(texto[i]);

        if (letra >= 'A' && letra <= 'Z')
        {
            // Loop interno: percorre a matriz de chave
            // Matrizes: j é o índice da coluna (a posiçãod a letra no alfabeto)
            for (int j = 0; j < TAMANHO_ALFABETO; j++)
            {
                // Matrizes/Strings: Compara a letra atual com a linha 0(original) da matriz
                if (letra == mapa_cifra[0][j])
                {
                    // Se encontrar a letra igual, o valor correspondente na linha 1(cifrado) é pego:
                    texto_cifrado[i] = mapa_cifra[1][j];
                    break; //Ao encontarr a letra, sai do loop interno e vai para o próximo caractere
                } 
            }   
        } else {
            // Caso não não seja uma letra, apenas copia o caractere original:
            texto_cifrado[i] = texto[i];
        }
    }
        
    //Termina a string com '\0
    texto_cifrado[tamanho] = '\0';

    return texto_cifrado;
}

//Função 3: Decifrar (Mapeamento Inverso)
char* decifrar(const char *texto_cifrado) {
    size_t tamanho = strlen(texto_cifrado);

    //Alocação dinâmica: aloca a memória para o texto decifrado
    char *texto_original = (char *)malloc((tamanho + 1) * sizeof(char));

    if (texto_original == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para decifragem.\n");
        return NULL;
    }

    // Loop externo: percorre cada caractere do texto cifrado
    for (size_t i = 0; i < tamanho; i++) {
        // Conversão para maiúscula para facilitar:
        char letra = toupper(texto_cifrado[i]); 
        
        if (letra >= 'A' && letra <= 'Z') {
            
            // LOOP INTERNO (Estruturas de Repetição Aninhadas): Busca o mapeamento
            for (int j = 0; j < TAMANHO_ALFABETO; j++) { 
                
                // Matrizes/Strings: Compara com a Linha 1 (Cifrado)
                if (letra == mapa_cifra[1][j]) { 
                    
                    // Substitui pelo valor da Linha 0 (Original):
                    texto_original[i] = mapa_cifra[0][j];
                    break; 
                }
            }
        } else {
            // Se não for letra, copia o caractere
            texto_original[i] = texto_cifrado[i];
        }
    }
    
    //Termina a string com '\0
    texto_original[tamanho] = '\0'; 
    
    return texto_original;
}

//Função principal:
int main() {
    char *texto_entrada = NULL;
    char *texto_cifrado = NULL;
    char *texto_decifrado = NULL;

    // Entrada do Usuário (Alocação Dinâmica)
    texto_entrada = ler_entrada(); 
    
    if (texto_entrada == NULL || strlen(texto_entrada) == 0) {
        printf("Nenhum texto válido foi inserido ou erro de leitura. Encerrando.\n");
        if (texto_entrada) free(texto_entrada);
        return 1;
    }

    printf("\nResultados:\n");
    printf("Texto original: %s\n", texto_entrada); // Imprime o texto de entrada

    //Cifragem
    texto_cifrado = cifrar(texto_entrada);

    if (texto_cifrado != NULL) {
        printf("Texto Cifrado:   %s\n", texto_cifrado);
        
        // Decifragem:
        texto_decifrado = decifrar(texto_cifrado);

        if (texto_decifrado != NULL) {
            printf("Texto Decifrado: %s\n", texto_decifrado);

            free(texto_decifrado); // Liberação da memória do decifrado
        }

        free(texto_cifrado); // Liberação da memória do cifrado
    }

    free(texto_entrada); // Liberação da memória da entrada
    
    return 0;
}