#include <stdio.h>

int main() {
	int a;
	long b; // Equivalent to long int b;
	long long c; // Equivalent to long long int c;
	double e;
	long double f;
	
	printf("Size of int = %ld bytes \n", sizeof(a));
	printf("Size of long int = %ld bytes \n", sizeof(b));
	printf("Size of long long int = %ld bytes \n", sizeof(c));
	printf("Size of double = %ld bytes \n", sizeof(e));
	printf("Size of long double = %ld bytes \n", sizeof(f));
	
	return 0;
}
