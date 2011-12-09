/*
 * q15.c
 * This file is part of CSU230 Monsoon 2010 Assignment 1
 *
 * Copyright (C) 2010  Kartik Singhal and Jaseem Abid
 * (Hope you don't mind our working on a big program together.)
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
	struct node *prev, *next;
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
		tail->next->prev = tail;
		tail = tail->next;
	}
}

void delete(int key) {
	struct node *temp;
	temp = head;
	while ( temp && temp->data != key ) temp = temp->next;
	if (temp) {
		if (temp->prev) temp->prev->next = temp->next;
		else head = temp->next;
		if (temp->next) temp->next->prev = temp->prev;
		else tail = temp->prev;
		free(temp);
		printf("\nDelete operation successful!\n");
	}
	else printf("\nDelete operation unsuccessful!\n");
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
	printf("\nFrom Head to Tail: \n");
	temp = head;
	while (temp) {
		printf("%d ", temp->data);
		temp = temp->next;
	}

	printf("\nFrom Tail to Head: \n");
	temp = tail;
	while (temp) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main ()
{
	int i, n = 5, key;
	printf("Enter 5 numbers: \n");
	for(i=0; i < n; i++)
		insert();
	
	print();

	printf("Enter a value you want to search: ");
	scanf("%d", &key);
	search(key);

	do {
		printf("Enter a value you want to delete: ");
		scanf("%d", &key);

		delete(key);

		print();
	} while(head);

	return 0;
}

