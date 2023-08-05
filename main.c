#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "heap.h"

int main(){

    setlocale(LC_ALL, "portuguese");

    int i, n;
    Lista *li;
    Nave falcon, starship;

    li = cria_lista(10);

    for(i = 0; i < 5; i++){

        printf("Digite um número: ");
        scanf("%d", &n);

        falcon.prioridade = n;

        adc_lista(li, falcon);

    }

    printf("Tamanho: %d.\n\n", tamanho_lista(li));

    cria_heap(li);

    altera_prioridade(li, 4, 9);

    for(i = 0; i < 5; i++){

        consulta_heap(li, &starship);
        remove_heap(li);

        printf("Prioridade: %d.\n", starship.prioridade);

    }

    return 0;
}
