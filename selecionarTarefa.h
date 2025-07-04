#ifndef SELECIONARTAREFA_H
#define SELECIONARTAREFA_H

#include "global.h"
#include "editarTarefa.h"
#include "excluirTarefa.h"

void selecionarTarefa(int numTarefa) {
    char resposta, status;

    system("cls");
    printf("TAREFA SELECIONADA: %s \n\n", tarefas[numTarefa]->nome);

    printf("ID: %d\n", tarefas[numTarefa]->id);
    printf("Nome: %s\n", tarefas[numTarefa]->nome);
    printf("Descricao: %s\n", tarefas[numTarefa]->descricao);
    printf("Data Limite: %s\n", tarefas[numTarefa]->dataLimite);
    printf("Prioridade: %d\n", tarefas[numTarefa]->prioridade);
    printf("Concluida: %s\n\n", tarefas[numTarefa]->concluida ? "Sim" : "Nao");

    printf("Escolha uma opcao: EDITAR (E) | EXCLUIR (D) | ALTERAR STATUS (A) | SAIR (R)\n");
    resposta = getch();

    if (resposta == 'E' || resposta == 'e') {
        editarTarefa(numTarefa);

    } else if (resposta == 'D' || resposta == 'd') {
        excluirTarefa(numTarefa);
        return;

    } else if (resposta == 'A' || resposta == 'a') {
        printf("\nDigite 1 para marcar a tarefa como \"Concluida\" ou 0 para \"Pendente\": \n");
        scanf("%d", &status);
        if (status == 0 || status == 1) {
            tarefas[numTarefa]->concluida = status;
            salvarDados();

        } else {
            printf("\nResposta invalida. Operacao cancelada. ");
            system("pause");

        }

    } else if (resposta == 'R' || resposta == 'r') {
        return;

    }  else {
        printf("\nResposta invalida. ");
        system("pause");

    }

    selecionarTarefa(numTarefa);

}

#endif
