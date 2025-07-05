#ifndef PESQUISARPALAVRACHAVE_H
#define PESQUISARPALAVRACHAVE_H

#include "global.h"
#include "listarPorPalavraChave.h"

void pesquisarPalavraChave() {
    char chave[MAX_STR];
    char resposta;

    system("cls");
    printf("PESQUISA POR PALAVRA-CHAVE\n\n");

    printf("OBSERVACAO: Procure pelas tarefas listadas em seus menus correspondentes (Pendente/Concluida). \n\n");

    printf("Digite uma palavra para encontrar a tarefa desejada: ");
    fgets(chave, MAX_STR, stdin);
    chave[strcspn(chave, "\n")] = 0;

    listarPorPalavraChave(chave);

    printf("\nDigite 1 para pesquisar novamente (0 para sair): ");
    scanf("%d", &resposta);
    getchar();
    if (resposta == 1) {
        pesquisarPalavraChave();

    }

}

#endif
