#include <stdlib.h>
#include "queue.h"

Status Init(LinkQueue &Q)
{
	Q.front = (Queue)malloc(sizeof(QNode));
	if (!Q.front)
	{
		exit(OVERFLOW);
	}
	Q.tail = Q.front;
	Q.front->next = NULL;
	return OK;
}
Status Destroy(LinkQueue &Q)
{
	while (Q.front)
	{
		Q.tail = Q.front->next;
		free(Q.front);
		Q.front = Q.tail;
	}
	return OK;
}
Status Clear(LinkQueue &Q)
{

	return OK;
}
Status IsEmpty(LinkQueue &Q)
{

	return OK;
}
int Length(LinkQueue Q)
{
	Queue node = Q.front->next;

	int len = 0;
	while (node)
	{
		node = node->next;
		len++;
	}
	return len;
}
Status GetHead(LinkQueue Q, QElemType &e)
{

	return OK;
}
Status Insert(LinkQueue &Q, QElemType e)
{
	Queue node = (Queue)malloc(sizeof(QNode));
	if (!node)
	{
		exit(OVERFLOW);
	}

	node->data = e;
	node->next = NULL;	
	Q.tail->next = node;
	Q.tail = node;
	return OK;
}
Status Delete(LinkQueue Q, QElemType &e)
{
	if (Q.front == Q.tail)
	{
		return ERROR;
	}
	Queue node = Q.front->next;
	if (node == Q.tail)
	{
		Q.tail = Q.front;
	}

	e = node->data;
	Q.front->next = node->next;
	free(node);

	return OK;
}
Status Traverse(LinkQueue Q, void (* visit)(LinkQueue))
{
	(* visit)(Q);
	return OK;
}