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

void inserirFim(struct stNo **dI,struct stNo **dF,int n){
	struct stNo *p,*q;
	if(*dI==NULL){ //vazio vazia
	p = cria_no();
	*dI = p;
	p->ant = NULL;
	p->pos = NULL;
	p->info = n;
	}else{
		p=*dI;// 1000
		while(p->pos!=NULL)
			p=p->pos;// posiciona no final da lista
		q = cria_no();//2000
		p->pos = q;
		q->pos = NULL;
		q->ant = p;
		q->info = n;
	};
};

void inserirIni(struct stNo **dI,struct stNo **dF,int n){
	struct stNo *p,*q;
	if(*dI==NULL){ //lista vazia
		p = cria_no();
		*dI = p;
		p->pos = NULL;
		p->info = n;
	}else{
		p=*dI;
		q = cria_no();
		q->pos = p;
		q->info = n;
		*dI = q;		
	};
};


void mostra_lista(struct stNo **dI){
	struct stNo *p;
	if(*dI!=NULL){
		p=*dI;
		while(p->pos!=NULL){
			printf(" %d",p->info);
			p = p->pos;
		};
	printf(" %d",p->info);
	}
	else printf("\nDeque Vazio");
};

void excluirFim(struct stNo **dI, struct stNo **dF){
	struct stNo *p,*q;
	if(*dF!=NULL){
		p=*dF;
		while(p->pos!=NULL)
			p = p->pos;
		q=p->ant;
		q->pos=NULL;
		free(p);
	}
	else printf("\nDeque Vazio");
};

void excluirIni(struct stNo **dI,struct stNo **dF){
	struct stNo *p,*q;
	if(*dI!=NULL){
		p=*dI;
		q=p->pos;
		q->ant = NULL;
		*dI = q;
		free(p);
	}
	else printf("\nDeque Vazio");
};

main() {
	struct stNo *dequeIni,*dequeFim;
	int num,i,no;
	dequeIni = NULL;
	dequeFim = NULL;
	char Menu, Menu1;
   	do{
    	system("cls");
    	printf("\nInicio|-----------|Fim");
      	printf("\nDEQUE =>");
	  	if (dequeIni==NULL)
	  		printf("Deque Vazio");
		else
			mostra_lista(&dequeIni);
      		fflush(stdin);
      		printf("\nMENU ==>[I]serir,[E]xcluir,[S]air: ");       
      		Menu=getche();
      		Menu=toupper(Menu);
      		switch (Menu){
            	case 'I':
				   		printf("\nInserir o no: ");
           		   		scanf("%i",&num);
           		   		printf("\nPOSICAO ==>[I]nicio ou [F]im"); 
      					Menu1=getche();
      					Menu1=toupper(Menu1);
           		   		if(dequeIni==NULL)
           		   			inserirIni(&dequeIni,&dequeFim,num);
           		   		else switch(Menu1){
           		   			case 'I':inserirIni(&dequeIni,&dequeFim,num);
           		   					break;
           		   			case 'F':inserirFim(&dequeIni,&dequeFim,num);
           		   					break;
							}
                       	break;
             case 'E':  printf("\nExcluir: ");
           		   		printf("\nPOSICAO ==>[I]nicio ou [F]im"); 
      					Menu1=getche();
      					Menu1=toupper(Menu1);
           		   		if(dequeIni!=NULL&&dequeFim!=NULL)
           		   		  switch(Menu1){
           		   			case 'I':excluirIni(&dequeIni,&dequeFim);
           		   					break;
           		   			case 'F':excluirFim(&dequeIni,&dequeFim);
           		   					break;
							}
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

