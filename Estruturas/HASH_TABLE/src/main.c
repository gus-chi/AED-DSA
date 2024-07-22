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

int main(void){
    int m, value; // m = prime_size of hash table value = value to be inserted in the hash table
    scanf("%d", &m);
    T_Hash *hash = malloc(sizeof *hash);
    InstantiateTHash(hash, m);
    while(scanf("%d", &value), value >= 0){
        // Insere
        Insert(hash, value, m);
    }
    int value_to_search;
    scanf("%d", &value_to_search);
    if(Search(hash, value_to_search) > 0){
        Remove(hash, value_to_search, m);
    }
    else{
        printf("Valor nao encontrado\n"); 
    }
    int i;
    for(i=0; i<m; i++){
        if(hash->value[i] >= 0)
            printf("%d ", hash->value[i]);
        else if(hash->value[i] == -1)
            printf("\\ ");
        else if(hash->value[i] == -2)
            printf("D ");
    }
    printf("\n");

    return 0;
}

void InstantiateTHash(T_Hash *hash,int size){
    hash->value = calloc(size , sizeof (int));
    int i;
    for(i=0; i< size; i++)
        hash->value[i]--;
}

int Hash(int k, int m, int i){
    int h1 = HashAux1(k, m); 
    int h2 = HashAux2(k, m);
    return (h1+ i * h2) % m;
}
int HashAux1(int k, int m){
    return k % m;
}
int HashAux2(int k, int m){
    return 1 + (k % (m-1));
}
void Insert(T_Hash* hash, int k, int m){
    int try = 0;
    do{
        int index = Hash(k, m, try);
        if(hash->value[index] <= 0){
            hash->value[index] = k;
            return;
        }
        try++;
    }
    while(try < m);
}
int Search(T_Hash* hash, int key){
    return hash->value[key];
}
int Remove(T_Hash* hash, int k, int m){
    int try = 0;
    int flag = 0;
    do{
        int index = Hash(k, m, try);
        if(hash->value[index] == k){
            hash->value[index] = -2;
            flag++;
        }
        try++;
    }
    while(try < m);
    return flag;
}