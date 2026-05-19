# Estrutura de Dados

Este subdiretório é dedicado aos conceitos, tópicos teóricos e implementações práticas desenvolvidos na disciplina de **Estrutura de Dados em C**.

## 🗂️ Organização do Conteúdo

Abaixo estão listados os tópicos estudados, divididos por conceitos fundamentais e estruturas de dados lineares/complexas:

### ⚙️ Fundamentos e Manipulação de Memória
* `vetores-e-alocacao-dinamica/`: Gerenciamento manual de memória (`malloc`, `calloc`, `free`) e vetores.
* `matrizes/`: Alocação bidimensional e manipulação de matrizes na memória.
* `cadeia-de-caracteres/`: Manipulação de strings, ponteiros e funções padrão da biblioteca `<string.h>`.

### 🧩 Abstração e Tipagem
* `tipos-estruturados/`: Uso de `struct` para criação de novos tipos de dados.
* `tipos-abstratos/`: Implementação de TADs (Tipos Abstratos de Dados), separando a especificação (`.h`) da implementação (`.c`).

### ⛓️ Estruturas de Dados Lineares
* `listas-encadeadas/`: Implementações de listas com encadeamento dinâmico.
* `listas-heterogeneas/`: Listas capazes de armazenar diferentes tipos de dados em seus nós.
* `pilhas/`: Estruturas do tipo LIFO (Last In, First Out).
* `filas/`: Estruturas do tipo FIFO (First In, First Out).

## 🛠️ Compilação e Execução

Como o repositório utiliza a linguagem C pura, os arquivos podem ser compilados utilizando o `gcc`. 

**Exemplo básico de compilação:**
```bash
gcc nome_do_arquivo.c -o programa
./programa