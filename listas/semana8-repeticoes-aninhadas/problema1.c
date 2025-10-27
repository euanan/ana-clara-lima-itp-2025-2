#include <stdio.h>

int main() {
    int m, n; //Os vetores representam a quantidade de números sorteados e a quantidade de números de uma aposta, respectivamente
    int count_num_acertados = 0; // Contador da quantidade de números apostados que foram sorteados, ou seja, a quantidade de números acertados na aposta
    
    // Recebendo as quantidades de números sorteados e números apostados:
    printf("Digite a quantidade de números sorteados:");
    scanf("%d", &m);
    printf("Digite a quantidade de números da aposta:");
    scanf("%d", &n);

    // Verificando a validez dos números fornecidos pelo usuário:
    if(!(m >= 1 && m <= 30)) {
        printf("Quantidade de números sorteados inválida.");
        return 0;
    }
    if(!(n >= m && n <= 50)) {
        printf("Quantidade de números apostados inválida.");
        return 0;
    }

    // Se os números fornecidos pelo usuário forem válidos, o primeiro irá corresponder à quantidade de números sorteados e o segundo à quantidade de números apostados:    
    int num_sorteados[m+1]; // "m" pois o "\n" será armazenado no último índice, e caso o usuário digite que a quantidade de números sorteados for 30, será necessário 30 espaços no vetor para armazenar e 1 espaço para armazenar "\n", então serão necessários 31 espaços. Tendo em vista que o primeiro índice é 0, de 0 a 30 são 31 espaços para serem armazenados. 
    // Analogamente ocorrerá com n, com restrição de ser maior ou igual a n e menor ou igual a 50 
    int num_apostados[n+1];

    for (size_t i = 0; i < m; i++)
    {
        printf("Digite o %d° número sorteado: \n", i+1);
        scanf("%d", &num_sorteados[i]);
    } // Recebe os números sorteados
    for (int j = 0; j < n; j++)
    {
        printf("Digite o %d° número apostado: \n", j+1);
        scanf("%d", &num_apostados[j]);
    } // Recebe os números apostados

    for (int k = 0; k <= m; k++)
    {
        for (int l = 0; l < n; l++)
        {
            if(num_sorteados[k] == num_apostados[l]) {
                count_num_acertados += 1;
            }
        } 
    } // Verifica se há números em comum entra os números sorteados e os números apostados, ou seja, os números acertados
    
    printf("Quantidade de números acertados: %d", count_num_acertados); // Imprime a quantidade de números acertados

    return 0;
    
}