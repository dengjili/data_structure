#include <stdio.h>
#include "stack.h"

void visit(Stack S)
{
	SElemType * p = S.base;
	while (p != S.top)
	{
		printf("[%d, %d]", (* p).seat.x, (* p).seat.y);
		p++;

		if (p != S.top)
		{
			printf(" -> ");
		}
	}
	printf("\n");
}

//  0：不通，1：通，2走过
Status IsPass(MazeType maze, PosType curpos)
{
	int x = curpos.x;
	int y = curpos.y;
	int flag = maze[x][y];
	return flag == OK ? TRUE : FALSE;
}

void FootPrint(MazeType maze, PosType curpos)
{
	int x = curpos.x;
	int y = curpos.y;
	maze[x][y] = 2;
}

SElemType MakeElemType(int curstep, PosType curpos, int di)
{
	SElemType e;
	e.ord = curstep;
	e.seat.x = curpos.x;
	e.seat.y = curpos.y;
	e.di = di;
	return e;
}

// 1:：东，2：南， 3：西， 4：北
PosType NextPos(PosType curpos, int di)
{
	switch (di)
	{
	case 1:
		curpos.x++;
		break;
	case 2:
		curpos.y++;
		break;
	case 3:
		curpos.x--;
		break;
	case 4:
		curpos.y--;
		break;
	default:
		break;
	}
	return curpos;
}

// 若迷宫mze中存在从入口 start到出口end的通道,则求得一条存放在栈中(从栈底到栈
// 顶),并返回TRUE;否则返回FAsE
Status MazePath(Stack &S, MazeType maze, PosType start, PosType end )
{
	// 设定"当前位置"为"入口位置
	PosType curpos = start;	
	
	// 探索第一步
	int curstep = 1;
	do 
	{
		// 当前位置可以通过,即是未曾走到过的通道块
		if (IsPass(maze, curpos)) 
		{
			// 留下足迹
			FootPrint (maze, curpos);
			SElemType e = MakeElemType(curstep, curpos, 1);
			// 加入路径
			Push(S,e);
			// 到达终点(出口)
			if((curpos.x == end.x) && (curpos.y == end.y))
			{
				return TRUE;
			}
			// 下一位置是当前位置的东邻
			curpos = NextPos(curpos, 1);
			// 探索下一步
			curstep++;
		}
		else 
		{
			// 当前位置不能通过
			if(!IsEmpty(S))
			{
				SElemType e;
				Pop(S, e);
				while (e.di == 4 && !IsEmpty(S))
				{
					// 留下不能通过的标记,并退回一步
					maze[e.seat.x][e.seat.y] = 2;
					Pop(S,e);
				}
				if (e.di < 4)
				{
					// 换下一个方向探索
					e.di++;
					Push(S, e);
					// 设定当前位置是该新方向上的相邻块
					curpos= NextPos(e.seat, e.di);
				}
			}
		}
	} 
	while(!IsEmpty(S));
	return FALSE;
}

int main()
{
	MazeType maze;
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - 1; j++)
		{
			maze[i][j] = 1;
		}
	}

	// 初始化不通结点
	PosType pos[] = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, 8}, {0, 9},
		{1, 0}, {1, 3}, {1, 7}, {1, 9},
		{2, 0}, {2, 3}, {2, 7}, {2, 9},
		{3, 0}, {3, 5}, {3, 6}, {3, 9},
		{4, 0}, {4, 2}, {4, 3}, {4, 4}, {4, 9},
		{5, 0}, {5, 4}, {5, 9},
		{6, 0}, {6, 2}, {6, 6}, {6, 9},
		{7, 0}, {7, 2}, {7, 3}, {7, 4}, {7, 6}, {7, 7}, {7, 9},
		{8, 0}, {8, 1}, {8, 9},
		{9, 0}, {9, 1}, {9, 2}, {9, 3}, {9, 4}, {9, 5}, {9, 6}, {9, 7}, {9, 8}, {9, 9}
	};
	for (int i = 0; i < 54; i++)
	{
		maze[pos[i].x][pos[i].y] = 0;
	}



	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}


	Stack S;
	Init(S); 

	PosType start = {1, 1}, end = {8, 8};
	Status status = MazePath(S, maze, start, end);
	printf("status = %d\n", status);
	visit(S);
	
	Destroy(S);

	return 0;
}