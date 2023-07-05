#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaES.h"

int main(){
    Fila *fila;
    Aluno aluno;

    fila = criar();

    printf("\nAdicionar 3 na fila:\n");
    inserirStruct(&aluno, "ARTHUR", 8, 8.5);
    inserirFila(fila, aluno);

    inserirStruct(&aluno, "MARIA", 4, 9.0);
    inserirFila(fila, aluno);

    inserirStruct(&aluno, "MALU", 3, 10.0);
    inserirFila(fila, aluno);

    mostrarFila(fila);

    printf("\nRemover 2 da fila:\n");
    removerFila(fila, &aluno);
    removerFila(fila, &aluno);

    mostrarFila(fila);

    printf("\nConsultar fila:\n");
    inserirStruct(&aluno, "ESTER", 11, 7.0);
    inserirFila(fila, aluno);

    inserirStruct(&aluno, "JEAN", 12, 9.5);
    inserirFila(fila, aluno);

    consultarFila(fila, &aluno);

    printf("[ %s, %d, %g ] ", aluno.nome, aluno.matricula, aluno.nota);

    printf("\n");
    
    printf("\nTamanho da fila:\n");
    int info = tamanho(fila);

    printf("Existem [%d] alunos nessa fila!\n", info);

    printf("\nLimpar fila:\n");
    limparFila(fila);

    mostrarFila(fila);

    return 0;
}