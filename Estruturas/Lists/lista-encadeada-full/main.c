#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extern.h"
#include "list.h"

void Menu(void);
void HandleMenu(int, struct List*);
int main(int argc, char* argv[]){
  int opt;
  struct List plist;
  InitList(&plist);
  for(;;){
    Menu();
    scanf("%d", &opt);
    system("clear");
    HandleMenu(opt, &plist);

  }
  return 0;
}

void Menu(void){
  printf("\t************************\n");
  printf("\t\t--MENU--\n");
  printf("\t  Type an option below.\n");
  printf("\t************************\n");
  printf("(1) Print List\n");
  printf("(2) Push item on the beginning of the list\n");
  printf("(3) Push item on the end of the list \n");
  printf("(4) Pop item from the beginning of the list\n");
  printf("(5) Pop item from the end of the list\n");
  printf("(6) Pop item by the code\n");
  printf("(7) Pop by position\n");
  printf("(0) Exit Program\n");
}
void HandleMenu(int opt, struct List* list){
  struct Product new_prod;
  int cod;
  int pos;
  switch(opt){
    case 0:
      printf(WARNING_EXIT);
      exit(0);
      break;
    case 1:
      PrintList(*list);
      break;
    case 2:
      GetProd(&new_prod);
      PushFront(list, new_prod);
      break;
    case 3:
      GetProd(&new_prod);
      PushBack(list, new_prod);
      break;
    case 4:
      PopFront(list);
      break;
    case 5:
      PopBack(list);
      break;
    case 6:
      printf("Insert product's code: ");
      scanf("%d", &cod);
      PopEspecific(list, cod);
      break;
    case 7:
      printf("Insert position to be poped: ");
      scanf("%d", &pos);
      PopPosition(list, pos);
      break;
    default:
      printf(WARNING_TYPE);
      break;
  }
}


