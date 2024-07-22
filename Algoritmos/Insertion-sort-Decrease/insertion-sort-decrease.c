#include <stdio.h>

void IniArray(int *array, int tamanho){
  int cont;
  for(cont= 0; cont< tamanho; cont++)
    scanf("%d", &array[cont]);
}

void InsertionSortDecrease(int *array, int tamanho){
  int cont;
  for(cont=0; cont< tamanho; cont++){
    int key = array[cont+1];
    int comparacao_com = cont;
    while(comparacao_com >= 0 && array[comparacao_com] < key){
      array[comparacao_com+1] = array[comparacao_com];
      comparacao_com--;
    }
    array[comparacao_com+1] = key;
    int l=0;
    for(;l<=cont; l++)
      printf("%d ", array[l]);
    printf("\n");
  }
}

void PrintarArray(int *array, int tamanho){
  int cont;
  for(cont = 0; cont < tamanho; cont++){
    cont != tamanho -1 ? printf("%d, ", array[cont]): printf("%d\n", array[cont]);
  }
}

int main(void){
  int tamanho = 5;
  int array[tamanho];
  IniArray(array, tamanho);
  InsertionSortDecrease(array, tamanho);
  PrintarArray(array, tamanho);
  return 0;
}
