#include "base.h"

#ifndef _CYCLE_QUEUE_H_
#define _CYCLE_QUEUE_H_

#define MAX_QUEUE_SIZE 100

typedef int QElemType;

typedef struct
{
	QElemType * base;
	int front;
	int tail;
}CycleQueue;

Status Init(CycleQueue &Q);
int Length(CycleQueue Q);
Status Insert(CycleQueue &Q, QElemType e);
Status Delete(CycleQueue &Q, QElemType &e);
Status Traverse(CycleQueue Q, void (* visit)(CycleQueue));

#endif