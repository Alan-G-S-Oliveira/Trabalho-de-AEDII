#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include "heap.h"
#include "hash.h"
#include "naves.h"

int main(){

    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    char linha[250];
    char aux[8];
    int i, j, x1, x2, n, menu, prioridade, posicao, auxiliar[3];
    Lista *li;
    FILE *fi;
    Nave adc, consulta;
    Hash *hs;

    hs = cria_hash();

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

        limpa_tela();

        switch(menu){

            case 1:
                printf("Digite o nome da nave: ");
                fgets(adc.nome, 50, stdin);
                corrige_string(adc.nome);
                fflush(stdin);

                do{

                    limpa_tela();
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

                    do{

                    limpa_tela();
                    printf("Adcione os itens:\n");
                    printf("Digite:\n1 - Unhas postiças que desafiam a gravidade;\n2 - Brazinito;\n3 - Água intergaláctica;\n4 - Notebook;\n5 - Carne enlatada de unicórnio;\n6 - Objetos de latex sonoros.");
                    scanf("%d", &n);
                    fflush(stdin);

                    }while(n < 1 || n > 6);

                    if(i == 0)
                        adc.suprimentos[i] = n;
                    if(i == 1){

                        while(n == adc.suprimentos[0]){

                            limpa_tela();
                            printf("É proibido a entrada de intens iguais para preservar a economia desta parte da galáxia.\nAdcione os itens:\n");
                            printf("Digite:\n1 - Unhas postiças que desafiam a gravidade;\n2 - Brazinito;\n3 - Água intergaláctica;\n4 - Notebook;\n5 - Carne enlatada de unicórnio;\n6 - Objetos de latex sonoros.");
                            scanf("%d", &n);
                            fflush(stdin);

                        }

                        if(n != adc.suprimentos[0])
                            adc.suprimentos[i] = n;

                    }
                    if(i == 2){

                        while(n == adc.suprimentos[0] || n == adc.suprimentos[1]){

                            limpa_tela();
                            printf("É proibido a entrada de intens iguais para preservar a economia desta parte da galáxia.\nAdcione os itens:\n");
                            printf("Digite:\n1 - Unhas postiças que desafiam a gravidade;\n2 - Brazinito;\n3 - Água intergaláctica;\n4 - Notebook;\n5 - Carne enlatada de unicórnio;\n6 - Objetos de latex sonoros.");
                            scanf("%d", &n);
                            fflush(stdin);

                        }

                        if(n != adc.suprimentos[0])
                            adc.suprimentos[i] = n;

                    }
                }

                x1 = (rand() % 5) + 1;
                x2 = (rand() % 5) + 1;
                define_prioridade(&adc, x1, x2);

                limpa_tela();
                if(adc_heap(li, adc))
                    printf("Nave adcionada com sucesso!\n");
                else
                    printf("Não foi possível adcionar a nave!\n");

                break;
            case 2:

                n = rand() % 10;

                if(!consulta_heap(li, &consulta)){

                    printf("A fila de naves está vazia!\n");
                    break;

                }

                if(n == 0){

                    x1 = (rand() % 5) + 1;
                    x2 = (rand() % 5) + 1;

                    define_prioridade(&consulta, x1, x2);
                    altera_prioridade(li, 0, consulta.prioridade);

                    printf("Detectamos um erro no cálculo da prioridade, portanto, não realizaremos a remoção da nave por questões de segurança.\n");

                }else{

                    remove_heap(li);
                    exibe_naves(consulta);

                    auxiliar[0] = consulta.suprimentos[0];
                    auxiliar[1] = consulta.suprimentos[1];
                    auxiliar[2] = consulta.suprimentos[2];

                    posicao = ordena_numeros(auxiliar);

                    if(!verifica_iguais(hs, posicao, auxiliar))
                        adc_hash(hs, auxiliar, posicao);

                    if(hs -> dados[posicao] -> qtd == 6){

                        Sleep(3000);
                        printf("A abertura da passagem vai se expandir!\n\n");

                        for(i = 0; i < 5; i++){

                            Sleep(2000);
                            printf("Nave %d:\n\n\n", i + 1);
                            consulta_heap(li, &consulta);
                            remove_heap(li);
                            remove_hash(hs, posicao);
                            exibe_naves(consulta);

                        }

                    }

                }

        }

    }while(menu != 3);

    apaga_lista(li);
    libera_hash(hs);
    fclose(fi);

    for(i = 0; i < 3; i++){
        printf("Encerrando");
        for(j = 0; j < 3; j++){

            printf(".");
            sleep(1);

        }
        limpa_tela();
    }

    return 0;
}
