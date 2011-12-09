/*
 * q6b.c
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
#define NOT_FOUND -1

int binary_search(int x, int a[], int low, int high)
{
	int mid = 0;
	if (low > high)
		return NOT_FOUND;
	mid = (low + high) / 2;
	if (x == a[mid])
		return mid;
	if (x < a[mid])
		return binary_search(x, a, low, mid-1);
	else
		return binary_search(x, a, mid+1, high);
}

int main ()
{
	int a[100], x, i;
	for (i=0; i < 100; i++)
		a[i] = i*5;
	printf("Enter a number to search: ");
	scanf("%d", &x);
	printf("Given number is at position: %d\n", binary_search(x, a, 0, 99));
	return 0;
}

