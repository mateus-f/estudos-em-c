typedef struct tarefa Tarefa;
typedef struct lista_tarefas ListaTarefas;

ListaTarefas *tarefas_criar();

int tarefas_inserir_ordenado(ListaTarefas *lista, char *desc, int prioridade);
int tarefas_concluir_topo(ListaTarefas *lista);

void tarefas_imprimir(ListaTarefas *lista);
void tarefas_liberar(ListaTarefas *lista);
