// Teste de soma simples
// Gabriel Klein

#include <stdio.h>

int main() {
    int a, b, r;
    printf("\nPrograma para somar dois valores\n");
    printf("\nDigite o primeiro valor: ");
    scanf("%d", &a);
    scanf("%d", &b);
    r = a + b;
    printf("\n\nResultado: %d + %d = %d\n\n", a, b, r);
    return 0;
}