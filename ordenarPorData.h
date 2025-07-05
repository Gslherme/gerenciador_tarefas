#ifndef ORDENARPORDATA_H
#define ORDENARPORDATA_H

#include "global.h"
#include "compararDatas.h"

// Ordena lista de tarefas por data limite em ordem crescente
void ordenarPorData(Tarefa *lista[], int qtd) {
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = i + 1; j < qtd; j++) {
            if (compararDatas(lista[i]->dataLimite, lista[j]->dataLimite) > 0) {
                Tarefa *temp = lista[i];

                lista[i] = lista[j];
                lista[j] = temp;

            }

        }

    }

}

#endif
