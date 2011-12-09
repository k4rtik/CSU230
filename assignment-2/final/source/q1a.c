/*
 * q1a.c
 * This file is part of CSU230 Monsoon 2010 Assignment 2
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

int stack[MAX];
int top = -1;

short is_stack_empty()
{
	return (top==-1);
}

void push(int key)
{
	if (top < MAX-1)
		stack[++top] = key;
	else printf("\nStack overflow!");
}

int pop()
{
	if (is_stack_empty())
		printf("\nStack underflow!");
	else return stack[top--];
}

int main()
{
	int i;
	for (i=0; i<MAX; i++)
		stack[i] = 0;

	int key;

	printf("Enter values to push in stack (0 to exit):\n");
	while (1)
	{
		scanf("%d", &key);
		if(key==0) break;
		push(key);
	}

	printf("Now popping all the values:\n");
	do {
		printf("%d\n", pop());
	} while(!is_stack_empty());

	return 0;
}
