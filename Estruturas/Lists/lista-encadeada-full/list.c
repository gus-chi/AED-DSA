#include "list.h"

void InitList(struct List* list){
  (*list).first = NULL;
  (*list).size = 0;
  (*list).code = 0;
}
int EmptyList(struct List list){
  return list.first == NULL ? 1 : 0;
}
void GetProd(struct Product* prod){
  printf("Insert product's name: ");
  scanf(" %[^\n]", &(*prod).name);
  printf("Insert product's price: ");
  scanf("%f", &(*prod).price);
}
void PrintProd(struct Product prod){
  printf("Name: %-8s | Price: R$%2.2f | Code: %04d\n", prod.name, prod.price, prod.code);
}

void PrintList(struct List list){
  if(EmptyList(list)){
    printf(WARNING_EMPTY);
    return;
  }
  struct Node* tracker;
  tracker = list.first;
  printf("\t\tListing...\n");
  while(tracker){
    PrintProd((*tracker).prod);
    tracker = (*tracker).next;
  }
}

void PushFront(struct List* list, struct Product new_prod){
  struct Node* new;
  new = (struct Node*) malloc(sizeof(struct Node));
  if(EmptyList(*list)){
    (*new).next = NULL;
    (*list).first = new;
  }
  else{
    (*new).next = (*list).first;
    (*list).first = new;
  }
  new_prod.code = (*list).code;
  (*new).prod = new_prod;
  (*list).code++;
  (*list).size++;
}
void PushBack(struct List* list, struct Product new_prod){
  struct Node* new,* tracker;
  new = (struct Node*) malloc(sizeof(struct Node));
  if(EmptyList(*list)){
    (*new).next = NULL;
    (*list).first = new;
  }
  else{
    tracker = (*list).first;
    while((*tracker).next){
      tracker = (*tracker).next;
    }
    (*tracker).next = new;
  }
  new_prod.code = (*list).code;
  (*new).prod = new_prod;

  (*list).code++;
  (*list).size++;
}
void PopFront(struct List* list){
  if(EmptyList(*list)){
    printf(WARNING_EMPTY);
    printf("Aborting...\n");
    return;
  }
  struct Node* aux;
  aux = (*list).first;
  (*list).first = (*list).first->next;
  free(aux);
  (*list).size--;
}
void PopBack(struct List* list){
  if(EmptyList(*list)){
    printf(WARNING_EMPTY);
    return;
  }
  struct Node* tracker;
  tracker = (*list).first;
  if((*tracker).next == NULL){
    (*list).first = (*list).first->next;
    free(tracker);
  }
  else{
    struct Node* aux;
    while((*tracker).next){
      (*tracker).next->prev = tracker;
      tracker = (*tracker).next;
    }
    tracker = (*list).first;
    while((*tracker).next){
      tracker = (*tracker).next;
    }
    aux = tracker;
    (*tracker).prev->next = NULL;
    free(aux);
  }
  (*list).size--;
}
void PopEspecific(struct List* list, int cod){
  if(EmptyList(*list)){
    printf(WARNING_EMPTY);
    return;
  }
  struct Node* tracker,* aux;
  tracker = (*list).first;
  if((*tracker).prod.code == cod){
    aux = (*list).first;
    (*list).first = (*list).first->next;
    free(aux);
  }
  else{
    while((*tracker).prod.code != cod && (*tracker).next != NULL){
        (*tracker).next->prev = tracker;
         tracker = (*tracker).next;
     }
    if((*tracker).prod.code == cod){
      (*tracker).prev->next = (*tracker).next;
      free(tracker);
    }
    else{
        printf(WARNING_NOT_FOUND);
        return;
    }
  }
  (*list).size--;
}
void PopPosition(struct List* list, int pos){
  if(EmptyList(*list)){
    printf(WARNING_EMPTY);
    return;
  }
  if(pos < 0 || pos >= (*list).size){
    printf(WARNING_OUT_OF_RANGE);
  }
  int cont=0;
  struct Node* tracker,* aux;
  tracker = (*list).first;
  if(cont == pos){
    aux =  (*list).first;
    (*list).first = aux->next;
    free(aux);
  }
  else{
    while(cont != pos && (*tracker).next != NULL){
      (*tracker).next->prev = tracker;
      tracker = (*tracker).next;
      cont++;
    }
      aux = tracker;
      (*tracker).prev->next = (*tracker).next;
      free(tracker);
  }

  (*list).size--;
}
