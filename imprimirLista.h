#ifndef IMPRIMIRLISTA_H
#define IMPRIMIRLISTA_H

#include "global.h"

int imprimirLista(int status) {
    printf("\tID\t|Titulo              |Data Limite\t|Prioridade\t|Status\n");

    for (int i = 0; i < qtTarefas; i++) {
        if (tarefas[i]->concluida == status) {
            printf("\t%02d\t|%-20.20s|%s\t|%d\t\t|%s\n", tarefas[i]->id, tarefas[i]->nome, tarefas[i]->dataLimite, tarefas[i]->prioridade, tarefas[i]->concluida ? "Concluida" : "Pendente");

        }

    }

}

#endif
