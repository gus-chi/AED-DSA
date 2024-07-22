#include "rb-tree.h"

// Tree Functions

RB_Node *InstantiateNode(int value){
    RB_Node * new_node = malloc(sizeof *new_node);
    new_node->value = value;
    new_node->color = 'r';
    new_node->left = new_node->right = NULL;
    return new_node;
}

RB_Node *InsertOnTree(RB_Node* tree, RB_Node* new_node, RB_Node**root){ // na primeira chamada node_to_fix = NULL e ao inserir o no new node, node_to_fix = new_node;
    RB_Node *node_to_fix = NULL;
    if (tree->value > new_node->value)
        if (tree->left == NULL){
            tree->left = new_node;
            return new_node;
        }
        else{
            node_to_fix = InsertOnTree(tree->left, new_node, root);
        }
    else
        if (tree->right == NULL){
            tree->right = new_node;
            return new_node;
            }
        else{
            node_to_fix = InsertOnTree(tree->right, new_node, root);
        }
        return node_to_fix;
}
RB_Node *FixBalance(RB_Node *node_to_fix, RB_Node **root){
    RB_Node* grandfather, *father, *uncle;
    grandfather = father = uncle = NULL;
    RB_Node** aux = malloc(sizeof *aux);
    *aux = NULL;
    father = SearchFather(aux, *root, node_to_fix);
    if(father){
        *aux = NULL;
        grandfather = SearchFather(aux, *root, father);
    }
    if(grandfather){
            uncle = grandfather->left != father ? grandfather->left : grandfather->right;
            // Caso 1 tio vermelho  
            if(uncle && uncle->color == 'r')
                Recolor(grandfather), Recolor(father), Recolor(uncle);
            
            // Caso 2 e 3 tio preto
            else if((!uncle || uncle->color == 'b') && father->color == 'r'){
                RB_Node **p_grandfather = SearchPointer(root, grandfather);
                RB_Node **p_father = SearchPointer(root, father);
                // 4 Casos   
                if(grandfather->left == father && father->left && father->left->color == 'r'){ // pode estar errado father->left
                     *p_grandfather = LL_Rotation(grandfather);
                 }
                else if(grandfather->right == father && father->right && father->right->color == 'r'){
                    *p_grandfather = RR_Rotation(grandfather);
                }
                else if(grandfather->right == father && father->left && father->left->color == 'r'){
                    *p_father = LL_Rotation(father);
                    father = *p_father;
                    *p_grandfather = RR_Rotation(grandfather);
                }
                else if(grandfather->left == father && father->right && father->right->color == 'r'){
                    *p_father = RR_Rotation(father);
                    father = *p_father;
                    *p_grandfather = LL_Rotation(grandfather); 
                }
                Recolor(grandfather);
                Recolor(father);
                if(grandfather == *root)
                    *root = *p_grandfather;
                    //*p_tree= root;
            }
            FixBalance(grandfather, root);
            
        }    

    if((*root)->color == 'r') // Arrumar caso 2
            Recolor(*root);
}

RB_Node *InsertOnRBTree(RB_Node* tree, RB_Node* new_node, RB_Node **root){
    RB_Node* node_to_fix = InsertOnTree(tree, new_node, root);
    FixBalance(node_to_fix, root);
}

// void InsertOnTree(RB_Node** p_tree, RB_Node** p_grandfather, RB_Node** p_father, RB_Node* new_node, RB_Node **root){
//     RB_Node* grandfather = NULL, *father = NULL, *uncle= NULL;
//     if(p_grandfather)
//         grandfather = *p_grandfather;
//     if(p_father)
//         father = *p_father;
//     RB_Node* tree = *p_tree;
//     RB_Node** p_tree_left = &(tree->left);
//     RB_Node** p_tree_right = &(tree->right);
//     if (tree->value > new_node->value)
//         if (tree->left == NULL)
//             tree->left = new_node;
//         else{
//              InsertOnTree(p_tree_left, p_father, p_tree, new_node, root);
//             RB_Node** aux = malloc(sizeof *aux);
//             *aux = NULL;
//              father = SearchFather(aux, *root, tree);
//              grandfather = SearchFather(aux, *root, father);

//         }
//     else
//         if (tree->right == NULL)
//             tree->right = new_node;
//         else{
//             InsertOnTree(p_tree_right, p_father, p_tree, new_node, root);
//         }       
//     // Bloco abaixo sujeito a mudanças    
//     p_grandfather = p_father;
//     p_father = p_tree;
//     if(p_grandfather)
//         grandfather = *p_grandfather;
//     if(p_father)
//         father = *p_father = *p_tree;
//     if(grandfather){
//         uncle = grandfather->left != father ? grandfather->left : grandfather->right;
        
//         // Caso 1 tio vermelho  
//         if(uncle && uncle->color == 'r')
//             Recolor(grandfather), Recolor(father), Recolor(uncle);
        
//         // Caso 2 e 3 tio preto
//         else if((!uncle || uncle->color == 'b') && father->color == 'r'){
//             // 4 Casos   
//             if(grandfather->left == father && father->left && father->left->color == 'r'){ // pode estar errado father->left
//                 *p_grandfather = LL_Rotation(grandfather);
//             }
//             else if(grandfather->right == father && father->right && father->right->color == 'r'){
//                 *p_grandfather = RR_Rotation(grandfather);
//             }
//             else if(grandfather->right == father && father->left && father->left->color == 'r'){
//                     *p_father = LL_Rotation(father);
//                     father = *p_father;
//                     *p_grandfather = RR_Rotation(grandfather);
//             }
//             else if(grandfather->left == father && father->right && father->right->color == 'r'){
//                 *p_father = RR_Rotation(father);
//                 father = *p_father;
//                 *p_grandfather = LL_Rotation(grandfather); 
//                 }
            
//             Recolor(grandfather);
//             Recolor(father); 
//             if(grandfather == *root)
//                 *root = *p_grandfather;
//                 //*p_tree= root;
//         }
        
//     }    

//    if((*root)->color == 'r') // Arrumar caso 2
//         Recolor(*root);
// }

RB_Node *SearchOnTree(RB_Node* tree, int value){
    RB_Node *node_searched = NULL;
    if(tree != NULL){
        if(tree->value == value)
            return tree;
        else if(tree->value > value)
            node_searched = SearchOnTree(tree->left, value);
        else if(tree->value < value)
                node_searched = SearchOnTree(tree->right, value);
        }
    return node_searched;
}
RB_Node *SearchFather(RB_Node** aux, RB_Node* root, RB_Node* target){
    if(root!= NULL){
        if(root == target)
            return *aux;
        else if(root->value > target->value)
            *aux = SearchFather(&root, root->left, target);
        else if(root->value < target->value)
            *aux = SearchFather(&root, root->right, target);

    }
    return *aux;
}
RB_Node **SearchPointer(RB_Node**tree, RB_Node*target){
    RB_Node** pointer = NULL;
    RB_Node** aux;
    if(*tree == target)
        return tree;
    else if((*tree)->value > target->value){
        aux = &((*tree)->left);
        pointer = SearchPointer(aux, target);
        }
    else if((*tree)->value < target->value){
        aux = &((*tree)->right);
        pointer = SearchPointer(aux, target);
    }
    return pointer;
}

int FindHeight(RB_Node *tree){
    int height, h_left, h_right;
    h_left = tree->left == NULL ? 0 : FindHeight(tree->left) + 1;
    h_right = tree->right == NULL ? 0 : FindHeight(tree->right) + 1;
    height = h_left >= h_right ? h_left : h_right;
    return height;
}


// RB Functions

void Recolor(RB_Node* node){
    node->color = node->color == 'r' ? 'b' : 'r';
}

int FindBlackHeight(RB_Node* tree){
    int height, h_left, h_right;
    h_left = tree->left == NULL ? 1 : tree->left->color == 'b' ? FindBlackHeight(tree->left) + 1 : FindBlackHeight (tree->left);
    h_right = tree->right == NULL ? 1 : tree->right->color == 'b' ? FindBlackHeight(tree->right) + 1 : FindBlackHeight (tree->right);
    height = h_left >= h_right ? h_left : h_right;
    return height;
}


//Rotation Functions
RB_Node* LL_Rotation(RB_Node* unbalanced_node){ // Linha reta esquerda
    RB_Node* aux = malloc(sizeof *aux);
    aux = unbalanced_node->left;
    unbalanced_node->left = aux->right;
    aux->right = unbalanced_node;
    return aux; 
}

RB_Node* RR_Rotation(RB_Node* unbalanced_node){ // Linha reta direita
    RB_Node* aux = malloc(sizeof *aux);
    aux = unbalanced_node->right;
    unbalanced_node->right = aux->left;
    aux->left = unbalanced_node;
    return aux;
}