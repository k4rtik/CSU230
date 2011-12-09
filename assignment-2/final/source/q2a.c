/*
 * q2a.c
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
#define MAX 10 //one more than required number of values

int queue[MAX];
int head = 0, tail = 0;

short is_queue_empty()
{
	return (head == tail);
}

short is_queue_full()
{
	return ((head == tail+1) || (tail == MAX-1 && head==0));
}

void enqueue(int key)
{
	if (is_queue_full())
		printf("\nQueue full!");
	else {
		queue[tail] = key;
		if(tail == MAX-1) tail = 0;
		else tail = tail + 1;
	}
}

int dequeue()
{
	int key;
	if (is_queue_empty())
		printf("\nQueue empty!");
	else {
		key = queue[head];
		if(head == MAX-1) head = 0;
		else head = head + 1;
		return key;
	}
}

int main()
{
	int i;
	for (i=0; i<MAX; i++)
		queue[i] = 0;

	int key;

	printf("Enter values to enqueue (0 to exit):\n");
	while (1)
	{
		scanf("%d", &key);
		if(key==0) break;
		enqueue(key);
	}

	printf("Now dequeuing all the values:\n");
	while(!is_queue_empty()) {
		printf("%d\n", dequeue());
	}

	return 0;
}
