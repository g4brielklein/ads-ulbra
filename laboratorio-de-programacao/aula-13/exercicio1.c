/* 1. Leia o total gasto por um cliente e a opção de pagamento
desejada, envie esses dados porparâmetros para uma função
que calcula e escreve o valor total a ser pago e o valor
dasprestações, quando for o caso.
Opções de pagamento:
- à vista com 10% de desconto;
- em 2 vezes (preço da etiqueta);
- de 3 a 6 vezes com 3% de juros ao mês (somente para compras
acima de R$ 200,00).
*/
// Gabriel Klein

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calculo_parcela( float valor_gasto, int opcao) {
    if (opcao==1) {
        return (valor_gasto * 0.9);
    } else if (opcao==2) {
        return (valor_gasto / 2);
    } else if (opcao>=3&&opcao<=6) {
        return ((valor_gasto + valor_gasto*(opcao*0.03))/opcao);
    }
}

int main() {
    float valor_gasto, valor_parcela, valor_total;
    int opcao;
    printf("\nDigite o valor total gasto nas compras: ");
    scanf("%f", &valor_gasto);
    printf("\nEscolhe uma das opcoes de pagamento: ");
    printf("\n1 - Pagamento a vista");
    printf("\n2 - Pagamento parcelado em 2 vezes");
    if (valor_gasto>200.00) {
        printf("\n3 - Pagamento parcelado em 3 vezes");
        printf("\n4 - Pagamento parcelado em 4 vezes");
        printf("\n5 - Pagamento parcelado em 5 vezes");
        printf("\n6 - Pagamento parcelado em 6 vezes\n");
    };
    printf("\nOpcao: ");
    scanf("%d", &opcao);
    valor_parcela = calculo_parcela(valor_gasto, opcao);
    valor_total = opcao * valor_parcela;
    switch(opcao) {
        case 1: printf("Valor total a ser pago: %.2f \n\n", valor_parcela);
                break;
        case 2:
        case 3:
        case 4:
        case 5:       
        case 6: printf("\nPrestacoes: %d vezes de R$ %.2f \n", opcao, valor_parcela);
                printf("Valor total a ser pago: %.2f \n\n", valor_total);
                break;
        default: printf("Opcao invalida!");
    }
    return 0;
}