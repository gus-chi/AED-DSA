#include <stdio.h>

#define TAM_A 6

int ordenarArray(int* array, int tam_array){
  int cont;
  for(cont= 0; cont< tam_array; cont++){ //Loop invariant [0:tam_array-1]
                                         //Inicio cont = 0 está no escopo do looping, true
    int chave = array[cont+1];
    int comparar_com = cont;
    while(comparar_com >= 0 && array[comparar_com]>chave){
      array[comparar_com+1] = array[comparar_com];
      comparar_com--;
    }
    array[comparar_com+1] = chave;

  }
}
void printarArray(int* array){
  int cont;
  for(cont = 0; cont < TAM_A; cont++){
    if (cont != TAM_A -1)
        printf("%d, ", array[cont]);
    else
      printf("%d\n", array[cont]);
  }
  return;
}

int main(void){
  int cont;
  int array_baguncado[TAM_A];
  for(cont = 0; cont<TAM_A; cont++)
    scanf("%d", &array_baguncado[cont]);
  printarArray(array_baguncado);
  ordenarArray(array_baguncado, TAM_A);
  printarArray(array_baguncado);
  return 0;
}
