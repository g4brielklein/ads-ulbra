#include <stdio.h>
#include <conio.h>
#define TAM 5

int Pilha_Procura(int *P,int T, int V){
	int i,pos=-1;
	if (T>=0)
		for(i=0;i<=T;i++)
			if(P[i]==V)
				pos=i;
	return pos;	
};

int Pilha_Exclui( int *P, int T){
	if (T<0)
		printf("\nPilha Vazia");
	else
	    T--;
	return T;
};


int Pilha_Inclui (int *P, int T, int V){
	if(T>=TAM-1)
		printf("\nPilha Cheia");
	else
		P[++T]=V;
	return T;
};

void Pilha_Mostra (int *P, int T){
	int i;
	if(T>-1){
	 for(i=T; i>=0; i--)
	    printf("\nP[%d]=%d",i,P[i]);
 };
};

int main(){
 int Pilha[TAM],Topo=-1,Pos;
 	Topo=Pilha_Inclui(Pilha,Topo, 10);
  	Topo=Pilha_Inclui(Pilha,Topo, 20);
	Topo=Pilha_Inclui(Pilha,Topo, 30);
	Topo=Pilha_Inclui(Pilha,Topo, 40);
	Topo=Pilha_Inclui(Pilha,Topo, 50);
	Pilha_Mostra(Pilha,Topo);
	Topo=Pilha_Exclui(Pilha,Topo);
	printf("\n");
	system("pause");
	system("cls");
	Pilha_Mostra(Pilha,Topo);
	Topo=Pilha_Inclui(Pilha,Topo, 60);
	printf("\n");
	system("pause");
	system("cls");
	Pilha_Mostra(Pilha,Topo);

}

