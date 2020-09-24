#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

struct stNo {//nó da lista duplamente encadeada
  int info;
  struct stNo *ant, *pos;
};

struct stDNo {// nó do descritor
       int num;//quais informações deseja armazenar
       struct stNo *inicial,*final;
};
 
struct stDNo *Cria_Descritor() {
  struct stDNo *p;

  if ((p = (struct stDNo *) malloc(sizeof(struct stDNo))) == NULL)
    return NULL;
  else {
    p->num = 0;
    p->inicial = NULL;
    p->final = NULL; 
    return p;
  }
 };
       
struct stNo *cria_no() {
  struct stNo *p;

  if ((p = (struct stNo *) malloc(sizeof(struct stNo))) == NULL)
    return NULL;
  else {
    p->pos = NULL;
    p->ant = NULL; 
    return p;
  }
 };



void insere_lista(struct stDNo **Dlist,int n){
     struct stNo *p,*q;
     struct stDNo *d;
     d = *Dlist;
     if(d->inicial == NULL){ //lista vazia
        p = cria_no();
        d->inicial = p;
        d->final = p;
        d->num = d->num + 1;
        //p->prox = NULL;
        p->info = n;
       }
     else{
        p=d->inicial;
        while(p->pos!=NULL)
              p=p->pos;// posiciona no final da lista
        q = cria_no();
        p->pos = q;
        //q->pos = NULL;
        q->info = n;
        q->ant = p;
        d->final = q;
        d->num = d->num + 1;
     };
};
        
void mostra_lista(struct stDNo **Dlist){
     struct stNo *p;
     struct stDNo *d;
     d=*Dlist;
     printf("\nDescritor");
     printf("\nNum: %i",d->num);
     p=d->inicial;
     printf("\nInicial: %i - ",p->info);
     p=d->final;
	 printf("Final: %i\n\nNós",p->info);
     if(d!=NULL){
        p=d->inicial;
        while(p->pos!=NULL){
              printf("\nInfo:%d ",p->info);
              p = p->pos;
         };
         printf("\nInfo:%d ",p->info);
        }
        else printf("\nLista Vazia");
};


int main() {
	setlocale(LC_ALL,"Portuguese");
  struct stDNo *Dlista;
  int qtd,i,nn;
  
   Dlista = Cria_Descritor(); // criando descritor
  
   printf("\nDigite quantos nós deseja inserir: ");
   scanf("%d",&qtd);

 

  for(i=0;i<qtd;i++) {
    
    printf("\nDigite um valor: ");
    scanf("%d",&nn); 
 
    if (qtd)
        insere_lista(&Dlista, nn);// passando o endereço do inicio da lista
   };
 
   mostra_lista(&Dlista);
    


  getch();
  return 0;
}




	  
