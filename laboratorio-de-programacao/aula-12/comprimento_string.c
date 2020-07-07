#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contar(char *str) {
    int total=0;
    while( str[total] != '\0')
        total++;
    return total;
}

int main() {
	char nome[50];
	int comprimento, quantid; 
	
	
	printf("Digite seu nome: ");
	gets(&nome);
	
	// Retorna o comprimento da string utilizando a funcao strlen
	printf("\nComprimento da string utilizando a funcao strlen: ");
	comprimento = strlen(nome);
	printf("%d", comprimento);
	
	// Retorna o comprimento da string NAO utilizando a funcao strlen
	printf("\n\nComprimento da string NAO utilizando a funcao strlen: ");
	quantid = contar(nome);
	printf("%d", quantid);
	return 0;
}

