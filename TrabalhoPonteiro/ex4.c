#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Quantos funcionarios (n)? ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int *horas = malloc(n * sizeof(int));
    if (!horas) { printf("Erro de alocacao\n"); return 1; }

    for (int i = 0; i < n; i++) {
        printf("Horas do funcionario %d: ", i + 1);
        scanf("%d", horas + i); // gravando via ponteiro
    }

    long total = 0;
    for (int i = 0; i < n; i++) total += *(horas + i);

    printf("Total de horas trabalhadas no mes: %ld\n", total);

    free(horas);
    return 0;
}

