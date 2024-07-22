#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main(void){
    BTree** p_tree = malloc(sizeof *p_tree);
    int order, value; // 1º Indica a ordem da arvore 2º Valores que serão Inseridos na árvore e o procurado 
    scanf("%d", &order);
    
    *p_tree = InstantiateTree(order);
    InitTree(*p_tree, order);
    while(scanf("%d", &value), value >= 0){
        // Inserir o valor na árvore, se estourar o tamanho splita/divide
        InsertOnTree(p_tree, value, order, p_tree);
    }
    scanf("%d", &value);
    printf("%d\n", (*p_tree)->size);
    // SearchonTree
    BTree* founded = SearchNode(*p_tree, value);
    if(founded){
        printf("%d\n", founded->size);
        int i;
        for(i=0; i<founded->size; i++)
            printf("%d ", founded->values[i]);
    }
    else{
        printf("Valor nao encontrado");
    }
    


    return 0;
}
