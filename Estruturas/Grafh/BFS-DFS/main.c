#include <stdio.h>
#include <stdlib.h>

typedef struct Graph Graph;
typedef struct Vertex Vertex;

struct Vertex{
        int value;
        int color; // 0 branco 1 cinza 2 preto
        struct Vertex *next;
};
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


typedef struct Queue Queue;
struct Queue{
    int size;
    struct Vertex* head;
};

Queue* InstantiateQueue();
void InsertOnQueue(Queue**, Vertex);
void RemoveOnQueue(Queue*);

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

Queue* InstantiateQueue(){
    Queue* new_queue = malloc(sizeof *new_queue);
    new_queue->size = 0;
    new_queue->head = NULL;
    return new_queue;
}
void InsertOnQueue(Queue** tracker,Vertex new_vertex){
    Vertex* p_new_vertex = malloc(sizeof *p_new_vertex);
    new_vertex.next = (*tracker)->head;
    *p_new_vertex = new_vertex;
    (*tracker)->head = p_new_vertex;
    (*tracker)->size++;
}
void RemoveOnQueue(Queue* queue){
    Vertex** tracker;
    tracker = &queue->head;
    while(*tracker != NULL && (*tracker)->next != NULL){
        tracker = &(*tracker)->next;
    }
    // talvez free seja desnecessario
    Vertex *aux = *tracker;
    *tracker = NULL;
    free(aux);
    
    queue->size--;
}