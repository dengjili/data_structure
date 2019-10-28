#include <stdlib.h>
#include "link.h"

// 分配由p指向的值为e的结点,并返回0K;若分配失败,则返回EROR
Status MakeNode(Link &p, ElemType e)
{
	p = (Link)malloc(sizeof(LNode));
	if (!p)
	{
		return ERROR;
	}

	p->data = e;
	p->next = NULL;
	return OK;
}

// 释放p所指结点
void FreeNode(Link &p)
{
	free(p);
	p = NULL;
}

// 构造一个空的线性链表L
Status Init(LinkList &L)
{
	ElemType e;
	e.coef = 0;
	e.expn = 0;
	Status status = MakeNode(L.head, e);
	if (status == ERROR)
	{
		exit(INFESIBLE);
	}

	L.tail = L.head;
	L.len = 0;
	return OK;
}

// 销毁线性链表L,L不再存在
Status Destroy(LinkList &L)
{
	Clear(L);

	FreeNode(L.head);
	L.tail = NULL;
	L.len = 0;

	return OK;
}

// 将线性链表L重置为空表,并释放原链表的结点空间
Status Clear(LinkList &L)
{
	Link node = L.head->next;
	while (node)
	{
		Link deleteNode = node;
		node = node->next;
		free(deleteNode);
	}

	L.head->next = NULL;
	L.tail = L.head;
	L.len = 0;

	return OK;
}

// 已知h指向线性链表的头结点,将s所指结点插入在第一个结点之前
Status InsertFirst(Link h, Link s)
{
	s->next = h->next;
	h->next = s;
	return OK;
}

// 已知h指向线性链表的头结点,删除链表中的第一个结点并以q返回
Status DeleteFirst(Link h, Link &q)
{
	q = h->next;
	if (!q)
	{
		return ERROR;
	}
	h->next = q->next;
	q->next = NULL;
	return OK;
}

// 将指针s所指(彼此以指针相链)的一串结点链接在线性链表L的最后一个结点
// 之后,并改变链表L的尾指针指向新的尾结点
Status Append(LinkList &L, Link s)
{
	L.tail->next = s;

	Link node = s;
	while (node->next)
	{
		node = node->next;
	}
	L.tail = node;

	return OK;
}

// 删除线性链表L中的尾结点并以q返回,改变链表L的尾指针指向新的尾结点
Status Remove(LinkList &L, Link &q)
{
	// GetLast

	Link head = L.head;
	Link tail = L.tail;

	if (head == tail)
	{
		return ERROR;
	}

	Link node = head->next;
	while (node->next != tail)
	{
		node = node->next;
	}
	q = tail;
	tail = node;
	tail->next = NULL;
	return OK;
}


// 已知p指向线性链表L中的一个结点,将s所指结点插入在p所指结点之前,
// 并修改指针p指向新插入的结点
Status InsertBefore(LinkList &L, Link &p, Link s)
{
	Link head = L.head, prior = head;
	while (prior->next != p)
	{
		prior = prior->next;
	}

	prior->next = s;
	s->next = p;
	p = s;
	return OK;
}
// 已知P指向线性链表L中的一个结点,将s所指结点插入在p所指结点之后,
// 并修改指针p指向新插入的结点
Status InsertAfter(LinkList &L, Link &p, Link s)
{
	Link head = L.head, node = head;
	while (node != p)
	{
		node = node->next;
	}
	
	s->next = node->next;
	node->next = s;

	p = s;
	return OK;
}
// 已知p指向线性链表中的一个结点,用e更新p所指结点中数据元素的值
Status SetCurElem(Link &p, int e)
{
	p->data.coef = e;
	return OK;
}
// 已知P指向线性链表中的一个结点,返回P所指结点中数据元素的值
ElemType getCurElem(Link p)
{
	return p->data;
}
// 若线性链表L为空表,则返回TRUE,否则返回FASE
Status IsEmpty(LinkList L)
{
	return L.head->next == NULL ? TRUE : FALSE;
}
// 返回线性链表L中元素个数
int Length(LinkList L)
{
	return L.len;
}
// 返回线性链表L中头结点的位置
Position GetHead(LinkList L)
{
	return L.head;
}
// 返回线性链表L中最后一个结点的位置
Position GetLast(LinkList L)
{
	return L.tail;
}
// 已知p指向线性链表L中的一个结点,返回p所指结点的直接前驱的位置,
// 若无前驱,则返回NULL
Position PriorPos(LinkList L, Link p)
{
	Link head = L.head, prior = head;
	while (prior && prior->next != p)
	{
		prior = prior->next;
	}
	return prior;
}
// 已知P指向线性链表L中的一个结点,返回p所指结点的直接后继的位置,
// 若无后继,则返回NULL
Position NextPos(LinkList L, Link p)
{
	Link head = L.head, node = head;
	while (node && node != p)
	{
		node = node->next;
	}
	return node->next;
}
// 返回p指示线性链表L中第i个结点的位置并返回OK,i值不合法时返回ERROR
Status LocatePos(LinkList L, int i, Link &p)
{
	int len = Length(L);
	if (i < 0 || i > len)
	{
		return ERROR;
	}

	Link node = L.head;
	int j = 0;
	while (j < i)
	{
		node = node->next;
		j++;
	}
	p = node;
	return OK;
}
// 返回线性链表L中第1个与e满足函数 compare()判定关系的元素的位置
// 若不存在这样的元素,则返回
Position LocateElem(LinkList L, ElemType e, Link &h, Status (* compare)(int, int))
{
	Link node = L.head->next;
	h = L.head;
	while (node)
	{
		if ((* compare)(node->data.expn, e.expn) == TRUE)
		{
			break;
		}
		node = node->next;
		h = h->next;
	}

	return node;
}

// 依次对L的每个元素调用函数 visit()。一且vsit()失败,则操作失败
void Traverse(LinkList L, void (* visit)(LinkList))
{
	(* visit)(L);
}
