#ifndef LISTARTAREFASPENDENTES_H
#define LISTARTAREFASPENDENTES_H

#include "global.h"
#include "selecionarTarefa.h"
#include "procurarPorId.h"
#include "imprimirLista.h"

void listarTarefasPendentes() {
    char resposta;
    int id, numTarefa;

    system("cls");
    printf("LISTA DE TAREFAS PENDENTES\n\n");

    imprimirLista(0);

    printf("\nDeseja selecionar uma tarefa? (S/N) \n");
    resposta = getch();

    if (resposta == 'S' || resposta == 's') {
        printf("\nDigite o ID da tarefa que deseja selecionar: \n");
        scanf("%d", &id);
        getchar();

        numTarefa = procurarPorId(id);

        if (numTarefa == -1) {
            printf("\nTarefa nao encontrada. ");
            system("pause");

        } else {
            selecionarTarefa(numTarefa);

        }

    } else if (resposta == 'N' || resposta == 'n') {
        return;

    } else {
        printf("\nResposta invalida. ");
        system("pause");

    }

    listarTarefasPendentes();

}

#endif
