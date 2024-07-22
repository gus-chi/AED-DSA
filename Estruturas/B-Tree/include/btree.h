#include <stdio.h>
#include <stdlib.h>

typedef struct BTree BTree;

struct BTree{
    int size;
    int *values;
    BTree **pointers;
};
// Aux BTree Functions

// BTree* FindFather(BTree* origem, BTree* target);
int IsLeaf(BTree*);
int InsertOnArray(int*, int, int);

int Fill(int*, int*, int, int);
void Link(BTree**, BTree**, int, int); // Fill but with the pointers
BTree* Gather(BTree*, BTree*, BTree*, int);
BTree* Split(BTree**, BTree**);
BTree* SearchNode(BTree*, int);
BTree* SearchFather(BTree*, int);

// Tree Functions

BTree* InstantiateTree(int);
void InitTree(BTree*, int);
void InsertOnTree(BTree**, int, int, BTree**);
