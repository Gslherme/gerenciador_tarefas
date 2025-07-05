#ifndef LISTARTAREFASPENDENTES_H
#define LISTARTAREFASPENDENTES_H

#include "global.h"
#include "selecionarTarefa.h"
#include "procurarPorId.h"
#include "imprimirLista.h"

// Função que lista tarefas pendentes com opção de ordenação e seleção
void listarTarefasPendentes() {
    char resposta;
    int id, numTarefa;
    int ordenacao = 3;

    system("cls");
    printf("LISTA DE TAREFAS PENDENTES\n\n");
    imprimirLista(0, 3);  // Mostra pendentes (status 0) sem ordenação específica

    while (1) {
        // Opções de ordenação para o usuário
        printf("\nALTERAR A ORDEM DA LISTA? (1) POR DATA LIMITE (2) POR PRIORIDADE (3) NAO\n");
        resposta = getch();
        ordenacao = resposta - '0';

        if (ordenacao == 1 || ordenacao == 2) {
            system("cls");
            printf("LISTA DE TAREFAS PENDENTES\n\n");
            imprimirLista(0, ordenacao);  // Reimprime com nova ordenação

        } else if (ordenacao == 3) {
            break;

        } else {
            printf("\nOpcao invalida. ");
            system("pause");

        }

    }

    // Pergunta se deseja selecionar uma tarefa
    printf("\nDeseja selecionar uma tarefa? (S/N) \n");
    resposta = getch();

    if (resposta == 'S' || resposta == 's') {
        printf("\nDigite o ID da tarefa que deseja selecionar: \n");
        scanf("%d", &id);
        getchar();

        numTarefa = procurarPorId(id);  // Busca índice da tarefa

        if (numTarefa == -1) {
            printf("\nTarefa nao encontrada. ");
            system("pause");

        } else {
            selecionarTarefa(numTarefa);  // Abre submenu da tarefa

        }

    } else if (resposta == 'N' || resposta == 'n') {
        return;

    } else {
        printf("\nResposta invalida. ");
        system("pause");

    }

    listarTarefasPendentes();  // Recursivamente reinicia a listagem

}

#endif
