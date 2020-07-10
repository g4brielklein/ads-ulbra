// Questao 1

#include <stdio.h>
#include <stdlib.h>
#define tam 7

void cadastrarTemperaturas(double temp[tam]) {
	// Primeira funcao
	int i;
	for (i=0;i<tam;i++) {
		printf("\nDigite a temperatura do dia %i: ", i);
		fflush(stdin);
		scanf("%lf", &temp[i]);
	}
}

void calcularTemperaturaMediaSemana(double temp[tam]) {
	// Segunda funcao
	int i;
	double todas, media_semana;
	for(i=0;i<tam;i++) {
		todas = todas + temp[i];
	}
	media_semana = todas/7;	
	printf("\nMedia da semana: %.1lf\n", media_semana);
		
}

void mostrarTemperaturas(double temp[tam]) {
	// Terceira funcao
	int i;
	double todas, media_semana;
	printf("\n\nMostrando a temperatura de todos os dias:\n\n");
	for(i=0;i<tam;i++) {
		printf("\ndia %i: %.1lf graus", i, temp[i]);
		todas = todas + temp[i];
	}
	printf("\n\nMedia da semana: %.1lf", media_semana);
}

int main() {
	double temp[tam];
	int i;
	double todas, media_semana;
	
	cadastrarTemperaturas(temp);
	calcularTemperaturaMediaSemana(temp);
	mostrarTemperaturas(temp);
	
}


