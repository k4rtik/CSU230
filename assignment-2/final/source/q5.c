/*
 * q5.c
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
#include <limits.h>

void merge(int *A, int p, int q, int r)
{
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1+2], R[n2+2];
	for (i=1; i<=n1; i++)
		L[i] = A[p + i - 1];
	for (j=1; j<=n2; j++)
		R[j] = A[q + j];
	L[n1+1] = INT_MAX;
	R[n2+1] = INT_MAX;
	i = 1;
	j = 1;
	for (k=p; k<=r; k++)
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
}

void merge_sort(int *A, int p, int r)
{
	int q;
	if (p<r) {
		q = (p + r)/2;
		merge_sort(A, p, q);
		merge_sort(A, q+1, r);
		merge(A, p, q, r);
	}
}

int main()
{
	int A[9], i;
	for (i=1; i <= 8; i++) A[i] = 8-i+1;
	printf("\nInitial array: ");
	for (i=1; i <= 8; i++) printf("%d ", A[i]);
		
	merge_sort(A, 1, 8);
	printf("\nFinal array  : ");
	
	for (i=1; i <= 8; i++) printf("%d ", A[i]);
	printf("\n");
	return 0;
}
