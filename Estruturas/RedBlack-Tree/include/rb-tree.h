#include <stdio.h>
#include <stdlib.h>

typedef struct RB_Node RB_Node;

struct RB_Node{
    int value;
    char color;
    struct RB_Node *left;
    struct RB_Node *right;
};

RB_Node *InstantiateNode(int); // Instancia e Inicializa o Rb_Node; // Feito

// Tree Functions
void Recolor(RB_Node*); // Feito
RB_Node *InsertOnTree(RB_Node**, RB_Node**, RB_Node**, RB_Node*, RB_Node**); // Não Feito
RB_Node *SearchOnTree(RB_Node*, int); // Feito
int FindHeight(RB_Node*); // Feito
int FindBlackHeight(RB_Node*);
    // Rotations Functions
    RB_Node* LL_Rotation(RB_Node*);
    RB_Node* RR_Rotation(RB_Node*);
  