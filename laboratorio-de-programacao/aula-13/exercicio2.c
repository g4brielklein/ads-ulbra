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
#include <stdlib.h>
#include <string.h>
#define lin 4
#define col 3

void mostrar_matriz(int matriz[lin][col]) {
    int i, j;
    system("CLS");
    for(i=0;i<lin;i++) {
        printf("\n");
        for(j=0;j<col;j++) {
            printf("%3d", matriz[i][j]);
        }
    }
}

void ler_matriz(int matriz[lin][col]) {
    int i, j;
    system("CLS");
    for(i=0;i<lin;i++) {
        for(j=0;j<col;j++) {
            printf("Linha %d, coluna %d: ", i, j);
            scanf("%d", &matriz[i][j]);
        }   
    }
}

int soma_das_linhas(int matriz[lin][col]) {
    int i, j, r[lin], somal=0, maior;

    for(i=0;i<lin;i++) {
        printf("\n");
        for(j=0;j<col;j++) {
            printf("%3d", matriz[i][j]);
            somal = somal + matriz[i][j];
        }
        printf("\t= %d", somal);
        r[i] = somal;
        somal=0;
    }
    maior = r[0];
    for(i=0;i<lin;i++) {
        if (r[i] > maior) {
            maior = r[i];
        }
    }
    return maior;
}

main() {
    int matriz[lin][col];
    ler_matriz(matriz);
    mostrar_matriz(matriz);
    printf("\n\nMaior somatorio entre as linhas: %d \n\n", soma_das_linhas(matriz));
}