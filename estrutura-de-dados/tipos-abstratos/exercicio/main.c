/* DESAFIO: TAD Cadastro de Alunos
    -------------------------------------------------------------------------
    OBJETIVO: Criar um sistema onde o usuário gerencia uma "Turma".
    A Turma deve esconder um vetor dinâmico de ponteiros para a struct "Aluno".

    ARQUIVOS:
    1. turma.h:
       - Defina: typedef struct turma Turma;
       - Protótipos:
         * Turma* turma_criar(int capacidade);
         * int turma_adicionar_aluno(Turma* t, char* nome, float nota);
         * void turma_imprimir_lista(Turma* t);
         * void turma_liberar(Turma* t);

    2. turma.c:
       - A struct "Turma" deve ter: Aluno** alunos, int qtd, int cap.
       - A struct "Aluno" (privada no .c) deve ter: char* nome e float nota.
       - IMPORTANTE: No adicionar_aluno, você deve usar strdup() ou malloc+strcpy
         para duplicar a string do nome, evitando que o TAD aponte para
         uma memória temporária da main.

    3. main.c:
       - Teste o cadastro de 3 alunos.
       - Tente adicionar um 4º aluno em uma turma de capacidade 3 e trate o erro.

    DICA DE MONITOR:
    Lembre-se que para liberar a Turma, a ordem é:
    1. Free no char* nome de cada aluno.
    2. Free em cada struct Aluno.
    3. Free no vetor de ponteiros (alunos**).
    4. Free na struct Turma.
    -------------------------------------------------------------------------
*/

#include "turma.h"

int main()
{
    Turma *t = turma_criar(10);

    turma_adicionar_aluno(t, "Mateus", 10.0);
    turma_adicionar_aluno(t, "Marcos", 8.5);
    turma_adicionar_aluno(t, "João", 7.0);
    turma_adicionar_aluno(t, "Lucas", 9.6);
    turma_adicionar_aluno(t, "Paulo", 7.9);

    turma_imprimir_lista(t);

    turma_liberar(t);

    return 0;
}
