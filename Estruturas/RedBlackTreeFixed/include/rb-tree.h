#include <stdio.h>
#include <stdlib.h>

typedef struct RB_Node RB_Node;

struct RB_Node{
    int value;
    char color;
    struct RB_Node *left;
    struct RB_Node *right;
};

// Tree Functions

RB_Node *InstantiateNode(int); // Instancia e Inicializa o Rb_Node
//void InsertOnTree(RB_Node**, RB_Node**, RB_Node**, RB_Node*, RB_Node**); // Problema
RB_Node *InsertOnTree(RB_Node*, RB_Node*, RB_Node**);
RB_Node *InsertOnRBTree(RB_Node*, RB_Node*, RB_Node**);
RB_Node *FixBalance(RB_Node*, RB_Node**);
RB_Node *SearchOnTree(RB_Node*, int); // 
RB_Node *SearchFather(RB_Node**, RB_Node*, RB_Node*);
RB_Node **SearchPointer(RB_Node**, RB_Node*);
int FindHeight(RB_Node*); // 

// RB Functions
void Recolor(RB_Node*);
int FindBlackHeight(RB_Node*);
    // Rotations Functions
    RB_Node* LL_Rotation(RB_Node*);
    RB_Node* RR_Rotation(RB_Node*);
  