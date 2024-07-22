#include <stdio.h>

void IniArray(int *array, int tamanho){
  int cont;
  for(cont = 0; cont < tamanho; cont++)
    scanf("%d", &array[cont]);
}
int SumArray(int *array, int tamanho){
    int soma, cont;
    soma = 0;
    for(cont = 0; cont < tamanho; cont++){
      soma += array[cont];
    }
    printf("%d", cont);
    return soma;

}
int main(void){
  int tamanho = 3;
  int array[tamanho];
  printf("Inicializando array...\n");
  IniArray(array, tamanho);
  printf("Somando array...\n");
  printf("A soma é %d", SumArray(array, tamanho));
  return 0;
}
