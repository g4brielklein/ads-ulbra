/* 3. Escreva uma função que receba duas strings de no máximo 20
caracteres por parâmetro;
a. verifique se elas são iguais;
b. retorne -1 ao programa principal se elas forem iguais ou
oíndice do primeiro caractere não coincidente quando
elas forem diferentes.

Exemplo 01  String 1: contar            Exemplo 02  String 1: livro
            String 2: contagiar                     String 2: livro
            Retorno:     5                          Retorno:    -1     */
// Gabriel Klein

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 20

void LerNomes(char *n1, char *n2) {
    printf("\nDigite o primeiro nome: ");
    gets(n1);
    printf("\nDigite o segundo nome: ");
    gets(n2);
}

int ComparaNomes(char *n1, char *n2) {
    int status;
    status= strcmp(n1, n2);

    if(status==0) {
        return -1;
    } else {
        return strspn(n1, n2);
    }
}

int main() {
    char nome1[tam], nome2[tam];
    LerNomes(nome1, nome2);
    printf("\n%s - %s\n", nome1, nome2);
    printf("\n%d\n\n", ComparaNomes(nome1, nome2));
    return 0;
}