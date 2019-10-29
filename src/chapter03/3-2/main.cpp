#include <stdio.h>
#include "stack.h"

void visit(Stack S)
{
	SElemType * p = S.base;
	while (p != S.top)
	{
		printf("%c", * p);
		p++;
	}
	printf("\n");
}



/** 
����,���û����ָոռ����һ���ַ��Ǵ��ʱ,��
����һ���˸����#��,�Ա�ʾǰһ���ַ���Ч;������ֵ�ǰ��������ڲ��϶������
����,����Լ���һ�����з���@��,�Ա�ʾ��ǰ���е��ַ�����Ч������,������ն˽�
�������������ַ�:

�������EOF��
Windows��ʹ��CTRL+Z
*/


int main()
{
	Stack S;
	Init(S);
	char c = getchar();

	while (c != EOF)
	{
		while (c != EOF && c != '\n')
		{
			if (c == '#')
			{
				Pop(S, c);
			}
			else if (c == '@')
			{
				Clear(S);
			}
			else
			{
				Push(S, c);
			}
			c = getchar();
		}
		visit(S);

		Clear(S);

		if (c != EOF)
		{
			c = getchar();
		}
	}

	Destroy(S);

	return 0;
}