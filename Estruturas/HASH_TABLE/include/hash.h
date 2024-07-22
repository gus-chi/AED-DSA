#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct T_Hash T_Hash;

// Por ser uma tabela Hash de endereçamento aberto, o No não precisa de um ponteiro para o próximo elemento para lidar com colisões

struct T_Hash{
    int *value;
};

void InstantiateTHash(T_Hash*, int); // Instantiate and Init Hash
int Hash(int, int, int);
int HashAux1(int, int);
int HashAux2(int, int);
void Insert(T_Hash*, int, int);
int Remove(T_Hash*, int, int);
int Search(T_Hash*, int);