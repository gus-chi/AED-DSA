#include "list.h"

Node* InstantiateNode(){
    Node* new_node = malloc(sizeof *new_node);
    new_node->prox = NULL;
    return new_node;
}
void InitNode(Node* node, char* name, float price){
    strcpy(node->name, name);
    node->price = price;
}
void PrintNode(Node node){
    printf("Name: %8s  Price: %.2f\n", node.name, node.price);
}
int EmptyList(List list){
    return list.size == 0 ? 1 : 0;
}
List* InstantiateList(void){
    List* new_list = malloc(sizeof *new_list);
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}
void InitList(List* list, Node* new_node){
    new_node->prox = list->head;
    list->head = new_node;
    list->size++;
}
void PushFront(List* list, Node* new_node){
    if(EmptyList(*list)){
        InitList(list, new_node);
        return;
    }
    Node* tracker = list->head;
    while(tracker->prox != NULL)
        tracker = tracker->prox;
    tracker->prox = new_node;
    list->size++;
}
void PushBack(List* list, Node* new_node){
        InitList(list, new_node);
}
void PushByIndex(List* list, Node* new_node, int index){
    if(index==0){
        PushBack(list, new_node);
        return;
    }
    Node* aux = TrackListbyIndex(*list, index-1);
    Node* aux2 = aux->prox;
    if(aux){
        new_node->prox = aux->prox;
        aux->prox = new_node;
        list->size++;
    }
}
Node* TrackListbyIndex(List lista, int index){
    if(index > lista.size){
        printf("Unreachable List index \n"); // Warning
        return NULL;
    }
    int cont = 0;
    Node* aux = lista.head;
    while(cont != index){
        aux = aux->prox;
        cont++;
    }
    return aux;
}
void PopFront(List* list){
    if(EmptyList(*list))
        return;
    Node* aux = list->head;
    Node *tracker, *tracker_next;
    tracker = list->head;
    if(tracker->prox != NULL){
        tracker_next = tracker->prox;
        while(tracker_next->prox != NULL){
            tracker = tracker_next;
            tracker_next = tracker_next->prox;
        }    
        tracker->prox = NULL;
        aux = tracker_next;
    }
    if(aux == list->head){
        list->head = NULL;
    }
    free(aux);
    list->size--;
}
void PopBack(List* list){
    if(EmptyList(*list))
        return;
    Node* aux = list->head;
    list->head = list->head->prox;
    free(aux);
    list->size--;   
}
void PopByIndex(List* list, int index){
    if(index==0){
        PopBack(list);
        return;
    }
    //if(index+1== list->size){
    //    PopFront(list);
    //    return;
    //}
    Node *aux, *aux_next;
    aux = TrackListbyIndex(*list, index-1);
    if(aux){
    aux_next = aux->prox;
    aux->prox = aux_next->prox;
    free(aux_next);
    list->size--;
    }
}

void PrintList(List list){
    Node* tracker = list.head;
    while(tracker != NULL){
        PrintNode(*tracker);
        tracker = tracker->prox;
    }
}
