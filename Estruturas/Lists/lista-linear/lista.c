#include "lista.h"

void IniciarLista(struct Lista* lista){
	(*lista).ultimo = 0;
    (*lista).primeiro = 0;
}
void PrintarLista(struct Lista* lista){
	if((*lista).ultimo == 0 || (*lista).ultimo == (*lista).primeiro){
		printf("Lista vazia\n");
        printf("***********\n");
		return;
	}
	int cont=(*lista).primeiro;
	for(; cont < (*lista).ultimo; cont++){
		printf("Nome: %-10s | Chave: %04d | Preço: R$ %4.2f\n", (*lista).itens[cont].nome, (*lista).itens[cont].chave, (*lista).itens[cont].preco);
	}
	printf("************************\n");
}

void AddNaPos(struct Lista* lista){
  int pos, chave, ultimo;
  int key;
  char nome[50];
  float preco;
  ultimo = (*lista).ultimo;
  printf("Digite a posicao que deseja adicionar");
  scanf("%d", &pos);
  printf("ITEM ---------------\n");
  printf("Digite o nome do item: ");
  scanf("%s", nome);
  printf("Digite a chave do item: ");
  scanf("%d", &chave);
  printf("Digite o preço do item: ");
  scanf("%f", &preco);
  if(pos >= MAX_ITENS){
    printf("Indice alto demais! Abortando...");
    return;
  }
  if((*lista).ultimo >= MAX_ITENS - 1){
    printf("Impossível adicionar elemento, Lista Cheia\n");
    return;
  }
  printf("--------------------\n");
  if( pos > ultimo+1){
    printf("Erro de entrada de índice! Abortando...\n");
    return;
  }
  if(pos <= ultimo+1){
    for(; ultimo > pos; ultimo--){
        strcpy((*lista).itens[ultimo].nome, (*lista).itens[ultimo-1].nome);
          (*lista).itens[ultimo].chave = (*lista).itens[ultimo-1].chave;
        (*lista).itens[ultimo].preco = (*lista).itens[ultimo-1].preco;
    }
    strcpy((*lista).itens[pos].nome, nome);
    (*lista).itens[pos].chave = chave;
    (*lista).itens[pos].preco = preco;
    printf("Item Adicionado\n"); 
    (*lista).ultimo++;
  }

}
void RemDaPos(struct Lista* lista){
 int pos;
 char nome[50];
 printf("Digite a posição da lista que deseja remover: ");
 scanf("%d", &pos);
  if((*lista).primeiro <= pos && (*lista).ultimo >= pos){
  int cont;
  strcpy(nome, (*lista).itens[pos].nome);
  for(cont = pos; cont < (*lista).ultimo; cont++){
    (*lista).itens[cont] = (*lista).itens[cont+1];
  }
  (*lista).ultimo--;
  printf("Item %s Removido\n", nome); 
  }
}
void InsFin(struct Lista* lista){
	char nome[50];
	int chave;
	float preco;
	printf("Digite o nome do item: ");
	scanf("%s", nome);
	printf("Digite a chave do item: ");
	scanf("%d", &chave);
	printf("Digite o preço do item: ");
	scanf("%f", &preco);
	strcpy((*lista).itens[(*lista).ultimo].nome, nome);
	(*lista).itens[(*lista).ultimo].chave = chave;
	(*lista).itens[(*lista).ultimo].preco = preco;
	(*lista).ultimo++;


}
void RemFin(struct Lista* lista){
    if ((*lista).ultimo == (*lista).primeiro){
      printf("Lista Vazia");
      return;
    }
	printf("Item %s Removido!\n", (*lista).itens[(*lista).ultimo-1].nome);
	(*lista).ultimo--;
}
void RemIni(struct Lista* lista){
  if((*lista).primeiro == (*lista).ultimo){
    printf("Lista Vazia!\n");
    return;
  }
  printf("Item %s Removido!\n", (*lista).itens[(*lista).primeiro].nome);
  (*lista).primeiro++;
}
void RetiraEspecifico(struct Lista* lista){
  // Retirar por nome ou chave
  int primeiro = (*lista).primeiro;
  int ultimo = (*lista).ultimo;
  int achou = 0;
  
  if(primeiro == ultimo){
   printf("Lista Vazia\n");
   printf("***********\n");
   return;
  }
  char opcao;
  printf("Digite (n) ou (c) se quer retirar o item por nome ou chave\n");
  printf("(n) para nome\n");
  printf("(c) para chave\n");
  fflush(stdin);
  scanf(" %c", &opcao);

  if(opcao == 'n'){
    char nome_requerido[50];
    printf("Digite o nome do item: ");
    scanf("%s", nome_requerido);
    for(; primeiro< ultimo; primeiro++){
      if (!strcmp((*lista).itens[primeiro].nome, nome_requerido)){
          printf("Item %s Removido!", (*lista).itens[primeiro].nome);
          (*lista).itens[primeiro] = (*lista).itens[primeiro+1];
          achou = 1;
          }
    }
  }
  if(opcao == 'c'){
    int chave_requerida;
    printf("Digite a chave do item: ");
    scanf("%d", &chave_requerida);
    for(; primeiro< ultimo; primeiro++){
      if((*lista).itens[primeiro].chave == chave_requerida){
        printf("Item %d Removido!", (*lista).itens[primeiro].chave);
       (*lista).itens[primeiro] = (*lista).itens[primeiro+1];
        achou = 1;
      }
    }
  }

  if(achou)
    (*lista).ultimo--;
}
