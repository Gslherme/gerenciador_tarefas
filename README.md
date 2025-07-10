# gerenciador_tarefas
 Trabalho da disciplina de Linguagem de Programação com tema de "Gerenciador de Tarefas Pessoais".

Este projeto é um sistema de linha de comando para gerenciamento de tarefas pessoais, desenvolvido em linguagem C, como parte das atividades da disciplina de Linguagem de Programação. Ele permite ao usuário realizar diversas operações de controle de tarefas, com persistência de dados em arquivo CSV e uso de estruturas dinâmicas via ponteiros e structs.

FUNCIONALIDADES ATUAIS

- Adicionar novas tarefas
- Listar tarefas pendentes (com ordenação por prioridade ou data)
- Listar tarefas concluídas (com opção de reverter o status)
- Editar tarefas existentes
- Excluir tarefas
- Marcar/desmarcar como concluída
- Pesquisar tarefas por palavra-chave no nome
- Procurar tarefas por ID
- Salvar e carregar dados automaticamente em arquivo CSV (tarefas.csv)

ESTRUTURA DO PROJETO

gerenciador_tarefas/
- main.c
# Arquivo principal com menu e fluxo do programa
- adicionarTarefa.h
# Lógica para adicionar tarefas
- editarTarefa.h
# Edição de nome, descrição, data e prioridade
- excluirTarefa.h
# Exclusão com realocação de memória
- listarTarefasPendentes.h
# Lista pendentes com ordenação opcional
- listarTarefasConcluidas.h
# Lista concluídas com opção de reverter status
- ordenarPorData.h
# Função de ordenação por data (usando strcmp)
- ordenarPorPrioridade.h
# Função de ordenação por prioridade (decrescente)
- selecionarTarefa.h
# Menu para editar/excluir/status individual
- salvarDados.h
# Escrita do CSV
- procurarPorId.h
# Localização da tarefa via ID
- imprimirLista.h
# Impressão formatada da lista de tarefas
- listarPorPalavraChave.h
# Filtro de tarefas com base em palavra-chave
- pesquisarPalavraChave.h
# Entrada da palavra-chave e interface
- compararDatas.h
# Comparação simples entre datas (AAAA-MM-DD)
- global.h
# Definições globais: struct Tarefa e vetor de ponteiros
- tarefas.csv
# Arquivo de persistência
- CMakeLists.txt (opcional)
# Para compilar com CMake

REQUISITOS

- Compilador C (ex: GCC)
- CMake (opcional)
- Sistema Windows (recomendado)
    - Uso de conio.h e system("cls")
- Para Linux/macOS: adaptar para substituir funções específicas de terminal

COMPILAÇÃO E EXECUÇÃO

Usando CMake:
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./gerenciador_tarefas

Compilação manual (Windows):
> gcc main.c -o gerenciador_tarefas
> gerenciador_tarefas.exe

OBSERVAÇÕES

- O arquivo tarefas.csv é o banco de dados local (criado e atualizado automaticamente).
- Todo o programa funciona via linha de comando com menu interativo.
- Estrutura modular: cada funcionalidade está separada em headers para melhor organização.

LICENÇA

Projeto de uso acadêmico, sem licença específica.
