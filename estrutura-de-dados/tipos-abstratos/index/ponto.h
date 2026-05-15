typedef struct ponto Ponto;

Ponto *ponto_criar(float x, float y);
void ponto_liberar(Ponto *ponto);
float ponto_acessar_x(Ponto *ponto);
float ponto_acessar_y(Ponto *ponto);