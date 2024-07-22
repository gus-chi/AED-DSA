#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "extern.h"

void Menu(void);
void HandleMenu(int, struct Queue*);

int main(int argc, char argv[]){
  int opt;
  struct Queue queue;
  InitQueue(&queue);
  for(;;){
    Menu();
    scanf("%d", &opt);
    system("clear");
    HandleMenu(opt, &queue);
  }
  return 0;
}

void Menu(void){
  printf("Lista de Atendimento Hospitalar\n");
  printf("*******************************\n");
  printf("(1) Print Queue\n");
  printf("(2) Push patient on Queue\n");
  printf("(3) Pop patient of Queue\n");
  printf("(4) Destroy Queue\n");
  printf("(0) Exit\n");
}
void HandleMenu(int opt, struct Queue* queue){
  switch(opt){
    case 1:
        PrintQueue((*queue));
        break;
    case 2:
        struct Patient new_pat;
        CreatePatient(&new_pat);
        PushBack(queue, new_pat);
        break;
    case 3:
        break;
    case 4:
        DestroyQueue(queue);
        break;
    case 0:
        printf(WARNING_EXIT);
        exit(0);
        break;
    default:
        printf(WARNING_OPTION);
        break;
  }
}
