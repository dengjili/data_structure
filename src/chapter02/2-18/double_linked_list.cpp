#include <stdlib.h>
#include "double_linked_list.h"

Status Init(DuLinkList &L)
{
	L = (DuLinkList)malloc(sizeof(DuLNode));
	L->prior = L;
	L->next = L;
	return OK;
}

DuLNode * Get(DuLinkList L, int i)
{
	// 只有头结点
	if (i == 1)
	{
		return L;
	}

	DuLinkList head = L, begin = L;
	int j = 1;
	while (begin->next != head && j < i)
	{
		begin = begin->next;
		j++;
	}

	if ((begin == head) || i < 1) 
	{
		return NULL;
	}
	return begin;
}

Status Insert(DuLinkList &L, int i, ElemType e)
{
	DuLinkList node = Get(L, i);
	if (!node)
	{
		return ERROR;
	}

	DuLinkList newNode = (DuLinkList)malloc(sizeof(DuLNode));
	newNode->data = e;

	// Insert the new node into the bidirectional list
	DuLinkList next = node->next;
	// Before the link
	newNode->prior = node;
	node->next = newNode;
	// After the link
	newNode->next = next;
	next->prior = newNode;

	return OK;
}

Status Delete(DuLinkList &L, int i, ElemType &e)
{
	DuLinkList front = Get(L, i);
	if (!front)
	{
		return ERROR;
	}

	DuLinkList deleteNode = front->next;
	DuLinkList next = deleteNode->next;

	e = deleteNode->data;
	front->next = next;
	next->prior = front;
	return OK;
}

void Traverse(DuLinkList L, void (* visit)(DuLinkList))
{
	(* visit)(L);
}