#include <stdio.h>

int main(void) {
    double notas[6];
    double *p = notas;

    for (int i = 0; i < 6; i++) {
        printf("Nota do aluno %d: ", i + 1);
        scanf("%lf", p + i);
    }

    // Inverte usando ponteiros
    for (int i = 0; i < 3; i++) {
        double tmp = *(p + i);
        *(p + i) = *(p + 5 - i);
        *(p + 5 - i) = tmp;
    }

    printf("\nNotas na nova ordem:\n");
    for (int i = 0; i < 6; i++) {
        printf("Aluno %d: %.2f\n", i + 1, *(p + i));
    }

    return 0;
}

