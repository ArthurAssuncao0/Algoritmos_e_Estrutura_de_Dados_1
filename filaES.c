#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaES.h"

Fila *criar(){
    Fila *f = (Fila*) malloc (sizeof(Fila));
    f->inicio = 0;
    f->fim = 0;
    f->quant = 0;

    return f;
}

void limparFila(Fila *fila){
    fila->inicio = 0;
    fila->fim = 0;
    fila->quant = 0;
    
    free(fila);
    fila = NULL;
}

void inserirStruct(Aluno *aluno, char nome[], int matricula, float nota){
    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;
    aluno->nota = nota;
}

void mostrarFila(Fila *fila){
    if(fila != NULL){
        int inicio = fila->inicio;
        int quant = fila->quant;

        while(quant > 0){
            printf("[ %s, %d, %g ] ", fila->aluno[inicio].nome, fila->aluno[inicio].matricula, fila->aluno[inicio].nota);
            inicio = (inicio + 1) % MAX;
            quant--;
        }
        printf("\n");
    }
}

int filaVazia(Fila *fila){ 
    if(fila == NULL){
        return 2;
    }
    
    if(fila->quant == 0){
        return 0;
    }
    
    else return 1;
}

int filaCheia(Fila *fila){
    if(fila == NULL){
        return 2;
    }
    
    if(fila->quant == MAX){
        return 0;
    }
    
    else return 1;
}

int inserirFila(Fila *fila, Aluno aluno){
    if(fila == NULL){
        return 1;
    }
    if(filaCheia(fila) == 0){
        return 2;
    }

    fila->aluno[fila->fim] = aluno;
    fila->fim = (fila->fim + 1) % MAX;
    fila->quant++;

    return 0;
}

int removerFila(Fila *fila, Aluno *aluno){
    if(fila == NULL){
        return 1;
    }

    if(filaVazia(fila)  == 0){
        return 2;
    }

    *aluno = fila->aluno[fila->inicio];
    fila->quant--;
    fila->inicio = (fila->inicio + 1) % MAX;

    return 0;
}

int consultarFila(Fila *fila, Aluno *aluno){
    if(fila == NULL){
        return 1;
    }

    if(filaVazia(fila) == 0){
        return 2;
    }

    *aluno = fila->aluno[fila->inicio];

    return 0;
}

int tamanho(Fila *fila){
    if(fila == NULL){
        return 1;
    }

    return fila->quant;
}

