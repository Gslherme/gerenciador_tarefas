#ifndef ORDENARPORPRIORIDADE_H
#define ORDENARPORPRIORIDADE_H

#include "global.h"

void ordenarPorPrioridade(Tarefa *lista[], int qtd) {
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = i + 1; j < qtd; j++) {
            if (lista[i]->prioridade < lista[j]->prioridade) {
                Tarefa *temp = lista[i];

                lista[i] = lista[j];
                lista[j] = temp;

            }

        }

    }

}

#endif
