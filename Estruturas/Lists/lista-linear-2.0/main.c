#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void Menu(void);
void LidarMenu(int, struct List*);

int main(void){
  int opt;
  struct List lista;
  InitList(&lista);
  for(;;){
  Menu();
  scanf("%d", &opt);
  system("clear");
  LidarMenu(opt, &lista);
  }
  return 0;
}

void Menu(void){
  printf("Menu\n");
  printf("****\n");
  printf("(1) Printar Lista\n");
  printf("(2) Add com\n");
  printf("(3) Add fim\n");
  printf("(4) Rem com\n");
  printf("(5) Rem fim\n");
  printf("(6) Add Esp\n");
  printf("(7) Rem Esp\n");
}

void LidarMenu(int opt, struct List* list){
  struct Item novo_p;
      int pos;
  switch(opt){
    case 1:
      PrintList(*list);
      break;
    case 2:
      CreateP(&novo_p);
      AddCom(list, novo_p);
      break;
    case 3:
      CreateP(&novo_p);
      AddFim(list, novo_p);
      break;
    case 4:
      RemCom(list);
      break;
    case 5:
      RemFim(list);
      break;
    case 6:
      CreateP(&novo_p);
      printf("Digite a posição a adicionar o paciente: ");
      scanf("%d", &pos);
      AddEsp(list, novo_p, pos);
      break;
    case 7:
      printf("Digite a posição a remover o paciente: ");
      scanf("%d", &pos);
      RemEsp(list, pos);
      break;
    default:
      break;
  }
}
