#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 100
#define TAM_NOME 50
struct Item{
	char nome[50];
	int chave;
	float preco;
};

struct Lista{
	struct Item itens[MAX_ITENS];
	int primeiro;
	int ultimo;
};

void IniciarLista(struct Lista*);
void PrintarLista(struct Lista*);
void InsFin(struct Lista*);
void RemFin(struct Lista*);
void RemIni(struct Lista*);
void AddNaPos(struct Lista*);
void RemDaPos(struct Lista*);
void RetiraEspecifico(struct Lista*);
