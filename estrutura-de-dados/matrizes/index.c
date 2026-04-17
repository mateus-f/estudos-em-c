#include <stdio.h>
#include <stdlib.h>

void limparMatriz(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }

    free(matriz);
}

void imprimirMatriz(int **matriz, int linhas, int colunas)
{
    printf("MATRIZ IMPRESSA:\n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int **matriz;
    int linhas, colunas;

    printf("---- CONFIGURAÇÃO DA MATRIZ ----\n");
    printf("Quantas linhas terá a matriz? ");
    scanf("%d", &linhas);
    printf("E colunas? ");
    scanf("%d", &colunas);
    printf("--------------------------------\n");

    matriz = (int **)malloc(linhas * sizeof(int *));

    if (matriz == NULL)
    {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }

    for (int i = 0; i < linhas; i++)
    {
        printf("LINHA #0%d\n", i + 1);
        matriz[i] = (int *)malloc(colunas * sizeof(int));

        if (matriz[i] == NULL)
        {
            printf("Erro: Memória insuficiente!\n");
            exit(1);
        }

        for (int j = 0; j < colunas; j++)
        {
            printf("- Coluna 0%d: ", j + 1);
            scanf("%d", &matriz[i][j]);
        }
        printf("--------------------------------\n");
    }

    imprimirMatriz(matriz, linhas, colunas);
    limparMatriz(matriz, linhas, colunas);

    return 0;
}