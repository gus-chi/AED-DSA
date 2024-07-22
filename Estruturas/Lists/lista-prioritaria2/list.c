#include "list.h"

void InitQueue(struct Queue* queue){
  (*queue).last = NULL;
  (*queue).size = 0;
}
int EmptyQueue(struct Queue queue){
  return queue.last == NULL ? 1 : 0;
}
void CreatePatient(struct Patient* new_patient){
  printf("Insert Patient's Name: ");
  scanf(" %[^\n]", &(*new_patient).name);
  printf("Insert Patient's Age: ");
  scanf("%d", &(*new_patient).age);
  (*new_patient).preferential = (*new_patient).age >= 60 ? 1 : 0;
}

void PrintPatient(struct Patient pat){
  printf("Name: %-8s | Age: %d | Pref: %s \n", pat.name, pat.age, pat.preferential== 1 ? "Preferential": "Normal");
}

void PrintQueue(struct Queue queue){
  if(EmptyQueue(queue)){
    printf(WARNING_EMPTY);
    return;
  }
  struct Node* tracker;
  tracker = queue.last;
  while(tracker){
    PrintPatient(tracker->pat); 
    tracker = tracker->next;
  }
}

void DestroyQueue(struct Queue* q){
  if(EmptyQueue(*q)){
    printf(WARNING_EMPTY);
    return;
  }
  struct Node* aux,*aux2;
  aux = (*q).last;
  aux2 = (*aux).next;
  while(aux2 != NULL){
    (*q).last = aux2;
    free(aux);
    aux = aux2;
    aux2 = (*aux2).next;
  }
  (*q).last = NULL;
  free(aux);
  (*q).size = 0;
}
void PushBack(struct Queue* queue, struct Patient new_pat){
  struct Node* new;
  new = (struct Node*) malloc(sizeof(struct Node));
  if(new){
  (*new).next = (*queue).last;
  (*queue).last = new;
  (*queue).size++;
  (*new).pat = new_pat;
  }
}
