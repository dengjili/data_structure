#include <stdio.h>


// ����n��ʾ���Ӵ�С��Ҳ���ǵڼ�������
void move(int n, char x, char y)
{
	printf("%c -> %c move size: %d\n", x, y, n);
}

// ����n��ʾ���β��뺺ŵ�ƶ����ܸ���
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