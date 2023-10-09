#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include "heap.h"
#include "hash.h"
#include "naves.h"

const char suprimentos[][50] = {"Unhas postiças que desafiam a gravidade", "Brazinito", "Água intergaláctica", "Notebook", "Carne enlatada de unicórnio", "Objetos de latex sonoros"};

int main(){

    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    char linha[250];
    char aux[8];
    int i, j, x1, x2, n, menu, prioridade, posicao, auxiliar[3];
    Lista *li;
    FILE *fi;
    Nave adc, consulta;
    LISTA *hash[MAX];

    for(i = 0; i < MAX; i++)
        hash[i] = Cria_Lista();

    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);
    fflush(stdin);

    li = cria_lista(n);

    fi = fopen("naves.csv", "r");

    if(fi == NULL)
        exit(1);

    fgets(linha, 250, fi);

    while(fgets(linha, 250, fi) != NULL){

        corrige_string(linha);

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
            adc.suprimentos[i] = atoi(strtok(NULL, ","));


        x1 = 1;
        x2 = 1;

        define_prioridade(&adc, x1, x2);
        if(!adc_lista(li, adc))
            break;

    }

    cria_heap(li);

    do{

        printf("Digite:\n1 - Adcionar Nave.\n2 - Remover Nave.\n3 - Sair.\n\n");
        scanf("%d", &menu);
        fflush(stdin);

        system("cls");

        switch(menu){

            case 1:
                printf("Digite o nome da nave: ");
                fgets(adc.nome, 50, stdin);
                corrige_string(adc.nome);
                fflush(stdin);

                do{

                    system("cls");
                    printf("Digite o tipo da nave:\n1 - Ambulância;\n2 - Refugiados;\n3 - Cargas;\n4 - Policial;\n5 - Viametro.\n");
                    scanf("%d", &n);
                    fflush(stdin);

                } while(n < 1 || n > 5);

                switch(n){

                    case 1:
                        strcpy(adc.tipo, "Ambulância");
                        break;
                    case 2:
                        strcpy(adc.tipo, "Refugiados");
                        break;
                    case 3:
                        strcpy(adc.tipo, "Cargas");
                        break;
                    case 4:
                        strcpy(adc.tipo, "Policial");
                        break;
                    default:
                        strcpy(adc.tipo, "Viametro");

                }

                for(i = 0; i < 3; i++){

                    printf("Digite o nome do passageiro %d: ", i + 1);
                    fgets(adc.alien[i].nome, 50, stdin);
                    corrige_string(adc.alien[i].nome);
                    fflush(stdin);

                    printf("Digite a indentificação do passageiro %d: ", i + 1);
                    scanf("%d", &adc.alien[i].id);
                    fflush(stdin);

                    printf("Digite a idade do passageiro %d: ", i + 1);
                    scanf("%d", &adc.alien[i].idade);
                    fflush(stdin);

                    printf("Digite o planeta do passageiro %d: ", i + 1);
                    fgets(adc.alien[i].planeta, 50, stdin);
                    corrige_string(adc.alien[i].planeta);
                    fflush(stdin);

                }

                for(i = 0; i < 3; i++){

                    printf("Digite 0 para ver a lista de suprimentos ou digite de 1 a 25 para adcionar o item: ");
                    scanf("%d", &n);
                    fflush(stdin);

                    if(n == 0)
                        exibe_itens();
                    //else
                        //adc_itens(li, n);

                }


                if(adc_heap(li, adc))
                    printf("Nave adcionada com sucesso!\n");
                else
                    printf("Não foi possível adcionar a nave!\n");

                break;
            case 2:

                n = rand() % 10;

                consulta_heap(li, &consulta);

                if(n == 0){

                    x1 = (rand() % 5) + 1;
                    x2 = (rand() % 5) + 1;

                    define_prioridade(&consulta, x1, x2);
                    altera_prioridade(li, 0, consulta.prioridade);

                    printf("Detectamos um erro no cálculo da prioridade, portanto, não realizamos a remoção da nave por questões de segurança.\n");

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
                            printf("%s, ", suprimentos[consulta.suprimentos[i]]);
                        else
                            printf("%s", suprimentos[consulta.suprimentos[i]]);
                    }
                    printf(".\n\n");

                    auxiliar[0] = consulta.suprimentos[0];
                    auxiliar[1] = consulta.suprimentos[1];
                    auxiliar[2] = consulta.suprimentos[2];

                    posicao = ordena_numeros(auxiliar);
                    for(i = 0; i < hash[posicao] -> qtd; i++){

                        if(verifica_iguais(auxiliar, hash[posicao] -> dados[i]))
                            break;

                    }
                    if(i == hash[posicao] -> qtd){
                        for(i = 0; i < 3; i++)
                            hash[posicao] -> dados[hash[posicao] -> qtd][i] = auxiliar[i];

                        hash[posicao] -> qtd++;
                    }

                    if(hash[posicao] -> qtd == 6){

                        printf("A abertura da passagem vai se expandir!");
                        system("pause");

                    }

                }
        }

    }while(menu != 3);

    apaga_lista(li);
    fclose(fi);

    for(i = 0; i < 3; i++){
        printf("Encerrando");
        for(j = 0; j < 3; j++){

            printf(".");
            sleep(1);

        }
        system("cls");
    }

    return 0;
}
