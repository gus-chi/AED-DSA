#include <stdio.h>
#include <stdlib.h>
#include "rb-tree.h"
int main(void){
    RB_Node* Balanced_Tree = NULL;
    int value;
    while(scanf("%d", &value), value > 0){
        RB_Node *new_node = InstantiateNode(value);
        Balanced_Tree == NULL ? Balanced_Tree = new_node, Recolor(Balanced_Tree) : InsertOnTree(&Balanced_Tree, NULL, NULL, new_node, &Balanced_Tree);
    }
    printf("%d, ", FindHeight(Balanced_Tree));
    if(Balanced_Tree->left)
        printf("%d, ", FindHeight(Balanced_Tree->left)+1);
    if(Balanced_Tree->right)
    printf("%d", FindHeight(Balanced_Tree->right)+1);
    return 0;
}