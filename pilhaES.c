#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaES.h"

Pilha *criar(){
    Pilha *p = (Pilha*) malloc (sizeof(Pilha));
    p->top = 0;

    return p;
}

void limparPilha(Pilha *pilha){
    free(pilha);
    pilha = NULL;
}

void inserirStruct(Valor *valor, int x){
    valor->x = x;
}

void mostrarPilha(Pilha *pilha){
    if(pilha != NULL){
        for(int i = pilha->top - 1; i >= 0; i--){
            printf("[ %d ] ", pilha->valor[i].x);
            printf("\n");
        }
        printf("\n");
    }
}

int pilhaVazia(Pilha *pilha){
    if(pilha == NULL){
        return 2;
    }

    if(pilha->top == 0){
        return 0;
    }
    
    else{
        return 1;
    }
}

int pilhaCheia(Pilha *pilha){
    if(pilha == NULL){
        return 2;
    }

    if(pilha->top == MAX){
        return 0;
    }

    else{
        return 1;
    }
}

int Push(Pilha *pilha, Valor valor){
    if(pilha == NULL){
        return 2;
    }

    if(pilhaCheia(pilha) == 0){
        return 3;
    }

    pilha->valor[pilha->top] = valor;
    pilha->top++;

    return 0;
}

int Pop(Pilha *pilha){
    if(pilha == NULL){
        return 2;
    }

    if(pilhaVazia(pilha) == 0){
        return 3;
    }

    pilha->top--;

    return 0;
}

int consultarTop(Pilha *pilha, Valor *valor){
    if(pilha == NULL){
        return 2;
    }

    if(pilhaVazia(pilha) == 0){
        return 3;
    }

    *valor = pilha->valor[pilha->top - 1];
    
    return 0;
}

int tamanho(Pilha *pilha){
    if(pilha == NULL){
        return 2;
    }

    return pilha->top;
}

