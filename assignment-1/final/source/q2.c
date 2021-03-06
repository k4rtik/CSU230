/*
 * q2.c
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

int rev_string (int ch)
{
	if ((ch = getchar()) != '\n') {
		rev_string(ch);
	}
	printf("%c", ch);
}

int main ()
{
	printf("Enter a string(s) to get the reverse form: ");
	rev_string (1);
	printf("\n");
	return 0;
}

