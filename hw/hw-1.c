// HW Question 1: Write a macro in C to find the largest among three numbers.
// Date: July 29, 2010

#include <stdio.h>
#define largest(A,B,C) ((A)>(B) ? (A)>(C)?(A):(C) : (B)>(C)?(B):(C))

main()
{
	int a, b, c;
	printf("Input three numbers: ");
	scanf("%d %d %d", &a, &b, &c);
	printf("Largest: %d\n", largest(a,b,c));
}
