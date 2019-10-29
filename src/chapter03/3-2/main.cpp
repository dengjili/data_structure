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
例如,当用户发现刚刚键入的一个字符是错的时,可
补进一个退格符“#”,以表示前一个字符无效;如果发现当前键入的行内差错较多或难以
补救,则可以键人一个退行符“@”,以表示当前行中的字符均无效。例如,假设从终端接
受了这样两行字符:

如何输入EOF：
Windows下使用CTRL+Z
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