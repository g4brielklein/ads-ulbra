#include <stdio.h>
#include <conio.h>

#define lin 10
#define col 10

main() {
	int m[lin][col], i, j, num=1;
	
	for(i = 0; i < lin; i++)
 	  for (j = 0; j < col; j++)
 	    m[i][j] = num++;
 	    
    for(i = 0; i < lin; i++) {
    	printf("\n");
    	  for(j = 0; j < col; j++)
    	    printf("%4d", m[i][j]);
	}
	getch();
}
