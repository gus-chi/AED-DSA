#include <stdio.h>
#define TAM_ARRAY 5

void InicializarArray(int *array){
  int cont;
  for(cont=0; cont < TAM_ARRAY; cont++){
    scanf("%d", &array[cont]);
  }
}
void PrintarArray(int *array){
  int cont;
  for(cont=0; cont< TAM_ARRAY; cont++)
    printf("%d ", array[cont];
  printf("\n");
}
void Insertion_sort(int *array){
  int i;
  for(i=1; i < TAM_ARRAY; i++){
    
  }
  
}

int main(void){
  int array[TAM_ARRAY];
  InicializarArray(array);
}
