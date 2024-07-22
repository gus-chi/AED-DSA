#include "avl_tree.h"


int FindHeight(AVL_NODE* tree){
    int h_left, h_right, height;
    if(tree == NULL)
        return 0;
    h_left = tree->left == NULL ? 0 : FindHeight(tree->left)+1;
    h_right = tree->right == NULL ? 0 : FindHeight(tree->right)+1;
    height = h_left >= h_right ? h_left : h_right;
    return height;
} // Encontrar altura da árvore

AVL_NODE *InstantiateAVLNode(int value){
    AVL_NODE *new_node = malloc(sizeof *new_node);
    new_node->value = value;
    new_node->left = new_node->right = NULL;
    new_node->bf = 0;
    return new_node;
}

int CalculateBF(AVL_NODE* father){
     int h_left = father->left != NULL ? FindHeight(father->left) + 1 : FindHeight(father->left);
     int h_right = father->right != NULL ? FindHeight(father->right)+1 : FindHeight(father->right);
     return h_left - h_right;
}

void InsertABBNode(AVL_NODE* father, AVL_NODE *new_node){
    if(father->value > new_node->value)
        if(!father->left)
            father->left = new_node;
        else
            InsertABBNode(father->left, new_node);
    else
        if(!father->right)
            father->right = new_node;
        else
            InsertABBNode(father->right, new_node);
    father->bf = CalculateBF(father);
}

void InsertAVLNode(AVL_NODE** pointer_father, AVL_NODE *new_node){
    AVL_NODE* father = *pointer_father;
    InsertABBNode(father, new_node);
    // Colocar Essa parte de baixo numa função porque ta muito confuso AAAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHH
    int rotation_type;
    if(father->bf > 1)
        if(father->left != NULL && father->left->bf > 0)
            rotation_type = 1; // LL
        else
            rotation_type = 2; //LR
    else if (father->bf < -1)
        if(father->left != NULL && father->left->bf < 0)
            rotation_type = 3; // RR
        else
            rotation_type = 4; // RL
    if(father->bf > 1 || father->bf < -1)
        ApplyRotation(pointer_father, rotation_type);

    // AVL_NODE* father = *pointer_father;
    // if(father->value > new_node->value)
    //     if(!father->left)
    //         father->left = new_node;
    //     else
    //         InsertAVLNode(&(father->left), new_node);
    // else
    //     if(!father->right)
    //         father->right = new_node;
    //     else
    //         InsertAVLNode(&(father->right), new_node);
    // father->bf = CalculateBF(father);
    // // Colocar Essa parte de baixo numa função porque ta muito confuso AAAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHH

    // int rotation_type;
    // if(father->bf > 1)
    //     if(father->left != NULL && father->left->bf > 0)
    //         rotation_type = 1; // LL
    //     else
    //         rotation_type = 2; //LR
    // else if (father->bf < -1)
    //     if(father->left != NULL && father->left->bf < 0)
    //         rotation_type = 3; // RR
    //     else
    //         rotation_type = 4; // RL
    // if(father->bf > 1 || father->bf < -1)
    //     ApplyRotation(pointer_father, rotation_type);
}



void ApplyRotation(AVL_NODE** unbalanced_node,int rotation_type){
    switch(rotation_type){
        case 1:
            *unbalanced_node = LL_Rotation(*unbalanced_node);
            break;
        case 2:
            *unbalanced_node = LR_Rotation(*unbalanced_node);
            break;
        case 3:
            *unbalanced_node = RR_Rotation(*unbalanced_node);
            break;
        case 4:
            *unbalanced_node = RL_Rotation(*unbalanced_node);
            break;
    }
}

AVL_NODE* LL_Rotation(AVL_NODE* unbalanced_node){
    AVL_NODE* aux = malloc(sizeof *aux);
    aux = unbalanced_node->left;
    unbalanced_node->left = aux->right;
    aux->right = unbalanced_node;
    return aux; 
}

AVL_NODE* LR_Rotation(AVL_NODE* unbalanced_node){
    AVL_NODE* aux;
    unbalanced_node->left = RR_Rotation(unbalanced_node->left);
    aux = LL_Rotation(unbalanced_node);
    return aux;
}

AVL_NODE* RR_Rotation(AVL_NODE* unbalanced_node){
    AVL_NODE* aux = malloc(sizeof *aux);
    aux = unbalanced_node->right;
    unbalanced_node->right = aux->left;
    aux->left = unbalanced_node;
    return aux;
}

AVL_NODE* RL_Rotation(AVL_NODE* unbalanced_node){
     AVL_NODE* aux;
    unbalanced_node->right = LL_Rotation(unbalanced_node->right);
    aux = RR_Rotation(unbalanced_node);
    return aux;
}

AVL_NODE* SearchOnTree(AVL_NODE* root, int value){
    AVL_NODE *aux = NULL;
    if(root->value == value)
        aux= root;
    else if(root->value > value)
        aux = SearchOnTree(root->left, value);
    else if(root->value < value)
        aux = SearchOnTree(root->right, value);
    return aux;
}