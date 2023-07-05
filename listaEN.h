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
};
typedef struct no No;
    
struct lista{
    No *inicio;
};
typedef struct lista Lista;

Lista * criar();

int listaVazia(Lista *lista);

void adicionarStruct(Aluno *aluno, char nome[], int matricula, float nota);

int adicionarInicio(Lista *lista, Aluno aluno);

int mostrarLista(Lista *lista);

int removerInicio(Lista *lista);

int adicionarFim(Lista *lista, Aluno aluno);

int removerFim(Lista *lista);

int tamanho(Lista *lista);

int adicionarPos(Lista *lista, Aluno aluno, int pos);

int removerPos(Lista *lista, int pos);

int removerItem(Lista *lista, int matricula);

int buscarPos(Lista *lista, int pos, Aluno *aluno);

int esvaziarLista(Lista *lista);