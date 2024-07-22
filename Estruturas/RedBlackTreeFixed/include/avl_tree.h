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
int FindHeightAVL(AVL_NODE*); // Encontrar altura da árvore

// AVL/ABB Functions

AVL_NODE *InstantiateAVLNode(int);
int CalculateBF(AVL_NODE*); // Depende da função FindHeight
void InsertABBNode(AVL_NODE*, AVL_NODE*);
void InsertAVLNode(AVL_NODE**, AVL_NODE*);
void ApplyRotation(AVL_NODE**, int);

    // Rotações
    AVL_NODE* AVL_LL_Rotation(AVL_NODE*);
    AVL_NODE* AVL_LR_Rotation(AVL_NODE*);
    AVL_NODE* AVL_RR_Rotation(AVL_NODE*);
    AVL_NODE* AVL_RL_Rotation(AVL_NODE*);
AVL_NODE* SearchOnTreeAVL(AVL_NODE*, int);