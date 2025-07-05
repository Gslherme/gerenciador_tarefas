#ifndef LISTARTAREFASCONCLUIDAS_H
#define LISTARTAREFASCONCLUIDAS_H

#include "global.h"
#include "procurarPorId.h"
#include "imprimirLista.h"

// Lista tarefas concluídas e permite alterar status para pendente
void listarTarefasConcluidas() {
    char resposta;
    int id, numTarefa;

    system("cls");
    printf("LISTA DE TAREFAS CONCLUIDAS\n\n");

    imprimirLista(1, 3);  // Lista tarefas com status concluído (1)

    printf("\nDeseja alterar o status de uma tarefa para pendente? (S/N) \n");
    resposta = getch();

    if (resposta == 'S' || resposta == 's') {
        printf("\nDigite o ID da tarefa que deseja alterar o status: \n");
        scanf("%d", &id);
        getchar();

        numTarefa = procurarPorId(id);

        // Verifica se a tarefa existe e está concluída
        if (numTarefa == -1 || tarefas[numTarefa]->concluida == 0) {
            printf("\nTarefa nao encontrada. ");
            system("pause");

        } else {
            tarefas[numTarefa]->concluida = 0;  // Marca como pendente
            printf("\nStatus alterado com sucesso. ");
            system("pause");

        }

    } else if (resposta == 'N' || resposta == 'n') {
        return;

    } else {
        printf("\nResposta invalida. ");
        system("pause");

    }

    listarTarefasConcluidas();  // Reinicia a listagem

}

#endif
