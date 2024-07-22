#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(void){
    Graph* graph = NULL;
    Graph* graph2 = NULL;
    int initial_vertex_value, qtt_v, qtt_e;
    int index_vertex_j, index_vertex_k;
    int i; // Variáveis auxiliares
    scanf("%d", &initial_vertex_value), scanf("%d", &qtt_v), scanf("%d", &qtt_e);
    graph = InstantiateGraph(qtt_v, qtt_e);
    graph2 = InstantiateGraph(qtt_v, qtt_e);
    for(i=0; i<qtt_e; i++){
        scanf("%d", &index_vertex_j), scanf("%d", &index_vertex_k);
        LinkVertex(graph->adj_list,index_vertex_j, index_vertex_k, graph->qtt_v);
        LinkVertex(graph2->adj_list,index_vertex_j, index_vertex_k, graph->qtt_v);
    }
    BFS(*graph, initial_vertex_value); 
    printf("\n");
    DFS(*graph2, initial_vertex_value, initial_vertex_value);
    return 0;
}
