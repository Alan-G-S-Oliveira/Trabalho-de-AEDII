#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include "heap.h"

int main(){

    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    char linha[250];
    char aux[8];
    int i, x1, x2, n, menu, prioridade;
    Lista *li;
    FILE *fi;
    Nave adc, consulta;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);
    fflush(stdin);

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


        x1 = 1;
        x2 = 1;

        define_prioridade(&adc, x1, x2);
        adc_lista(li, adc);

    }

    cria_heap(li);

    do{

        printf("Digite:\n1 - Adcionar Nave.\n2 - Remover Nave.\n3 - Sair.\n\n");
        scanf("%d", &menu);
        fflush(stdin);

        system("cls");

        switch(menu){

            case 1:
                printf("fds");

                break;
            case 2:

                n = rand() % 10;

                consulta_heap(li, &consulta);

                if(n == 0){

                    x1 = (rand() % 5) + 1;
                    x2 = (rand() % 5) + 1;

                    define_prioridade(&consulta, x1, x2);
                    altera_prioridade(li, 0, consulta.prioridade);

                    printf("Detectamos uma erro no cálculo da prioridade, portanto, não realizamos a remoção da nave por questões de segurança.\n");

                }else{

                    remove_heap(li);
                    printf("Nome da nave: %s.\nTipo da nave: %s.\nPrioridade da nave: %d.\n", consulta.nome, consulta.tipo, consulta.prioridade);
                    printf("\nPassageiros:\n");
                    for(i = 0; i < 3; i++){

                        printf("Nome: %s.\nPlaneta de origem: %s.\n", consulta.alien[i].nome, consulta.alien[i].planeta);
                        printf("Idade: %d.\nIdentificação: %d.\n\n", consulta.alien[i].idade, consulta.alien[i].id);

                    }

                    printf("Suprimentos: ");
                    for(i = 0; i < 3; i++){

                        if(i < 2)
                            printf("%s, ", consulta.suprimentos[i]);
                        else
                            printf("%s", consulta.suprimentos[i]);
                    }
                    printf(".");

                }
        }

    }while(menu != 3);

    apaga_lista(li);
    fclose(fi);

    return 0;
}
