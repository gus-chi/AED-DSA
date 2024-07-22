#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "extern.h"
void Menu(void);
void HandleMenu(int);

int main(void){
    int option;
    for(;;){
        Menu();
        printf("Type your choosen:");
        scanf("%d", &option);
        system("clear");
        HandleMenu(option);
    }
    return 0;
}

void Menu(void){
    printf("\t--------\n");
    printf("\t |Menu|\n");
    printf("\t--------\n");
    printf("(1) Add Element in Front\n");
    printf("(2) Add Element in Back\n");
    printf("(3) Add Element in Position\n");
    printf("(4) Remove Element from Front\n");
    printf("(5) Remove Element from Back\n");
    printf("(6) Remove Element by Position\n");
    printf("(7) Print List\n");
    printf("(8) Calculate Itens Sum\n");
    printf("(0) Exit Program\n");
}
void HandleMenu(int option){
    static List * market_list = NULL;
    Node* new_node = NULL;
    char node_name[STR_SIZE];
    float node_price;
    int index;
    if(market_list == NULL)
       market_list = InstantiateList();
    switch(option){
        case 0:
            exit(1);
            break;
        case 1:
            new_node = InstantiateNode();
            printf("Type the product's name: ");
            scanf(" %[^\n]", node_name);
            printf("Type the product's price: ");
            scanf("%f", &node_price);
            InitNode(new_node, node_name, node_price);
            PushFront(market_list, new_node);
            printf("Item Added\n");
            break;
        case 2:
            new_node = InstantiateNode();
            printf("Type the product's name: ");
            scanf(" %[^\n]", node_name);
            printf("Type the product's price: ");
            scanf("%f", &node_price);
            InitNode(new_node, node_name, node_price);
            PushBack(market_list, new_node);
            printf("Item Added\n");
            break;
        case 3:
            new_node = InstantiateNode();
            printf("Type the product's name: ");
            scanf(" %[^\n]", node_name);
            printf("Type the product's price: ");
            scanf("%f", &node_price);
            InitNode(new_node, node_name, node_price);
            printf("Type Index: ");
            scanf("%d", &index);
            PushByIndex(market_list, new_node, index-1);
            printf("Item Added\n");
            break;

        case 4:
            PopFront(market_list);
            break;
        case 5:
            PopBack(market_list);
            break;
        case 6:
            printf("Type Index: ");
            scanf("%d", &index);
            PopByIndex(market_list, index-1);
            break;
        case 7:
            PrintList(*market_list);
            break;
      //  case 6:
       //     printf("Total Price: %.2f\n", CalculatePurchase(*market_list));
       //     break;
       // case 7:
       //     break;
       // default:
       //     break;
    }
}