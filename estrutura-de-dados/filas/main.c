/* EXERCÍCIO DE FIXAÇÃO: O Simulador de Fila de Banco (Gerenciador de Atendimento)
    -------------------------------------------------------------------------
    OBJETIVO:
    Implementar um sistema de gerenciamento de atendimento para uma agência bancária.
    O sistema deve emitir senhas numéricas e chamar os clientes por ordem de chegada.

    ESTRUTURAS DO TAD (fila_banco.c):
    - Nó: int numero_senha, struct no* proximo.
    - Estrutura Fila: Nó* inicio, Nó* fim.

    REGRAS DAS FUNÇÕES DO TAD:
    1. Fila* fila_criar();
       - Aloca a estrutura da fila e inicializa inicio e fim como NULL.

    2. int emitir_senha(Fila* f, int proxima_senha);
       - Equivale ao Enqueue. Aloca um nó com o número da senha e insere no FIM da fila.
       - Trate corretamente o caso da fila estar vazia.

    3. int chamar_proximo(Fila* f, int* senha_chamada);
       - Equivale ao Dequeue. Remove o cliente que está no INÍCIO da fila.
       - Copia o número da senha para a variável 'senha_chamada' (passada por ponteiro).
       - Se a fila ficar vazia após a remoção, lembre-se de atualizar f->fim para NULL.
       - Libere a memória do nó removido. Retorne 1 para sucesso e 0 se a fila estiver vazia.

    4. void fila_liberar(Fila* f);
       - Limpa todos os nós que ainda restarem na fila usando um laço e libera a struct Fila.

    CENÁRIO DE TESTE (Na main.c):
    - Emita as senhas: 101, 102, 103.
    - Chame o próximo cliente -> Deve exibir: "Chamando senha: 101"
    - Emita a senha: 104.
    - Chame o próximo cliente -> Deve exibir: "Chamando senha: 102"
    -------------------------------------------------------------------------
*/

#include "fila_banco.h"

int main()
{
    Fila *fila_banco = fila_criar();

    emitir_senha(fila_banco, 101);
    emitir_senha(fila_banco, 102);
    emitir_senha(fila_banco, 103);

    int senha_chamada;

    chamar_proximo(fila_banco, &senha_chamada);

    emitir_senha(fila_banco, 104);

    chamar_proximo(fila_banco, &senha_chamada);

    return 0;
}