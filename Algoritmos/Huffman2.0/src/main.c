#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintMenu(void);
void HandleMenu(int);
int main(int argv, char argc[]){
    int option;
    for(;;){
        PrintMenu();
        scanf("%d", &option);
        system("clear");
        HandleMenu(option);
    }
    return 0;
}

void PrintMenu(void){
    printf("\t ******\t\n");
    printf("\t  Menu \t\n");
    printf("\t********\t\n");
    printf("(1) Para Criar Árvore de Huffman\n");
    printf("(2) Para Encodificar Árvore\n");
    printf("(3) Para Decodificar Árvore\n");
}
void HandleMenu(int option){
    //static Tree* huffman_tree = NULL;
    switch(option){
        case 0:
            exit(0);
            break;
        case 1:
            //if(huffman_tree == NULL){
            //  
            //else
            //  printf("Árvore já existe!!!");
            //}
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            printf("Valor não está no escopo.\n");
            break;
    }
}