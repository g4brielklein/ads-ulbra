#include <stdio.h>
#define size 3

struct reg {
	char name[50], phone[20], email[50];
	int ativo;
}agenda[size];

int main() {
	int i;
	
	for (i=0; i < size; i++)
		agenda[i].ativo = 0;
		
	char Menu;
	do {
		system("cls");
		fflush(stdin);
	 	printf("\n Menu Principal\n");
	 	printf("\n A - Inserir");
	 	printf("\n B - Visualizar");
	 	printf("\n C - Alterar");
	 	printf("\n D - Excluir");
	 	printf("\n E - Sair");
	 	printf("\n\nOpcao: ");
	 	Menu=getche();
	 	Menu=toupper(Menu);
	 
	 	switch (Menu){
	 		case 'A':	system("cls");
						printf("\nInserir");
	 					printf("\n Pressione uma tecla para voltar ao menu");
	 					
	 					
	 					getch();
	 					break;
			case 'B':	system("cls");
						printf("\nVisualizar");
						printf("\n Pressione uma tecla para voltar ao menu");
						getch();
						break;
	 		case 'C':	system("cls");
						printf("\nAlterar");
						printf("\n Pressione uma tecla para voltar ao menu");
						getch();
						break;
	 		case 'D':	system("cls");
						printf("\nExcluir");
						printf("\n Pressione uma tecla para voltar ao menu");
						getch();
						break;
	 		case 'E': 	printf("\nSaindo...");
						sleep(3);
						break;
	 		default:	printf("\n Opcao invalida");
	 					printf("\n Pressione uma tecla para voltar ao menu");
	 					getch();
	 		}
	} while (Menu!= 'E');
}
