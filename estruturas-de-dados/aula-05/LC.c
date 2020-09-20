#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stNo {
  int info;
  struct stNo *ant, *pos;
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
 }


void insere_lista(struct stNo **list,int n){
     struct stNo *p,*q;
     if(*list==NULL){ //lista vazia
        p = cria_no();
        *list = p;
        //p->prox = NULL;
        p->info = n;
        p->ant = p;
        p->pos = p;
       }
     else{
        p=*list;
        while(p->pos!= *list)
              p=p->pos;// posiciona no final da lista
        q = cria_no();
        p->pos = q;
        q->info = n;
        q->ant = p;
        p = *list;
        p->ant = q;
        q->pos = p;
     };
};
        

void mostra_lista(struct stNo **list){
     struct stNo *p;
     if(*list!=NULL){
        p=*list;
        while(p->pos!=*list){
              printf("\nInfo:%d (%d) ",p->info,p);
              printf("\n\tAnt:%d ",p->ant);
         	  printf("\n\tPos:%d ",p->pos);
              p = p->pos;
         };
         printf("\nInfo:%d (%d) ",p->info,p);
         printf("\n\tAnt:%d ",p->ant);
         printf("\n\tPos:%d ",p->pos);
        }
        else printf("\nLista Vazia");
};

/*void exclui_ultimo_no(struct stNo **list){
     struct stNo *p, *q;
     printf("\nExclui o ultimo no!!!");
     if(*list!=NULL){
        p=*list;
        while(p->pos!=NULL)
              p = p->pos;
        q = p->ant;
        q->pos = NULL;
        free (p);
        }
        else printf("\nLista Vazia");
};

*/
main() {
  struct stNo *listac;
  int num,i,nn;
  
   listac = NULL; // inicializando a lista vazia
   
   printf("\nDigite quantos nos deseja inserir: ");
   scanf("%d",&num);

 
 
  for(i=0;i<num;i++) {
    
    printf("\nDigite um valor: ");
    scanf("%d",&nn); 
 
    if (num)
        insere_lista( &listac, nn);// passando o endereço do inicio da lista
   };
 
    mostra_lista(&listac);
    
    //exclui_ultimo_no (&listac);
    
    
    //exclui_primeiro_no (&listac);
    


}

