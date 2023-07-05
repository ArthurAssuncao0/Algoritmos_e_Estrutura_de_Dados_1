#define ERROR 1
#define OK 0

struct aluno{
    char nome[30];
    int matricula;
    float nota;
};
typedef struct aluno Aluno;

 struct no{
    Aluno aluno;
    struct no *proximo;
    struct no *anterior;
};
typedef struct no No;
    
struct lista{
    No *inicio;
};
typedef struct lista Lista;

Lista * criar(); //OK

int listaVazia(Lista *lista); //OK

void adicionarStruct(Aluno *aluno, char nome[], int matricula, float nota); //OK

int adicionarInicio(Lista *lista, Aluno aluno); //OK

int mostrarLista(Lista *lista); //OK

int removerInicio(Lista *lista); //OK

int adicionarFim(Lista *lista, Aluno aluno); //OK

int removerFim(Lista *lista); //OK

int tamanho(Lista *lista); //OK

int adicionarPos(Lista *lista, Aluno aluno, int pos); //OK

int removerPos(Lista *lista, int pos); //OK

int removerItem(Lista *lista, int matricula); //OK

int buscarPos(Lista *lista, int pos, Aluno *aluno); //OK

int esvaziarLista(Lista *lista); //OK