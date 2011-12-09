/*
 * q7.c
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

int main ()
{
	int arr[MAX], n, i, j, key;
	printf("Enter the length of sequence you want to sort (less than %d): ", MAX);
	scanf("%d", &n);
	printf("Enter %d numbers: ", n);
	for (i=0; i<n; i++) scanf("%d", &arr[i]);

	for (j = 1; j < n; j++) {
		key = arr[j];
		i = j - 1;
		while ( i >= 0 && arr[i] >= key) {
			arr[i+1] = arr[i];
			i-=1;
		}
		arr[i+1] = key;
	}
	printf("\nThe [insertion] sorted sequence follows:\n");
	
	for (i=0; i<n; i++) printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

