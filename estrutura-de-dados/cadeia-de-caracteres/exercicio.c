/******************************************************************************
 * EXERCÍCIO: ECONOMIA DE MEMÓRIA (STRINGS)
 * ----------------------------------------------------------------------------
 * OBJETIVO:
 * Criar um programa que receba o nome de 3 disciplinas e as armazene
 * usando o mínimo de memória possível.
 * * REQUISITOS:
 * 1. Criar um vetor de ponteiros: `char *disciplinas[3]`.
 * 2. Para cada disciplina:
 * - Ler o nome em um buffer temporário.
 * - Alocar dinamicamente o tamanho exato.
 * - Copiar o nome para a posição do vetor.
 * 3. Imprimir a lista de disciplinas e o total de bytes economizados.
 * 4. Liberar a memória de cada string individualmente.
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE_BUFFER 100
#define QTD_DISCIPLINA 3

void interfaceInicial()
{
    printf("================================================\n");
    printf("       OTIMIZADOR DE MEMÓRIA PARA STRINGS      \n");
    printf("================================================\n\n");
}

void validarAlocacaoFalha(void *ponteiro)
{
    if (ponteiro == NULL)
    {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }
}

void imprimirVetor(char *vetor[], int tamanhoVetor)
{
    printf("# DISCIPLINAS IMPRESSAS:\n");
    for (int i = 0; i < tamanhoVetor; i++)
    {
        if (vetor[i] != NULL)
        {
            printf("%d. %s\n", i + 1, vetor[i]);
        }
    }
}

void imprimirMemoriaEconomizada(char *vetor[], int tamanhoVetor, char buffer[])
{
    int somaDeBytesReais = 0;
    int gastoEstaticoTeorico = QTD_DISCIPLINA * LIMITE_BUFFER;

    for (int i = 0; i < tamanhoVetor; i++)
    {
        int quantidadeDeBytes = strlen(vetor[i]) + 1;

        somaDeBytesReais += quantidadeDeBytes;
    }

    int bytesEconomizados = gastoEstaticoTeorico - somaDeBytesReais;

    printf("# RESUMO DOS BYTES\n");
    printf("- Total do buffer: %d Bytes\n", gastoEstaticoTeorico);
    printf("- Dinamicamente utilizado: %d Bytes\n", somaDeBytesReais);
    printf("- Economia: %d Bytes\n", bytesEconomizados);
}

void limparVetorDePonteiros(char *vetor[], int tamanhoVetor)
{
    for (int i = 0; i < tamanhoVetor; i++)
    {
        if (vetor[i] != NULL)
        {
            free(vetor[i]);
            vetor[i] = NULL;
        }
    }
}

int main()
{
    char buffer[LIMITE_BUFFER];
    char *disciplinas[QTD_DISCIPLINA];

    interfaceInicial();

    printf("# INSERIR DISCIPLINAS\n");

    for (int i = 0; i < QTD_DISCIPLINA; i++)
    {
        printf("- Disciplina %d: ", i + 1);
        scanf(" %99[^\n]", buffer);

        disciplinas[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

        validarAlocacaoFalha(disciplinas[i]);

        strcpy(disciplinas[i], buffer);
    }

    printf("\n================================================\n\n");

    imprimirVetor(disciplinas, QTD_DISCIPLINA);

    printf("\n================================================\n\n");

    imprimirMemoriaEconomizada(disciplinas, QTD_DISCIPLINA, buffer);

    limparVetorDePonteiros(disciplinas, QTD_DISCIPLINA);

    return 0;
}