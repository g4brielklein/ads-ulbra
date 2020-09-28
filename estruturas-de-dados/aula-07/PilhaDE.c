#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

struct Pilha {
  int info;
  struct Pilha *ant, *pos;
};


struct Pilha *cria_no() {
  struct Pilha *p;

  if ((p = (struct Pilha *) malloc(sizeof(struct Pilha))) == NULL)
    return NULL;
  else {  
    p->pos = NULL; 
    p->ant = NULL;
    return p;
  }
 }



void push(struct Pilha **stack, int n){
     struct Pilha *p,*q;
     if(*stack==NULL){ //pilha vazia
        p = cria_no();
        *stack = p;
        p->pos = NULL;
        p->ant = NULL;
        p->info = n;
       }
     else{
        p=*stack;
        while(p->pos!=NULL)
              p=p->pos;// posiciona no topo da pilha
        q = cria_no();
		p->pos = q;
		q->pos = NULL;
		q->ant = p;
		q->info = n;
     };
};
 
void pop(struct Pilha **stack){
     struct Pilha *p,*q;
     if(*stack!=NULL){ //pilha vazia
        p=*stack;
        while(p->pos!=NULL){
              q=p;
              p=p->pos;
        };      
        q->pos = NULL;
        free(p);
     };
      
};
        
void mostraPilha(struct Pilha **stack){
     struct Pilha *p;
     if(*stack!=NULL){
        p=*stack;
        while(p->pos!=NULL)
              p=p->pos;
        while(p->ant!=NULL){
        	if(p->pos==NULL)
	            printf("\n\tInfo:%d (topo)",p->info);
	        else
				printf("\n\tInfo:%d ",p->info);
            p = p->ant;
         };
        if(p->pos==NULL)
	        printf("\n\tInfo:%d (topo)",p->info);
	    else
			printf("\n\tInfo:%d ",p->info);
        }
        else printf("\nPilha Vazia");
};

main() {
	setlocale(LC_ALL,"Portuguese");
  	struct Pilha *inicio;
  	int num;
  	char Menu;
  
   	inicio = NULL; // inicializando a Pilha vazia

   	do{
    	system("cls");
      	printf("\nPILHA =>");
	  	if (inicio==NULL)
	  		printf("Pilha Vazia");
		else
			mostraPilha(&inicio);
      		fflush(stdin);
      		printf("\nMENU ==>[C]olocar,[T]irar,[S]air Programa: ");       
      		Menu=getche();
      		Menu=toupper(Menu);
      		switch (Menu){
            	case 'C':
				   		printf("\nInserir o no: ");
           		   		scanf("%i",&num);
						push(&inicio,num);
                       	break;
             	case 'T': 
				 		system("cls");
                       	printf("\nExcluir");
                       	printf("\n Pressione uma tecla para voltar ao menu");
                       	getch();
                       	break;
             case 'S': 	
			 			printf("\nSaindo...");
             		   	sleep(3);
			 		   	break;
             default : 	
			 			printf("\n Opcao invalida");
                       	printf("\n Pressione uma tecla para voltar ao menu");
                       	getch();
    	}
   }while (Menu!='S');
}




	  
