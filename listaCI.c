#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaCI.h"

Lista * criar()
{
    Lista *nova_lista = (Lista *) malloc(sizeof(Lista));
    nova_lista->inicio = NULL;
    return nova_lista;
}

int listaVazia(Lista *lista)
{
    if (lista == NULL)
        return ERROR;

    if (lista->inicio == NULL)
        return ERROR;  
        
    return OK;
}

void adicionarStruct(Aluno *aluno, char nome[], int matricula, float nota)
{
    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;
    aluno->nota = nota;
}

int adicionarInicio(Lista *lista, Aluno aluno)
{

    if (lista == NULL)
        return ERROR;
    
    No *no = (No *) malloc(sizeof(No));
    no->aluno = aluno;

    if(listaVazia(lista) == ERROR){
        no->proximo = no;
        lista->inicio = no;
    }
    else{
        No *aux = lista->inicio;

        while(aux->proximo != lista->inicio){
            aux = aux->proximo;
        }
        
        no->proximo = lista->inicio;
        lista->inicio = no;
        aux->proximo = no;
    }

    return OK;
}

int mostrarLista(Lista *lista)
{

    if(lista == NULL || lista->inicio == NULL){
        return ERROR;
    }

    No *aux = lista->inicio;

    do{
        printf("[ %s, %d, %g ] ", aux->aluno.nome, aux->aluno.matricula, aux->aluno.nota);
        aux = aux->proximo;
    }
    while (aux != lista->inicio);
    
    printf("\n");

    return OK;
}

int removerInicio(Lista *lista)
{
    if (lista == NULL)
        return ERROR;
    
    if (listaVazia(lista) == ERROR)
        return ERROR;
    
    No *aux = lista->inicio;

    lista->inicio = lista->inicio->proximo;

    No *aux2 = lista->inicio->proximo;

    while(aux2->proximo != aux){
        aux2 = aux2->proximo;
    }

    aux2->proximo = lista->inicio;

    free(aux);
    return OK;
}

int adicionarFim(Lista *lista, Aluno aluno)
{
    if (lista->inicio == NULL)
        adicionarInicio(lista, aluno);
    
    No *no = (No *) malloc(sizeof(No));
    No *aux = lista->inicio;
    no->aluno = aluno;

    while (aux->proximo != lista->inicio)
        aux = aux->proximo;
    
    aux->proximo = no;
    no->proximo = lista->inicio;

    return OK;
}

int removerFim(Lista *lista)
{
    if (lista == NULL || lista->inicio == NULL)
        return ERROR;
    
    No *aux1 = lista->inicio;
    No *aux2;
    
    while (aux1->proximo != lista->inicio){
        aux2 = aux1;
        aux1 = aux1->proximo;
    }

    aux2->proximo = lista->inicio;
    free(aux1);

    return OK;
}

int tamanho(Lista *lista){
    int c = 0;

    No *aux = lista->inicio;

    while(aux->proximo != lista->inicio){
        aux = aux->proximo;
        c++;
    }

    return c;
}


int adicionarPos(Lista *lista, Aluno aluno, int pos){
    if(lista == NULL){
        return ERROR;
    }

    if(pos <= 0 || listaVazia(lista) == ERROR){
        adicionarInicio(lista, aluno);

        return OK;
    }

    if(pos > tamanho(lista)){
        adicionarFim(lista, aluno);

        return OK;
    }

    No *aux = lista->inicio;

    int c = 1;

    while((aux->proximo != lista->inicio) && (c < pos)){
        aux = aux->proximo;
        c++;
    }

    No *no = (No*) malloc (sizeof(No));
    no->aluno = aluno;
    no->proximo = aux->proximo;
    aux->proximo = no;

    return OK;
}

int removerPos(Lista *lista, int pos){
    if(listaVazia(lista) == ERROR){
        return ERROR;
    }

    if(pos <= 0){
        removerInicio(lista);

        return OK;
    }

    if(pos > tamanho(lista)){
        removerFim(lista);

        return OK;
    }

    No *aux1 = lista->inicio;
    No *aux2;

    int c = 0;

    while((aux1->proximo != NULL) && (c < pos)){
        aux2 = aux1;
        aux1 = aux1->proximo;
        c++;
    }

    aux2->proximo = aux1->proximo;
    free(aux1);

    return OK;
}

int removerItem(Lista *lista, int matricula){
    int pos = 0;

    if(listaVazia(lista) == ERROR){
        return ERROR;
    }

    No *aux = lista->inicio;

    do{
        if(aux->aluno.matricula == matricula){
            removerPos(lista, pos);
        }

        aux = aux->proximo;
        pos++;
    }while(aux != lista->inicio);

    return OK;  
}

int buscarPos(Lista *lista, int pos, Aluno *aluno){
    if(listaVazia(lista) == ERROR){
        return ERROR;
    }

    No *aux = lista->inicio;

    int c = 0;

    do{
        aux = aux->proximo;
        c++;
    }while((aux != lista->inicio) && (c < pos));

    if(aux == NULL){
        return ERROR;
    }

    *aluno = aux->aluno;

    return OK;
}

int esvaziarLista(Lista *lista){
    if(listaVazia(lista) == ERROR){
        return ERROR;
    }

    while(tamanho(lista)){
        removerInicio(lista);
    }

    free(lista->inicio);
    lista->inicio = NULL;

    return OK;
}