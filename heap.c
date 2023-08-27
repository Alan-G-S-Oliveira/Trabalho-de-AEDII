#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "heap.h"

Lista *cria_lista(int tamanho){

    Lista *li;
    li = (Lista *)malloc(sizeof(Lista));

    if(li != NULL){

        li -> qtd = 0;
        li -> star = (Nave *)malloc(sizeof(Nave) * tamanho);
        li -> tamanho = tamanho;

    }

    return li;

}

void apaga_lista(Lista *li){

    free(li -> star);
    free(li);

}

int tamanho_lista(Lista *li){

    if(li == NULL)
        return -1;

    return (li -> qtd);

}

int adc_lista(Lista *li, Nave adc){

    if(li == NULL || li -> qtd == li -> tamanho)
        return 0;

    li -> star[li -> qtd] = adc;
    li -> qtd++;

    return 1;

}

int cria_heap(Lista *li){

    if(li == NULL || li -> qtd == 0)
        return 0;

    int i;
    int n = li -> qtd - 1;

    for(i = floor((n - 1) / 2); i >= 0; i--)
        descer_heap(li, i);

    return 1;

}

int adc_heap(Lista *li, Nave adc){

    if(li == NULL || li -> qtd == li -> tamanho)
        return 0;

    li -> star[li -> qtd] = adc;
    li -> qtd++;
    subir_heap(li, li -> qtd - 1);

    return 1;

}

int remove_heap(Lista *li){

    if(li == NULL || li -> qtd == 0)
        return 0;

    li -> star[0] = li -> star[li -> qtd - 1];
    li -> qtd--;
    descer_heap(li, 0);

    return 1;

}

int consulta_heap(Lista *li, Nave *checar){

    if(li == NULL || li -> qtd == 0)
        return 0;

    *checar = li -> star[0];

    return 1;

}

int altera_prioridade(Lista *li, int i, int nova_prioridade){

    if(li == NULL || li -> qtd == 0)
        return 0;

    li -> star[i].prioridade = nova_prioridade;
    subir_heap(li, i);
    descer_heap(li, i);

    return 1;

}

void subir_heap(Lista *li, int i){

    int j = floor((i - 1) / 2);
    Nave aux;

    if(j >= 0){

        if(li -> star[i].prioridade > li -> star[j].prioridade){

            aux = li -> star[i];
            li -> star[i] = li -> star[j];
            li -> star[j] = aux;

            subir_heap(li, j);

        }

    }

}

void descer_heap(Lista *li, int i){

    int j = 2*i + 1;
    int n = li -> qtd - 1;
    Nave aux;

    if(j <= n){

        if(j < n){

            if(li -> star[j + 1].prioridade > li -> star[j].prioridade)
                j = j + 1;

        }

        if(li -> star[j].prioridade > li -> star[i].prioridade){

            aux = li -> star[i];
            li -> star[i] = li -> star[j];
            li -> star[j] = aux;

            descer_heap(li, j);

        }

    }

}

void define_prioridade(Nave *pri, int x1, int x2){

    float prioridade, x;

    x = (float)x1 / x2;

    prioridade = (float)((pri -> alien[0].idade + pri -> alien[1].idade + pri -> alien[2].idade) / 3);
    prioridade = (float)(prioridade * x);


    if(!strcmp("Ambulância", pri -> tipo))
        pri -> prioridade = floor(prioridade * 0.9);
    else if(!strcmp("Refugiados", pri -> tipo))
        pri -> prioridade = floor(prioridade * 0.8);
    else if(!strcmp("Cargas", pri -> tipo))
        pri -> prioridade = floor(prioridade * 0.7);
    else if(!strcmp("Policial", pri -> tipo))
        pri -> prioridade = floor(prioridade * 0.6);
    else
        pri -> prioridade = floor(prioridade * 0.5);

}
