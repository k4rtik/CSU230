/*
 * q5.c
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

/* 
 * This is a modified and improved version of a similar program by
 * Frank Ruskey & Joe Sawada. The original version can be found at:
 * http://theory.cs.uvic.ca/inf/perm/PermInfo.html
 */

#include <stdio.h>

int n;
int permutation[100];

void print_perm() {
	int i;
	for (i = 1; i <= n; i++)
		printf("%c", permutation[i]);
	printf("\n");
}

void swap(int i, int j) {
	int tmp;
	tmp = permutation[i];
	permutation[i] = permutation[j];
	permutation[j] = tmp;
}

int next_perm() {
	int k, j, r, s;

	k = n - 1;
	while (permutation[k] >= permutation[k+1]) k--;
	if (k == 0) return 0;
	else {
		j = n;
		while (permutation[k] >= permutation[j]) j--;
		swap(j, k);
		r = n; s = k+1;
		while (r > s) {
			swap(r, s);
			r--; s++;
		}
	}
	print_perm();
	return 1;
}

void sort() {
	int i, j, tmp;
	for (i = 1; i <= n; i++ )
		for (j = 1; j <= n-i; j++)
			if (permutation[j] > permutation[j+1]) {
				tmp = permutation[j];
				permutation[j] = permutation[j+1];
				permutation[j+1] = tmp;
			}
}

int main ()
{
	int i=0;

	printf("Enter n: ");
	scanf("%d", &n);

	if  (n <= 0) return 1;

	printf("Enter the string: ");
	while (i <= n) permutation[i++] = getchar();

	printf("\n");
	sort(); //Sorting required for implementing lexicographic ordering method.
	print_perm();
	
	while(next_perm());
	printf("\n");
	return 0;
}

