#ifndef LISTARTAREFASCONCLUIDAS_H
#define LISTARTAREFASCONCLUIDAS_H

#include "global.h"
#include "procurarPorId.h"
#include "imprimirLista.h"

void listarTarefasConcluidas() {
    char resposta;
    int id, numTarefa;

    system("cls");
    printf("LISTA DE TAREFAS CONCLUIDAS\n\n");

    imprimirLista(1, 3);

    printf("\nDeseja alterar o status de uma tarefa para pendente? (S/N) \n");
    resposta = getch();

    if (resposta == 'S' || resposta == 's') {
        printf("\nDigite o ID da tarefa que deseja alterar o status: \n");
        scanf("%d", &id);
        getchar();

        numTarefa = procurarPorId(id);

        if (numTarefa == -1 || tarefas[numTarefa]->concluida == 0) {
            printf("\nTarefa nao encontrada. ");
            system("pause");

        } else {
            tarefas[numTarefa]->concluida = 0;
            printf("\nStatus alterado com sucesso. ");
            system("pause");

        }

    } else if (resposta == 'N' || resposta == 'n') {
        return;

    } else {
        printf("\nResposta invalida. ");
        system("pause");

    }

    listarTarefasConcluidas();

}

#endif