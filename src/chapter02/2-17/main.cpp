#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "linklist_array.h"

void visit(LinkList S, int head)
{
	int index = S[head].cur;
	while (index > 0)
	{
		printf("%d ", S[index].data);
		index = S[index].cur;
	}
}

Status equal(ElemType e1, ElemType e2)
{
	return e1 == e2 ? TRUE : FALSE;
}

void difference(LinkList &S1, int head)
{
	ElemType temp, tail = head;
	// A = { 1, 2, 3, 4, 5}, B = { 4, 5, 6, 7, 8}
	int m = 5, n = 5;
	// Build the first collection
	for (int j = 1; j <= 5; j++)
	{
		temp = Malloc(S1);
		S1[temp].data = j;
		S1[tail].cur = temp;
		tail = temp;
	}
	S1[tail].cur = 0;
	printf("A = { ");
	Traverse(S1, head, visit);
	printf("}\n");

	printf("B = { ");
	// Adds the second collection to the first
	for (int j = 4; j <= 8; j++)
	{
		printf("%d ", j);
		// Find if an added element exists in the collection
		int front = head, begin = S1[head].cur, end = S1[tail].cur;
		while (begin != end && S1[begin].data != j)
		{
			front = begin;
			begin = S1[begin].cur;
		}

		// Add element does not exist in the current collection, add to the collection
		if (begin == end)
		{
			temp = Malloc(S1);
			S1[temp].data = j;
			S1[temp].cur = end;
			S1[tail].cur = temp;
			tail = temp;
		}
		else
		{
			// The element already exists in the collection, delete it
			S1[front].cur = S1[begin].cur;
			Free(S1, begin);

			// Delete tail node, tail pointer needs to move forward one bit
			if (begin == tail)
			{
				tail = front;
			}
		}
	}
	printf("}\n");

	printf("(A - B) U (B - A) = { ");
	Traverse(S1, head, visit);
	printf("}\n");
}

int main()
{
	LinkList S1;
	Init(S1);
	int head = Malloc(S1);
	difference(S1, head);
	return 0;
}