#include "turma.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct aluno
{
    char *nome;
    float nota;
} Aluno;

struct turma
{
    Aluno **alunos;
    int qtd;
    int cap;
};

Turma *turma_criar(int capacidade)
{
    Turma *t = (Turma *)malloc(sizeof(Turma));

    if (t == NULL)
        return NULL;

    t->cap = capacidade;
    t->qtd = 0;

    t->alunos = (Aluno **)malloc(capacidade * sizeof(Aluno *));

    for (int i = 0; i < capacidade; i++)
        t->alunos[i] = NULL;

    return t;
}

int turma_adicionar_aluno(Turma *turma, char *nome, float nota)
{
    if (turma == NULL)
    {
        printf("Turma vazia!");
        return 0;
    }

    if (turma->qtd >= turma->cap)
    {
        printf("Turma com capacidade máxima atingida!");
        return 0;
    }

    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));

    if (aluno == NULL)
    {
        printf("Falha na alocação!");
        return 0;
    }

    aluno->nome = strdup(nome);
    aluno->nota = nota;

    turma->alunos[turma->qtd] = aluno;
    turma->qtd++;

    return 1;
}

void turma_imprimir_lista(Turma *turma)
{
    printf("=== TURMA ===================\n");
    printf("> Total: %d\n> Capacidade máxima: %d\n\n", turma->qtd, turma->cap);

    printf("=== ALUNOS ==================\n");
    for (int i = 0; i < turma->qtd; i++)
    {
        printf("> #%d. %s - Nota: %.2f\n", i + 1, turma->alunos[i]->nome, turma->alunos[i]->nota);
    }
};

void turma_liberar(Turma *turma)
{
    if (turma == NULL)
        return;

    for (int i = 0; i < turma->qtd; i++)
    {
        if (turma->alunos[i] != NULL)
        {
            free(turma->alunos[i]->nome);
            free(turma->alunos[i]);
        }
    }

    free(turma->alunos);
    free(turma);
};