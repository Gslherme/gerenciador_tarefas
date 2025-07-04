#ifndef EDITARTAREFA_H
#define EDITARTAREFA_H

#include "global.h"
#include "salvarDados.h"

void editarTarefa(int numTarefa) {
    int novaPrioridade;

    system("cls");
    printf("EDITAR TAREFA\n");

    printf("\nNome atual: %s\n", tarefas[numTarefa]->nome);
    printf("Novo nome (aperte ENTER para manter): ");
    char entrada[MAX_STR];
    fgets(entrada, MAX_STR, stdin);
    if (entrada[0] != '\n') {
        entrada[strcspn(entrada, "\n")] = 0;
        strcpy(tarefas[numTarefa]->nome, entrada);

    }

    printf("\nDescricao atual: %s\n", tarefas[numTarefa]->descricao);
    printf("Nova descricao (aperta ENTER para manter): ");
    fgets(entrada, MAX_STR, stdin);
    if (entrada[0] != '\n') {
        entrada[strcspn(entrada, "\n")] = 0;
        strcpy(tarefas[numTarefa]->descricao, entrada);
    }

    printf("\nData limite atual: %s\n", tarefas[numTarefa]->dataLimite);
    printf("Nova data limite (AAAA-MM-DD, aperte ENTER para manter): ");
    fgets(entrada, MAX_STR, stdin);
    if (entrada[0] != '\n') {
        entrada[strcspn(entrada, "\n")] = 0;
        strcpy(tarefas[numTarefa]->dataLimite, entrada);
    }

    printf("\nPrioridade atual: %d\n", tarefas[numTarefa]->prioridade);
    printf("Nova prioridade (1 a 5, 0 para manter): ");
    scanf("%d", &novaPrioridade);
    getchar();
    if (novaPrioridade >= 1 && novaPrioridade <= 5) {
        tarefas[numTarefa]->prioridade = novaPrioridade;

    }

    salvarDados();
    printf("\nTarefa editada com sucesso. ");
    system("pause");

}

#endif
