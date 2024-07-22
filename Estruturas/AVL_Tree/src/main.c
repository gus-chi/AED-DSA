#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

int main(void){
    AVL_NODE* tree = NULL;
    int value;

    // etapa inserção na árvore

    scanf("%d", &value);
    while(value >=0){
        tree == NULL ? tree = InstantiateAVLNode(value) : InsertAVLNode(&tree, InstantiateAVLNode(value));
        scanf("%d", &value);
    }
    // etapa pesquisa na árvore
    scanf("%d", &value);
    while(value >=0){
        //SearchOnTree(value)
        scanf("%d", &value);
    }
    scanf("%d", &value);
    printf("%d \n", tree->value);
    return 0;
}
