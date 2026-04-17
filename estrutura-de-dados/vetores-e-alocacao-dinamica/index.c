#include <stdio.h>
#include <stdlib.h>

void imprimirElementos(int *vetor, int numeroDeElementos)
{
    for (int i = 0; i < numeroDeElementos; i++)
    {
        printf("%d\n", vetor[i]);
    }
}

int main()
{
    int numeroDeElementos;
    int *vetor;

    printf("Quantos elementos terá o vetor? ");
    scanf("%d", &numeroDeElementos);

    vetor = (int *)malloc(numeroDeElementos * sizeof(int));

    if (vetor == NULL)
    {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }

    for (int i = 0; i < numeroDeElementos; i++)
    {
        vetor[i] = i * 10;
    }

    imprimirElementos(vetor, numeroDeElementos);

    free(vetor);

    return 0;
}