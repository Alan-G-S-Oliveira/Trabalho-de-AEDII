#include <locale.h>
#include "naves.h"

const char suprimentos[][50] = {"Unhas postiças que desafiam a gravidade", "Brazinito", "Água intergaláctica", "Notebook", "Carne enlatada de unicórnio", "Objetos de latex sonoros"};

void corrige_string(char *str){

    if(str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';

}

void exibe_naves(Nave nave){

    setlocale(LC_ALL, "Portuguese");

    int i;

    printf("Nome da nave: %s.\nTipo da nave: %s.\nPrioridade da nave: %d.\n", nave.nome, nave.tipo, nave.prioridade);
    printf("\nPassageiros:\n");
    for(i = 0; i < 3; i++){

        printf("Nome: %s.\nPlaneta de origem: %s.\n", nave.alien[i].nome, nave.alien[i].planeta);
        printf("Idade: %d.\nIdentificação: %d.\n\n", nave.alien[i].idade, nave.alien[i].id);

    }

    printf("Suprimentos: ");
    for(i = 0; i < 3; i++){

        if(i < 2)
            printf("%s, ", suprimentos[nave.suprimentos[i]]);
        else
            printf("%s", suprimentos[nave.suprimentos[i]]);

    }
    printf(".\n\n");

}

void limpa_tela(){

    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif // WIN32

}
