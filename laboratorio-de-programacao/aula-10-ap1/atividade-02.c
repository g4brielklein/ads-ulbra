#include <stdio.h>
#include <locale.h>
#define size 2

struct aluno {
	char nome[30];
	double nota_g1, nota_g2;
	int qtd_presenca;
}turma[size];

main() {
	setlocale(LC_ALL, "portuguese");
	int i;
	
	for(i=0;i<size;i++) {
		printf("\nDigite o nome: ");
		fflush(stdin);
		gets(turma[i].nome);
		printf("Digite a nota da G1: ");
		fflush(stdin);
		scanf("%lf", &turma[i].nota_g1);
		printf("Digite a nota da G2: ");
		fflush(stdin);
		scanf("%lf", &turma[i].nota_g2);
		printf("Digite a quantidade de presenças: ");
		fflush(stdin);
		scanf("%d", &turma[i].qtd_presenca);
	}
	
	for(i=0;i<size;i++) {
		printf("\nNome: %s\nNota da G1: %.20lf\nNota da G2: %.20lf\nQuantidade de presenças: %d\n", 
		turma[i].nome, turma[i].nota_g1, turma[i].nota_g2, turma[i].qtd_presenca);
	}
}
