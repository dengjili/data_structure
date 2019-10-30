#include <stdio.h>
#include "stack.h"

void visit(Stack S)
{
	SElemType * p = S.base;
	while (p != S.top)
	{
		
	}
	printf("\n");
}

Status isNumber(SElemType c)
{
	return c >= '0' && c <= '9' ? TRUE : FALSE;
}


int char2int(char c)
{
	char * index_char = "+-*/()#";
	for (int i = 0; ; i++)
	{
		if (* (index_char + i) == c)
		{
			return i;
		}
	}
}

int char2number(char c)
{
	return c - 48;
}

char int2char(int i)
{
	char * index_char = "+-*/()#";
	return * (index_char + i);
}


Status compare(SElemType e1, SElemType e2)
{
	// > : 1、   = : 0、   < : -1  error : 2
	printf("%c  %c\n", int2char(e1), int2char(e2));
	int rules[7][7] = {{1, 1, -1, -1, -1, -1, 1},
	{1, 1, -1, -1, -1, 1, 1},
	{1, 1, 1, 1, -1, 1, 1},
	{1, 1, 1, 1, -1, 1, 1},
	{-1, -1, -1, -1, -1, 0, 2},
	{1, 1, 1, 1, 2, 1, 1},
	{-1, -1, -1, -1, -1, 2, 0}};

	return rules[e1][e2];
}

int opreate(SElemType e1, SElemType e2, SElemType symbol)
{
	int num1 = e1;
	int num2 = e2;

	int result = 0;
	switch (int2char(symbol))
	{
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		result = num1 / num2;
		break;
	}

	return result;
}

// 暂不支持两位数以上的运算
int main()
{
	// 运算符、运算数
	Stack S, S2;
	Init(S); 
	Init(S2); 

	// char * index_char = "+-*/()#";
	Push(S, char2int('#'));
	char * string = "3*(7-2)-6/3#";
	char c, temp;
	while ( (c = * string) != '#' || (temp = GetTop(S)) != char2int('#'))
	{
		if (isNumber(c))
		{
			Push(S2, char2number(c));
			string++;
		}
		else
		{
			SElemType e1;
			e1 = GetTop(S);
			switch (compare(e1, char2int(c)))
			{
			case -1:
				Push(S, char2int(c));
				string++;
				break;
			case 0:
				Pop(S, e1);
				string++;
				break;
			case 1:
				SElemType symbol;
				SElemType e2;
				Pop(S, symbol);
				Pop(S2, e2);
				Pop(S2, e1);

				int result = opreate(e1, e2, symbol);

				printf("\n\n%d\n\n", result);

				Push(S2, result);
				break;
			}
		}
	}

	SElemType e;
	e = GetTop(S2);
	printf("%s=%d\n", "3*(7-2)-6/3=", e);

	Destroy(S);

	return 0;
}