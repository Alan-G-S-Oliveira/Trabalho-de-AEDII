#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#define MAX 346

struct elemento{

    int dados[3];
    struct elemento *prox;

};

typedef struct{

    struct elemento *inicio;
    int qtd;

} ListaEncadeada;

typedef struct{

    ListaEncadeada *dados[MAX];

} Hash;

Hash *cria_hash();

ListaEncadeada *cria_lista_encadeada();

void libera_hash(Hash *hs);

void libera_lista_encadeada(ListaEncadeada *li);

int ordena_numeros(const int x[]);

int adc_lista_encadeada(ListaEncadeada *li, int adc[]);

int remove_lista_encadeada(ListaEncadeada *li);

int adc_hash(Hash *hs, int adc[], int posicao);

int remove_hash(Hash *hs, int posicao);

int verifica_iguais(Hash *hs, int posicao, const int x[]);

#endif // HASH_H_INCLUDED
