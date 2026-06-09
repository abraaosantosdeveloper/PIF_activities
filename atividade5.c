#include <stdio.h>
#include <stdlib.h> /* malloc, free */

typedef struct
{
    int id;
    float preco;
} Produto;

void aplicar_desconto(Produto *produto, float percentual)
{
    produto->preco = produto->preco * (1.0f - percentual / 100.0f);
}

/* Reutilizada da Atividade 4 — aritmética de ponteiros, sem colchetes */
void imprimir_produtos(Produto *ptr, int quantidade)
{
    printf("\n%-6s %s\n", "ID", "Preco");
    printf("-------------------\n");
    for (int i = 0; i < quantidade; i++)
    {
        printf("  %d      R$ %.2f\n",
               (ptr + i)->id,
               (ptr + i)->preco);
    }
    printf("\n");
    printf("Pressione Enter para continuar...\n");
    getchar();
}

int main(void)
{
    int n;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d%*c", &n);

    if (n <= 0)
    {
        printf("Numero invalido.\n");
        return 1;
    }

    /* -------------------------------------------------------
     * malloc retorna um void* — alocamos n blocos do tamanho
     * de Produto.  Se falhar, retorna NULL.
     * ------------------------------------------------------- */
    Produto *estoque = (Produto *)malloc(n * sizeof(Produto));

    if (estoque == NULL)
    {
        printf("Erro: nao foi possivel alocar memoria.\n");
        printf("Pressione Enter para continuar...\n");
        getchar();
        return 1;
    }

    /* Preenchimento iterando com aritmética de ponteiros */
    for (int i = 0; i < n; i++)
    {
        (estoque + i)->id = i + 1;

        printf("Digite o preco do produto #%d: R$ ", i + 1);
        scanf("%f%*c", &(estoque + i)->preco);
    }

    printf("\n=== Produtos cadastrados ===");
    imprimir_produtos(estoque, n);

    /* Aplica 10% de desconto em todos usando ponteiro aritmético */
    for (int i = 0; i < n; i++)
    {
        aplicar_desconto(estoque + i, 10.0f);
    }

    printf("=== Apos desconto de 10%% em todos ===");
    imprimir_produtos(estoque, n);

    /* Libera a memória alocada dinamicamente */
    free(estoque);
    estoque = NULL; /* boa prática: evita ponteiro dangling */

    printf("Memoria liberada com sucesso.\n");
    printf("Pressione Enter para continuar...\n");
    getchar();
    return 0;
}