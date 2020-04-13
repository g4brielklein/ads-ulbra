#include <stdio.h>
#define num_l 4
#define num_c 4

main() {
	int linha, coluna;
	
	int matriz[num_l][num_c];
	
	printf("\nLendo os valores da matriz: \n\n");
	
	for (linha = 0;linha < num_l;linha++) {
		for (coluna = 0;coluna < num_c;coluna++) {
			printf("Valor da linha %d, coluna %d: ", linha, coluna);
			scanf("%d", &matriz[linha][coluna]);
		}
	}
	
	char menu;
	
	do {
		system("cls");
		fflush(stdin);
		printf("\nMenu principal\n");
		printf("\n A - Escreva o menor elemento e quantas vezes ele aparece na matriz");
		printf("\n B - Escreva a soma dos elementos da diagonal principal");
		printf("\n C - Troque os elementos da coluna 1 com os da coluna 4 e mostre a matriz");
		printf("\n D - Encerre o programa");
		printf("\n\nOpcao: ");
		menu = getche();
		menu = toupper(menu);
		
		switch(menu) {
			case 'A': system("cls");
			          printf("\n Escreva o menor elemento e quantas vezes ele aparece na matriz\n");
			          
			          int menor = matriz[0][0];
			          int aparece = 0;
			          
			          	for (linha = 0; linha < num_l; linha++) {
			          		for (coluna = 0; coluna < num_c; coluna++) {
			          			if (matriz[linha][coluna] < menor) {
			          				menor = matriz[linha][coluna];
								}
							}
					  	}
						for (linha = 0; linha < num_l; linha++) {
			          		for (coluna = 0; coluna < num_c; coluna++) {
			          			if (matriz[linha][coluna] == menor) {
			          				aparece++;
								}
							}
					  	}
			          printf("\nO menor elemento foi %d e ele apareceu %d vezes\n", menor, aparece);
			          
			          	printf("\n\nExibindo o conteudo da matriz:\n\n");
	
						for (linha = 0; linha < num_l; linha++) {
							for (coluna = 0; coluna < num_c; coluna++) {
								printf("%4d", matriz[linha][coluna]);
							}
							printf("\n");
						}
			          
			          printf("\n Pressione qualquer tecla para voltar ao menu");
					  getch();
					  break;
			case 'B': system("cls");
					  printf("\n Escreva a soma dos elementos da diagonal principal\n");
					  
					  int soma_diagonal = matriz[0][0] + matriz[1][1] + matriz [2][2] + matriz[3][3];
					  printf("\nSoma dos elementos da diagonal principal: %d\n", soma_diagonal);
					  
					  printf("\n\nExibindo o conteudo da matriz:\n\n");
	
						for (linha = 0; linha < num_l; linha++) {
							for (coluna = 0; coluna < num_c; coluna++) {
								printf("%4d", matriz[linha][coluna]);
							}
							printf("\n");
						}
					  
					  printf("\n Pressione qualquer tecla para voltar ao menu");
					  getch();
					  break;	
			case 'C': system("cls");
					  printf("\n Troque os elementos da coluna 1 com os da coluna 4 e mostre a matriz\n");
					  
					  // codigo aqui
					  int vetor[4];
					  
					  vetor[0] = matriz[0][0];
					  vetor[1] = matriz[1][0];
					  vetor[2] = matriz[2][0];
					  vetor[3] = matriz[3][0];
					  
					  matriz[0][0] = matriz[0][3];
					  matriz[1][0] = matriz[1][3];
					  matriz[2][0] = matriz[2][3];
					  matriz[3][0] = matriz[3][3];
					  
					  matriz[0][3] = vetor[0];
					  matriz[1][3] = vetor[1];
					  matriz[2][3] = vetor[2];
					  matriz[3][3] = vetor[3];
					  
					  printf("\n\nExibindo o conteudo da matriz modificada:\n\n");
	
						for (linha = 0; linha < num_l; linha++) {
							for (coluna = 0; coluna < num_c; coluna++) {
								printf("%4d", matriz[linha][coluna]);
							}
							printf("\n");
						}
					  
					  printf("\n Pressione qualquer tecla para voltar ao menu");
					  getch();
					  break;
			case 'D': printf("\nEncerrando...");
					  sleep(3);
					  break;
			default: printf("\n\nOpcao invalida!\n");
					 printf("\n Pressione qualquer tecla para voltar ao menu");
					 getch();
		}
	} while(menu!='D');
	
}
