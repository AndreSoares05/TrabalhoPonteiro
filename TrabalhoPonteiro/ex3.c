#include <stdio.h>

int main(void) {
    double precos[5];
    double *p = precos;

    for (int i = 0; i < 5; i++) {
        printf("Preco do produto %d: ", i + 1);
        scanf("%lf", p + i); // lê diretamente no endereço via ponteiro
    }

    printf("\nPrecos e com 10%% de desconto:\n");
    for (int i = 0; i < 5; i++) {
        double preco = *(p + i);
        double desconto = preco * 0.10;
        double preco_final = preco - desconto;
        printf("Produto %d: preco = %.2f, com 10%% desconto = %.2f\n", i + 1, preco, preco_final);
    }

    return 0;
}


