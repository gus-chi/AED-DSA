#include <stdio.h>
#include <stdlib.h>
#include "rb-tree.h"
#include "avl_tree.h"

int main(void){
    RB_Node* Balanced_Tree = NULL;
    AVL_NODE* AVL_TREE = NULL;
    int value;
    while(scanf("%d", &value), value > 0){
        RB_Node *new_node = InstantiateNode(value);
        AVL_NODE *novo_no = InstantiateAVLNode(value);
        Balanced_Tree == NULL ? Balanced_Tree = new_node, Recolor(Balanced_Tree) : InsertOnRBTree(Balanced_Tree, new_node, &Balanced_Tree);
        AVL_TREE == NULL ? AVL_TREE = novo_no : InsertAVLNode(&AVL_TREE, novo_no);
    }

    printf("%d, ", FindHeightAVL(AVL_TREE));
    if(AVL_TREE->left)
        printf("%d, ", FindHeightAVL(AVL_TREE->left)+1);
    if(AVL_TREE->right)
        printf("%d\n", FindHeightAVL(AVL_TREE->right)+1);

    printf("%d, ", FindHeight(Balanced_Tree));
        if(Balanced_Tree->left)
            printf("%d, ", FindHeight(Balanced_Tree->left)+1);
        if(Balanced_Tree->right)
            printf("%d\n", FindHeight(Balanced_Tree->right)+1);
    
    // Sujeito a mudança:
        // printf("%d, ", FindHeight(Balanced_Tree));
        // if(Balanced_Tree->left)
            // printf("%d, ", FindHeight(Balanced_Tree->left)+1);
        // if(Balanced_Tree->right)
        // printf("%d", FindHeight(Balanced_Tree->right)+1);
return 0;
}