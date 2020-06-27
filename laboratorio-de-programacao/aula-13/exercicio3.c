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

int LerNomes(char *n1, char *n2) {
    printf("\nDigite o nome: ");
    gets(n1);
    printf("\nDigite o sobrenome: ");
    gets(n2);
}

int ComparaNomes(char *n1, char *n2) {
    int status;
    status= strcmp(n1, n2);

    if(status==0) {
        status = -1;
    } else {
        return strspn(n1, n2);
    }
}

main() {
    char nome[tam], sobrenome[tam];
    LerNomes(nome, sobrenome);
    printf("\n%s %s\n\n", nome, sobrenome);
    printf("\n%d\n\n", ComparaNomes(nome, sobrenome));
}