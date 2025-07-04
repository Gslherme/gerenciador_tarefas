#ifndef GLOBAL_H
#define GLOBAL_H

#define MAX_TAREFAS 100
#define MAX_STR 100

typedef struct {
    int id;
    char nome[MAX_STR];
    char descricao[MAX_STR];
    char dataLimite[11];
    int prioridade;
    int concluida;
} Tarefa;

Tarefa *tarefas[MAX_TAREFAS];
int qtTarefas = 0;

#endif
