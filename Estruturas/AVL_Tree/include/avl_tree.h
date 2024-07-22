#include <stdio.h>
#include <stdlib.h>

typedef struct AVL AVL_NODE;

struct AVL{
    int value;
    int bf; // fator de balanceamento
    AVL_NODE *left;
    AVL_NODE *right;
};
// Aux Functions
int FindHeight(AVL_NODE*); // Encontrar altura da árvore

// AVL/ABB Functions

AVL_NODE *InstantiateAVLNode(int);
int CalculateBF(AVL_NODE*); // Depende da função FindHeight
void InsertABBNode(AVL_NODE*, AVL_NODE*);
void InsertAVLNode(AVL_NODE**, AVL_NODE*);
void ApplyRotation(AVL_NODE**, int);

    // Rotações
    AVL_NODE* LL_Rotation(AVL_NODE*);
    AVL_NODE* LR_Rotation(AVL_NODE*);
    AVL_NODE* RR_Rotation(AVL_NODE*);
    AVL_NODE* RL_Rotation(AVL_NODE*);
AVL_NODE* SearchOnTree(AVL_NODE*, int);