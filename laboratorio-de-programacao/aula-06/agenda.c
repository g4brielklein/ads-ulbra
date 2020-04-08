#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define tam 20

struct reg{
	int ativo;
	char nome[30];
	char endereco[50];
	char telefone[11];
	char cel[11];
	char email[40];
}agenda[tam];

main() {
 setlocale(LC_ALL, "portuguese");
 int i;
 char busca_nome[30];

 for (i=0;i<tam;i++)
 	agenda[i].ativo =0;
 	
 char Menu;
 do{
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
					printf("\n Inserir um registro\n");
 					for (i=0;i<tam;i++)
 						if(agenda[i].ativo == 0 && i<tam) {
 							agenda[i].ativo = 1;
 							printf("\nDigite o nome: ");
 							fflush(stdin);
 							gets(agenda[i].nome);
 							printf("Digite o endereço: ");
 							fflush(stdin);
 							gets(agenda[i].endereco);
 							printf("Digite o telefone: ");
 							fflush(stdin);
 							gets(agenda[i].telefone);
 							printf("Digite o celular: ");
 							fflush(stdin);
 							gets(agenda[i].cel);
 							printf("Digite o email: ");
 							fflush(stdin);
 							scanf("%s", &agenda[i].email);
 							break;
						 };
						 if (i==tam) 
						 	printf("\nAgenda cheia!\n");
 					printf("\n Pressione uma tecla para voltar ao menu");
 					getch();
 					break;
		case 'B':	system("cls");
					printf("\n Visualizar registros\n");
					for(i=0;i<tam;i++){
						if (agenda[i].ativo == 1) {
							printf("\nNome: %s\nEndereço: %s\nTelefone: %s\nCelular: %s\nEmail: %s\n", 
							agenda[i].nome, agenda[i].endereco, agenda[i].telefone, agenda[i].cel, agenda[i].email);
						}
					}
					printf("\n Pressione uma tecla para voltar ao menu");
					getch();
					break;
 		case 'C':	system("cls");
					printf("\n Alterar um registro\n");
					printf("\nDigite o nome do registro que deseja alterar: ");
					fflush(stdin);
					gets(busca_nome);
					for(i=0;i<tam;i++) {
						if(agenda[i].ativo == 0) {
							printf("\nRegistro não encontrado! \n");
							break;
						} else {
						if(strcmp(busca_nome,agenda[i].nome)==0){
							printf("\nDigite o nome: ");
 							fflush(stdin);
 							gets(agenda[i].nome);
 							printf("Digite o endereço: ");
 							fflush(stdin);
 							gets(agenda[i].endereco);
 							printf("Digite o telefone: ");
 							fflush(stdin);
 							gets(agenda[i].telefone);
 							printf("Digite o celular: ");
 							fflush(stdin);
 							gets(agenda[i].cel);
 							printf("Digite o email: ");
 							fflush(stdin);
 							scanf("%s", &agenda[i].email);
 							printf("\nRegistro alterado com sucesso!\n");
 							break;
						}
					}
					}
					
					printf("\n Pressione uma tecla para voltar ao menu");
					getch();
					break;
 		case 'D':	system("cls");
					printf("\n Excluir um registro\n");
					printf("\nDigite o nome do registro que deseja excluir: ");
					fflush(stdin);
					gets(busca_nome);
					for(i=0;i<tam;i++){
						if(agenda[i].ativo == 0) {
							printf("\nRegistro não encontrado! \n");
							break;
						} else {
						
						if(strcmp(busca_nome,agenda[i].nome) == 0) {
							agenda[i].ativo = 0;
							printf("\nRegistro exluido com sucesso!\n");
							break;
						}
						}
					}
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
 	}
 	while (Menu!='E');
}






