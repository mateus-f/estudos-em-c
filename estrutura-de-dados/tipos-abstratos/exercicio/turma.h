typedef struct turma Turma;

Turma *turma_criar(int capacidade);
int turma_adicionar_aluno(Turma *turma, char *nome, float nota);
void turma_imprimir_lista(Turma *turma);
void turma_liberar(Turma *turma);