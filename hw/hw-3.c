// HW Question 3: Write a program to find the number of 1's present in a given 16-bit variable.
// Date: July 29, 2010

#include <stdio.h>

main()
{
	short var, count=0;
	printf("Enter a character: ");
	var = getchar();

	count+=var%2;
	while (var=var/2)
		count+=var%2;

	printf("The number of 1's in the given\
 character: %d\n", count);
}
