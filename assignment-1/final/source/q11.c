/*
 * q11.c
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

int strlenm(char *s)
{
	int i = 0;
	while (*s++ != '\0')
		i++;
	return i;
}

int strend(char *s, char *t) {
	if (!(*s)) return 0;
	int i = 0;
	for(; i < strlenm(t) && *(s+i)==*(t+i); i++)
		;
	if ( *(s+i)=='\0') return 1;
	else return strend(s+1, t);
}

int main ()
{
	char s[2*MAX], t[MAX];
	int i;

	printf("Enter two strings (separated by Enter): ");

	i = 0;
	while ((s[i++] = getchar()) != '\n');
	s[i-1] = '\0';

	i = 0;
	while ((t[i++] = getchar()) != '\n');
	t[i-1] = '\0';

	printf("The result of strend is: %d\n", strend(s, t));

	return 0;
}

