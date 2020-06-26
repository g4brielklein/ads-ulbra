/* 2. Leia uma matriz 3x4, com elementos do tipo inteiro, na função
principal;
a. envie a matrizpor parâmetro para uma função que
deverá fazer (a) a soma dos elementos de cada umadas
linhas e escrever esses resultados;
b. (b) verificar qual dos resultados é o maior eretornar este
valor ao programa principal.
c. Finalmente, na função principal, escreva o valor de
retorno da função.
*/
// Gabriel Klein

#include <stdio.h>
#define lin 4
#define col 3

int main() {
    int i, j;
    int matriz[lin][col];

    for(i=0;i<lin;i++) {
        for(j=0;j<col;j++) {
            printf("Linha %d, coluna %d": ), i, j;
            scanf("%d", matriz[j][j]);
        }   
    }

    for(i=0;i<lin;i++) {
        for(j=0;j<col;j++) {
            printf(matriz[i][j]);
        }   
    }

    return 0;
}