#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int Menu(){
	int opcao=0;
	printf("Oque deseja fazer?\n");
	printf("(1) Printar lista\n");
	printf("(2) Adicionar elemento na posição\n");
	printf("(3) Remover elemento da posição\n");
	printf("(4) Inserir elemento no final da lista\n");
	printf("(5) Remover do Final\n");
	printf("(6) Remover do Início\n");
	printf("(7) Retira Específico\n");
	scanf("%d", &opcao);
	system("clear");
	return opcao;
}

void LidarMenu(int opcao, struct Lista* lista){
	switch(opcao){
		case 1:
			PrintarLista(lista);
			break;
		case 2:
			AddNaPos(lista);
			break;
		case 3:
			RemDaPos(lista);
			break;
		case 4:
			InsFin(lista);
			break;
        case 5: 
            RemFin(lista);
            break;
        case 6:
            RemIni(lista);
            break;
        case 7:
            RetiraEspecifico(lista);
            break;
		default:
			printf("Número não reconhecido identificado\n");
			exit(1);
	}
}

int main(void){
	struct Lista list;
	IniciarLista(&list);
	for(;;){
	LidarMenu(Menu(), &list);
	}
	return 0;
}
