/*
 * q4.c
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

static short int count = 0;

int input (int ch)
{
	count++;
	if ((ch = getchar()) == '\n') {
		count--;
		return input(1);
	}
	else if (ch == ' ') 
		return count;
	else return input(1);
}


int main ()
{
	printf("Enter the string: ");
	printf("The space character was encountered at position %d.\n", input(1));
	return 0;
}

