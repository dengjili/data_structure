#include <stdlib.h>
#include "stack.h"

Status Init(Stack &S)
{
	S.base = (SElemType *)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
	if (!S.base)
	{
		exit(OVERFLOW);
	}
	S.top = S.base;	
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
Status Destroy(Stack &S);
Status Clear(Stack &S);
Status IsEmpty(Stack S);
int Length(Stack S);
Status GetTop(Stack S, SElemType &e)
{
	if (S.base == S.top)
	{
		return ERROR;
	}
	e = * (S.top - 1);
	return OK;
}
Status Push(Stack &S, SElemType e)
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType *)realloc(S.base, sizeof(SElemType) * (S.stacksize + STACK_INCREMENT_SIZE));
		if (!S.base)
		{
			exit(OVERFLOW);
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT_SIZE;
	}

	* S.top = e;
	S.top++;

	return OK;
}
Status Pop(Stack &S, SElemType &e)
{
	if (S.base == S.top)
	{
		return ERROR;
	}
	S.top--;
	e = * S.top;
	return OK;
}
void Traverse(Stack S, void (* visit)(Stack))
{
	(* visit)(S);
}