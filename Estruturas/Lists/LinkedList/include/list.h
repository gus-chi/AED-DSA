#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extern.h"

typedef struct Node Node;
typedef struct List List;

struct Node{
    char name[STR_SIZE];
    float price;
    int code;
    struct Node* prox; 
};

struct List{
    struct Node *head;
    int size;
};
Node* InstantiateNode(void);
void InitNode(Node*, char*, float);
void PrintNode(Node);

int EmptyList(List);
List* InstantiateList(void);
void InitList(List*, Node*);// Adiciona quando lista esta Vazia
void PushFront(List*, Node*);
void PushBack(List*, Node*);
void PushByIndex(List*, Node*, int);
Node* TrackListbyIndex(List, int);
void PopFront(List*);
void PopBack(List*);
void PopByIndex(List*, int);
void PrintList(List);