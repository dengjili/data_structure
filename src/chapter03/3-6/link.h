#include "base.h"
#include "event.h"

#ifndef _LINK_H_
#define _LINK_H_

// ���е����Ͷ�ͳһ����ΪElemType
typedef Event ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode * next;
} LNode, * Link, * Position;

typedef struct 
{
	Link head, tail;
	int len;
} LinkList;

// �¼��������ͣ���������
typedef LinkList EventList;

Status MakeNode(Link &p, ElemType e);
void FreeNode(Link &p);
Status Init(LinkList &L);
Status Destroy(LinkList &L);
Status Clear(LinkList &L);
Status InsertFirst(Link h, Link s);
Status DeleteFirst(Link h, Link &q);
Status Append(LinkList &L, Link s);
Status Remove(LinkList &L, Link &q);
Status InsertBefore(LinkList &L, Link &p, Link s);
Status InsertAfter(LinkList &L, Link &p, Link s);
Status SetCurElem(Link &p, ElemType e);
ElemType getCurElem(Link p);
Status IsEmpty(LinkList L);
int Length(LinkList L);
Position GetHead(LinkList L);
Position GetLast(LinkList L);
Position PriorPos(LinkList L, Link p);
Position NextPos(LinkList L, Link p);
Status LocatePos(LinkList L, int i, Link &p);
Position LocateElem(LinkList L, ElemType e, Status (* compare)(ElemType, ElemType));
void Traverse(LinkList L, void (* visit)(LinkList));
Status OrderInsert(LinkList &L, ElemType e, int (* cmp)(ElemType, ElemType);

#endif