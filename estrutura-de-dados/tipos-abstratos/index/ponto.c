#include <stdlib.h>
#include <stdio.h>
#include "ponto.h"

struct ponto
{
    float x;
    float y;
};

Ponto *ponto_criar(float x, float y)
{
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));

    if (p != NULL)
    {
        p->x = x;
        p->y = y;
    }

    return p;
}

void ponto_liberar(Ponto *ponto)
{
    if (ponto != NULL)
    {
        free(ponto);
    }
}

float ponto_acessar_x(Ponto *ponto)
{
    if (ponto == NULL)
    {
        printf("Ponto inexistente!");
        exit(1);
    }

    return ponto->x;
}

float ponto_acessar_y(Ponto *ponto)
{
    if (ponto == NULL)
    {
        printf("Ponto inexistente!");
        exit(1);
    }

    return ponto->y;
};