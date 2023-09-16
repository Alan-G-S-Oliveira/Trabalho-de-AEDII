#ifndef NAVES_H_INCLUDED
#define NAVES_H_INCLUDED

struct passageiro{

    int id;
    int idade;
    char nome[50];
    char planeta[50];

};

struct nave{

    char nome[50];
    char tipo[50];
    char suprimentos[3][50];
    struct passageiro alien[3];
    int prioridade;

};

typedef struct nave Nave;
typedef struct passageiro Passageiro;

void corrige_string(char *str);

void exibe_itens();

#endif // NAVES_H_INCLUDED
