#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaEN.h"

int main(){
    Lista *lista;
    Aluno aluno;

    lista = criar();

    printf("\nAdicionar 3 no inicio:\n");
    adicionarStruct(&aluno, "FER", 1, 7.5);
    adicionarInicio(lista, aluno);

    adicionarStruct(&aluno, "ESTER", 2, 9.3);
    adicionarInicio(lista, aluno);

    adicionarStruct(&aluno, "BRUNO", 3, 9.9);
    adicionarInicio(lista, aluno);

    mostrarLista(lista);

    printf("\nRemover 2 no inicio:\n");
    removerInicio(lista);
    removerInicio(lista);

    mostrarLista(lista);

    printf("\nAdicionar 3 no fim:\n");
    adicionarStruct(&aluno, "TUTU", 8, 8.0);
    adicionarFim(lista, aluno);

    adicionarStruct(&aluno, "ODELMO", 4, 8.5);
    adicionarFim(lista, aluno);

    adicionarStruct(&aluno, "BERTO", 5, 10.0);
    adicionarFim(lista, aluno);

    mostrarLista(lista);

    printf("\nRemover 2 no fim:\n");

    removerFim(lista);
    removerFim(lista);

    mostrarLista(lista);

    printf("\nAdicionar na primeira posicao:\n");

    adicionarStruct(&aluno, "STHE", 7, 7.0);
    adicionarPos(lista, aluno, 1);

    mostrarLista(lista);

    printf("\nRemover na primeira posicao:\n");

    removerPos(lista, 1);

    mostrarLista(lista);

    printf("\nRemover item:\n");

    removerItem(lista, 8);

    mostrarLista(lista);

    //Adicionando na lista

    adicionarStruct(&aluno, "JEAN", 9, 10.0);
    adicionarInicio(lista, aluno);

    adicionarStruct(&aluno, "MALU", 10, 10.0);
    adicionarInicio(lista, aluno);

    adicionarStruct(&aluno, "MARTINS", 11, 8.0);
    adicionarInicio(lista, aluno);

    mostrarLista(lista);

    printf("\nBuscar posicao:\n");

    buscarPos(lista, 1, &aluno);

    printf("\n%s, %d, %g\n", aluno.nome, aluno.matricula, aluno.nota);

    printf("\nEsvaziar lista:\n");

    esvaziarLista(lista);

    mostrarLista(lista);

   return 0;
}