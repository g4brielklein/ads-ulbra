#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stNo {
	int info;
	struct stNo *ant,*pos;
};

struct stNo *cria_no() {
	struct stNo *p;
	if ((p = (struct stNo *) malloc(sizeof(struct stNo))) == NULL)
		return NULL;
	else
		return p;
}
void inserirFila(struct stNo **fil,int n){
	struct stNo *p,*q;
	if(*fil==NULL){ //Fila vazia
	p = cria_no();
	*fil = p;
	p->ant = NULL;
	p->pos = NULL;
	p->info = n;
	}else{
		p=*fil;
		while(p->pos!=NULL)
			p=p->pos;// posiciona no final da fila
		q = cria_no();
		p->pos = q;
		q->pos = NULL;
		q->ant = p;
		q->info = n;
	};
};
void mostraFila(struct stNo **fil){
	struct stNo *p;
	if(*fil!=NULL){
		p=*fil;
		while(p->pos!=NULL){
			printf(" %d",p->info);
			p = p->pos;
		};
	printf(" %d",p->info);
	}
	else printf("\nFila Vazia");
};

main() {
	struct stNo *fila;
	int num,i,no;
	fila = NULL; 
	char Menu, Menu1;
   	do{
    	system("cls");
      	printf("\nFILA =>");
	  	if (fila==NULL)
	  		printf("Lista Vazia");
		else
			mostraFila(&fila);
      		fflush(stdin);
      		printf("\nMENU ==>[C]olocar,[T]irar,[S]air Programa: ");       
      		Menu=getche();
      		Menu=toupper(Menu);
      		switch (Menu){
            	case 'C':
				   		printf("\nInserir o no: ");
           		   		scanf("%i",&num);
						inserirFila(&fila,num);
                       	break;
             case 'T': system("cls");
                       printf("\nExcluir");
                       printf("\n Pressione uma tecla para voltar ao menu");
                       getch();
                       break;
             case 'S': printf("\nSaindo...");
             		   sleep(3);
			 		   break;
             default : printf("\n Opcao invalida");
                       printf("\n Pressione uma tecla para voltar ao menu");
                       getch();
    	}
   }while (Menu!='S');
}

