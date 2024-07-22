#include "hash.h"

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