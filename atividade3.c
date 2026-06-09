#include <stdio.h>

typedef struct
{
    int id;
    float preco;
} Produto;

/*
 * aplicar_desconto
 * @produto    : ponteiro para a struct Produto a ser alterada
 * @percentual : valor do desconto em % (ex: 10.0 para 10%)
 */
void aplicar_desconto(Produto *produto, float percentual)
{
    /* Operador -> acessa o campo de uma struct via ponteiro */
    produto->preco = produto->preco * (1.0f - percentual / 100.0f);
}

int main(void)
{
    Produto p = {.id = 1, .preco = 250.0f};

    printf("Produto #%d\n", p.id);
    printf("  Preco original          : R$ %.2f\n", p.preco);

    aplicar_desconto(&p, 20.0f);

    printf("  Preco apos desconto 20%% : R$ %.2f\n", p.preco);
    printf("\nPressione ENTER para encerrar...");
    getchar();
    return 0;
}