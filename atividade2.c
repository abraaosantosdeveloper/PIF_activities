#include <stdio.h>

/*
 * aplicar_desconto
 * @preco      : ponteiro para o preço a ser modificado
 * @percentual : valor do desconto em % (ex: 15.0 para 15%)
 */
void aplicar_desconto(float *preco, float percentual)
{
    *preco = *preco * (1.0f - percentual / 100.0f);
}

int main(void)
{
    float preco = 100.0f;

    printf("Preco original          : R$ %.2f\n", preco);

    /* Passa o ENDEREÇO da variável — passagem por referência */
    aplicar_desconto(&preco, 15.0f);

    printf("Preco apos desconto 15%% : R$ %.2f\n", preco);
    printf("\nPressione ENTER para encerrar...");
    getchar();

    return 0;
}