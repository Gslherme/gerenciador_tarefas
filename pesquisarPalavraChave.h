#ifndef PESQUISARPALAVRACHAVE_H
#define PESQUISARPALAVRACHAVE_H

#include "global.h"
#include "listarPorPalavraChave.h"

// Função que solicita ao usuário uma palavra-chave e realiza a busca
void pesquisarPalavraChave() {
    char chave[MAX_STR];
    char resposta;

    system("cls");
    printf("PESQUISA POR PALAVRA-CHAVE\n\n");

    printf("OBSERVACAO: Procure pelas tarefas listadas em seus menus correspondentes (Pendente/Concluida). \n\n");

    // Captura da palavra-chave
    printf("Digite uma palavra para encontrar a tarefa desejada: ");
    fgets(chave, MAX_STR, stdin);
    chave[strcspn(chave, "\n")] = 0;

    // Chamada da função que imprime as tarefas encontradas
    listarPorPalavraChave(chave);

    // Opção para repetir a busca
    printf("\nDigite 1 para pesquisar novamente (0 para sair): ");
    scanf("%d", &resposta);
    getchar();
    if (resposta == 1) {
        pesquisarPalavraChave();

    }

}

#endif
