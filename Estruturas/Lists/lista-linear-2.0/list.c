#include "list.h"

void InitList(struct List* list){
  (*list).prim = (*list).ultimo = 0;
}
int EmptyList(struct List list){
  return list.prim == list.ultimo ? 1 : 0;
}
int FullList(struct List list){
  return list.ultimo == LIST_SIZE ? 1 : 0;
}
void CreateP(struct Item* novo_p){
  printf("Digite o nome: ");
  scanf(" %[^\n]", &novo_p->nome);
  printf("Digite a idade: ");
  scanf("%d", &novo_p->idade);
}
void PrintP(struct Item p){
  printf("Nome: %s | Idade: %d\n", p.nome, p.idade);
}

void PrintList(struct List list){
  if(EmptyList(list)){
    printf(WARNING_EMPTY);
    return;
  }
  int cont = list.prim;
  while(cont< list.ultimo){
    PrintP(list.paciente[cont]);
    cont++;
  }
}
void AddCom(struct List* list, struct Item novo_p){
  if(FullList(*list)){
    printf(WARNING_FULL);
    return;
  }
  int aux = (*list).ultimo;
  while(aux != list->prim){
    list->paciente[aux] = list->paciente[aux-1];
    aux--;
  }
  list->paciente[aux] = novo_p;
  list->ultimo++;
}
void AddFim(struct List *list, struct Item novo_p){
  if(FullList(*list)){
    printf(WARNING_FULL);
    return;
  }
  list->paciente[list->ultimo] = novo_p;
  list->ultimo++;
}
void RemCom(struct List* list){
  if(EmptyList(*list)){
    printf(WARNING_EMPTY);
    return;
  }
  list->prim++;
}
void RemFim(struct List* list){
  if(EmptyList(*list)){
    printf(WARNING_EMPTY);
    return;
  }
  list->ultimo--;
}
void AddEsp(struct List* list, struct Item novo_p, int pos){
  if(FullList(*list)){
    printf(WARNING_FULL);
    return;
  }
  if(pos >= list->prim && pos <= list->ultimo){
      int aux = list->ultimo;
      while(pos < aux){
        list->paciente[aux] = list->paciente[aux-1];
        aux--;
      }
    list->paciente[aux] = novo_p;
    list->ultimo++;
  }
  else{
    printf("Não é possível adicionar no índice escolhido\n");
  }
}
void RemEsp(struct List* list, int pos){
  if(EmptyList(*list)){
    printf(WARNING_EMPTY);
    printf("Impossivel Remover.Abortando...\n");
    return;
  }
  if(pos >= list->prim && pos <= list->ultimo){
    int aux = pos;
   while(aux+1 < list->ultimo){
     list->paciente[aux] = list->paciente[aux+1];
     aux++;
   } 
    list->ultimo--;
  }
  else
    printf("Não é possível remover do índice escolhido\n");
}
