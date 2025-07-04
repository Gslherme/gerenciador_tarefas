#ifndef LISTARTAREFAS_H
#define LISTARTAREFAS_H

#include "global.h"
#include "selecionarTarefa.h"
#include "procurarPorId.h"

void listarTarefas() {
    char resposta;
    int id, numTarefa;

    system("cls");
    printf("LISTA DE TAREFAS\n\n");
    printf("\tID\t|Titulo              |Data Limite\t|Prioridade\t|Status\n");

    for (int i = 0; i < qtTarefas; i++) {
        printf("\t%02d\t|%-20.20s|%s\t|%d\t\t|%s\n", tarefas[i]->id, tarefas[i]->nome, tarefas[i]->dataLimite, tarefas[i]->prioridade, tarefas[i]->concluida ? "Concluida" : "Pendente");

    }

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

    listarTarefas();

}

#endif
