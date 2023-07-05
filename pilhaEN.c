#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaEN.h"

Pilha *criar(){
    Pilha *p = (Pilha*) malloc (sizeof(Pilha));
    p->top = NULL;

    return p;
}

int pilhaVazia(Pilha *pilha){
    if(pilha == NULL){
        return 2;
    }

    if(pilha->top == NULL){
        return 0;
    }
    
    else{
        return 1;
    }
}

void limparPilha(Pilha *pilha){
    if(pilha == NULL){
        return;
    }

    if(pilhaVazia(pilha) != 0){
        Pop(pilha);
    }
    
    free(pilha);
    pilha = NULL;
}

void inserirStruct(Valor *valor, int x){
    valor->x = x;
}

void mostrarPilha(Pilha *pilha){
    if(pilha != NULL){
        No *aux = pilha->top;

        while(aux != NULL){
            printf("[ %d ] ", aux->valor.x);
            printf("\n");
            aux = aux->proximo;
        }
    }
    printf("\n");
}

int Push(Pilha *pilha, Valor valor){
    if(pilha == NULL){
        return 2;
    }

    No *no =  (No*) malloc (sizeof(No));

    no->valor = valor;
    no->proximo = pilha->top;
    pilha->top = no;
    
}

int Pop(Pilha *pilha){
    if(pilha == NULL){
        return 2;
    }

    if(pilhaVazia(pilha) == 0){
        return 3;
    }

    No *aux = pilha->top;
    pilha->top = aux->proximo;

    free(aux);

    return 0;
}

int consultarTop(Pilha *pilha, Valor *valor){
    if(pilha == NULL){
        return 2;
    }

    if(pilhaVazia(pilha) == 0){
        return 3;
    }

    No *aux = pilha->top;
    *valor = aux->valor;

    return 0;
}

int tamanho(Pilha *pilha){
    if(pilha == NULL){
        return 2;
    }

    if(pilhaVazia(pilha) == 0){
        return 3;
    }

    No *aux = pilha->top;
    int c = 0;

    while(aux != NULL){
        c++;
        aux = aux->proximo;
    }

    return c;
}

int pilhaCheia(Pilha *pilha){
    return 1;
}