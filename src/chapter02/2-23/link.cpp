#include <stdlib.h>
#include "link.h"

// ������pָ���ֵΪe�Ľ��,������0K;������ʧ��,�򷵻�EROR
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

// �ͷ�p��ָ���
void FreeNode(Link &p)
{
	free(p);
	p = NULL;
}

// ����һ���յ���������L
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

// ������������L,L���ٴ���
Status Destroy(LinkList &L)
{
	Clear(L);

	FreeNode(L.head);
	L.tail = NULL;
	L.len = 0;

	return OK;
}

// ����������L����Ϊ�ձ�,���ͷ�ԭ����Ľ��ռ�
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

// ��֪hָ�����������ͷ���,��s��ָ�������ڵ�һ�����֮ǰ
Status InsertFirst(Link h, Link s)
{
	s->next = h->next;
	h->next = s;
	return OK;
}

// ��֪hָ�����������ͷ���,ɾ�������еĵ�һ����㲢��q����
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

// ��ָ��s��ָ(�˴���ָ������)��һ�������������������L�����һ�����
// ֮��,���ı�����L��βָ��ָ���µ�β���
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

// ɾ����������L�е�β��㲢��q����,�ı�����L��βָ��ָ���µ�β���
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


// ��֪pָ����������L�е�һ�����,��s��ָ��������p��ָ���֮ǰ,
// ���޸�ָ��pָ���²���Ľ��
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
// ��֪Pָ����������L�е�һ�����,��s��ָ��������p��ָ���֮��,
// ���޸�ָ��pָ���²���Ľ��
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
// ��֪pָ�����������е�һ�����,��e����p��ָ���������Ԫ�ص�ֵ
Status SetCurElem(Link &p, int e)
{
	p->data.coef = e;
	return OK;
}
// ��֪Pָ�����������е�һ�����,����P��ָ���������Ԫ�ص�ֵ
ElemType getCurElem(Link p)
{
	return p->data;
}
// ����������LΪ�ձ�,�򷵻�TRUE,���򷵻�FASE
Status IsEmpty(LinkList L)
{
	return L.head->next == NULL ? TRUE : FALSE;
}
// ������������L��Ԫ�ظ���
int Length(LinkList L)
{
	return L.len;
}
// ������������L��ͷ����λ��
Position GetHead(LinkList L)
{
	return L.head;
}
// ������������L�����һ������λ��
Position GetLast(LinkList L)
{
	return L.tail;
}
// ��֪pָ����������L�е�һ�����,����p��ָ����ֱ��ǰ����λ��,
// ����ǰ��,�򷵻�NULL
Position PriorPos(LinkList L, Link p)
{
	Link head = L.head, prior = head;
	while (prior && prior->next != p)
	{
		prior = prior->next;
	}
	return prior;
}
// ��֪Pָ����������L�е�һ�����,����p��ָ����ֱ�Ӻ�̵�λ��,
// ���޺��,�򷵻�NULL
Position NextPos(LinkList L, Link p)
{
	Link head = L.head, node = head;
	while (node && node != p)
	{
		node = node->next;
	}
	return node->next;
}
// ����pָʾ��������L�е�i������λ�ò�����OK,iֵ���Ϸ�ʱ����ERROR
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
// ������������L�е�1����e���㺯�� compare()�ж���ϵ��Ԫ�ص�λ��
// ��������������Ԫ��,�򷵻�
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

// ���ζ�L��ÿ��Ԫ�ص��ú��� visit()��һ��vsit()ʧ��,�����ʧ��
void Traverse(LinkList L, void (* visit)(LinkList))
{
	(* visit)(L);
}
