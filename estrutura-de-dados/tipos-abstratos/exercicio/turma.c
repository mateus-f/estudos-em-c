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
        return NULL;

    if (turma->qtd >= turma->cap)
    {
        printf("Turma com capacidade máxima atingida!");
        return 0;
    }

    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));

    if (aluno == NULL)
        return NULL;

    aluno->nome = strdup(nome);
    aluno->nota = nota;

    turma->alunos[turma->qtd] = aluno;
    turma->qtd++;

    return 1;
}

void turma_imprimir_lista(Turma *turma);
void turma_liberar(Turma *turma);