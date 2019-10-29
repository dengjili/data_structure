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
Status Destroy(Stack &S)
{
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0;
	return OK;
}
Status Clear(Stack &S)
{
	S.top = S.base;
	S.stacksize = 0;
}
Status IsEmpty(Stack S)
{
	return S.top == S.base ? TRUE : FALSE;
}
int Length(Stack S)
{
	return S.stacksize;
}
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