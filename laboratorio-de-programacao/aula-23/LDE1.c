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

void insere_lista(struct stNo **list,int n){
	struct stNo *p,*q;
	if(*list==NULL){ //lista vazia
	p = cria_no();
	*list = p;
	p->ant = NULL;
	p->pos = NULL;
	p->info = n;
	}else{
		p=*list;// 1000
		while(p->pos!=NULL)
			p=p->pos;// posiciona no final da lista
		q = cria_no();//2000
		p->pos = q;
		q->pos = NULL;
		q->ant = p;
		q->info = n;
	};
};

/*void mostra_lista(struct stNo **list){
	struct stNo *p;
	if(*list!=NULL){
		p=*list;
		while(p->pos!=NULL){
			printf("\nNo:%d - Info:%d - ant:%d  - pos:%d",p,p->info,p->ant,p->pos);
			p = p->pos;
		};
	printf("\nNo:%d - Info:%d - ant:%d  - pos:%d",p,p->info,p->ant,p->pos);
	}
	else printf("\nLista Vazia");
};*/

void mostra_lista(struct stNo **list){
	struct stNo *p;
	if(*list!=NULL){
		p=*list;
		while(p->pos!=NULL){
			printf("\nInfo:%d",p->info);
			p = p->pos;
		};
	printf("\nInfo:%d",p->info);
	}
	else printf("\nLista Vazia");
};

void excluir_ultimo(struct stNo **list){
	struct stNo *p,*q;
	if(*list!=NULL){
		p=*list;
		while(p->pos!=NULL)
			p = p->pos;
		q=p->ant;
		q->pos=NULL;
		free(p);
	}
	else printf("\nLista Vazia");
};

void excluir_primeiro(struct stNo **list){
	struct stNo *p,*q;
	if(*list!=NULL){
		p=*list;
		q=p->pos;
		q->ant = NULL;
		*list = q;
		free(p);
	}
	else printf("\nLista Vazia");
};

void altera_no(struct stNo **list, int nn){
	struct stNo *p;
	if(*list!=NULL){
		p=*list;
		while(p->pos!=NULL&&p->info!=nn)
			p = p->pos;
		printf("\nInfo:%d", p->info);
	}
	else printf("\nLista Vazia");
};

void excluir_no(struct stNo **list, int nn){
	struct stNo *p,*q,*z;
	if(*list!=NULL){
		p=*list;
		while(p->pos!=NULL&&p->info!=nn)
			p = p->pos;
		q = p->ant;
		z = p->pos;
		q->pos = z;
		z->ant = q;
		free(p);
	}
	else printf("\nLista Vazia");
};

main() {
	struct stNo *inicio;
	int num,i,nn;
	inicio = NULL; // inicializando a lista vazia
	printf("\nDigite quantos nos deseja inserir: ");
	scanf("%d",&num);
	
	for(i=0;i<num;i++) {
		printf("\nDigite um valor: ");//4
		scanf("%d",&nn);	
		if (num)
			insere_lista(&inicio,nn);// passando o endereço do inicio da lista
	};
	
	mostra_lista(&inicio);
	printf("\n");
/*	altera_no(&inicio, 4);
	printf("\n");
	excluir_ultimo(&inicio);
	printf("\n");
	mostra_lista(&inicio);
	printf("\n");
	excluir_primeiro(&inicio);
	printf("\n");
*/
    excluir_no(&inicio,3);
	printf("\n");
	mostra_lista(&inicio);
}
