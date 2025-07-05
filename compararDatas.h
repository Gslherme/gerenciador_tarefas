#ifndef COMPARARDATAS_H
#define COMPARARDATAS_H

#include "global.h"

// Função que compara duas datas no formato AAAA-MM-DD
// Retorna valor semelhante ao strcmp: <0 se data1 < data2, >0 se data1 > data2, 0 se iguais
int compararDatas(const char *data1, const char *data2) {
    return strcmp(data1, data2);

}

#endif
