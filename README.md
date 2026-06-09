# Ponteiros em C — Atividades Práticas

Resolução das 5 atividades da disciplina, cobrindo ponteiros, passagem por referência, structs, aritmética de ponteiros e alocação dinâmica de memória.

---

## Estrutura do repositório

```
.
├── atividade1.c   # Ponteiros básicos e modificação direta
├── atividade2.c   # Passagem por referência via função
├── atividade3.c   # Ponteiros para structs (operador ->)
├── atividade4.c   # Aritmética de ponteiros em arrays
├── atividade5.c   # Alocação dinâmica com malloc e free
└── README.md
```

---

## Como compilar e executar

Pré-requisito: GCC instalado.

```bash
gcc atividadeX.c -o atividadeX
```

---

## Explicação por atividade

### Atividade 1 — Fundamentos de Ponteiros

```c
float preco  = 100.0f;
float *ptr   = &preco;   // ptr guarda o ENDEREÇO de preco
*ptr = *ptr * 1.10f;     // desreferência: modifica o valor no endereço
```

**Conceitos-chave:**
- `&variavel` → obtém o endereço de memória.
- `*ponteiro` → acessa/modifica o valor no endereço (desreferência).
- Qualquer alteração via `*ptr` reflete diretamente em `preco`.

---

### Atividade 2 — Passagem por Referência

```c
void aplicar_desconto(float *preco, float percentual) {
    *preco = *preco * (1.0f - percentual / 100.0f);
}

// Na main:
aplicar_desconto(&preco, 15.0f);
```

**Por que passar o endereço?**  
Em C, argumentos são copiados por padrão (*pass by value*). Ao passar `&preco`, a função recebe o endereço real da variável, podendo alterar seu conteúdo diretamente — sem precisar de retorno.

---

### Atividade 3 — Ponteiros para Structs

```c
typedef struct { int id; float preco; } Produto;

void aplicar_desconto(Produto *produto, float percentual) {
    produto->preco = produto->preco * (1.0f - percentual / 100.0f);
}
```

**Operador `->` (seta):**  
Equivale a `(*produto).preco`, mas é a forma idiomática para acessar membros via ponteiro. Modifica o campo `preco` da struct original na memória.

---

### Atividade 4 — Aritmética de Ponteiros em Arrays

```c
void imprimir_produtos(Produto *ptr, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("%d  R$ %.2f\n", (ptr + i)->id, (ptr + i)->preco);
    }
}
```

**Como funciona:**  
O nome do array (`estoque`) decai para um ponteiro para o primeiro elemento. `ptr + i` avança `i * sizeof(Produto)` bytes na memória, alcançando o i-ésimo elemento sem usar colchetes.

| Expressão   | Equivalente com colchetes |
|-------------|--------------------------|
| `(ptr + 0)` | `&ptr[0]`                |
| `(ptr + 1)` | `&ptr[1]`                |
| `(ptr + i)->preco` | `ptr[i].preco`  |

---

### Atividade 5 — Alocação Dinâmica (`malloc` / `free`)

```c
#include <stdlib.h>

Produto *estoque = (Produto *) malloc(n * sizeof(Produto));

if (estoque == NULL) { /* trate o erro */ }

// ... uso do array ...

free(estoque);
estoque = NULL;  // evita ponteiro dangling
```

**Por que `malloc`?**  
Arrays estáticos exigem tamanho em tempo de compilação. `malloc` aloca `n * sizeof(Produto)` bytes na **heap** em tempo de execução, retornando um ponteiro para o bloco. `free` devolve essa memória ao sistema operacional — não chamar `free` causa *memory leak*.

**Boas práticas aplicadas:**
1. Sempre verificar se `malloc` retornou `NULL`.
2. Atribuir `NULL` ao ponteiro após `free`.
3. `sizeof(Tipo)` garante portabilidade entre arquiteturas.

---

## Resumo visual do fluxo de memória

```
Stack (main)          Heap (malloc)
┌──────────────┐      ┌─────────────────────────────────┐
│ estoque *────┼─────►│ Produto[0] │ Produto[1] │  ...  │
│ n = 3        │      └─────────────────────────────────┘
└──────────────┘               ▲
                           free(estoque)
                         devolve este bloco
```