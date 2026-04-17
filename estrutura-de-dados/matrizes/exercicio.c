/******************************************************************************
 * EXERCÍCIO: MAPA DE ASSENTOS DINÂMICO
 * ----------------------------------------------------------------------------
 * OBJETIVO:
 * Criar um sistema de reserva de assentos para uma sala de cinema/teatro
 * usando uma matriz dinâmica (ponteiro para ponteiro).
 * * REQUISITOS:
 * 1. Perguntar ao usuário o número de FILEIRAS e de ASSENTOS por fileira.
 * 2. Alocar a matriz dinâmica `int **sala` (0 para livre, 1 para ocupado).
 * 3. Inicializar todos os assentos como LIVRES (0).
 * 4. Permitir que o usuário escolha uma coordenada (fileira, assento) para
 * marcar como OCUPADO (1).
 * 5. Criar uma função `exibirSala` que mostre a matriz de forma organizada.
 * * REGRAS DE OURO:
 * - A alocação deve ser em duas etapas: primeiro o vetor de `int*`,
 * depois cada linha de `int`.
 * - A liberação (free) deve seguir a ordem inversa da alocação.
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void interfaceInicial()
{
    printf("================================================\n");
    printf("       SISTEMA DE CINEMA DINÂMICO              \n");
    printf("================================================\n");
    printf(" Gerenciamento de Memória: Matriz [int **]      \n");
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

int *inicializarAssentos(int assentos)
{
    int *fileiraPreenchida = (int *)malloc(assentos * sizeof(int));

    validarAlocacaoFalha(fileiraPreenchida);

    for (int i = 0; i < assentos; i++)
    {
        fileiraPreenchida[i] = 0;
    }

    return fileiraPreenchida;
}

int **realizarMapeamentoInicial(int fileiras, int assentos)
{
    int **novaSala = (int **)malloc(fileiras * sizeof(int *));

    validarAlocacaoFalha(novaSala);

    for (int i = 0; i < fileiras; i++)
    {
        novaSala[i] = inicializarAssentos(assentos);
    }

    return novaSala;
}

int ocuparAssento(int **sala, int fileiraEscolhida, int assentoEscolhido, int totalFileiras, int totalAssentos)
{
    if (sala != NULL)
    {

        if ((fileiraEscolhida < 0) || (fileiraEscolhida > totalFileiras) || (assentoEscolhido < 0) || (assentoEscolhido > totalAssentos))
        {
            printf("\n[ERRO] Posição [%d][%d] não existe nesta sala!\n", fileiraEscolhida, assentoEscolhido);
            return 0;
        }

        if (sala[fileiraEscolhida - 1][assentoEscolhido - 1] == 1)
        {
            printf("\n[AVISO] O assento [%d][%d] já está ocupado!\n", fileiraEscolhida, assentoEscolhido);
            return 0;
        }

        sala[fileiraEscolhida - 1][assentoEscolhido - 1] = 1;

        printf("\nAssento [%d][%d] ocupado com sucesso!\n", fileiraEscolhida, assentoEscolhido);

        return 1;
    }
}

void imprimirMapeamentoDaSala(int **sala, int fileiras, int assentos)
{
    printf("# NOVO MAPEAMENTO DA SALA:\n");
    for (int i = 0; i < fileiras; i++)
    {
        for (int j = 0; j < assentos; j++)
        {
            printf("%d ", sala[i][j]);
        }

        printf("\n");
    }
}

void limparMatriz(int **matriz, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }

    free(matriz);
}

int main()
{
    int **sala;
    int fileiras, assentos;

    interfaceInicial();

    printf("# CONFIGURAÇÃO DA SALA:\n");
    printf("Quantas FILEIRAS a sala possui? ");
    scanf("%d", &fileiras);
    printf("E quantos ASSENTOS por fileira? ");
    scanf("%d", &assentos);
    printf("\n================================================\n");

    sala = realizarMapeamentoInicial(fileiras, assentos);

    int reservaConcluida = 0;

    while (!reservaConcluida)
    {
        int fileiraEscolhida, assentoEscolhido;
        printf("\n# ESCOLHER ASSENTO PARA OCUPAR:\n");

        printf("Qual fileira deseja ficar (TOTAL: %d)? ", fileiras);
        scanf("%d", &fileiraEscolhida);
        printf("E em qual assento (TOTAL: %d)? ", assentos);
        scanf("%d", &assentoEscolhido);

        reservaConcluida = ocuparAssento(sala, fileiraEscolhida, assentoEscolhido, fileiras, assentos);

        if (!reservaConcluida)
        {
            printf("Por favor, tente novamente.\n");
        }
    }

    printf("\n================================================\n\n");

    imprimirMapeamentoDaSala(sala, fileiras, assentos);

    limparMatriz(sala, fileiras);

    return 0;
}