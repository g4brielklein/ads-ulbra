#include <stdio.h>
#include <conio.h>
#define TAM 5

Fila_Exclui( int *P, int *i, int *f){
	if (*f<*i){
		printf("\nFila Vazia");
	}else{
	    ++*i;
	};
};


Fila_Inclui (int *F, int *f, int V){
	if(*f==TAM-1){
		printf("\nFila Cheia");
	}else{
		F[++*f]=V;
	};

};

void Fila_Mostra (int *F, int i, int f){
	int x;
	if(f>=0){
	 for(x=i; x<=f; x++)
	    printf("[%d]",F[x]);
 };
};

int main(){
 int Fila[TAM],inicio=0,fim=-1;
 	Fila_Inclui(Fila,&fim, 10);
  	Fila_Inclui(Fila,&fim, 20);
	Fila_Inclui(Fila,&fim, 30);
	Fila_Mostra(Fila,inicio,fim);
	printf("\n");
	system("pause");
	system("cls");
	Fila_Exclui(Fila,&inicio,&fim);
	Fila_Mostra(Fila,inicio,fim);
	printf("\n");
	system("pause");
	system("cls");
	Fila_Inclui(Fila,&fim, 60);
	Fila_Mostra(Fila,inicio,fim);
	printf("\n");
	system("pause");
	system("cls");
	
}

