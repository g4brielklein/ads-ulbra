#include <stdio.h>

int main() {
	double first, second, temp;
	printf("Enter first number: ");
	scanf("%lf", &first);
	printf("Enter second number: ");
	scanf("%lf", &second);
	
	printf("First = %.2lf\nSecond = %.2lf\n", first, second);
	
	// Value of first is assign to temp	
	temp = first;
	
	// Value of seconf os assign to first	
	first = second;
	
	// Value of temp (initial value of first) is assign to second	
	second = temp;
	
	printf("First = %.2lf\nSecond = %.2lf\n", first, second);
	
	return 0;
}
