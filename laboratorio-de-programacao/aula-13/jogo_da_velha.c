#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define lin 3
#define col 3

void inicializa(int v[lin][col])
{
    int i, j;
    for (i = 0; i < lin; i++)
        for (j = 0; j < col; j++)
            v[i][j] = 0; // 0-vazio 1-jogador1 2-jogador2
}

void visualiza(int v[lin][col]) {
    int i, j;
    for (i = 0; i < lin; i++)
    {
        printf("\n");
        for (j = 0; j < col; j++)
            switch (v[i][j])
            {
            case 0:
                printf(" ? ");
                break;
            case 1:
                printf(" 1 ");
                break;
            case 2:
                printf(" 2 ");
                break;
            }
    };
}

void jogadores(char *j1, char *j2) {
    printf("\n Digite o nome do Jogador 1: ");
    gets(j1);
    printf("\n Digite o nome do Jogador 2: ");
    gets(j2);
}

int jogada(int v[lin][col], int c) {
    int ll, cc, jogada_boa = 0, ganhou = 0;
    do
    { // verificar se a jogada é boa
        system("CLS");
        visualiza(v);
        printf("\nJogador %i ", c);
        printf("\nDigite a linha (0-2): ");
        scanf("%d", &ll);

        printf("\nDigite a coluna (0-2): ");
        scanf("%d", &cc);
        ? se LL >= 0 e LL < lin
            ? se cc >= 0 e ll < col
            ? se v[ll][cc] == 0 está vazio
    } while (!jogada_boa);

    // verificar se ganhou, fechou uma trilha
    // se ((v[0][0]==c&&v[0][1]==c&&v[0][2]==c)||

    // ganhou = 1;
    // return ganhou;
}

main() {
    int venceu = 0, terminou = 0, controle = 1;
    char jogador1[30], jogador2[30];
    int velha[lin][col];
    inicializa(velha);
    jogadores(jogador1, jogador2);
    do
    {
        if (controle == 1)
        {
            venceu = jogada(velha, controle);
            controle = 2;
        }
        else
        {
            venceu = jogada(velha, controle);
            controle = 1;
        }
        terminou++;
        getch();
    } while (!venceu && terminou <= 9);
    if (venceu)
        if (controle == 1)
            printf("\nParabens %s voce venceu!!!", jogador2);
        else
            printf("\nParabens %s voce venceu!!!", jogador1);
    getch();
}