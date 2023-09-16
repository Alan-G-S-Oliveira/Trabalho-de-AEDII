#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

struct lista{

    int qtd;
    int tamanho;
    struct nave *star;

};

typedef struct nave Nave;
typedef struct lista Lista;
typedef struct passageiro Passageiro;

Lista *cria_lista(int tamanho);

void apaga_lista(Lista *li);

int tamanho_lista(Lista *li);

int adc_lista(Lista *li, Nave adc);

int cria_heap(Lista *li);

int adc_heap(Lista *li, Nave adc);

int remove_heap(Lista *li);

int consulta_heap(Lista *li, Nave *checar);

int altera_prioridade(Lista *li, int i, int nova_prioridade);

void subir_heap(Lista *li, int i);

void descer_heap(Lista *li, int i);

void define_prioridade(Nave *pri, int x1, int x2);

#endif // HEAP_H_INCLUDED
