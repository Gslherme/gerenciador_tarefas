#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "global.h"
#include "adicionarTarefa.h"
#include "listarTarefasPendentes.h"
#include "listarTarefasConcluidas.h"
#include "pesquisarPalavraChave.h"

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

int main() {
    inicializa();

    int opcao_int;
    char opcao_ch;

    while (1) {
        system("cls");
        printf("MENU\n\n   1. Adicionar tarefa\n   2. Listar tarefas pendentes\n   3. Listar tarefas concluidas\n   4. Procurar por palavra-chave\n   5. Sair \n\nDigite a opcao desejada: ");
        opcao_ch = getch();
        opcao_int = opcao_ch - '0';

        switch (opcao_int) {
            case 1:
                adicionarTarefa();
                break;

            case 2:
                listarTarefasPendentes();
                break;

            case 3:
                listarTarefasConcluidas();
                break;

            case 4:
                pesquisarPalavraChave();
                break;

            case 5:
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
