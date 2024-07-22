#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extern.h"

#ifndef LIST_H
#define LIST_H

struct Product{
  char name[SIZE_STR];
  float price;
  int code;
};
struct Node{
  struct Product prod;
  struct Node* next;
  struct Node* prev;
};
struct List{
  struct Node* first;
  int code;
  int size;
};

//Implementation Functions

void InitList(struct List*);
int EmptyList(struct List);
void GetProd(struct Product*);
void PrintProd(struct Product);

void PrintList(struct List);
void PushFront(struct List*, struct Product);
void PushBack(struct List*, struct Product);
void PopFront(struct List*);
void PopBack(struct List*);
void PopEspecific(struct List*, int);
void PopPosition(struct List*, int);

#endif
