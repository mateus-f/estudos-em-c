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

void interfaceInicial() {
    printf("================================================\n");
    printf("       SISTEMA DE CINEMA DINÂMICO              \n");
    printf("================================================\n");
    printf(" Gerenciamento de Memória: Matriz [int **]      \n");
    printf("================================================\n\n");
}