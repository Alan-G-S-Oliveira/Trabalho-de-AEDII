#include <stdlib.h>
#include "hash.h"

LISTA *Cria_Lista(){

    LISTA *li = (LISTA *)malloc(sizeof(LISTA));

    if(li != NULL)
        li -> qtd = 0;

    return li;

}

void Libera_Lista(LISTA *li){

    free(li);

}

int ordena_numeros(const int x[]){

    int i, menor, maior, meio;
    char aux[4];

    maior = x[0];
    menor = x[0];
    for(i = 1; i < 3; i++){

        if(x[i] < menor)
            menor = x[i];

        if(x[i] > maior)
            maior = x[i];

    }

    for(i = 0; i < 3; i++){

        if(x[i] != maior && x[i] != menor){

            meio = x[i];
            break;

        }

    }

    aux[0] = '0' + menor;
    aux[1] = '0' + meio;
    aux[2] = '0' + maior;
    aux[3] = '\0';

    return atoi(aux);

}

int verifica_iguais(const int x[],const int y[]){

    return (x[0] == y[0] && x[1] == y[1] && x[2] == y[2]);

}
