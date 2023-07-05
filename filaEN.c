#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaEN.h"

Fila *criar(){
    Fila *f = (Fila*) malloc (sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->quant = 0;

    return f;
}

void limparFila(Fila *fila){
    if(fila == NULL){
        return;
    }
    
    while(filaVazia(fila) != 0){
        removerFila(fila, NULL);
    }
    
    free(fila);
    fila = NULL;
}

/*void inserirStruct(Aluno *aluno, char nome[], int matricula, float nota){
    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;
    aluno->nota = nota;
}
*/

void mostrarFila(Fila *fila){
    if(fila != NULL){
        No *aux = fila->inicio;

        while(aux->proximo != NULL){
            printf("[ %s, %d, %g ] ", aux->aluno.nome, aux->aluno.matricula, aux->aluno.nota);
            aux = aux->proximo;
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
    
    else{
        return 1;
    }
}

int filaCheia(Fila *fila){
    return 1;
}

int inserirFila(Fila *fila, Aluno aluno){
    if(fila == NULL){
        return 1;
    }
    
    No *no = (No*) malloc (sizeof(No));
    no->aluno = aluno;
    no->proximo = NULL;

    if(filaVazia(fila) == 0){
        fila->inicio = no;
    }
    else{
        fila->fim->proximo = no;
    }
    
    fila->fim = no;
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

    No *aux = fila->inicio;
    fila->inicio = aux->proximo;

    free(aux);

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    fila->quant--;

    return 0;
}

int consultarFila(Fila *fila, Aluno *aluno){
    if(fila == NULL){
        return 1;
    }

    if(filaVazia(fila) == 0){
        return 2;
    }

    *aluno = fila->inicio->aluno;

    return 0;
}

int tamanho(Fila *fila){
    if(fila == NULL){
        return 1;
    }

    return fila->quant;
}

