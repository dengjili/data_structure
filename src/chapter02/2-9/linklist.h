#include "base.h"

#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

// 所有的类型都统一定义为ElemType
typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode * next;
} LNode, * LinkList;

// 链表开头是数据为空的结点

Status Init(LinkList &L);
Status Get(LinkList L, int i, ElemType &e);
Status Insert(LinkList &L, int i, ElemType e);
Status Delete(LinkList &L, int i, ElemType &e);
void Traverse(LinkList L, void (* visit)(LinkList));

#endif