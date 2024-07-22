#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extern.h"
struct Item{
  char nome[STR_SIZE];
  int idade;
};
struct List{
  struct Item paciente[LIST_SIZE];
  int prim;
  int ultimo;
};

void InitList(struct List*);
int EmptyList(struct List);
int FullList(struct List);
void CreateP(struct Item*);
void PrintP(struct Item);

void PrintList(struct List);
void AddCom(struct List*, struct Item);
void AddFim(struct List*, struct Item);
void AddEsp(struct List*, struct Item, int);
void RemCom(struct List*);
void RemFim(struct List*);
void RemEsp(struct List*, int);
