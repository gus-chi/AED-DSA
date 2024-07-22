#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#ifndef GRAPH_H

#define GRAPH_H
typedef struct Graph Graph;

#ifndef VERTEX_H
#define VERTEX_H
typedef struct Vertex Vertex;
struct Vertex{
        int value;
        int color; // 0 branco 1 cinza 2 preto
        struct Vertex *next;
};
#endif
struct Graph{
    int qtt_v; // quantidade de vertices
    int qtt_e; // quantidade de arestas
    Vertex** adj_list; // grafo representado como uma lista de adjacência
};


Graph* InstantiateGraph(int, int);
Vertex** InstantiateAdjList(int);

void LinkVertex(Vertex**,int , int, int);
    // procura no indice x da Lista de adjacencia que realiza a "linkagem/criação da aresta" 
    //inserindo na respectiva lista encadeada
void InsertOnVertexList(Vertex**, Vertex);

int SearchIfIsGray(Vertex**, int, int);
void ColorVertexinAdjList(Vertex**, int, int);
void BFS(Graph, int);
void DFS(Graph, int, int);
#endif