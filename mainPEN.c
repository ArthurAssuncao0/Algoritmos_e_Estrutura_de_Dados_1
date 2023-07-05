#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaEN.h"

int main(){
    Pilha *pilha;
    Valor valor;

    pilha = criar();

    inserirStruct(&valor, 10);
    Push(pilha, valor);
    inserirStruct(&valor, 20);
    Push(pilha, valor);
    inserirStruct(&valor, 30);
    Push(pilha, valor);
    inserirStruct(&valor, 40);
    Push(pilha, valor);
    inserirStruct(&valor, 50);
    Push(pilha, valor);
    inserirStruct(&valor, 60);
    Push(pilha, valor);
    inserirStruct(&valor, 70);
    Push(pilha, valor);
    inserirStruct(&valor, 80);
    Push(pilha, valor);

    Pop(pilha);
    Pop(pilha);

    mostrarPilha(pilha);

    consultarTop(pilha, &valor);

    printf("O top da fila eh: %d\n", valor.x);

    return 0;

}