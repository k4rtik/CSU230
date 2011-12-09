/*
 * q13.c
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

void ins_string(char s[], char t[], int x) {
	int i, j, k;
	char *temp;
	x--;
	for( i = 0; t[i] != '\0'; i++ );
	for( k = 0; s[k] != '\0'; k++ );
	for( j = 0; s[j] != '\0'; j++) 
		temp[j] = s[x+j];
	for( j = 0; j < i; j++) 
		s[x+j] = t[j];
	j = 0;
	while (x+i+j < k+i) s[x+i+j++] = *(temp++);
	s[x+i+j] = '\0';
}

void delnchars(char s[], int n, int x) {
	int i, j;
	x--;
	for( i = 0; s[i] != '\0'; i++ );
	for( j = x; j-x < i-n-x; j++ )
		s[j] = s[j+n];
	s[i-n] = '\0';
}

int main ()
{
	char str1[2*MAX], str2[MAX];
	int i, x, n;

	printf("Enter the main string: ");
	i = 0;
	while ((str1[i++] = getchar()) != '\n');
	str1[i-1] = '\0';

	printf("Enter the sub-string: ");
	i = 0;
	while ((str2[i++] = getchar()) != '\n');
	str2[i-1] = '\0';

	printf("Enter the position to insert sub-string to main string: ");
	scanf("%d", &x);
	ins_string(str1, str2, x);

	printf("The main string is now:\n%s\n", str1);

	printf("Enter the number of characters and the position to delete from in the above string: ");
	scanf("%d", &n);
	scanf("%d", &x);
	delnchars(str1, n, x);

	printf("The string is now:\n%s\n", str1);

	return 0;
}

