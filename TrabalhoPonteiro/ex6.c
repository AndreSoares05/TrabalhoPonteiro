#include <stdio.h>

int main(void) {
    double mat[3][3];
    double *p = &mat[0][0];

    // Leitura
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            printf("Nota [linha %d, col %d]: ", i + 1, j + 1);
            scanf("%lf", p + i * 3 + j);
        }

    // Mostrar todas usando apenas ponteiros
    printf("\nMatriz 3x3 de notas:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%.2f\t", *(p + i * 3 + j));
        printf("\n");
    }

    // Soma da diagonal principal (i==j)
    double soma = 0.0;
    for (int i = 0; i < 3; i++) soma += *(p + i * 3 + i);

    printf("Soma da diagonal principal: %.2f\n", soma);

    return 0;
}

