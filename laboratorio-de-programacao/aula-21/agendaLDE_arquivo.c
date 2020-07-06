/*
Trabalhando com  Arquivo Binário e Lista Duplamente Encadeada (LDE).
Crie uma agenda com as seguintes opções de MENU (Inserir Contato, Viasualizar Contato, Alterar Contato 
e Excluir Contato).* Visualizar, Alterar e Excluir Contato deve utililizar o nome do contato para encontrá-lo.
Ao entrar no programa, este abrirá o arquivo Agenda.dat e lerá (read)  todos os registros para um LDE.
Ao sair do programa, este abrirá o arquivo Agenda.dat e gravará (write) todos os registro da LDE.
Salve o arquivo com a extensão "*.c". E, envie para correção. Não gere arquivo texto, word ou pdf para enviar.
*/
// Gabriel Klein

#include <stdio.h>
#include <stdlib.h>

FILE *fptr;

struct reg {
	char nome[50];
    int idade;
    char fone[16];
    char email[50];	
};

struct stNo {
	char nome[50];
    int idade;
    char fone[16];
    char email[50];
	struct stNo *ant,*prox;
	
};

struct stNo *cria_no() {
	struct stNo *p;
	if ((p = (struct stNo *) malloc(sizeof(struct stNo))) == NULL)
		return NULL;
	else{
		p->prox = NULL;
		return p;
	}
}

void InsereContato(struct stNo **list){
	struct stNo *p,*q;
	
	if(*list==NULL){
		p = cria_no();
		*list = p;
		p->ant = NULL;
		p->prox = NULL;
				
	    printf("\nNome: ");
	    fflush(stdin);
		gets(&p -> nome);
	    printf("\nIdade: ");
	    fflush(stdin);
		scanf("%i",&p -> idade);
	    printf("\nFone: ");
	    fflush(stdin);
		scanf("%s", &p -> fone);
	    printf("\nEmail: ");
	    fflush(stdin);
		scanf("%s", &p -> email);
	    
	}else{
		p=*list;
		while(p->prox!=NULL)
			p=p->prox;
			
		q = cria_no();		
		p->prox = q;
		q->prox = NULL;
		q->ant = p;		
		
	    printf("\nNome: ");
	    fflush(stdin);
		gets(&q -> nome);
	    printf("\nIdade: ");
	    fflush(stdin);
		scanf("%i",&q -> idade);
	    printf("\nFone: ");
	    fflush(stdin);
		scanf("%s", &q -> fone);
	    printf("\nEmail: ");
	    fflush(stdin);
		scanf("%s", &q -> email);
	    
	};
};

void VisualizaContato(struct stNo **list){
	struct stNo *aux;
	char nomepesq[30];
    system("cls");
    printf("\nDigite o nome do contato para visualiza-lo: ");
    gets(&nomepesq);
	aux = *list;
	
	if(aux!=NULL){		
		while(aux->prox != NULL){	        
			if(!strcmp(nomepesq, aux -> nome)){	            
				printf("\nNome: %s",aux -> nome  );
		        printf("\nIdade: %d",aux -> idade );
		        printf("\nFone: %s",aux -> fone   );
		        printf("\nEmail: %s",aux -> email);
		        printf("\n\n");
		        system("pause");
	            printf("\n\n");	            
	        }
	        aux = aux -> prox;
	    }
	    if(!strcmp(nomepesq, aux -> nome)){	            
			printf("\nNome: %s",aux -> nome  );
	        printf("\nIdade: %d",aux -> idade );
	        printf("\nFone: %s",aux -> fone   );
	        printf("\nEmail: %s",aux -> email);
	        printf("\n\n");
	        system("pause");
            printf("\n\n");	            
        }
	}else printf("\nAgenda vazia!");   
	
};

void AlteraContato(struct stNo **list){
	struct stNo *aux;
	char nomepesq[30];
    system("cls");
    printf("\nDigite o nome do contato para altera-lo: ");
    gets(&nomepesq);
	aux = *list;
	
	if(aux!=NULL){
		while(aux->prox != NULL){	
	        if(!strcmp(nomepesq, aux -> nome)){	            	            
	        	
				printf("\nNome: %s",aux -> nome);
		        printf("\nIdade: %d",aux -> idade);
		        printf("\nFone: %s",aux -> fone);
		        printf("\nEmail: %s",aux -> email);
		        printf("\n\n");
		       	
		       	
		        printf("Digite os novos valores: \n");
				printf("\nNome: ");
			    fflush(stdin);
				gets(&aux -> nome);
			    printf("\nIdade: ");
			    fflush(stdin);
				scanf("%i",&aux -> idade);
			    printf("\nFone: ");
			    fflush(stdin);
				scanf("%s", &aux -> fone);
			    printf("\nEmail: ");
			    fflush(stdin);
				scanf("%s", &aux -> email);
	            system("pause");
	        }	        
	        aux = aux -> prox;
	    }
	    
	    if(!strcmp(nomepesq, aux -> nome)){	 
			printf("\nNome: %s",aux -> nome  );
	        printf("\nIdade: %d",aux -> idade );
	        printf("\nFone: %s",aux -> fone   );
	        printf("\nEmail: %s",aux -> email);
	        printf("\n\n");


	        printf("Digite os novos valores: \n");
			printf("\nNome: "          );
		    fflush(stdin);
			gets(&aux -> nome);
		    printf("\nIdade: ");
		    fflush(stdin);
			scanf("%i",&aux -> idade);
		    printf("\nFone: ");
		    fflush(stdin);
			scanf("%s", &aux -> fone);
		    printf("\nEmail: ");
		    fflush(stdin);
			scanf("%s", &aux -> email);
            system("pause");
        }	  
	    
	}else printf("\nAgenda vazia!");   
	
};

void ExcluiContato(struct stNo **list){
	struct stNo *aux, *p, *q;
	char nomepesq[30];
    system("cls");
    printf("\nDigite o nome do contato para exclui-lo: ");
    gets(&nomepesq);
	aux = *list;
	
	if(aux!=NULL){	
		if(!strcmp(nomepesq, aux -> nome)){			
			if(aux->prox != NULL){
				p = aux;
				aux = aux->prox;
				aux->ant = NULL;
				*list = aux;								
				free(p);				
			}else{
				*list = NULL;
				free(aux);
			}			
		}else{			
			while(aux->prox != NULL)
				aux = aux->prox;							
			
			if(!strcmp(nomepesq, aux -> nome)){
				q=aux->ant;
				q->prox=NULL;				
				free(aux);
				system("pause");
			}else{
				aux = *list;
				while(aux->prox != NULL){
					
					if(!strcmp(nomepesq, aux -> nome)){
						q = aux->ant;
						q->prox = aux->prox;
						p= q->prox;
						p->ant = aux->ant;						
						free(aux);
						break;
					}else{											
						aux = aux->prox;						
					}
				}	
			}	
		}	
	}else printf("\nAgenda vazia!");   
};

int main(){
    char menu;
    int cont;
    struct stNo *lista, *p, *q;
    struct reg agenda;
    long int offset;
    int achei , nro;
    lista = NULL;
    system("color 0A");
    
    if ((fptr = fopen("agenda.dat","rb"))==NULL){
	    printf("\nO arquivo não pode ser aberto!");
	}else{
		while (fread(&agenda,sizeof(agenda),1,fptr)==1){		
			if(lista==NULL){
				p = cria_no();
				lista = p;
				p->prox = NULL;		
				p->ant = NULL;
				strcpy(p->nome, agenda.nome);
			    p->idade = agenda.idade;
			    strcpy(p -> fone, agenda.fone);
			    strcpy(p -> email, agenda.email);
			}else{
				p= lista;
				while(p->prox!=NULL)
					p=p->prox;
					
				q = cria_no();
				p->prox = q;
				q->prox = NULL;
				q->ant = p;
				
				strcpy(q -> nome, agenda.nome);
			    q -> idade = agenda.idade;
			    strcpy(q -> fone, agenda.fone);
			    strcpy(q -> email, agenda.email);
			};
	 	};
	 	fclose(fptr);
	}
	
	do{
		system("cls");
		fflush(stdin);
		printf("\n Menu Principal\n");
 		printf("\n A - Inserir Contato");
 		printf("\n B - Visualizar Contato");
 		printf("\n C - Alterar Contato");
 		printf("\n D - Excluir Contato");
 		printf("\n E - Sair");
 		printf("\n\nOpcao: ");
		menu=getche();
		menu=toupper(menu);
		
		switch (menu){
			case 'A':	
				system("cls");
				printf("\n Inserir Contato\n");
 				InsereContato(&lista);
 				printf("\n Pressione enter para voltar ao menu");
 				getch();
 				break;
			case 'B':	
				system("cls");
				printf("\n Visualizar Contato\n");
				VisualizaContato(&lista);				
				printf("\n Pressione enter para voltar ao menu");
				getch();
				break;	
			case 'C':	
				system("cls");
				printf("\n Alterar Contato\n");
				AlteraContato(&lista);				
				printf("\n Pressione enter para voltar ao menu");
				getch();
				break;	
			case 'D':	
				system("cls");
				printf("\n Excluir Contato\n");
                ExcluiContato(&lista);				
				printf("\n Pressione enter para voltar ao menu");
				getch();
				break;	    	 
			case 'E':
				if(lista!=NULL){
					if ((fptr = fopen("agenda.dat","wb"))==NULL){
			            printf("\n Arquivo não pode ser criado.");
			       	}else{		
						while(lista->prox != NULL){		
							strcpy(agenda.nome,lista -> nome);			            
					        agenda.idade = lista -> idade;
					        strcpy(agenda.fone,lista -> fone);
					        strcpy(agenda.email,lista -> email);					        
				            fwrite(&agenda,sizeof(agenda),1,fptr);				            
				            lista = lista -> prox;				        
					    }	        
					    strcpy(agenda.nome,lista -> nome);			            
				        agenda.idade = lista -> idade;
				        strcpy(agenda.fone,lista -> fone);
				        strcpy(agenda.email,lista -> email);	
			        	fwrite(&agenda,sizeof(agenda),1,fptr);
			        	fclose(fptr);
					}
				}else{
					remove ("agenda.dat");
				}
					printf("\nSaindo...");
					sleep(3);
					break;
			default :
				printf("\n Opcao invalida");
 				printf("\n Pressione enter para voltar ao menu");
 				getch();
		}
	}

	while (menu!='E');
	getch();
	return 0;
}
