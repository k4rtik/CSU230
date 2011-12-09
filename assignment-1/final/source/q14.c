/*
 * q14.c
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
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL, *tail = NULL;

struct node * create(void) {
	struct node *temp;
	temp = (struct node *)  malloc(sizeof(struct node));
	scanf("%d", &(temp->data));
	return temp;
}

void insert(void) {
	if (head==NULL) {
		head = create();
		tail = head;
	}
	else {
		tail->next = create();
		tail = tail->next;
	}
}

void delete(void) {
	struct node *temp;
	temp = head;
	head = temp->next;
	if (!head) tail = head;
	free(temp);
}

void search(int key) {
	int pos=0;
	
	struct node *temp;
	temp = head;
	while (temp) {
		++pos;
		if (temp->data == key) break;
		temp = temp->next;
	}

	if(temp) printf("Given number found at position %d.\n", pos);
	else printf("Given number not found!\n");
}

void print(void) {
	struct node *temp;
	temp = head;
	while (temp) {
		printf("%d ", temp->data);
		temp = temp->next;
	}

	printf("\n");
}

int main ()
{
	int i, n = 5, key;
	printf("Enter 5 numbers: \n");
	for(i=0; i < n; i++)
		insert();

	printf("Enter a value you want to search: ");
	scanf("%d", &key);
	search(key);

	printf("\nNow deleting values one by one:\n");
	do {
		delete();
		print();
	} while(head);

	return 0;
}

