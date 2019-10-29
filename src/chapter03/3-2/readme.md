## 行编辑程序

当用户发现刚刚键入的一个字符是错的时,可补进一个退格符“#”,以表示前一个字符无效;如果发现当前键入的行内差错较多或难以
补救,则可以键人一个退行符“@”,以表示当前行中的字符均无效。例如,假设从终端接受了这样两行字符:

<img src="https://raw.githubusercontent.com/dengjili/data_structure/master/picture/chapter03/3-2/1.png" width = "400" height = "150" div align=center />


******

**核心代码**

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

所有代码入口：* [3.2-行编辑程序](./chapter03/3-2/main.cpp)

******
**测试**

<img src="https://raw.githubusercontent.com/dengjili/data_structure/master/picture/chapter03/3-2/2.png" width = "300" height = "130" div align=center />
