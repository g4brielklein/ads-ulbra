// 1. Faça um programa que então leia uma string e a imprima.
// Gabriel Klein

#include <stdio.h>
#include <stdlib.h>

main() {
    char nome[50];
    printf("\nDigite uma string: ");
    scanf("%s", &nome);
    printf("\nString: %s\n", nome);
}