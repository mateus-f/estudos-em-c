
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void validarAlocacaoFalha(void *ponteiro)
{
    if (ponteiro == NULL)
    {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }
}

typedef struct aluno
{
    char *nome;
    int idade;
    long matricula;
} Aluno;

int main()
{
    char buffer[100];

    Aluno *ptr_aluno = (Aluno *)malloc(sizeof(Aluno));

    printf("- Nome do aluno: ");
    scanf(" %99[^\n]", buffer);
    printf("- Idade: ");
    scanf("%d", &ptr_aluno->idade);
    printf("- Matrícula: ");
    scanf("%ld", &ptr_aluno->matricula);

    ptr_aluno->nome = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

    validarAlocacaoFalha(ptr_aluno->nome);

    strcpy(ptr_aluno->nome, buffer);

    printf("\n# APRESENTAÇÃO INDIVIDUAL:\n");
    printf("O aluno %s, de matrícula %ld, possui atualmente %d anos de idade.", ptr_aluno->nome, ptr_aluno->matricula, ptr_aluno->idade);

    return 0;
}