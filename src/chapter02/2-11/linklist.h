#include "base.h"

#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

// ���е����Ͷ�ͳһ����ΪElemType
typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode * next;
} LNode, * LinkList;

// ����ͷ������Ϊ�յĽ��

Status Init(LinkList &L);
Status Get(LinkList L, int i, ElemType &e);
Status Insert(LinkList &L, int i, ElemType e);
Status Delete(LinkList &L, int i, ElemType &e);
void Traverse(LinkList L, void (* visit)(LinkList));

#endif