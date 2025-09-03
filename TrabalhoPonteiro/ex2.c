#include <stdio.h>

int main(void) {
    int idade;
    int *p = &idade;

    printf("Digite a idade: ");
    if (scanf("%d", p) != 1) {
        printf("Entrada invalida\n");
        return 1;
    }

    printf("Idade digitada: %d\n", *p);
    printf("Endereco: %p\n", (void*)p);

    return 0;
}

