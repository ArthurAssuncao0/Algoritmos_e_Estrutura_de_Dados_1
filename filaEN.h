struct aluno{
    char nome[30];
    int matricula;
    float nota;
};
typedef struct aluno Aluno;

struct no{
    Aluno aluno;
    struct no *proximo;
};
typedef struct no No;

struct fila{
    No *inicio;
    No *fim;
    int quant;
};
typedef struct fila Fila;

Fila *criar();

void limparFila(Fila *fila);

//void inserirStruct(Aluno *aluno, char nome[], int matricula, float nota);

void mostrarFila(Fila *fila);

int inserirFila(Fila *fila, Aluno aluno);

int removerFila(Fila *fila, Aluno *aluno);

int consultarFila(Fila *fila, Aluno *aluno);

int tamanho(Fila *fila);

int filaVazia(Fila *fila);

int filaCheia(Fila *fila);