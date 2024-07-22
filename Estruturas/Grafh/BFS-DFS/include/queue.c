#include "queue.h"
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