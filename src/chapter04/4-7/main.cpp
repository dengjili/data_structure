#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void visit(String T)
{
	for (int i = 1; i <= T[0]; i++)
	{
		printf("%-3c", T[i]);
	}
	printf("\n");
}

void get_next(String T, int next[])
{
	int i = 1;
	int j = 0;

	next[1] = 0;

	while (i < T[0])
	{
		if (j == 0 || T[i] == T[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}


int main()
{
	String T;
	Create(T, "bbabbxbbabbyx");
	Traverse(T, visit);

	int next[MAX_STRING_LEN + 1];
	get_next(T, next);

	for (int j = 1; j <= T[0]; j++) 
	{
		printf("%-2d ", j);
	}
	printf("\n");
	for (int j = 1; j <= T[0]; j++) 
	{
		printf("%-2d ", next[j]);
	}
	printf("\n");

	return 0;
}