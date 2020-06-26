// 2. Crie um programa que calcula o comprimento de uma string (não use a função strlen).
// Gabriel Klein
#include <stdio.h>
#include <string.h>

int contar (char *str);

main() {
    char nome[50];
    int comprimento;
    printf("\nDigite seu nome: ");
    gets(nome);
    comprimento = contar(nome);

    printf("%s contem %d caracteres\n", nome, comprimento);
}
    int contar (char *str) {
        int total=0;
        while (str[total] != '\0')
        total++;

    return total;
    }
