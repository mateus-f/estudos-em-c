/* EXERCÍCIO DE FIXAÇÃO: O Validador de Parênteses e Chaves (Syntax Checker)
    -------------------------------------------------------------------------
    OBJETIVO:
    Utilizar o conceito de Pilha (LIFO) para resolver um problema clássico de
    compiladores: verificar se as chaves '{ }', colchetes '[ ]' e parênteses '( )'
    de uma expressão matemática ou código-fonte estão balanceados e fechados na
    ordem correta.

    POR QUE USAR PILHA?
    Sempre que encontrarmos um caractere de abertura, nós o empilhamos (Push).
    Sempre que encontrarmos um caractere de fechamento, nós desempilhamos (Pop)
    e verificamos se ele faz par com o símbolo que acabou de sair do topo da pilha.

    ESTRUTURAS DO TAD (pilha_char.c):
    - Nó: char caractere, struct no* proximo.
    - Estrutura Pilha: Nó* topo.

    REGRAS DA FUNÇÃO PRINCIPAL:
    Desenvolva a função: int verifica_balanco(char* expressao);

    LÓGICA DA VERIFICAÇÃO:
    1. Varra a string 'expressao' caractere por caractere (com um laço).
    2. Se o caractere atual for '(', '[' ou '{', dê um PUSH dele na pilha.
    3. Se o caractere atual for ')', ']' ou '}':
       - Dê um POP na pilha para descobrir qual foi o último símbolo aberto.
       - Se a pilha estiver vazia antes do POP, ou se o símbolo desempilhado
         não fechar corretamente o atual (ex: abriu '[' e tentou fechar com ')'),
         a expressão está INCORRETA.
    4. Ao final do laço da string, a pilha DEVE ESTAR COMPLETAMENTE VAZIA.
       Se sobrar algo na pilha, significa que algum símbolo foi aberto mas nunca fechado.
    5. Lembre-se de liberar toda a memória da pilha antes de retornar o resultado (0 ou 1).

    CENÁRIOS DE TESTE NA MAIN:
    - expressao1 = "((A+B)*{C-D})"       -> Deve retornar 1 (Válida)
    - expressao2 = "[A+B}(C)"            -> Deve retornar 0 (Inválida: fechou errado)
    - expressao3 = "((A+B)"              -> Deve retornar 0 (Inválida: sobrou item na pilha)
    - expressao4 = "A+B)"                -> Deve retornar 0 (Inválida: desempilhou de pilha vazia)
    -------------------------------------------------------------------------
*/

#include <stdio.h>

#include "pilha.h"

#define TAM_MAX 200

int main()
{
    char expressao[TAM_MAX];

    printf("=== VALIDADOR DE SINTAXE (PILHAS) ===================\n\n");
    printf("Digite a expressão matemática ou código para validar:\n> ");

    if (fgets(expressao, TAM_MAX, stdin) != NULL)
    {
        printf("\n-----------------------------------------------------\n");

        if (verifica_balanco(expressao))
        {
            printf("SUCESSO: A expressão está perfeitamente balanceada!\n");
        }
        else
        {
            printf("ERRO: Sintaxe inválida! Há símbolos '{ }', '[ ]' ou '( )' mal fechados.\n");
        }

        printf("-----------------------------------------------------\n");
    }

    return 0;
}
