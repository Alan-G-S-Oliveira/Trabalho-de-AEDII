#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include "heap.h"

int main(){

    setlocale(LC_ALL, "portuguese");

    char linha[250];
    char aux[8];
    int i, prioridade;
    Lista *li;
    FILE *fi;
    Nave adc, nm;

    li = cria_lista(60);

    fi = fopen("naves.csv", "r");

    if(fi == NULL)
        exit(1);

    fgets(linha, 250, fi);

    while(fgets(linha, 250, fi) != NULL){
        strcpy(adc.nome, strtok(linha, ","));
        strcpy(adc.tipo, strtok(NULL, ","));

        for(i = 0; i < 3; i++){

            strcpy(adc.alien[i].nome, strtok(NULL, ","));

            strcpy(aux, strtok(NULL, ","));
            adc.alien[i].id = atoi(aux);

            strcpy(aux, strtok(NULL, ","));
            adc.alien[i].idade = atoi(aux);

            strcpy(adc.alien[i].planeta, strtok(NULL, ","));

        }

        for(i = 0; i < 3; i++)
            strcpy(adc.suprimentos[i], strtok(NULL, ","));

        prioridade = floor((adc.alien[0].idade + adc.alien[1].idade + adc.alien[2].idade) / 3);

        if(!strcmp("Ambulância", adc.tipo))
            adc.prioridade = floor(prioridade * 0.9);
        else if(!strcmp("Refugiados", adc.tipo))
            adc.prioridade = floor(prioridade * 0.8);
        else if(!strcmp("Cargas", adc.tipo))
            adc.prioridade = floor(prioridade * 0.7);
        else if(!strcmp("Policial", adc.tipo))
            adc.prioridade = floor(prioridade * 0.6);
        else
            adc.prioridade = floor(prioridade * 0.5);

        adc_lista(li, adc);

    }

    cria_heap(li);

    consulta_heap(li, &nm);

    printf("Nave: %s.\nTipo: %s.\nPriodidade: %d.\n\n", nm.nome, nm.tipo, nm.prioridade);

    remove_heap(li);

    consulta_heap(li, &nm);

    printf("Nave: %s.\nTipo: %s.\nPriodidade: %d.\n\n", nm.nome, nm.tipo, nm.prioridade);

    apaga_lista(li);
    fclose(fi);

    return 0;
}
