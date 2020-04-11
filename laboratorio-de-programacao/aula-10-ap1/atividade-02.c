#include <stdio.h>
#include <locale.h>
#define size 2

struct aluno {
	char nome[30];
	double g1, g2, media;
	int qtd_presenca;
	int aprovado; // 0 = Não(Reprovado) | 1 = Sim(Aprovado) 
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
		scanf("%lf", &turma[i].g1);
		printf("Digite a nota da G2: ");
		fflush(stdin);
		scanf("%lf", &turma[i].g2);
		printf("Digite a quantidade de presenças: ");
		fflush(stdin);
		scanf("%d", &turma[i].qtd_presenca);
	}
	
	for (i=0;i<size;i++) {
		turma[i].media = (turma[i].g1 + turma[i].g2) / 2;
	}
	
	for (i=0;i<size;i++) {
		if (turma[i].media >= 6.0 && turma[i].qtd_presenca >= 51) {
			turma[i].aprovado = 1;
		} else {
			turma[i].aprovado = 0;
		}
	}
	
	for(i=0;i<size;i++) {
		printf("\nNome: %s\nNota da G1: %.1lf\nNota da G2: %.1lf\nQuantidade de presenças: %d\nMédia: %.1lf\nAprovado: %d\n", 
		turma[i].nome, turma[i].g1, turma[i].g2, turma[i].qtd_presenca, turma[i].media, turma[i].aprovado);
	}
}
