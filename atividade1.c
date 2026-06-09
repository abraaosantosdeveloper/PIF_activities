#include <stdio.h>

int main(void)
{
    float preco = 100.0f;

    /* Declaração do ponteiro e atribuição do endereço de 'preco' */
    float *ptr = &preco;

    printf("Preco antes do aumento : R$ %.2f\n", preco);

    /* Modificação exclusivamente pelo ponteiro */
    *ptr = *ptr * 1.10f;

    /* Imprime a variável original — já está alterada */
    printf("Preco apos aumento 10%% : R$ %.2f\n", preco);

    return 0;
}