#include <stdlib.h>
#include <stdio.h>

#include "fila_banco.h"

struct no
{
    int numero_senha;
    No *proximo;
};

struct fila
{
    No *inicio;
    No *fim;
};

Fila *fila_criar()
{

    Fila *fila = (Fila *)malloc(sizeof(Fila));

    if (fila == NULL)
    {
        printf("ERRO: Sem espaço na memória!");
        exit(0);
    }

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
};

int emitir_senha(Fila *f, int proxima_senha)
{
    if (f == NULL)
    {
        printf("ERRO: Fila vázia!");
        return 0;
    }

    No *no = (No *)malloc(sizeof(No));

    if (no == NULL)
    {
        printf("ERRO: Sem espaço na memória!");
        return 0;
    }

    no->numero_senha = proxima_senha;
    no->proximo = NULL;

    if (f->inicio == NULL)
    {
        f->inicio = no;
        f->fim = no;
    }
    else
    {
        f->fim->proximo = no;
        f->fim = no;
    }

    return 1;
};

int chamar_proximo(Fila *f, int *senha_chamada)
{
    if (f == NULL || f->inicio == NULL)
    {
        printf("ERRO: Fila vázia!");
        return 0;
    }

    No *temp = f->inicio;
    *senha_chamada = temp->numero_senha;
    f->inicio = f->inicio->proximo;

    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }

    printf("Chamando senha: %d\n", temp->numero_senha);

    free(temp);

    return 1;
};

void fila_liberar(Fila *f)
{
    if (f == NULL)
    {
        printf("Fila já vázia!");
        exit(0);
    }

    No *atual = f->inicio;

    while (atual != NULL)
    {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    free(f);
};