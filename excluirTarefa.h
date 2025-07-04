#ifndef EXCLUIRTAREFA_H
#define EXCLUIRTAREFA_H

#include "global.h"
#include "salvarDados.h"

void excluirTarefa(int numTarefa) {
    char resposta;

    system("cls");
    printf("Deseja realmente excluir a tarefa \"%s\"? (S/N): \n", tarefas[numTarefa]->nome);
    scanf("%c", &resposta);
    getchar();

    if (resposta == 'S' || resposta == 's') {
        free(tarefas[numTarefa]);

        for (int i = numTarefa; i < qtTarefas - 1; i++) {
            tarefas[i] = tarefas[i + 1];

        }

        qtTarefas--;

        for (int i = 0; i < qtTarefas; i++) {
            tarefas[i]->id = i + 1;

        }

        salvarDados();

        printf("\nTarefa excluida com sucesso. ");
        system("pause");

    } else if (resposta == 'N' || resposta == 'n') {
        printf("Operacao cancelada com sucesso. ");
        system("pause");

    } else {
        printf("\nResposta invalida. ");
        system("pause");

    }

}

#endif
