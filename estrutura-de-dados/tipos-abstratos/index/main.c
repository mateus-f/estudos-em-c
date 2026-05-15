#include <stdio.h>
#include "ponto.h"

int main()
{

    Ponto *p1 = ponto_criar(10.0, 15.0);

    printf("Ponto X: %.2f", ponto_acessar_x(p1));
    ponto_liberar(p1);

    return 0;
}
