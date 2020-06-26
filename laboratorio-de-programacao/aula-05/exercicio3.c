// 3. Entre com um nome e imprima o nome somente se a primeira letra do nome for ‘a’ (maiúscula ou minúscula).
// Gabriel Klein

#include <stdio.h>
#include <stdlib.h>

main() {
    char nome[50];
    printf("\nDigite seu nome: ");
    scanf("%s", &nome);
    if (nome[0]=='a' || nome[0]=='A') {
        printf("%s\n", nome);
    }
}