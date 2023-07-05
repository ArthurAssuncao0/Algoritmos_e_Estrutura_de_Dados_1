#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaEN.h"

void InserirFila(Pilha *pilha1){
    if(pilha1 == NULL || pilhaVazia(pilha1) == 0){
        return;
    }

    Pilha *aux = criar();
    Valor valorAux;

    while(pilhaVazia(pilha1) != 0){
        consultarTop(pilha1, &valorAux);
        Pop(pilha1);
        Push(aux, valorAux);
    }

    inserirStruct(&valorAux, 10);
    Push(aux, valorAux);

    while(pilhaVazia(aux) != 0){
        consultarTop(aux, &valorAux);
        Pop(aux);
        Push(pilha1, valorAux);
    }

    limparPilha(aux);
}

void InverterPilha(Pilha *pilha1, Pilha *pilha2){
    if(pilha1 == NULL || pilhaVazia(pilha1) == 0){
        return;
    }

    if(pilha2 != NULL && pilhaVazia(pilha2) != 0){
        return;
    }

    Valor valor;

    while(pilhaVazia(pilha1) != 0){
        consultarTop(pilha1, &valor);
        Pop(pilha1);
        Push(pilha2, valor);
    }
}

void RemoveItem(Pilha *pilha1, int x){
    if(pilha1 == NULL && pilhaVazia(pilha1) == 0){
        return;
    }

    Pilha *Paux = criar();
    Valor valor;

    while((pilhaVazia(pilha1) != 0)){
        consultarTop(pilha1, &valor);
        
        if(valor.x == x){
            Pop(pilha1);
        }
        
        else{
            Pop(pilha1);
            Push(Paux, valor);
        }
    }

    while(pilhaVazia(Paux) != 0){
        consultarTop(Paux, &valor);
        Pop(Paux);
        Push(pilha1, valor);
    }

    limparPilha(Paux);
}

int Confere(Pilha *pilha1, Pilha *pilha2){
    Valor valor1, valor2;
    int c = 0;

    if(tamanho(pilha1) != tamanho(pilha2)){
        return 2;
    }

    Pilha *aux1 = criar();
    Pilha *aux2 = criar();

    while(pilhaVazia(pilha1) != 0 && pilhaVazia(pilha2) != 0){
        consultarTop(pilha1, &valor1);
        consultarTop(pilha2, &valor2);
        Pop(pilha1);
        Pop(pilha2);

        if(valor1.x == valor2.x){
            Push(aux1, valor1);
            Push(aux2, valor2);
        }
        else{
            Push(aux1, valor1);
            Push(aux2, valor2);

            while(pilhaVazia(aux1) != 0 && pilhaVazia(aux2) != 0){
                consultarTop(aux1, &valor1);
                consultarTop(aux2, &valor2);
                Pop(aux1);
                Pop(aux2);
                Push(pilha1, valor1);
                Push(pilha2, valor2);

                return 1;
            }
        }
    }

     while(pilhaVazia(aux1) != 0 && pilhaVazia(aux2) != 0){
        consultarTop(aux1, &valor1);
        consultarTop(aux2, &valor2);
        Pop(aux1);
        Pop(aux2);
        Push(pilha1, valor1);
        Push(pilha2, valor2);
     }
}

int main(){
    Pilha *pilha1 = NULL;
    Pilha *pilha2 = NULL;
    Valor valor;
    int x, y;

    pilha1 = criar();
    pilha2 = criar();

    inserirStruct(&valor, 20);
    Push(pilha1, valor);
    inserirStruct(&valor, 30);
    Push(pilha1, valor);
    inserirStruct(&valor, 40);
    Push(pilha1, valor);
    inserirStruct(&valor, 50);
    Push(pilha1, valor);
    inserirStruct(&valor, 60);
    Push(pilha1, valor);

    InserirFila(pilha1);

    mostrarPilha(pilha1);

    InverterPilha(pilha1, pilha2);

    mostrarPilha(pilha2);

    printf("Digite um numero que deseja remover da pilha: \n");
    scanf("%d", &x);
    printf("\n");

    RemoveItem(pilha2, x);

    mostrarPilha(pilha2);

    inserirStruct(&valor, 60);
    Push(pilha1, valor);
    inserirStruct(&valor, 50);
    Push(pilha1, valor);
    inserirStruct(&valor, 40);
    Push(pilha1, valor);
    inserirStruct(&valor, 30);
    Push(pilha1, valor);
    inserirStruct(&valor, 20);
    Push(pilha1, valor);
    
    mostrarPilha(pilha1);

    y = Confere(pilha1, pilha2);

    if(y == 0){
        printf("Sao iguais\n");
    }
    else{
        printf("Nao sao iguais\n");
    }
    printf("\n");

    mostrarPilha(pilha1);
    mostrarPilha(pilha2);

}