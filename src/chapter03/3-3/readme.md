## 行编辑程序

需要找出从入口到出来的可达路径，如图所示

<img src="https://raw.githubusercontent.com/dengjili/data_structure/master/picture/chapter03/3-3/1.png" width = "300" height = "300" div align=center />

******

**类型定义**

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

所有代码入口： [3.3-迷宫求解](https://github.com/dengjili/data_structure/blob/master/src/chapter03/3-3/main.cpp)

******
**测试**

<img src="https://raw.githubusercontent.com/dengjili/data_structure/master/picture/chapter03/3-3/2.png" width = "700" height = "250" div align=center />
