#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

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
int numTarefas = 0;

void inicializa() {
    FILE *arquivo = fopen("tarefas.csv", "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo!\n");
        return;

    }
    char linha[512];
    fgets(linha, 512, arquivo);

    while (fgets(linha, 512, arquivo)) {
        tarefas[numTarefas] = (Tarefa *)malloc(sizeof(Tarefa));
        sscanf(linha, "%d,%[^,],%[^,],%[^,],%d,%d",
            &tarefas[numTarefas]->id,
            tarefas[numTarefas]->nome,
            tarefas[numTarefas]->descricao,
            tarefas[numTarefas]->dataLimite,
            &tarefas[numTarefas]->prioridade,
            &tarefas[numTarefas]->concluida);
        numTarefas++;

    }
    fclose(arquivo);

}

void salvarDados() {
    FILE *arquivo = fopen("tarefas.csv", "w");
    if (!arquivo) {
        printf("Erro ao salvar o arquivo!\n");
        return;

    }

    fprintf(arquivo, "ID,Nome,Descricao,DataLimite,Prioridade,Concluida\n");
    for (int i = 0; i < numTarefas; i++) {
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

void adicionarTarefa() {
    if (numTarefas >= MAX_TAREFAS) {
        printf("Limite de tarefas atingido. Delete alguma para continuar. \n");
        system("pause");
        return;

    }

    Tarefa *nova = (Tarefa *)malloc(sizeof(Tarefa));
    nova->id = numTarefas + 1;

    printf("ADICIONAR NOVA TAREFA\n\n");

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

    tarefas[numTarefas++] = nova;
    salvarDados();

    printf("\nTarefa adicionada com sucesso. ");
    system("pause");

}

void listarTarefas() {
    printf("LISTA DE TAREFAS\n\n");

    for (int i = 0; i < numTarefas; i++) {
        printf("ID: %d\n", tarefas[i]->id);
        printf("Nome: %s\n", tarefas[i]->nome);
        printf("Descricao: %s\n", tarefas[i]->descricao);
        printf("Data Limite: %s\n", tarefas[i]->dataLimite);
        printf("Prioridade: %d\n", tarefas[i]->prioridade);
        printf("Concluida: %s\n\n", tarefas[i]->concluida ? "Sim" : "Nao");

    }

    system("pause");

}

int main() {
    inicializa();

    int opcao_int;
    char opcao_ch;

    while (1) {
        system("cls");
        printf("MENU\n\n   1. Adicionar tarefa \n   2. Listar tarefas\n   3. Sair \n\nDigite a opcao desejada: ");
        opcao_ch = getch();
        opcao_int = opcao_ch - '0';

        switch (opcao_int) {
            case 1:
                system("cls");
                adicionarTarefa();
                break;

            case 2:
                system("cls");
                listarTarefas();
                break;

            case 3:
                system("cls");
                printf("Obrigado por usar o programa! \n\n");
                for (int i = 0; i < numTarefas; i++) {
                    free(tarefas[i]);

                }
                return 0;

            default:
                system("cls");
                printf("Opcao invalida. Retornando ao menu. ");
                system("pause");
                break;

        }

    }

}
