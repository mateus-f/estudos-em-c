typedef enum tipo_cliente TipoCliente;
typedef union info_cliente InfoCliente;

typedef struct pessoa_fisica PessoaFisica;
typedef struct pessoa_juridica PessoaJuridica;
typedef struct no No;

int insere_pf(No **inicio, char *nome, char *cpf, float fat);
int insere_pj(No **inicio, char *razao, char *cnpj, float fat);
float calcular_total_impostos(No *inicio);
void libera_no(No *inicio);