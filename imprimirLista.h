#ifndef IMPRIMIRLISTA_H
#define IMPRIMIRLISTA_H

#include "global.h"
#include "ordenarPorData.h"
#include "ordenarPorPrioridade.h"

int imprimirLista(int status, int ordenarPor) {
    Tarefa *lista[MAX_TAREFAS];
    int count = 0;

    for (int i = 0; i < qtTarefas; i++) {
        if (tarefas[i]->concluida == status) {
            lista[count++] = tarefas[i];

        }

    }

    if (ordenarPor == 1) ordenarPorData(lista, count);
    else if (ordenarPor == 2) ordenarPorPrioridade(lista, count);

    printf("\tID\t|Titulo              |Data Limite\t|Prioridade\t|Status\n");

    for (int i = 0; i < count; i++) {
        printf("\t%02d\t|%-20.20s|%s\t|%d\t\t|%s\n", lista[i]->id, lista[i]->nome, lista[i]->dataLimite, lista[i]->prioridade, lista[i]->concluida ? "Concluida" : "Pendente");

    }

    return count;

}

#endif
