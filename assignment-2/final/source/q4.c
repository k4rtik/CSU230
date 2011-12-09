/*
 * q4.c
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

void exchange(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *A, int p, int r)
{
	int x = A[r];
	int i = p-1, j;
	for(j=p; j <= r-1; j++)
		if(A[j] <= x) {
			i++;
			exchange(&A[i],&A[j]);
		}
		exchange(&A[i+1], &A[r]);
		return i+1;
}

void quick_sort(int *A, int p, int r)
{
	int q;
	if (p<r) {
		q = partition(A, p, r);
		quick_sort(A, p, q-1);
		quick_sort(A, q+1, r);
	}
}

int main()
{
	int A[8], i;
	for (i=0; i < 8; i++) A[i] = 8-i;
	printf("\nInitial array: ");
	for (i=0; i < 8; i++) printf("%d ", A[i]);
		
	quick_sort(A, 0, 7);
	printf("\nFinal array  : ");
	
	for (i=0; i < 8; i++) printf("%d ", A[i]);
	printf("\n");
	return 0;
}
