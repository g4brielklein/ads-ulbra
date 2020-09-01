#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stNo {
	int info;
    char nome[30];
	struct stNo *ant, *prox;
};

struct stNo *cria_no() {
	struct stNo *p;
	if ((p = (struct stNo *) malloc(sizeof(struct stNo))) == NULL)
		return NULL;
	else
		return p;
}

void inserir_fim(struct stNo **list,int n, char *nom){
	struct stNo *p,*q;
	if(*list==NULL){ //lista vazia
	p = cria_no();
	*list = p;
	p->ant = NULL;
	p->prox = NULL;
	p->info = n;
	strcpy(p->nome,nom);
	}else{
		p=*list;
		while(p->prox!=NULL)
			p=p->prox;// posiciona no final da lista
		q = cria_no();
		p->prox = q;
		q->ant = p;
		q->prox = NULL;
		q->info = n;
		strcpy(q->nome,nom);
	};
};

void inserir_inicio(struct stNo **list, int n, char *nom){
	struct stNo *p,*q;
	if(*list==NULL){ //lista vazia
		p = cria_no();
		*list = p;
		p->ant = NULL;
		p->prox = NULL;
		p->info = n;
		strcpy(p->nome,nom);
	}else{
		p=*list;
		q = cria_no();
		q->ant = NULL;
		q->prox = p;
		p->ant = q;
		q->info = n;
		strcpy(q->nome,nom);
		*list = q;		
	};
};

void inserir_meio(struct stNo **list,int depois, int n, char *nom){
	struct stNo *p,*q,*z;
	if(*list==NULL){ //lista vazia
		printf("\nLista Vazia!");
	}else{
		p=*list;
		while(p->prox!=NULL&&p->info!=depois){
			p=p->prox;// posiciona
		}
		if(p->info==depois&&p->prox!=NULL){
			q = cria_no();
			z = p->prox;
			q->info = n;
			strcpy(q->nome,nom);
			p->prox = q;
			q->prox = z;
			q->ant = p;
			z->ant = q;
		};
	};
};

void mostrar_lista(struct stNo **list){
	struct stNo *p;
	if(*list!=NULL){
		p=*list;
		while(p->prox!=NULL){
			printf(" %d(%s) ",p->info,p->nome);
			p = p->prox;
		};
	printf(" %d(%s) ",p->info,p->nome);
	}
	else printf("\nLista Vazia");
};

void excluir_fim(struct stNo **list){
	struct stNo *p,*q;
	if(*list!=NULL){
		p=*list;
		if (p->prox==NULL){
			free(p);
			*list = NULL;
		} else {
			while(p->prox!=NULL){
				q = p;
				p = p->prox;
			}
			q=p->ant;
			q->prox =NULL;
			free(p);
		}
	}
	else printf("\nLista Vazia");
};

void excluir_inicio(struct stNo **list){
	struct stNo *p,*q;
	if(*list!=NULL){
		p=*list;
		if(p->prox==NULL){
			free(p);
			*list=NULL;
		}else{
			q=p->prox;
			q->ant = NULL;
			*list=q;
			free(p);
		}
	}
	else printf("\nLista Vazia");
};

void excluir_meio(struct stNo **list, int n){
	struct stNo *p,*q,*z;
	if(*list!=NULL){
		p=*list;
		while(p->prox!=NULL&&p->info!=n){
			q = p;
			p = p->prox;
		}
		if(p->prox!=NULL){
			z=p->prox;
			q->prox=z;
			z->ant = q;
			free(p);			
		}else
			printf("\nEh o ultimo!");
	}
	else printf("\nLista Vazia");
};

void alterar_no(struct stNo **list, int n){
	struct stNo *p;
	if(*list!=NULL){
		p=*list;
		while(p->prox!=NULL&&p->info!=n)
			p = p->prox;
		if(p->info==n){
			fflush(stdin);
			printf("\nDigite um novo nome: ");
			gets(p->nome);
		}else{
		}
	}
	else printf("\nLista Vazia");
};

main() {
	struct stNo *lista,*lis;
	char nomeS[30];
	int num,i,no;
	lista = NULL; 
	char Menu,Menu1;
   	do{
    	system("cls");
      	printf("\nLISTA =>");
	  	if (lista==NULL)
	  		printf("Lista Vazia");
		else
			mostrar_lista(&lista);
      fflush(stdin);
      printf("\nMENU ==>[I]nserir,[A]lterar,[E]xcluir,[S]air: ");       
      Menu=getche();
      Menu=toupper(Menu);
      switch (Menu){
             case 'I':  printf("\nInserir o no: ");
           		   		scanf("%i",&num);
           		   		fflush(stdin);
           		   		printf("\nDigite um nome: ");
						gets(nomeS);
           		   		printf("\nPOSICAO ==>[I]nicio,[F]im,[D]epois no: ");
      					Menu1=getche();
      					Menu1=toupper(Menu1);
           		   		if(lista==NULL)
           		   			inserir_fim(&lista,num,nomeS);
           		   		else switch(Menu1){
           		   			case 'I':inserir_inicio(&lista,num,nomeS);
           		   					break;
           		   			case 'F':inserir_fim(&lista,num,nomeS);
           		   					break;
           		   			case 'D':printf("\nDepois do no: ");
      								scanf("%i",&no);
      								inserir_meio(&lista,no,num,nomeS);
      								break;
							}
                       	break;
                       	
             case 'A':  printf("\nAlterar o no: ");
           		   		scanf("%i",&num);
						alterar_no(&lista,num);
                       	break;
                       	
             case 'E': 	printf("\nExcluir o no: ");
           		   		scanf("%i",&num);
           		   		lis = lista;
           		   		if(lis!=NULL){
           		   			while(lis->prox!=NULL&&lis->info!=num)
           		   				lis=lis->prox;
           		   			if(lis->info==num){
           		   				if(lista == lis)
           		   					excluir_inicio(&lista);
           		   				else if (lista->prox==NULL)
           		   						excluir_fim(&lista);
           		   					 else
           		   					 	excluir_meio(&lista,num);
							}else{
								printf("\nNo nao encontrado!");
							}        		   		
						}else{
							printf("\nLista Vazia!");
						}
                       	break;
                       	
             case 'S': printf("\nSaindo...");
             		   	sleep(1);
			 		   	break;
			 		   	
             default : printf("\n Opcao invalida");
                       printf("\n Pressione uma tecla para voltar ao menu");
                       getch();
      }
   }   while (Menu!='S');
}
