typedef struct no No;
typedef struct fila Fila;

Fila *fila_criar();
int emitir_senha(Fila *f, int proxima_senha);
int chamar_proximo(Fila *f, int *senha_chamada);
void fila_liberar(Fila* f);