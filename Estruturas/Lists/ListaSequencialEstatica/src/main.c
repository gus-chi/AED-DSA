#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"

void Menu(void);
void HandleMenu(int);
int main(void){
    int option;
    //List* market_list = InstantiateList(); 
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
    printf("(1) Add Element at Begin of List\n");
    printf("(2) Add Element at End of List\n");
    printf("(3) Remove Element at Begin of List\n");
    printf("(4) Remove Element at End of List\n");
    printf("(5) Print List\n");
    printf("(6) Calculate Itens Sum\n");
    printf("(0) Exit Program\n");
}
void HandleMenu(int option){
    static List * market_list = NULL;
    Item new_item;
    char item_name[50];
    float item_price;
    if(market_list == NULL)
       market_list = InstantiateList();
    switch(option){
        case 0:
            exit(1);
            break;
        case 1:
            if(FullList(market_list)){
                printf("Full List\n");
                break;
            }
            printf("Type the product's name: ");
            scanf(" %[^\n]", item_name);
            printf("Type the product's price: ");
            scanf("%f", &item_price);
            InitItem(&new_item, item_name, item_price);
            AddItemOnBegin(market_list, new_item);
            printf("Item Added\n");
            break;
        case 2:
            if(FullList(market_list)){
                printf("Full List\n");
                break;
            }
            printf("Type the product's name: ");
            scanf(" %[^\n]", item_name);
            printf("Type the product's price: ");
            scanf("%f", &item_price);
            InitItem(&new_item, item_name, item_price);
            AddItemOnEnd(market_list, new_item);
            printf("Item Added\n");
            break;
        case 3:
            RemoveItemOfBegin(market_list);
            break;
        case 4:
            RemoveItemOfEnd(market_list);
            break;
        case 5:
            PrintList(*market_list);
            break;
        case 6:
            printf("Total Price: %.2f\n", CalculatePurchase(*market_list));
            break;
        case 7:
            break;
        default:
            break;
    }
}