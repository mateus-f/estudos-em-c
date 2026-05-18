#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "pilha.h"

struct no
{
    char caractere;
    No *proximo;
};

struct pilha
{
    No *topo;
};

Pilha *cria_pilha()
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));

    if (pilha == NULL)
    {
        printf("ERRO: Memória insufiente!");
        exit(1);
    }

    pilha->topo = NULL;

    return pilha;
};

void libera_pilha(Pilha *pilha)
{
    if (pilha == NULL)
    {
        printf("Pilha já vázia!");
        exit(1);
    }

    No *atual = pilha->topo;

    while (atual != NULL)
    {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    free(pilha);
};

int push_pilha(Pilha *pilha, char caractere)
{
    if (pilha == NULL)
    {
        printf("ERRO: Pilha vázia!");
        return 0;
    }

    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("ERRO: Memória insufiente!");
        return 0;
    }

    novo->caractere = caractere;
    novo->proximo = pilha->topo;
    pilha->topo = novo;

    return 1;
};

int pop_pilha(Pilha *pilha, char *valor_retornado)
{
    if (pilha == NULL || pilha->topo == NULL)
    {
        printf("ERRO: Pilha vázia!");
        return 0;
    }

    No *temp = pilha->topo;
    *valor_retornado = temp->caractere;
    pilha->topo = pilha->topo->proximo;

    free(temp);

    return 1;
};

int verifica_par(char abertura, char fechamento)
{
    if (abertura == '(' && fechamento == ')')
        return 1;
    if (abertura == '[' && fechamento == ']')
        return 1;
    if (abertura == '{' && fechamento == '}')
        return 1;

    return 0;
};

int verifica_balanco(char *expressao)
{
    int cont = -1;
    Pilha *pilha = cria_pilha();

    for (int i = 0; i < strlen(expressao); i++)
    {
        char atual = expressao[i];

        if (atual == '(' || atual == '{' || atual == '[')
        {
            push_pilha(pilha, atual);
            cont++;
        }
        else if (atual == ')' || atual == '}' || atual == ']')
        {
            if (cont == -1)
            {
                return 0;
            }

            char ultimo_char;
            pop_pilha(pilha, &ultimo_char);
            cont--;

            if (!verifica_par(ultimo_char, atual))
            {
                return 0;
            }
        }
    }

    libera_pilha(pilha);

    return cont == -1 ? 1 : 0;
}
