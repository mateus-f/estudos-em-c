#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[100];
    char *nomeDoCurso;

    printf("Digite o nome do curso: ");
    scanf(" %99[^\n]", buffer);

    nomeDoCurso = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

    if (nomeDoCurso != NULL)
    {
        strcpy(nomeDoCurso, buffer);
        printf("Curso alocado: %s (Tamanho: %lu bytes)\n", nomeDoCurso, strlen(nomeDoCurso) + 1);
    }

    free(nomeDoCurso);

    return 0;
}