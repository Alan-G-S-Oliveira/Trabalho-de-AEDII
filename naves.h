#ifndef NAVES_H_INCLUDED
#define NAVES_H_INCLUDED

extern const char suprimentos[][50];

struct passageiro{

    int id;
    int idade;
    char nome[50];
    char planeta[50];

};

struct nave{

    char nome[50];
    char tipo[50];
    int suprimentos[3];
    struct passageiro alien[3];
    int prioridade;

};

typedef struct nave Nave;
typedef struct passageiro Passageiro;

void corrige_string(char *str);

void exibe_naves(Nave nave);

void limpa_tela();

#endif // NAVES_H_INCLUDED
