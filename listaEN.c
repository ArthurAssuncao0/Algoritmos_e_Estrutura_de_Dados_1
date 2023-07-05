#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaEN.h"

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

    no->proximo = lista->inicio;
    lista->inicio = no;

    return OK;
}

int mostrarLista(Lista *lista)
{

    if(lista == NULL || lista->inicio == NULL){
        return ERROR;
    }

    No *aux = lista->inicio;

    while (aux != NULL)
    {
        printf("[ %s, %d, %g ] ", aux->aluno.nome, aux->aluno.matricula, aux->aluno.nota);
        aux = aux->proximo;
    }
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

    while (aux->proximo != NULL)
        aux = aux->proximo;
    
    aux->proximo = no;
    no->proximo = NULL;

    return OK;
}

int removerFim(Lista *lista)
{
    if (lista == NULL || lista->inicio == NULL)
        return ERROR;
    
    No *aux1 = lista->inicio;
    No *aux2;
    while (aux1->proximo != NULL)
    {
        aux2 = aux1;
        aux1 = aux1->proximo;
    }

    free(aux1);
    aux2->proximo = NULL;

    return OK;
}

int tamanho(Lista *lista){
    int c = 0;

    No *aux = lista->inicio;

    while(aux->proximo != NULL){
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

    while((aux->proximo != NULL) && (c < pos)){
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

    while(aux != NULL){
        if(aux->aluno.matricula == matricula){
            removerPos(lista, pos);
        }

        aux = aux->proximo;
        pos++;
    }

    return OK;  
}

int buscarPos(Lista *lista, int pos, Aluno *aluno){
    if(listaVazia(lista) == ERROR){
        return ERROR;
    }

    No *aux = lista->inicio;

    int c = 0;

    while((aux != NULL) && (c < pos)){
        aux = aux->proximo;
        c++;
    }

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

    while(lista->inicio != NULL){
        removerInicio(lista);
    }

    return OK;
}