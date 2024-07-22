#include "graph.h"

Graph* InstantiateGraph(int qtt_v, int qtt_e){
    Graph* new_graph = malloc(sizeof *new_graph);
    new_graph->qtt_v = qtt_v;
    new_graph->qtt_e = qtt_e;
    new_graph->adj_list = InstantiateAdjList(qtt_v);
    return new_graph;
}
Vertex** InstantiateAdjList(int qtt_v){
    Vertex** new_adj_list = malloc(qtt_v * sizeof *new_adj_list); // malloca n listas encadeadas(ponteiros) para a lista de adjacência 
    int i;
    for(i=0; i<qtt_v; i++)
        new_adj_list[i] = NULL;
    return new_adj_list;
}
void LinkVertex(Vertex** adj_list, int vertex_j, int vertex_k, int n){
    Vertex vertex;
    vertex.value = vertex_k;
    vertex.color = 0;
    vertex.next = NULL;
    Vertex ** tracker = &adj_list[vertex_j];
    InsertOnVertexList(tracker, vertex);
}

void InsertOnVertexList(Vertex** tracker, Vertex vertex){
    Vertex* new_vertex_to_list = malloc(sizeof *new_vertex_to_list);
    while(*tracker && (*tracker)->value < vertex.value){
        tracker = &(*tracker)->next;
    }
    if(*tracker)
        vertex.next = (*tracker);
    *new_vertex_to_list = vertex;
    *tracker = new_vertex_to_list;
}

int SearchIfIsGray(Vertex** adj, int target , int n){
    int i;
    for(i=0; i<n; i++){
        Vertex*aux = adj[i];
        while(aux){
            if(aux->value == target && aux->color==1)
                return 1;
        }
    }
    return 0;
}
void ColorVertexinAdjList(Vertex** adj, int target, int n){
    int i;
    for(i=0; i< n; i++){
        Vertex*aux = adj[i];
        while(aux){
            if(aux->value == target)
                aux->color = 1;
            aux = aux->next;
        }
    }
}
void BFS(Graph graph, int source){
    Queue* queue = InstantiateQueue();
    Vertex source_vertex;
    source_vertex.value = source;
    source_vertex.color = 0;
    source_vertex.next = NULL;
    InsertOnQueue(&queue, source_vertex);
    
    while(queue->head){
        Vertex** tracker = &queue->head;
        while(*tracker != NULL && (*tracker)->next != NULL){
            tracker = &(*tracker)->next;
        }
        printf("%d ", (*tracker)->value);
        Vertex* aux = graph.adj_list[(*tracker)->value];
        while(aux){
            if(aux->value == source){
                ColorVertexinAdjList(graph.adj_list, source, graph.qtt_v);
               // aux->color = 1; // Pintar todas as instancias do valor na lista
            }
            if(aux->color == 0){
                ColorVertexinAdjList(graph.adj_list, aux->value, graph.qtt_v);
                //aux->color = 1;// Pintar todas 
                InsertOnQueue(&queue, *aux);
            }
            aux = aux->next; 
        }
        RemoveOnQueue(queue);
        //printf("%d", (*tracker)->value);

    }

    //graph.adj_list[source]

}
void DFS(Graph graph, int source, int root){
    printf("%d ", source);
    Vertex* aux = graph.adj_list[source];
    while(aux){
        if(aux->value == root){
                ColorVertexinAdjList(graph.adj_list, source, graph.qtt_v);
                break;
               // aux->color = 1; // Pintar todas as instancias do valor na lista
            }
        if(aux->color== 0){
            ColorVertexinAdjList(graph.adj_list, aux->value, graph.qtt_v);
            DFS(graph, aux->value, root);
        }
        aux = aux->next;
    }
}