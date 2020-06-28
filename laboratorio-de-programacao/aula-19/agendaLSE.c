#include <stdio.h>
#include <stdlib.h>
#define tam 20

struct reg{
	char nome[30];
	char endereco[50];
	char fone[16];
	char email[40];
	struct reg *prox;
};

struct reg *cria_no() {
	struct reg *p;
	if ((p = (struct reg *) malloc(sizeof(struct reg))) == NULL)
		return NULL;
	else{
		p->prox = NULL;
		return p;
	}
}

void InsereRegistro(struct reg **list){
	struct reg *p,*q;

	if(*list==NULL){ //lista vazia
		p = cria_no();
		*list = p;
		p->prox = NULL;
	    printf("\nDigite o nome: ");
 		fflush(stdin);
		gets(&p -> nome);
	    printf("Digite o endereco: ");
 		fflush(stdin);
		gets(&p -> endereco);
	    printf("Digite o fone: ");
 		fflush(stdin);
		gets(&p -> fone);
	    printf("Digite o email: ");
 		fflush(stdin);
		scanf("%s",&p -> email);
	}else{
		p=*list;
		while(p->prox!=NULL)
			p=p->prox;// posiciona no final da lista

		q = cria_no();
		p->prox = q;
		q->prox = NULL;
		
		printf("\nDigite o nome: ");
 		fflush(stdin);
		gets(&q -> nome);
	    printf("Digite o endereco: ");
 		fflush(stdin);
		gets(&q -> endereco);
	    printf("Digite o fone: ");
 		fflush(stdin);
		gets(&q -> fone);
	    printf("Digite o email: ");
 		fflush(stdin);
		scanf(" %s",&q -> email);
	};
};

void VisualizaRegistros(struct reg **list){
	struct reg *aux;
	aux = *list;

	if(aux!=NULL){
		while(aux->prox != NULL){
            printf("\nNome: %s",aux -> nome);
	        printf("\nEndereco: %s",aux -> endereco);
	        printf("\nFone: %s",aux -> fone);
	        printf("\nEmail: %s",aux -> email);
	        printf("\n\n");
            aux = aux -> prox;

	    }
	    printf("\nNome: %s",aux -> nome);
        printf("\nEndereco: %s",aux -> endereco);
        printf("\nFone: %s",aux -> fone);
        printf("\nEmail: %s",aux -> email);
        printf("\n\n");
	}else printf("\nLista Vazia");

};


main() {
 int i;
 struct reg *lista;
 char Menu;
 lista = NULL;
 
 do{
	system("cls");
	fflush(stdin);
 	printf("\n Menu Principal\n");
 	printf("\n A - Inserir");
 	printf("\n B - Visualizar");
 	printf("\n C - Sair");
 	printf("\n\nOpcao: ");
 	Menu=getche();
 	Menu=toupper(Menu);
 	
 	switch (Menu){
 		case 'A':	system("cls");
					printf("\n Inserir um registro\n");
 					InsereRegistro(&lista);
 					printf("\n Pressione uma tecla para voltar ao menu");
 					getch();
 					break;
		case 'B':	system("cls");
					printf("\n Visualizar registros\n");
					VisualizaRegistros(&lista);
					printf("\n Pressione uma tecla para voltar ao menu");
					getch();
					break;
 		case 'C': 	printf("\nSaindo...");
					sleep(3);
					break;
 		default:	printf("\n Opcao invalida");
 					printf("\n Pressione uma tecla para voltar ao menu");
 					getch();
 		}
 	}
 	while (Menu!='C');
}
