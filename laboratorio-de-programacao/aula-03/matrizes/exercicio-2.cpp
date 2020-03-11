#include <stdio.h>
#include <conio.h>

#define lin 7
#define col 7

main() {
	int m[lin][col], i, j;
	
	for(i = 0; i < lin; i++)
 	  for(j = 0; j < col; j++)
	    if(i == j) m[i][j] = 1;
	    else m[i][j] = 0;
	    
    for(i = 0; i < lin; i++) {
    	printf("\n");
    	for(j=0; j < col; j++)
    	printf("%2d", m[i][j]);
	}
	getch();
}
