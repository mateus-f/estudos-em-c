typedef struct no No;
typedef struct pilha Pilha;

Pilha *cria_pilha();
void libera_pilha(Pilha *pilha);

int push_pilha(Pilha *pilha, char caractere);
int pop_pilha(Pilha *pilha, char *valor_retornado);

int verifica_par(char anterior, char atual);
int verifica_balanco(char *expressao);