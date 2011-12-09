/*
 * q9.c
 * This file is part of CSU230 Monsoon 2010 Assignment 1
 *
 * Copyright (C) 2010  Kartik Singhal
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#define MAX 100

// last m in strcmpm indicates the function is manual (not library one)
int strcmpm(char *s1, char *s2) {
	for ( ; *s1 == *s2; s1++, s2++ )
		if (*s1 == '\0')
			return 0;
	return *s1 - *s2;
}

int main ()
{
	char str1[MAX], str2[MAX];
	int i;

	printf("Enter two strings (separated by Enter): ");

	i = 0;
	while ((str1[i++] = getchar()) != '\n');
	str1[i-1] = '\0';

	i = 0;
	while ((str2[i++] = getchar()) != '\n');
	str2[i-1] = '\0';

	printf("The result of strcmp is: %d\n", strcmpm(str1, str2));

	return 0;
}

