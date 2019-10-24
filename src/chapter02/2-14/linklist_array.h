#include "base.h"

#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

#define MAX_SIZE 1000

// 所有的类型都统一定义为ElemType
typedef int ElemType;

typedef struct
{
	ElemType data;
	int cur;
} component, LinkList[MAX_SIZE];

Status Init(LinkList &S);
int Malloc(LinkList &S);
void Free(LinkList &S, int k);
int Locate(LinkList S, int head, ElemType e);
void Traverse(LinkList L, int head, void (* visit)(LinkList, int));

#endif