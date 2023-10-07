#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#define MAX 345

typedef struct{

    int qtd;
    int dados[6];

} LISTA;

LISTA *Cria_Lista();

void Libera_Lista(LISTA *li);

int ordena_numeros(int x[]);

#endif // HASH_H_INCLUDED
