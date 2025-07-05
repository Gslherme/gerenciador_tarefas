#ifndef PROCURARPORID_H
#define PROCURARPORID_H

#include "global.h"

// Retorna o índice da tarefa com determinado ID ou -1 se não encontrada
int procurarPorId(int id) {
    for (int i = 0; i < qtTarefas; i++) {
        if (tarefas[i]->id == id) {
            return i;

        }

    }

    return -1;

}

#endif
