#define MAX 100

struct valor{
    int x;
};
typedef struct valor Valor;

struct pilha{
    int top;
    Valor valor[MAX];
};
typedef struct pilha Pilha;

Pilha *criar();

void limparPilha(Pilha *pilha);

void inserirStruct(Valor *valor, int x);

void mostrarPilha(Pilha *pilha);

int Push(Pilha *pilha, Valor valor);

int Pop(Pilha *pilha);

int consultarTop(Pilha *pilha, Valor *valor);

int tamanho(Pilha *pilha);

int pilhaVazia(Pilha *pilha);

int pilhaCheia(Pilha *pilha);