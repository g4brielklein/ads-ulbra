#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

#define tam 4

main() {
       int v[tam], maior, menor, i, pmaior, pmenor;
       
       for (i = 0; i < tam; i++) {
           printf("\n v[%d] = ", i);
           scanf("%d", &v[i]);
           if(i==0){maior=v[i];menor=v[i];}
           if(v[i] > maior) {
             maior = v[i]; 
             pmaior = i;
           }
           
           if(v[i] < menor){
             menor = v[i];
             pmenor = i;
           }
       }
       
       printf("\n O maior valor digitado foi: %d na posicao %d", maior, pmaior);
       printf("\n Menor: %d na posicao %d", menor, pmenor); 
       getch();
}
     
