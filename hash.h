#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#define MAX 346

typedef struct{

    int qtd;
    int dados[6][3];

} LISTA;

LISTA *Cria_Lista();

void Libera_Lista(LISTA *li);

int ordena_numeros(const int x[]);

int verifica_iguais(const int x[],const int y[]);

#endif // HASH_H_INCLUDED
