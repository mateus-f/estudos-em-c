#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "sistema.h"

enum tipo_cliente
{
    PESSOA_FISICA,
    PESSOA_JURIDICA
};

struct pessoa_fisica
{
    char *nome;
    char *cpf;
    float faturamento;
};

struct pessoa_juridica
{
    char *razao_social;
    char *cnpj;
    float faturamento;
};

union info_cliente
{
    PessoaFisica pf;
    PessoaJuridica pj;
};

struct no
{
    TipoCliente tipo;
    InfoCliente info;
    No *proximo;
};

int insere_pf(No **inicio, char *nome, char *cpf, float fat)
{
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("ERRO: Sem espaço na memória!");
        return 0;
    }

    novo->tipo = PESSOA_FISICA;
    novo->info.pf.nome = strdup(nome);
    novo->info.pf.cpf = strdup(cpf);
    novo->info.pf.faturamento = fat;
    novo->proximo = *inicio;

    *inicio = novo;

    return 1;
};

int insere_pj(No **inicio, char *razao, char *cnpj, float fat)
{
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("ERRO: Sem espaço na memória!");
        return 0;
    }

    novo->tipo = PESSOA_JURIDICA;
    novo->info.pj.razao_social = strdup(razao);
    novo->info.pj.cnpj = strdup(cnpj);
    novo->info.pj.faturamento = fat;
    novo->proximo = *inicio;

    *inicio = novo;

    return 1;
};

float calcular_total_impostos(No *inicio)
{
    No *atual = inicio;
    float total_imposto = 0;

    while (atual != NULL)
    {
        switch (atual->tipo)
        {
        case PESSOA_FISICA:
            total_imposto += atual->info.pf.faturamento * 0.15;
            break;

        case PESSOA_JURIDICA:
            total_imposto += atual->info.pj.faturamento * 0.1;
            break;

        default:
            break;
        }

        atual = atual->proximo;
    }

    return total_imposto;
};

void libera_no(No *inicio)
{
    No *atual = inicio;

    while (atual != NULL)
    {
        switch (atual->tipo)
        {
        case PESSOA_FISICA:
            free(atual->info.pf.nome);
            free(atual->info.pf.cpf);
            break;

        case PESSOA_JURIDICA:
            free(atual->info.pj.razao_social);
            free(atual->info.pj.cnpj);
            break;

        default:
            break;
        }

        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
};