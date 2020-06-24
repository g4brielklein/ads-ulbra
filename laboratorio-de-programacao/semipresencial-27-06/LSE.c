#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stNo {
	int info;
	struct stNo *prox;
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
	p->prox = NULL;
	p->info = n;
	}else{
		p=*list;
		while(p->prox!=NULL)
		p=p->prox;// posiciona no final da lista
		q = cria_no();
		p->prox = q;
		q->prox = NULL;
		q->info = n;
	};
};

void mostra_lista(struct stNo **list){
	struct stNo *p;
	if(*list!=NULL){
		p=*list;
		while(p->prox!=NULL){
			printf("\nInfo:%d ",p->info);
			p = p->prox;
		};
	printf("\nInfo:%d ",p->info);
	}
	else printf("\nLista Vazia");
};

void excluir_ultimo(struct stNo **list){
	struct stNo *p,*q;
	if(*list!=NULL){
		p=*list;
		while(p->prox!=NULL){
			q = p;
			p = p->prox;
		}
		q->prox =NULL;
		free(p);
	}
	else printf("\nLista Vazia");
};

main() {
	struct stNo *lista;
	int num,i,nn;
	lista = NULL; // inicializando a lista vazia
	printf("\nDigite quantos nos deseja inserir: ");
	scanf("%d",&num);
	
	for(i=0;i<num;i++) {
		printf("\nDigite um valor: ");
		scanf("%d",&nn);	
		if (num)
			insere_lista( &lista, nn);// passando o endereço do inicio da lista
	};
	
	mostra_lista(&lista);
	printf("\n");
	excluir_ultimo(&lista);
	printf("\n");
	mostra_lista(&lista);
}
