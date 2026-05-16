#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "tarefa.h"

struct tarefa
{
    char *descricao;
    int prioridade;
    Tarefa *proximo;
};

struct lista_tarefas
{
    Tarefa *inicio;
};

ListaTarefas *tarefas_criar()
{
    ListaTarefas *lista = (ListaTarefas *)malloc(sizeof(ListaTarefas));

    if (lista == NULL)
    {
        printf("ERRO: Memória sem espaço!");
        exit(1);
    }

    lista->inicio = NULL;

    return lista;
};

int tarefas_inserir_ordenado(ListaTarefas *lista, char *desc, int prioridade)
{
    if (lista == NULL)
    {
        printf("ERRO: Lista de tarefas vázia!");
        return 0;
    }

    Tarefa *nova = (Tarefa *)malloc(sizeof(Tarefa));

    if (nova == NULL)
    {
        printf("ERRO: Memória sem espaço!");
        return 0;
    }

    nova->descricao = strdup(desc);
    nova->prioridade = prioridade;

    Tarefa *anterior = NULL;
    Tarefa *atual = lista->inicio;

    while (atual != NULL && atual->prioridade >= nova->prioridade)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior != NULL)
    {
        anterior->proximo = nova;
    }

    nova->proximo = atual;

    if (lista->inicio == NULL || lista->inicio->prioridade < nova->prioridade)
    {
        lista->inicio = nova;
    }

    return 1;
};

int tarefas_concluir_topo(ListaTarefas *lista)
{
    if (lista == NULL)
    {
        printf("ERRO: Lista de tarefas vázia!");
        return 0;
    }

    Tarefa *temp = lista->inicio;
    lista->inicio = lista->inicio->proximo;

    free(temp);
};

void tarefas_imprimir(ListaTarefas *lista)
{
    if (lista == NULL)
    {
        printf("ERRO: Lista de tarefas vázia!");
        exit(1);
    }

    Tarefa *atual = lista->inicio;

    printf("=== TAREFAS ===================\n");

    if (lista->inicio == NULL)
    {
        printf("Sem tarefas no momento.");
    }

    for (int i = 0; atual != NULL; i++)
    {
        printf("> %d. [#%d] %s\n", i + 1, atual->prioridade, atual->descricao);
        atual = atual->proximo;
    }
};

void tarefas_liberar(ListaTarefas *lista)
{
    Tarefa *atual = lista->inicio;

    while (atual != NULL)
    {
        Tarefa *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    free(lista);
};
