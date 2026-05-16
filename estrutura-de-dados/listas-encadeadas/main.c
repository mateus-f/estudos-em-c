/* DESAFIO DE FIXAÇÃO: Lista Encadeada com Inserção Ordenada
    -------------------------------------------------------------------------
    OBJETIVO:
    Criar um "Gerenciador de Tarefas" (To-Do List) onde as tarefas não são
    inseridas no início nem no fim, mas sim ORDENADAS por prioridade.
    A tarefa com a MAIOR prioridade deve ficar sempre no início da lista.

    ESTRUTURAS (No arquivo tarefas.c):
    - Nó (Tarefa): char* descricao, int prioridade, struct tarefa* proximo.
    - TAD (ListaTarefas): struct tarefa* inicio.

    REGRAS DAS FUNÇÕES (.h e .c):
    1. ListaTarefas* tarefas_criar();
       - Aloca a estrutura gerenciadora e define o inicio como NULL.

    2. int tarefas_inserir_ordenado(ListaTarefas* l, char* desc, int prioridade);
       - Aloca o novo nó (lembre-se do strdup para a descrição).
       - Procure a posição correta usando dois ponteiros (atual e anterior).
       - Você deve avançar na lista enquanto o atual não for NULL E a
         prioridade do atual for MAIOR ou IGUAL à prioridade da nova tarefa.
       - Quando o laço parar, insira o novo nó entre o anterior e o atual.
       - Lembre-se de tratar o caso se a nova tarefa precisar virar o novo 'inicio'.

    3. int tarefas_concluir_topo(ListaTarefas* l);
       - Remove a tarefa do início da lista (que sempre será a de maior prioridade).
       - Lembre-se da sua lógica: salvar o ponteiro do início em um temporário,
         avançar o início da lista para o próximo, dar free na descrição e no temporário.

    4. void tarefas_imprimir(ListaTarefas* l);
       - Varre a lista exibindo a descrição e a prioridade de cada uma.

    5. void tarefas_liberar(ListaTarefas* l);
       - Libera toda a memória restante usando a lógica do ponteiro temporário.

    CENÁRIO DE TESTE (Na main.c):
    - Insira: "Estudar para Cálculo" (Prioridade 3)
    - Insira: "Fazer o lab de ED" (Prioridade 5)
    - Insira: "Lavar a louça" (Prioridade 1)

    A impressão OBRIGATORIAMENTE deve resultar em:
    [Prioridade 5] Fazer o lab de ED -> [Prioridade 3] Estudar para Cálculo -> [Prioridade 1] Lavar a louça -> NULL
    -------------------------------------------------------------------------
*/

#include "tarefa.h"

int main()
{

   ListaTarefas *lista = tarefas_criar();

   tarefas_inserir_ordenado(lista, "Estudar para Cálculo", 3);
   tarefas_inserir_ordenado(lista, "Fazer o lab de ED", 5);
   tarefas_inserir_ordenado(lista, "Lavar a louça", 1);

   tarefas_concluir_topo(lista);

   tarefas_imprimir(lista);

   tarefas_liberar(lista);

   return 0;
}
