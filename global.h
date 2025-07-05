#ifndef GLOBAL_H
#define GLOBAL_H

#define MAX_TAREFAS 100  // Número máximo de tarefas
#define MAX_STR 100      // Tamanho máximo para strings

// Definição da struct Tarefa
typedef struct {
    int id;
    char nome[MAX_STR];
    char descricao[MAX_STR];
    char dataLimite[11];
    int prioridade;
    int concluida;
} Tarefa;

// Vetor de ponteiros para tarefas
Tarefa *tarefas[MAX_TAREFAS];
int qtTarefas = 0;  // Quantidade atual de tarefas

#endif
