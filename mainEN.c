#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaEN.h"

int main(){
    Lista *lista;
    Aluno aluno;

    lista = criar();

    printf("\nAdicionar 3 no inicio:\n");
    adicionarStruct(&aluno, "JEAN", 50, 11.50);
    adicionarInicio(lista, aluno);

    adicionarStruct(&aluno, "STHE DA LOGICA", 51, 15);
    adicionarInicio(lista, aluno);

    adicionarStruct(&aluno, "MARTINS BUNDUDO", 53, 18);
    adicionarInicio(lista, aluno);

    mostrarLista(lista);

    printf("\nRemover 2 no inicio:\n");
    removerInicio(lista);
    removerInicio(lista);

    mostrarLista(lista);

    printf("\nAdicionar 3 no fim:\n");
    adicionarStruct(&aluno, "TUTUZIN DO MAU", 54, 999);
    adicionarFim(lista, aluno);

    adicionarStruct(&aluno, "ODELMO GOD", 56, 15);
    adicionarFim(lista, aluno);

    adicionarStruct(&aluno, "BERTO REI DELX", 57, 666);
    adicionarFim(lista, aluno);

    mostrarLista(lista);

    printf("\nRemover 2 no fim:\n");

    removerFim(lista);
    removerFim(lista);

    mostrarLista(lista);

    printf("\nAdicionar na primeira posicao:\n");

    adicionarStruct(&aluno, "RATO MORTO", 95, 0);
    adicionarPos(lista, aluno, 1);

    mostrarLista(lista);

    printf("\nRemover na primeira posicao:\n");

    removerPos(lista, 1);

    mostrarLista(lista);

    printf("\nRemover item:\n");

    removerItem(lista, 50);

    mostrarLista(lista);

    //Adicionando na lista

    adicionarStruct(&aluno, "JEAN", 50, 11.50);
    adicionarInicio(lista, aluno);

    adicionarStruct(&aluno, "STHE DA LOGICA", 51, 15);
    adicionarInicio(lista, aluno);

    adicionarStruct(&aluno, "MARTINS BUNDUDO", 53, 18);
    adicionarInicio(lista, aluno);

    printf("\nBuscar posicao:\n");

    buscarPos(lista, 1, &aluno);

    printf("\n%s, %d, %g\n", aluno.nome, aluno.matricula, aluno.nota);

    printf("\nEsvaziar lista:\n");

    esvaziarLista(lista);

    mostrarLista(lista);

   return 0;
}