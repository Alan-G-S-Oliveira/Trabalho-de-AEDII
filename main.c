#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "heap.h"

int main(){

    setlocale(LC_ALL, "portuguese");

    FILE *fi;
    fi = fopen("naves.csv", "r");

    if(fi != NULL)
        exit(1);

    fclose(fi);

    return 0;
}
