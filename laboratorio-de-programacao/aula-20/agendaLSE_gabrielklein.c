/*
Crie uma agenda com as seguintes opções de MENU (Inserir Contato, Viasualizar Contato, Alterar Contato
 e Excluir Contato). * Visualizar, Alterar e Excluir Contato deve utililizar o nome do contato para encontrá-lo.
Salve o arquivo com a extensão "*.c". E, envie para correção. Não gere arquivo texto, word ou pdf para enviar.
*/
// Gabriel Klein

#include <stdio.h>
#include <stdlib.h>

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

void InsereContato(struct reg **list){
	struct reg *p,*q;
	
	if(*list==NULL){
		p = cria_no();
		*list = p;
		p->prox = NULL;
				
		printf("\nDigite o nome: ");
 		fflush(stdin);
 		gets(&p -> nome);
 		printf("Digite o endereco: ");
 		fflush(stdin);
 		gets(&p -> endereco);
 		printf("Digite o Fone: ");
 		fflush(stdin);
 		gets(&p -> fone);
 		printf("Digite o email: ");
 		fflush(stdin);
 		scanf("%s", &p -> email);
 		printf("\nContato inserido com sucesso!\n");
		   
	}else{
		p=*list;
		while(p->prox!=NULL)
			p=p->prox;
			
		q = cria_no();
		p->prox = q;
		q->prox = NULL;
		
	    printf("\nDigite o nome: ");
 		fflush(stdin);
 		gets(&q -> nome);
 		printf("Digite o endereco: ");
 		fflush(stdin);
 		gets(&q -> endereco);
 		printf("Digite o Fone: ");
 		fflush(stdin);
 		gets(&q -> fone);
 		printf("Digite o email: ");
 		fflush(stdin);
 		scanf("%s", &q -> email); 
 		printf("\nContato inserido com sucesso!\n");
	};
};

void VisualizaContato(struct reg **list){
	struct reg *aux;
	char nomepesq[30];
    system("cls");
    printf("\nDigite o nome do contato para visualiza-lo: ");
    gets(&nomepesq);
	aux = *list;
	
	if(aux!=NULL){		
		while(aux->prox != NULL){	        
			if(!strcmp(nomepesq, aux -> nome)){	            
				printf("\nNome: %s",aux -> nome  );
		        printf("\nEndereco: %s",aux -> endereco );
		        printf("\nFone: %s",aux -> fone   );
		        printf("\nEmail: %s",aux -> email  );
		        printf("\n\n");
		        system("pause");
	            printf("\n\n");	 
				        
	        }
	        aux = aux -> prox;
	        printf("Nao encontrado");
	    }
	    
	    if(!strcmp(nomepesq, aux -> nome)){	            
			printf("\nNome: %s",aux -> nome  );
	        printf("\nEndereco: %s",aux -> endereco );
	        printf("\nFone: %s",aux -> fone   );
	        printf("\nEmail: %s",aux -> email  );
	        printf("\n\n");
	        system("pause");
            printf("\n\n");	     
			         
        }
         
	}else printf("\nAgenda vazia!");   
	
};

void AlteraContato(struct reg **list){
	struct reg *aux;
	char nomepesq[30];
    system("cls");
    printf("\nDigite o nome do contato para altera-lo: ");
    gets(&nomepesq);
	aux = *list;
	
	if(aux!=NULL){
		while(aux->prox != NULL){	
	        if(!strcmp(nomepesq, aux -> nome)){	            	            
	        	
				printf("\nNome: %s",aux -> nome);
		        printf("\nEndereco: %s",aux -> endereco);
		        printf("\nFone: %s",aux -> fone);
		        printf("\nEmail: %s",aux -> email);
		        printf("\n\n");
		        
		        printf("Digite os novos valores: \n");
				printf("\nNome: ");
			    fflush(stdin);
				gets(&aux -> nome);
			    printf("\nEndereco: ");
			    fflush(stdin);
				gets(&aux -> endereco);
			    printf("\nFone: ");
			    fflush(stdin);
				gets(&aux -> fone);
			    printf("\nEmail: ");
			    fflush(stdin);
				scanf("%s", &aux -> email);
	            system("pause");
	        }	        
	        aux = aux -> prox;
	    }
	    
	    if(!strcmp(nomepesq, aux -> nome)){	 
			printf("\nNome: %s",aux -> nome);
	        printf("\nEndereco: %s",aux -> endereco);
	        printf("\nFone: %s",aux -> fone);
	        printf("\nEmail: %s",aux -> email);
	        printf("\n\n");
	        

	        printf("Digite os novos valores: \n");
			printf("\nNome: "          );
		    fflush(stdin);
			gets(&aux -> nome);
		    printf("\nEndereco: ");
		    fflush(stdin);
			gets(&aux -> endereco);
		    printf("\nFone: ");
		    fflush(stdin);
			gets(&aux -> fone);
		    printf("\nEmail: ");
		    fflush(stdin);
			scanf("%s", &aux -> email);
            system("pause");
        }	  
	    
	}else printf("\nAgenda vazia!");   
	
};

void ExcluiContato(struct reg **list){
	struct reg *aux, *p;
	char nomepesq[30];
    system("cls");
    printf("\nDigite o nome do contato para exclui-lo: ");
    gets(&nomepesq);
	aux = *list;
	
	if(aux!=NULL){		
		
		if(!strcmp(nomepesq, aux -> nome)){		
			if(aux->prox != NULL){
				p= aux;
				aux=aux->prox;
				*list=aux;
				free(p);	
			}else{
				*list = NULL;	
			}			
		}else{
			while(aux->prox != NULL){
				p = aux;
				aux = aux->prox;				
			}
			
			if(!strcmp(nomepesq, aux -> nome)){
				p->prox = NULL;
				free(aux);
			}else{
				aux = *list;
				while(aux->prox != NULL){
					
					if(!strcmp(nomepesq, aux -> nome)){
						p->prox = aux->prox;						
						free(aux);
						break;
					}else{					
						p = aux;
						aux = aux->prox;						
					}
				}
				
			}
			
		}	
	
	}else printf("\nAgenda vazia!");   
	
};

main() {
 int i;	
 char Menu;
 struct reg *lista;
 lista = NULL;
 system("color 0A");
    
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
 	Menu=getche();
 	Menu=toupper(Menu);
 
 	switch (Menu){
 		case 'A':	system("cls");
					printf("\n Inserir Contato\n");
 					InsereContato(&lista);
 					printf("\n Pressione enter para voltar ao menu");
 					getch();
 					break;
		case 'B':	system("cls");
					printf("\n Visualizar Contato\n");
					VisualizaContato(&lista);				
					printf("\n Pressione enter para voltar ao menu");
					getch();
					break;
 		case 'C':	system("cls");
					printf("\n Alterar Contato\n");
					AlteraContato(&lista);				
					printf("\n Pressione enter para voltar ao menu");
					getch();
					break;
 		case 'D':	system("cls");
					printf("\n Excluir Contato\n");
                    ExcluiContato(&lista);				
					printf("\n Pressione enter para voltar ao menu");
					getch();
					break;
 		case 'E': 	printf("\nSaindo...");
					sleep(3);
					break;
 		default:	printf("\n Opcao invalida");
 					printf("\n Pressione enter para voltar ao menu");
 					getch();
 		}
 	}
 	while (Menu!='E');
}
