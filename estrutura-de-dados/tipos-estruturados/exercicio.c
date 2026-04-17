/******************************************************************************
 * EXERCÍCIO: SISTEMA DE GESTÃO DE FROTA (VETOR DE STRUCTS)
 * ----------------------------------------------------------------------------
 * OBJETIVO:
 * Gerenciar múltiplos veículos com alocação dinâmica para o vetor e nomes.
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *modelo;
    int ano;
} Veiculo;

void interfaceInicial()
{
    printf("================================================\n");
    printf("           SISTEMA DE GESTÃO DE FROTA          \n");
    printf("================================================\n\n");
}

void validarAlocacaoFalha(void *ponteiro)
{
    if (ponteiro == NULL)
    {
        printf("Erro ao alocar memória para a frota!\n");
        exit(1);
    }
}

Veiculo *cadastrarVeiculos(Veiculo *frota, int numeroDeVeiculos)
{
    char buffer[100];

    Veiculo *novaFrota = (Veiculo *)malloc(numeroDeVeiculos * sizeof(Veiculo));
    validarAlocacaoFalha(novaFrota);

    printf("# CADASTRO DE VEÍCULOS:");

    for (int i = 0; i < numeroDeVeiculos; i++)
    {
        printf("\n- VEÍCULO #0%d\n", i + 1);

        novaFrota[i].modelo = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        validarAlocacaoFalha(novaFrota[i].modelo);

        printf(" > Modelo: ");
        scanf(" %99[^\n]", buffer);
        strcpy(novaFrota[i].modelo, buffer);

        printf(" > Ano: ");
        scanf("%d", &novaFrota[i].ano);
    }

    return novaFrota;
};

void exibirFrota(Veiculo *frota, int numeroDeVeiculos)
{
    printf("# EXIBIÇÃO DA FROTA:\n");

    for (int i = 0; i < numeroDeVeiculos; i++)
    {
        printf("%d. %s - Ano: %d", i + 1, frota[i].modelo, frota[i].ano);
    }
}

int main()
{
    int numeroDeVeiculos;
    char buffer[100];
    Veiculo *frota;

    interfaceInicial();

    printf("# TAMANHO DA FROTA:\n");
    printf("Quantos veículos deseja cadastrar na frota? ");
    scanf("%d", &numeroDeVeiculos);

    validarAlocacaoFalha(frota);

    printf("\n================================================\n\n");

    frota = cadastrarVeiculos(frota, numeroDeVeiculos);

    printf("\n================================================\n\n");

    exibirFrota(frota, numeroDeVeiculos);
    return 0;
}