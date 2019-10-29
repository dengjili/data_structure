#include "base.h"

#ifndef _STACK_H_
#define _STACK_H_

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT_SIZE 10

#define SIZE 10

// 值含义  0：不通，1：通，2走过
typedef int MazeType[SIZE][SIZE]; 

typedef struct
{
	int x;
	int y;
}PosType;

typedef struct
{
	int ord;
	PosType seat;
	int di;
}SElemType;

typedef struct 
{
	SElemType * base;
	SElemType * top;
	int stacksize;
}Stack;

Status Init(Stack &S);
Status Destroy(Stack &S);
Status Clear(Stack &S);
Status IsEmpty(Stack S);
int Length(Stack S);
Status GetTop(Stack S, SElemType &e);
Status Push(Stack &S, SElemType e);
Status Pop(Stack &S, SElemType &e);
void Traverse(Stack S, void (* visit)(Stack));

#endif