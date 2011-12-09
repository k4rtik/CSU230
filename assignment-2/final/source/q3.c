/*
 * q3.c
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
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node *nil = NULL;

struct node * search(int key)
{
	struct node *temp = nil->next;
	while (temp->data && temp->data != key)
		temp = temp->next;
	return temp;
}

void insert(struct node *temp)
{
	temp->next = nil->next;
	nil->next->prev = temp;
	nil->next = temp;
	temp->prev = nil;
}

void delete(struct node *temp)
{
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
}

void print(void) {
	struct node *temp;
	temp = nil->next;
	while (temp->data) {
		printf("%d ", temp->data);
		temp = temp->next;
	}

	printf("\n");
}

int main ()
{
	nil = (struct node *)  malloc(sizeof(struct node));
	nil->next = nil->prev = nil;

	int i, n = 5, key;
	struct node *temp;

	printf("Enter 5 numbers: \n");
	for(i=0; i < n; i++)
	{
		temp = (struct node *)  malloc(sizeof(struct node));
		scanf("%d", &(temp->data));
		insert(temp);
	}
	
	print();

	printf("Enter a value you want to search: ");
	scanf("%d", &key);
	printf("%d", (search(key)->data));

	printf("\nNow deleting values one by one:\n");
	do {
		delete(nil->next);
		print();
	} while(nil != nil->next);

	return 0;
}

