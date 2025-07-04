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
int qtTarefas = 0;

void inicializa() {
    FILE *arquivo = fopen("tarefas.csv", "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo!\n");
        return;

    }
    char linha[512];
    fgets(linha, 512, arquivo);

    while (fgets(linha, 512, arquivo)) {
        tarefas[qtTarefas] = (Tarefa *)malloc(sizeof(Tarefa));
        sscanf(linha, "%d,%[^,],%[^,],%[^,],%d,%d",
            &tarefas[qtTarefas]->id,
            tarefas[qtTarefas]->nome,
            tarefas[qtTarefas]->descricao,
            tarefas[qtTarefas]->dataLimite,
            &tarefas[qtTarefas]->prioridade,
            &tarefas[qtTarefas]->concluida);
        qtTarefas++;

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
    for (int i = 0; i < qtTarefas; i++) {
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
    if (qtTarefas >= MAX_TAREFAS) {
        printf("Limite de tarefas atingido. \n");
        system("pause");
        return;

    }

    Tarefa *nova = (Tarefa *)malloc(sizeof(Tarefa));
    nova->id = qtTarefas + 1;

    system("cls");
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

    tarefas[qtTarefas++] = nova;
    salvarDados();

    printf("\nTarefa adicionada com sucesso. ");
    system("pause");

}

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

    } else if (resposta != 'N' && resposta != 'n') {
        printf("\nResposta invalida. ");
        system("pause");

    } else {
        printf("Operacao cancelada com sucesso. ");
        system("pause");

    }

}

void editarTarefa(int numTarefa) {
    int novaPrioridade;

    system("cls");
    printf("EDITAR TAREFA\n");

    printf("\nNome atual: %s.\n", tarefas[numTarefa]->nome);
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

void selecionarTarefa(int numTarefa) {
    char resposta;

    system("cls");
    printf("TAREFA SELECIONADA: %s. \n\n", tarefas[numTarefa]->nome);

    printf("ID: %d\n", tarefas[numTarefa]->id);
    printf("Nome: %s\n", tarefas[numTarefa]->nome);
    printf("Descricao: %s\n", tarefas[numTarefa]->descricao);
    printf("Data Limite: %s\n", tarefas[numTarefa]->dataLimite);
    printf("Prioridade: %d\n", tarefas[numTarefa]->prioridade);
    printf("Concluida: %s\n\n", tarefas[numTarefa]->concluida ? "Sim" : "Nao");

    printf("Escolha uma opcao: EDITAR (E) | EXCLUIR (D) | SAIR (R) \n");
    resposta = getch();

    if (resposta == 'E' || resposta == 'e') {
        editarTarefa(numTarefa);
        selecionarTarefa(numTarefa);

    } else if (resposta == 'D' || resposta == 'd') {
        excluirTarefa(numTarefa);

    } else if (resposta != 'R' && resposta != 'r') {
        printf("\nResposta invalida. ");
        system("pause");
        selecionarTarefa(numTarefa);

    }

}

int procurarPorId(int id) {
    for (int i = 0; i < qtTarefas; i++) {
        if (tarefas[i]->id == id) {
            return i;

        }

    }

    return -1;

}

void listarTarefas() {
    char resposta;
    int id, numTarefa;

    system("cls");
    printf("LISTA DE TAREFAS\n\n");
    printf("\tID\t|Titulo              |Data Limite\t|Prioridade\t|Status\n");

    for (int i = 0; i < qtTarefas; i++) {
        printf("\t%02d\t|%-20.20s|%s\t|%d\t\t|%s\n", tarefas[i]->id, tarefas[i]->nome, tarefas[i]->dataLimite, tarefas[i]->prioridade, tarefas[i]->concluida ? "Concluida" : "Pendente");

    }

    printf("\nDeseja selecionar uma tarefa? (S/N) \n");
    resposta = getch();

    if (resposta == 'S' || resposta == 's') {
        printf("\nDigite o ID da tarefa que deseja selecionar: \n");
        scanf("%d", &id);
        getchar();

        numTarefa = procurarPorId(id);

        if (numTarefa == -1) {
            printf("\nTarefa nao encontrada. ");
            system("pause");

        } else {
            selecionarTarefa(numTarefa);

        }

    } else if (resposta != 'N' && resposta != 'n') {
        printf("\nResposta invalida. ");
        system("pause");

    } else {
        return;

    }

    listarTarefas();

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
                adicionarTarefa();
                break;

            case 2:
                listarTarefas();
                break;

            case 3:
                system("cls");
                printf("Obrigado por usar o programa! \n\n");
                for (int i = 0; i < qtTarefas; i++) {
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
