#ifndef LISTARPORPALAVRACHAVE_H
#define LISTARPORPALAVRACHAVE_H

#include "global.h"
#include <string.h>

// Lista todas as tarefas cujo nome contém a palavra-chave informada
void listarPorPalavraChave(char *chave) {
    int encontrou = 0;
    printf("\tID\t|Titulo              |Data Limite\t|Prioridade\t|Status\n");

    for (int i = 0; i < qtTarefas; i++) {
        // Verifica se a palavra-chave está contida no nome da tarefa
        if (strstr(tarefas[i]->nome, chave)) {
            printf("\t%02d\t|%-20.20s|%s\t|%d\t\t|%s\n", tarefas[i]->id, tarefas[i]->nome, tarefas[i]->dataLimite, tarefas[i]->prioridade, tarefas[i]->concluida ? "Concluida" : "Pendente");

        }

    }

}

#endif
