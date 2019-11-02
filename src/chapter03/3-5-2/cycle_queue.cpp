#include <stdlib.h>
#include "cycle_queue.h"

Status Init(CycleQueue &Q)
{
	Q.base = (QElemType *) malloc(MAX_QUEUE_SIZE * sizeof(QElemType));
	if (!Q.base)
	{
		exit(OVERFLOW);
	}
	Q.front = 0;
	Q.tail = 0;
	return OK;
}

int Length(CycleQueue Q)
{
	return (Q.tail - Q.front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

Status Insert(CycleQueue &Q, QElemType e)
{
	// over
	if ((Q.tail + 1) % MAX_QUEUE_SIZE == Q.front)
	{
		return ERROR;
	}
	Q.base[Q.tail] = e;
	Q.tail = (Q.tail + 1) % MAX_QUEUE_SIZE;
	return OK;
}

Status Delete(CycleQueue &Q, QElemType &e)
{
	if (Q.front == Q.tail)
	{
		return ERROR;
	}

	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAX_QUEUE_SIZE;
	return OK;
}

Status Traverse(CycleQueue Q, void (* visit)(CycleQueue))
{
	(* visit)(Q);
	return OK;
}