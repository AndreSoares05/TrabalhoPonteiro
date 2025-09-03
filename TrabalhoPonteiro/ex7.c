#include <stdio.h>
#include <limits.h>

int main(void) {
    int mat[4][4];
    int *p = &mat[0][0];

    // Leitura
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            printf("Pontos jogador %d, set %d: ", i + 1, j + 1);
            scanf("%d", p + i * 4 + j);
        }

    // Mostrar matriz
    printf("\nMatriz (jogadores x sets):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            printf("%4d ", *(p + i * 4 + j));
        printf("\n");
    }

    // Contar pares e impares
    int pares = 0, impares = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            int val = *(p + i * 4 + j);
            if (val % 2 == 0) pares++; else impares++;
        }
    printf("\nPares: %d, Impares: %d\n", pares, impares);

    // Total por jogador e jogador com maior pontuacao
    int total_jog[4] = {0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) total_jog[i] += *(p + i * 4 + j);
    }
    int max_jog = 0;
    for (int i = 1; i < 4; i++) if (total_jog[i] > total_jog[max_jog]) max_jog = i;
    for (int i = 0; i < 4; i++) printf("Total jogador %d: %d\n", i + 1, total_jog[i]);
    printf("Jogador com maior pontuacao: %d (total = %d)\n", max_jog + 1, total_jog[max_jog]);

    // Total por set e set mais disputado (maior soma)
    int total_set[4] = {0};
    for (int j = 0; j < 4; j++)
        for (int i = 0; i < 4; i++) total_set[j] += *(p + i * 4 + j);
    int max_set = 0;
    for (int j = 1; j < 4; j++) if (total_set[j] > total_set[max_set]) max_set = j;
    for (int j = 0; j < 4; j++) printf("Total set %d: %d\n", j + 1, total_set[j]);
    printf("Set mais disputado: %d (soma = %d)\n", max_set + 1, total_set[max_set]);

    // Media de pontos da partida por jogador
    printf("\nMedia por jogador (por partida):\n");
    for (int i = 0; i < 4; i++) printf("Jogador %d: %.2f\n", i + 1, total_jog[i] / 4.0);

    // Jogador mais regular (menor diferenca entre maior e menor set)
    int mais_regular = 0;
    int melhor_diferenca = INT_MAX;
    for (int i = 0; i < 4; i++) {
        int maior = INT_MIN, menor = INT_MAX;
        for (int j = 0; j < 4; j++) {
            int v = *(p + i * 4 + j);
            if (v > maior) maior = v;
            if (v < menor) menor = v;
        }
        int diff = maior - menor;
        printf("Jogador %d: maior=%d, menor=%d, diff=%d\n", i + 1, maior, menor, diff);
        if (diff < melhor_diferenca) {
            melhor_diferenca = diff;
            mais_regular = i;
        }
    }
    printf("\nJogador mais regular: %d (diferenca = %d)\n", mais_regular + 1, melhor_diferenca);

    return 0;
}

