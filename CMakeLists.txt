cmake_minimum_required(VERSION 3.29)
project(gerenciador_tarefas C)

set(CMAKE_C_STANDARD 11)

add_executable(gerenciador_tarefas main.c
        global.h
        salvarDados.h
        adicionarTarefa.h
        excluirTarefa.h
        editarTarefa.h
        selecionarTarefa.h
        procurarPorId.h
        listarTarefasPendentes.h
        imprimirLista.h
        listarTarefasConcluidas.h
        listarPorPalavraChave.h
        pesquisarPalavraChave.h)
