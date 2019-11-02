#include "base.h"

#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef int QElemType;

typedef struct QNode
{
	QElemType data;
	struct QNode * next;
}QNode, * Queue;

typedef struct 
{
	Queue front;
	Queue tail;
}LinkQueue;

Status Init(LinkQueue &Q);
Status Destroy(LinkQueue &Q);
Status Clear(LinkQueue &Q);
Status IsEmpty(LinkQueue &Q);
int Length(LinkQueue Q);
Status GetHead(LinkQueue Q, QElemType &e);
Status Insert(LinkQueue &Q, QElemType e);
Status Delete(LinkQueue Q, QElemType &e);
Status Traverse(LinkQueue Q, void (* visit)(LinkQueue));

#endif