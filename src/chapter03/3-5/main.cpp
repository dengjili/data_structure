#include <stdio.h>


// 其中n表示盘子大小，也就是第几个盘子
void move(int n, char x, char y)
{
	printf("%c -> %c move size: %d\n", x, y, n);
}

// 其中n表示本次参与汉诺移动的总个数
void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		move(1, a, c);
	}
	else
	{
		hanoi(n - 1, a, c, b);
		move(n, a, c);
		hanoi(n - 1, b, a, c);
	}
}

int main()
{
	hanoi(4, 'a', 'b', 'c');

	return 0;
}