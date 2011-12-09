// HW Question 2: Using pointers implement strcpy() function.
// Date: July 29, 2010

#include <stdio.h>

void strcpy(char *s2, char *s1) {
	while (*s1 != '\0')
		*s2++ = *s1++;
	*s2 = '\0';
}

main()
{
	char str1[100], str2[100];

	printf("Enter a string: ");
	scanf("%s", str1);

	strcpy(str2, str1);

	printf("\nOriginal string: %s\n", str1);
	printf("Copied string: %s\n", str2);
}
