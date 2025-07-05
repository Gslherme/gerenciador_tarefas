#ifndef EXCLUIRTAREFA_H
#define EXCLUIRTAREFA_H

#include "global.h"
#include "salvarDados.h"

// Função para excluir uma tarefa do vetor de tarefas
void excluirTarefa(int numTarefa) {
    char resposta;

    system("cls");
    // Solicita confirmação do usuário para exclusão da tarefa
    printf("Deseja realmente excluir a tarefa \"%s\"? (S/N): \n", tarefas[numTarefa]->nome);
    scanf("%c", &resposta);
    getchar();

    if (resposta == 'S' || resposta == 's') {
        // Libera a memória alocada para a tarefa
        free(tarefas[numTarefa]);

        // Realoca as tarefas seguintes para preencher o espaço da removida
        for (int i = numTarefa; i < qtTarefas - 1; i++) {
            tarefas[i] = tarefas[i + 1];

        }

        qtTarefas--;

        // Atualiza os IDs das tarefas restantes
        for (int i = 0; i < qtTarefas; i++) {
            tarefas[i]->id = i + 1;

        }

        // Salva os dados atualizados no arquivo CSV
        salvarDados();

        printf("\nTarefa excluida com sucesso. ");
        system("pause");

    } else if (resposta == 'N' || resposta == 'n') {
        // Operação cancelada pelo usuário
        printf("Operacao cancelada com sucesso. ");
        system("pause");

    } else {
        // Entrada inválida
        printf("\nResposta invalida. ");
        system("pause");

    }

}

#endif
