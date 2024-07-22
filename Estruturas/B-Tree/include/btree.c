#include "btree.h"

int IsLeaf(BTree* tree){
    int i;
    for(i=0; i <= tree->size; i++){
        if(tree->pointers[i] != NULL){ // É folha se todos os ponteiros forem nulos
            return 0;
        }
    }
    return 1;
}

int InsertOnArray(int* array, int qtt_ocuppied, int value){
    int i, index_to_insert;
    i = 0;
    while(i < qtt_ocuppied && array[i] < value){
        i++;
    }
    int j = qtt_ocuppied;
    for(;j>i; j--){
        array[j] = array[j-1];
    }
    array[i] = value;
    return i; // retorna o indice que o valor foi inserido no vetor;
}

int Fill(int*source,int* target, int start, int end){
    int i, j;
    for(i=start, j=0; i<end; i++, j++)
        target[j] = source[i];
    return j; // tamanho do array copiado
}
void Link(BTree** source, BTree** target, int start, int end){
    int i, j;
    for(i=start, j=0; i<end; i++, j++)
        target[j] = source[i];
}

BTree* Gather(BTree* father, BTree*left, BTree*right, int index){
    father->pointers[index] = left;
    int i;
    for(i= father->size; i>index; i--)
        father->pointers[i] = father->pointers[i-1];
    father->pointers[index+1] = right;
    return father;
}

BTree* Split(BTree** p_tree, BTree** root){ // Como tree->size == 2*order+1 para a split ser chamada, podemos isolar a order e passar como parametro
        // So inicializa as arvores e fazemos os 2 ponteiros da new_tree apontar tanto para left quanto para right
        BTree* tree = *p_tree;
        BTree* father = NULL;
        // Ao invés de lidar com valores fazer com índices
        if(tree == *root){
            father = InstantiateTree((tree->size-1)/2);
            InitTree(father, (tree->size-1)/2);
            *root = father;
        }
        else{
            father = SearchFather(*root, tree->values[0]);
        }
        // Inseri no father o valor do meio da arvore que será dividida e retorna o índice que inseriu
        int middle_index = tree->size/2;
        int inserted_index = InsertOnArray(father->values, father->size, tree->values[middle_index]);
       father->size++; 
        BTree* left = InstantiateTree((tree->size-1)/2);
        BTree* right = InstantiateTree((tree->size-1)/2);
        InitTree(left, (tree->size-1)/2), InitTree(right, (tree->size-1)/2);
        left->size = Fill(tree->values, left->values, 0, middle_index);
        right->size = Fill(tree->values, right->values, middle_index+1, tree->size);
        Link(tree->pointers, left->pointers, 0, middle_index+1);
        Link(tree->pointers, right->pointers, middle_index+1, tree->size+1);
        father = Gather(father, left, right, inserted_index);
        if(father->size >= 2*((tree->size-1)/2)+1){
            Split(&father, root); // No processo de split é necessario atualizar o tamanho das arvores que serão criadas left e right
        }
        *p_tree = father;
        free(tree);
        return father;
}
BTree* SearchNode(BTree* tracker, int target){
    BTree* node = NULL; 
    int i;
    for(i=0; i<tracker->size; i++){
        if(tracker->values[i] == target){
            return tracker;
        }
    }
    i=0;
    while(tracker->values[i]<target && i < tracker->size){
        i++;
    }
    BTree* pointer_to_search = tracker->pointers[i];
    if(pointer_to_search){
        node = SearchNode(pointer_to_search, target);
    }
    return node;

}
BTree* SearchFather(BTree* tracker, int target){
    BTree* father = NULL;
    BTree* pointer_to_search = NULL;
    int i=0;
    while( tracker->values[i]<target && i < tracker->size){
        i++;
    }
    pointer_to_search = tracker->pointers[i];
    for(i=0; i<pointer_to_search->size; i++){
        if(pointer_to_search->values[i] == target){
            father = tracker;
            return father;
            }
    }
    father = SearchFather(pointer_to_search, target);
    return father;
}

BTree* InstantiateTree(int order){
    BTree* new_tree = malloc(sizeof *new_tree);
    new_tree->values = malloc((2 * order + 1) *sizeof *new_tree->values);
    new_tree->pointers = malloc((2 * order + 2) *sizeof *new_tree->pointers);
}
void InitTree(BTree* new_tree, int order){
    int i;
    for(i=0; i< 2* order+2; i++)
        new_tree->pointers[i] = NULL;
    new_tree->size = 0;// Indica a quantidade de chaves que um nó contém
}

// Para saber se um nó é folha, os ponteiros de 0 ate size precisam ser NULL
void InsertOnTree(BTree** p_tree, int value, int order, BTree** root){
    BTree* tree = *p_tree;
    int leaf = IsLeaf(tree); //  Tree is leaf? 1 : 0;
    if(leaf){
        // Insere no próprio vetor da árvore e aumenta o tamanho
        
        InsertOnArray(tree->values, tree->size, value);
        tree->size++;
        
        // Verifica se o tamanho ultrapassou, indica que é necessário fazer split/dividir a árvore
        
        if(tree->size >= 2*order+1){
            Split(p_tree, root); // No processo de split é necessario atualizar o tamanho das arvores que serão criadas left e right
        }
    }
    else{
        // Procura qual o ponteiro certo para Inserir, e usa recursividade na função
        BTree* pointer_to_insert = NULL;
        int i=0;
        while( tree->values[i]< value && i < tree->size){
            i++;
        }
        pointer_to_insert = tree->pointers[i];
        InsertOnTree(&pointer_to_insert, value, order, root);
    }
}