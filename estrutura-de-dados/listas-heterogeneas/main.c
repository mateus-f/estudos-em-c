/* EXERCÍCIO DE FIXAÇÃO: Lista Heterogênea de Clientes e Empresas
    -------------------------------------------------------------------------
    OBJETIVO:
    Implementar uma lista encadeada heterogênea para um sistema de cobrança.
    A lista deve armazenar dois tipos de clientes: Pessoa Física (CPF)
    e Pessoa Jurídica (CNPJ), calculando a taxa de imposto correta para cada um.

    ESTRUTURAS AUXILIARES:
    1. Struct PessoaFisica: char* nome, char* cpf, float faturamento.
    2. Struct PessoaJuridica: char* razao_social, char* cnpj, float faturamento.
    3. Enum TipoCliente: PESSOA_FISICA, PESSOA_JURIDICA.
    4. Union InfoCliente: PessoaFisica pf, PessoaJuridica pj.

    ESTRUTURA DO NÓ:
    - TipoCliente tipo;
    - InfoCliente info;
    - struct no* proximo;

    REGRAS DA IMPLEMENTAÇÃO:
    1. Crie funções de inserção específicas para cada tipo no início da lista, ex:
       - int insere_pf(No** inicio, char* nome, char* cpf, float fat);
       - int insere_pj(No** inicio, char* razao, char* cnpj, float fat);
       * Nota: Lembre-se de alocar os nós e usar strdup para os textos.

    2. Desenvolva a função: float calcular_total_impostos(No* inicio);
       - Varra a lista heterogênea usando um laço e uma estrutura switch(atual->tipo).
       - Se for PESSOA_FISICA: O imposto é de 15% (0.15) sobre o faturamento.
       - Se for PESSOA_JURIDICA: O imposto é de 10% (0.10) sobre o faturamento.
       - A função deve retornar a soma de todos os impostos calculados.

    3. Desenvolva a função de liberação de memória de forma adequada, garantindo
       que os campos de texto internos de cada struct da união recebam free()
       antes do nó em si ser liberado.
    -------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>

#include "sistema.h"

int main()
{
    No *lista_cobranca = NULL;
    float total_impostos = 0.0;

    printf("--- Iniciando Cadastro no Sistema de Cobrança ---\n");

    // Faturamento: 10.000,00 -> Imposto esperado: 1.500,00
    if (insere_pf(&lista_cobranca, "Mateus Ferreira", "123.456.789-00", 10000.00))
    {
        printf("[SUCESSO] Pessoa Física inserida.\n");
    }
    else
    {
        printf("[ERRO] Falha ao inserir Pessoa Física.\n");
    }

    // Faturamento: 50.000,00 -> Imposto esperado: 5.000,00
    if (insere_pj(&lista_cobranca, "Tech Solutions Ltda", "12.345.678/0001-99", 50000.00))
    {
        printf("[SUCESSO] Pessoa Jurídica inserida.\n");
    }
    else
    {
        printf("[ERRO] Falha ao inserir Pessoa Jurídica.\n");
    }

    // Faturamento: 5.000,00 -> Imposto esperado: 750,00
    if (insere_pf(&lista_cobranca, "Ana Rosa", "987.654.321-11", 5000.00))
    {
        printf("[SUCESSO] Pessoa Física inserida.\n");
    }
    else
    {
        printf("[ERRO] Falha ao inserir acréscimo.\n");
    }

    // Total esperado: 1.500,00 + 5.000,00 + 750,00 = 7.250,00
    total_impostos = calcular_total_impostos(lista_cobranca);

    printf("\n--- Relatório Fiscal ---\n");
    printf("Total de Impostos a Recolher: R$ %.2f\n", total_impostos);

    libera_no(lista_cobranca);
    printf("\n[MEMÓRIA] Lista liberada com sucesso. Encerrando programa.\n");

    return 0;
}