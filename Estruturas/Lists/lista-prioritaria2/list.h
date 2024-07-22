#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extern.h"
struct Patient{
  char name[SIZE_STR];
  int age;
  int preferential;
};

struct Node{
  struct Patient pat;
  struct Node *next;
  struct Node *prev;
};

struct Queue{
  struct Node* last;
  int size;
};

// Implementation Functions

void InitQueue(struct Queue*);
int EmptyList(struct Queue*);
void CreatePatient(struct Patient*);
void PrintPatient(struct Patient);

void PrintQueue(struct Queue);
void DestroyQueue(struct Queue*);
void PushBack(struct Queue*, struct Patient);
void PopBack(struct Queue*);
