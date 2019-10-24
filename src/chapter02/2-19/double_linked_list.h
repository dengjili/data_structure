#include "base.h"

#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_

// 所有的类型都统一定义为ElemType
typedef int ElemType;

typedef struct DuLNode
{
	ElemType data;
	struct DuLNode * prior;
	struct DuLNode * next;
}DuLNode, * DuLinkList;

Status Init(DuLinkList &L);
DuLNode * Get(DuLinkList L, int i);
Status Insert(DuLinkList &L, int i, ElemType e);
Status Delete(DuLinkList &L, int i, ElemType &e);
void Traverse(DuLinkList L, void (* visit)(DuLinkList));
	
#endif