#ifndef SALVARDADOS_H
#define SALVARDADOS_H

#include "global.h"

// Função que salva todas as tarefas em um arquivo CSV
void salvarDados() {
    FILE *arquivo = fopen("tarefas.csv", "w");
    if (!arquivo) {
        printf("Erro ao salvar o arquivo!\n");
        return;

    }

    // Escreve cabeçalho do CSV
    fprintf(arquivo, "ID,Nome,Descricao,DataLimite,Prioridade,Concluida\n");
    for (int i = 0; i < qtTarefas; i++) {
        fprintf(arquivo, "%d,%s,%s,%s,%d,%d\n",
            tarefas[i]->id,
            tarefas[i]->nome,
            tarefas[i]->descricao,
            tarefas[i]->dataLimite,
            tarefas[i]->prioridade,
            tarefas[i]->concluida);

    }

    fclose(arquivo);

}

#endif
