#include <stdio.h>
#define size 30

struct aluno {
	int ativo;
	char nome[30];
	double g1, g2, media;
	int qtd_presenca;
	int aprovado; // 0 = Não(Reprovado) | 1 = Sim(Aprovado) 
}turma[size];

main() {
	int i;
	int total_alunos = 0;
	double soma_medias, media_turma;
	
	for (i=0;i<size;i++) {
		turma[i].ativo = 0;
	}	
	
	char Menu;
	do {
		system("cls");
		fflush(stdin);
		printf("\nMenu Principal\n");
		printf("\n A - Cadastrar aluno");
		printf("\n B - Listar todos os alunos");
		printf("\n C - Alunos em substituicao");
		printf("\n D - Alunos reprovados por falta");
		printf("\n E - Alunos com nota superior a 6,0, mas com presenca inferior a 75 porcento");
		printf("\n F - Media da turma");
		printf("\n G - Sair\n");
		printf("\n Opcao: ");
		Menu = getche();
		Menu = toupper(Menu);
		
		switch(Menu) {
			case 'A':	system("cls");
						printf("\nCadastrar um aluno\n");
						for(i=0;i<size;i++)
							if(turma[i].ativo == 0 && i<size) {
								turma[i].ativo = 1;	
								printf("\nDigite o nome: ");
								fflush(stdin);
								gets(turma[i].nome);
								printf("Digite a nota da G1: ");
								fflush(stdin);
								scanf("%lf", &turma[i].g1);
								printf("Digite a nota da G2: ");
								fflush(stdin);
								scanf("%lf", &turma[i].g2);
								printf("Digite a quantidade de presencas: ");
								fflush(stdin);
								scanf("%d", &turma[i].qtd_presenca);
								turma[i].media = (turma[i].g1 + turma[i].g2) / 2;
								if (turma[i].media >= 6.0 && turma[i].qtd_presenca >= 51) {
									turma[i].aprovado = 1;
								} else {
									turma[i].aprovado = 0;
								}
								total_alunos++;
								soma_medias = soma_medias + turma[i].media;
								break;
							};
							if (i==size)
								printf("\nTurma cheia!\n");
						printf("\nPressione qualquer tecla para voltar ao menu");
						getch();
						break;
			case 'B':	system("cls");
						printf("\nListar todos os alunos\n");
							for(i=0;i<size;i++) {
								if(turma[i].ativo == 1) {
									printf("\nNome: %s\nNota da G1: %.1lf\nNota da G2: %.1lf\nMedia final: %.1lf\nPresencas: %d\nAprovado: %d\n", 
									turma[i].nome, turma[i].g1, turma[i].g2, turma[i].media, turma[i].qtd_presenca, turma[i].aprovado);
								}
							}
						printf("\nPressione qualquer tecla para voltar ao menu");
						getch();
						break;
			case 'C':	system("cls");
						printf("\nAlunos em substituicao\n");
							for(i=0;i<size;i++) {
								if (turma[i].ativo == 1)
									if (turma[i].media < 6.0) {
										printf("\nNome: %s\nNota da G1: %.1lf\nNota da G2: %.1lf\nMedia final: %.1lf\nPresencas: %d\nAprovado: %d\n", 
										turma[i].nome, turma[i].g1, turma[i].g2, turma[i].media, turma[i].qtd_presenca, turma[i].aprovado);
									}
							}
						printf("\nPressione qualquer tecla para voltar ao menu");
						getch();
						break;
			case 'D':	system("cls");
						printf("\nAlunos reprovados por falta\n");
							for (i=0;i<size;i++) {
								if (turma[i].ativo == 1)
									if (turma[i].qtd_presenca < 51)
										printf("\nNome: %s\nNota da G1: %.1lf\nNota da G2: %.1lf\nMedia final: %.1lf\nPresencas: %d\nAprovado: %d\n", 
										turma[i].nome, turma[i].g1, turma[i].g2, turma[i].media, turma[i].qtd_presenca, turma[i].aprovado);
							}
						printf("\nPressione qualquer tecla para voltar ao menu");
						getch();
						break;
			case 'E':	system("cls");
						printf("\nAlunos com nota superior a 6,0, mas com presenca inferior a 75 porcento\n");
							for (i=0;i<size;i++) {
								if (turma[i].ativo == 1)
									if (turma[i].media >= 6.0 && turma[i].qtd_presenca < 51)
										printf("\nNome: %s\nNota da G1: %.1lf\nNota da G2: %.1lf\nMedia final: %.1lf\nPresencas: %d\nAprovado: %d\n", 
										turma[i].nome, turma[i].g1, turma[i].g2, turma[i].media, turma[i].qtd_presenca, turma[i].aprovado);
							}
						printf("\nPressione qualquer tecla para voltar ao menu");
						getch();
						break;
			case 'F':	system("cls");
						printf("\nMedia da turma\n");
							for(i=0;i<size;i++) {
								if (turma[i].ativo == 1) {
									media_turma = (soma_medias / total_alunos); 	
								}
							}
							printf("\nMedia da turma: %.1lf\n", media_turma);
						printf("\nPressione qualquer tecla para voltar ao menu");
						getch();
						break;
			case 'G':	printf("\nSaindo...");
						sleep(3);
						break;
			default:	printf("\nOpcao invalida!\n");
						printf("\nPressione qualquer tecla para voltar ao menu");
						getch();
		}		
	} while (Menu!='G');
}
