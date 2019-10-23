#include <stdlib.h>
#include "linklist.h"

Status Init(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	return OK;
}

Status Get(LinkList L, int i, ElemType &e)
{
	LinkList node = L->next;

	int j = 1;
	while (node && j < i) 
	{
		node = node->next;
		j++;
	}

	// �Ҳ���
	if (!node || j > i)
	{
		return ERROR;
	}

	// �ҵ�
	e = node->data;
	return OK;
}

Status Insert(LinkList &L, int i, ElemType e)
{
	LinkList node = L;

	int j = 1;
	while (node && j < i) 
	{
		node = node->next;
		j++;
	}

	// �Ƿ�,
	if (!node || j != i)
	{
		return ERROR;
	}

	LinkList newNode = (LinkList)malloc(sizeof(LNode));
	newNode->data = e;
	newNode->next = node->next;
	node->next = newNode;

	return OK;
}

Status Delete(LinkList &L, int i, ElemType &e)
{
	LinkList node = L;

	int j = 1;
	while (node->next && j < i) 
	{
		node = node->next;
		j++;
	}

	// �Ƿ�,
	if (!node->next || j != i)
	{
		return ERROR;
	}

	// ɾ�����
	LinkList deleteNode = node->next;
	node->next = deleteNode->next;
	e = deleteNode->data;
	free(deleteNode);

	return OK;
}

void Traverse(LinkList L, void (* visit)(LinkList))
{
	(* visit)(L);
}