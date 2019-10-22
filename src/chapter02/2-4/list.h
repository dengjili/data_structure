#include "base.h"

#ifndef _LIST_H_
#define _LIST_H_

#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 5

// 所有的类型都统一定义为ElemType
typedef int ElemType;

typedef struct
{
	ElemType * elem;
	int length;
	int size;
} List;

Status Init(List &L);
void Destory(List &L);
void Clear(List &L);
Status IsEmpty(List L);
int Length(List L);
Status Get(List L, int i, ElemType &e);
int Locate(List L, ElemType e, Status (* compare)(ElemType, ElemType));
Status Insert(List &L, int i, ElemType e);
Status Delete(List &L, int i, ElemType &e);
void Traverse(List L, void (* visit)(List));

#endif