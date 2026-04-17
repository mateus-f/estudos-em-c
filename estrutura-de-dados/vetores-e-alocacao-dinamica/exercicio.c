/*
 * EXERCÍCIO: Sistema de Notas do IF
 * ===============================================================
 * OBJETIVO: Gerenciar notas de N1 e N2 usando alocação dinâmica.
 * > REGRAS:
 *   1. Perguntar a quantidade de avaliações para N1 e para N2.
 *   2. Alocar dinamicamente os vetores para armazenar essas notas.
 *   3. Calcular a média aritmética simples de N1 e N2.
 *   4. Calcular a Média Ponderada (MP): (N1 * 2 + N2 * 3) / 5.
 * > CRITÉRIOS DE APROVAÇÃO:
 *   - MP >= 7.0: Aprovado direto.
 *   - MP < 3.0: Reprovado direto.
 *   - 3.0 <= MP < 7.0: Recuperação.
 *     -> Na recuperação, a nota deve ser alocada dinamicamente.
 *     -> Critério: (Média das Notas + Nota da Recuperação) >= 10.0.
 * > OBS: Lembre-se de liberar toda a memória alocada com free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void interfaceInicial()
{

    printf("==========================================================\n");
    printf("                 SISTEMA DE NOTAS - IF                  \n");
    printf("==========================================================\n");
    printf("       Diretrizes: Pesos N1(2) e N2(3) | Min: 7.0         \n");
    printf("----------------------------------------------------------\n\n");
}

void preencherNotas(float *notasDoPeriodo, int qtdDeAvaliacoes)
{
    printf("\n-------------------- INSIRA AS NOTAS ---------------------\n");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < qtdDeAvaliacoes; i++)
    {
        float nota;
        printf("- NOTA %d: ", i + 1);
        scanf("%f", &nota);
        notasDoPeriodo[i] = nota;
    }

    printf("\n");
}

float calcularMediaAritmetica(float *notasDoPeriodo, int qtdDeAvaliacoes)
{
    float somaDeNotas = 0;

    for (int i = 0; i < qtdDeAvaliacoes; i++)
    {
        somaDeNotas += notasDoPeriodo[i];
    }

    return somaDeNotas / qtdDeAvaliacoes;
}

float calcularMediaPonderada(float notaN1, float notaN2)
{
    const int PESO_N1 = 2, PESO_N2 = 3;

    return ((notaN1 * PESO_N1) + (notaN2 * PESO_N2)) / (PESO_N1 + PESO_N2);
}

char *determinarStatus(float mediaFinal)
{
    char *texto;

    texto = (char *)malloc(20 * sizeof(char));

    if (texto == NULL)
    {
        printf("Erro: Memória insuficiente!\n");
        return NULL;
    }

    if (mediaFinal >= 7.0)
        strcpy(texto, "APROVADO! :D");
    else if (mediaFinal < 3.0)
        strcpy(texto, "REPROVADO! :/");
    else
        strcpy(texto, "RECUPERAÇÃO! O_O");

    return texto;
}

void obterSituacaoAluno(float *notasN1, float *notasN2, int qtdAvaliacoesN1, int qtdAvaliacoesN2)
{
    float mediaAritmeticaN1 = calcularMediaAritmetica(notasN1, qtdAvaliacoesN1);
    float mediaAritmeticaN2 = calcularMediaAritmetica(notasN2, qtdAvaliacoesN2);

    float mediaFinal = calcularMediaPonderada(mediaAritmeticaN1, mediaAritmeticaN2);
    char *statusString = determinarStatus(mediaFinal);

    printf("\n- MÉDIA FINAL       : %.2f\n", mediaFinal);

    if (statusString != NULL)
    {
        printf("- STATUS            : %s", statusString);

        if (strcmp(statusString, "RECUPERAÇÃO! O_O") == 0)
        {
            float notaRestante = 10 - mediaFinal;
            printf("\n- VOCÊ TEM UMA SAÍDA: PRECISA TIRAR %.2f NA RECUPERAÇÃO", notaRestante);
        }

        free(statusString);
        statusString = NULL;
    }
}

int main()
{
    int qtdAvaliacoesN1, qtdAvaliacoesN2;
    float *notasN1, *notasN2;

    interfaceInicial();

    printf("---------- QUANTIDADE DE AVALIAÇÕES POR PERÍODO ----------\n");
    printf("----------------------------------------------------------\n");
    printf("N1: ");
    scanf("%d", &qtdAvaliacoesN1);

    notasN1 = (float *)malloc(qtdAvaliacoesN1 * sizeof(float));

    preencherNotas(notasN1, qtdAvaliacoesN1);

    printf("N2: ");
    scanf("%d", &qtdAvaliacoesN2);

    notasN2 = (float *)malloc(qtdAvaliacoesN2 * sizeof(float));

    preencherNotas(notasN2, qtdAvaliacoesN2);

    printf("======================= RESULTADO ========================");

    if (notasN1 == NULL || notasN2 == NULL)
    {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }

    obterSituacaoAluno(notasN1, notasN2, qtdAvaliacoesN1, qtdAvaliacoesN2);

    printf("\n==========================================================");

    free(notasN1);
    notasN1 = NULL;

    free(notasN2);
    notasN2 = NULL;

    return 0;
}