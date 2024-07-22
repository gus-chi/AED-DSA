#include "list.h"

void InitItem(Item* new_item,char* name, float price){
    strcpy(new_item->name, name);
    new_item->price = price;
}
int EmptyList(List* list){
    if(list == NULL || (list != NULL && list->size== 0))
        return 1;
    else return 0;
}
int FullList(List* list){
   return list->size == LIST_MAX_SIZE ? 1 : 0;
}
List* InstantiateList(void){
    List* new_list = malloc(sizeof new_list);
    new_list->size = 0;
    return new_list;
}
void AddItemOnBegin(List* list, Item new_item){
    if(FullList(list))
        return;
    new_item.code = list->size;
    int cont;
    for(cont = list->size; cont > 0; cont--){
        list->itens_of_list[cont+1] = list->itens_of_list[cont];
    }
    list->itens_of_list[0]= new_item;
    list->size++;
}
void AddItemOnEnd(List* list, Item new_item){
    if(FullList(list))
        return;
    new_item.code = list->size;
    list->itens_of_list[new_item.code] = new_item;
    list->size++;
}
void RemoveItemOfBegin(List* list){
    if(EmptyList(list)){
        printf("Empty List\n");
        return;
    }
    int cont;
    for(cont = 0;cont < list->size; cont++){
        list->itens_of_list[cont] = list->itens_of_list[cont+1];
    }
    list->size--;
}
void RemoveItemOfEnd(List* list){
    if(EmptyList(list)){
        printf("Empty List\n");
        return;
    }
    list->size--;
}
void PrintList(List list){
    if(EmptyList(&list)){
        printf("Lista Vazia\n");
        return;
    }
    int cont = 0;
    printf("--PRODUCTS--\n");
    for(cont; cont< list.size; cont++){
        printf("\t Name: %8s Price: %.2f Code: %.4d\n", list.itens_of_list[cont].name, list.itens_of_list[cont].price, list.itens_of_list[cont].code);
    }

}
float CalculatePurchase(List list){
    int cont = 0;
    float total_price = 0;
    for(;cont < list.size; cont++){
        total_price += list.itens_of_list[cont].price;
    }
    return total_price;
}