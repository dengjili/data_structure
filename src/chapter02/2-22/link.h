#include "base.h"
#include "polynomial.h"

#ifndef _LINK_H_
#define _LINK_H_

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
Status SetCurElem(Link &p, int e);
ElemType getCurElem(Link p);
Status IsEmpty(LinkList L);
int Length(LinkList L);
Position GetHead(LinkList L);
Position GetLast(LinkList L);
Position PriorPos(LinkList L, Link p);
Position NextPos(LinkList L, Link p);
Status LocatePos(LinkList L, int i, Link &p);
Position LocateElem(LinkList L, ElemType e, Link &h, Status (* compare)(int, int));
void Traverse(LinkList L, void (* visit)(LinkList));

#endif