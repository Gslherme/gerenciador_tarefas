#ifndef PROCURARPORID_H
#define PROCURARPORID_H

#include "global.h"

int procurarPorId(int id) {
    for (int i = 0; i < qtTarefas; i++) {
        if (tarefas[i]->id == id) {
            return i;

        }

    }

    return -1;

}

#endif
