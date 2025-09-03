#include <stdio.h>

int main(void) {
    int cofrinho = 200;   // valor exemplo; você pode trocar
    int *p = &cofrinho;   // ponteiro para cofrinho

    printf("Valor do cofrinho: %d\n", *p);         // acessando via ponteiro
    printf("Endereco na memoria: %p\n", (void*)p); // mostrando o endereco

    return 0;
}   
