#include <stdio.h>
#include "cycle_queue.h"

int main()
{
	CycleQueue Q;
	Init(Q);

	QElemType e;
	for (int i = 1; i <= 20; i++)
	{
		Insert(Q, i);
		Delete(Q, e);
		printf("%d ", e);
		Delete(Q, e);
	}
	printf("\n");

	return 0;
}