#include <stdio.h>

typedef struct
{
    int id;
    float preco;
} Produto;

void aplicar_desconto(Produto *produto, float percentual)
{
    produto->preco = produto->preco * (1.0f - percentual / 100.0f);
}

/*
 * imprimir_produtos
 * @ptr        : ponteiro para o primeiro elemento do array
 * @quantidade : número de itens a percorrer
 *
 * Percorre com aritmética de ponteiros: (ptr + i)->campo
 */
void imprimir_produtos(Produto *ptr, int quantidade)
{
    printf("%-5s %-20s %s\n", "ID", "Nome simplificado", "Preco");
    printf("----------------------------------\n");
    for (int i = 0; i < quantidade; i++)
    {
        printf("  %d              produto-%d       R$ %.2f\n",
               (ptr + i)->id,
               (ptr + i)->id,
               (ptr + i)->preco);
    }
}

int main(void)
{
    /* Array estático de 3 produtos */
    Produto estoque[3] = {
        {.id = 1, .preco = 49.90f},
        {.id = 2, .preco = 129.99f},
        {.id = 3, .preco = 299.00f}};

    int tamanho = 3;

    printf("=== Estoque ANTES dos descontos ===\n");
    imprimir_produtos(estoque, tamanho);

    /* Aplica descontos variados */
    aplicar_desconto(&estoque[0], 10.0f);
    aplicar_desconto(&estoque[1], 5.0f);
    aplicar_desconto(&estoque[2], 15.0f);

    printf("\n=== Estoque APOS os descontos ===\n");
    imprimir_produtos(estoque, tamanho);

    printf("\nPressione ENTER para continuar...\n");
    getchar();
    return 0;
}