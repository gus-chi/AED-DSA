#include<stdio.h>
#include<stdlib.h>
#ifndef VERTEX_H
#define VERTEX_H

typedef struct Vertex Vertex;
struct Vertex{
        int value;
        int color; // 0 branco 1 cinza 2 preto
        struct Vertex *next;
};

#endif

typedef struct Queue Queue;
struct Queue{
    int size;
    struct Vertex* head;
};

Queue* InstantiateQueue();
void InsertOnQueue(Queue**, Vertex);
void RemoveOnQueue(Queue*);