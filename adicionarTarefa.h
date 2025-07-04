#ifndef ADICIONARTAREFA_H
#define ADICIONARTAREFA_H

#include "global.h"
#include "salvarDados.h"

// Função para adicionar uma nova tarefa
void adicionarTarefa() {
    if (qtTarefas >= MAX_TAREFAS) {
        // Verifica se o limite de tarefas foi atingido
        printf("Limite de tarefas atingido. \n");
        system("pause");
        return;

    }

    // Aloca memória para nova tarefa
    Tarefa *nova = (Tarefa *)malloc(sizeof(Tarefa));
    nova->id = qtTarefas + 1;

    system("cls");
    printf("ADICIONAR NOVA TAREFA\n\n");

    // Coleta dados da nova tarefa
    printf("Nome da tarefa: ");
    fgets(nova->nome, MAX_STR, stdin);
    nova->nome[strcspn(nova->nome, "\n")] = 0;

    printf("Descricao: ");
    fgets(nova->descricao, MAX_STR, stdin);
    nova->descricao[strcspn(nova->descricao, "\n")] = 0;

    printf("Data limite (AAAA-MM-DD): ");
    fgets(nova->dataLimite, MAX_STR, stdin);
    nova->dataLimite[strcspn(nova->dataLimite, "\n")] = 0;

    printf("Prioridade (1 a 5): ");
    scanf("%d", &nova->prioridade);
    getchar();

    nova->concluida = 0;

    // Adiciona tarefa ao vetor
    tarefas[qtTarefas++] = nova;
    salvarDados();

    printf("\nTarefa adicionada com sucesso. ");
    system("pause");

}

#endif
