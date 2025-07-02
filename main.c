#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void) {
    int opcao_int;
    char opcao_ch;

    while (1) {
        system("cls");
        printf("MENU\n\n   1. Adicionar tarefa \n   2. Marcar tarefa como concluido \n   3. Alterar dados da tarefa \n   4. Buscar tarefas por palavra-chave \n   5. Listar tarefas pendentes \n   6. Sair \n\nDigite a opcao desejada: \n");
        opcao_ch = getch();
        opcao_int = opcao_ch - '0';

        switch (opcao_int) {
            case 1:
                system("cls");
                printf("Opcao 1. ");
                system("pause");
                break;

            case 2:
                system("cls");
                printf("Opcao 2. ");
                system("pause");
                break;

            case 3:
                system("cls");
                printf("Opcao 3. ");
                system("pause");
                break;

            case 4:
                system("cls");
                printf("Opcao 4. ");
                system("pause");
                break;

            case 5:
                system("cls");
                printf("Opcao 5. ");
                system("pause");
                break;

            case 6:
                system("cls");
                printf("Obrigado por usar o programa! ");
                system("pause");
                return 0;

            default:
                system("cls");
                printf("Opcao invalida. ");
                system("pause");
                break;

        }

    }

}
