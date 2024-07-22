#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_MAX_SIZE 5

typedef struct Item Item;
typedef struct List List;

struct Item{
    char name[50];
    float price;
    int code;
};

struct List{
    Item itens_of_list[LIST_MAX_SIZE];
    int size;
};


void InitItem(Item*, char*, float);

int EmptyList(List*);
int FullList(List*);
List* InstantiateList(void);
void AddItemOnBegin(List*, Item);
void AddItemOnEnd(List*, Item);
void RemoveItemOfBegin(List*);
void RemoveItemOfEnd(List*);
void PrintList(List);
float CalculatePurchase(List);