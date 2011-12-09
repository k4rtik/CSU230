/*
 * q8.c
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
	int arr[MAX], n, i, j, tmp;
	printf("Enter the length of sequence you want to sort (less than %d): ", MAX);
	scanf("%d", &n);
	printf("Enter %d numbers: ", n);
	for (i=0; i<n; i++) scanf("%d", &arr[i]);

	for (i = 0; i < n; i++) {
		for (j = 1; j < n - i; j++) {
			if (arr[j-1] > arr[j]) {
				tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}
	printf("\nThe [bubble] sorted sequence follows:\n");

	for (i=0; i<n; i++) printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

