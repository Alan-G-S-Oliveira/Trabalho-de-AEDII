#include <stdlib.h>
#include "hash.h"


Hash *cria_hash(){

    //Aloca espaço para a hash
    Hash *hs = (Hash *)malloc(sizeof(Hash));

    //Verifica de a alocação funcionou. Caso sim, a função criar_lista é chamada para todas as posições do vetor dados
    if(hs != NULL){

        int i;
        for(i = 0; i < MAX; i++)
            hs -> dados[i] = cria_lista_encadeada();

    }

    return hs;

}

ListaEncadeada *cria_lista_encadeada(){

    //Aloca espaço para a lista encadeada
    ListaEncadeada *li = (ListaEncadeada *)malloc(sizeof(ListaEncadeada));

    //Verifica se a alocação funcionou. Se sim, a quantidade recebe zero e o inicio da lista recebe 1
    if(li != NULL){

        li -> inicio = NULL;
        li -> qtd = 0;

    }

    return li;

}

void libera_hash(Hash *hs){

    //Verifica se a hash é válida. Se sim, usa a função libera_lista_encadeada para apagar cada posição do vetor dados
    if(hs != NULL){

        int i;
        for(i = 0; i < MAX; i++)
            libera_lista_encadeada(hs -> dados[i]);

    }

    //libera a hash
    free(hs);

}

void libera_lista_encadeada(ListaEncadeada *li){

    if(li != NULL){

        //Cria um auxiliar para navegar pela lista sem perder a referência para o começo
        struct elemento *aux;

        while(li -> inicio != NULL){

            //Percorre cada nó e o libera em seguida
            aux = li -> inicio;
            li -> inicio = li -> inicio -> prox;
            free(aux);

        }

        //Libera a cabeça da lista
        free(li);

    }

}

int adc_lista_encadeada(ListaEncadeada *li, int adc[]){

    if(li == NULL)
        return 0;

    struct elemento *no = (struct elemento *)malloc(sizeof(struct elemento));

    if(no == NULL)
        return 0;

    no -> dados[0] = adc[0];
    no -> dados[1] = adc[1];
    no -> dados[2] = adc[2];

    no -> prox = li -> inicio;
    li -> inicio = no;
    li -> qtd++;

    return 1;

}

int remove_lista_encadeada(ListaEncadeada *li){

    if(li == NULL)
        return 0;

    if(li -> qtd == 0)
        return 0;

    struct elemento *aux = li -> inicio;

    li -> inicio = aux -> prox;
    li -> qtd--;
    free(aux);

    return 1;

}

int adc_hash(Hash *hs, int adc[], int posicao){

    if(hs == NULL)
        return 0;

    return adc_lista_encadeada(hs -> dados[posicao], adc);


}

int remove_hash(Hash *hs, int posicao){

    if(hs == NULL)
        return 0;

    if(hs -> dados[posicao] -> qtd == 0)
        return 0;

    return remove_lista_encadeada(hs -> dados[posicao]);
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

int verifica_iguais(Hash *hs, int posicao, const int x[]){

    if(hs == NULL)
        return -1;

    if(hs -> dados[posicao] == NULL)
        return -1;

    struct elemento *aux = hs -> dados[posicao] -> inicio;

    while(aux != NULL){

        if(aux -> dados[0] == x[0] && aux -> dados[1] == x[1] && aux -> dados[2] == x[2])
            return 1;

        aux = aux -> prox;

    }

    return 0;
}
