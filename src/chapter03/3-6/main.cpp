#include <stdio.h>
#include <stdlib.h>
#include "link.h"
#include "event.h"

// 事件链表
EventList ev;
// 事件
Event en;
// 客户队列
LinkQueue q[5];
// 客户记录
CustomerElemType customer;
// 累计客户逗留时间，客户数
int totaltime, totalcustomernum;

// 依事件a的发生时刻<或=或>事件b的发生时刻分别返回-1或0或1
int cmp(Event a, Event b)
{
	if (a.occur_time == b.occur_time)
	{
		return 0;
	}

	return a.occur_time < b.occur_time ? -1 : 1;
}

 int MinLength(LinkQueue q[])
 {
	int index = 1;
	for (int i = 2; i <= 4; i++)
	{
		if (Length(q[index]) > Length(q[i]))
		{
			index = i;
		}
	}

	return index;
 }

void OpenForDay()
{

}
void CustomerArrived(int closetime)
{

}
void CustomerDeparture(int closetime)
{

}

void BankSimulation(int closetime)
{
	Link p;
	OpenForDay();
	while (!IsEmpty(ev))
	{
		DeleteFirst(GetHead(ev), p);
		en = getCurElem(p);
		if (en.event_type == 0)
		{
			CustomerArrived(closetime);
		}
		else 
		{
			CustomerDeparture(closetime);
		}
	}

	printf("%f\n", (float)totaltime / totalcustomernum);
}

int main()
{
	// 由于书本上的例子只有思想，实际代码是不可运行的，所以本例子不实现
	// 这里已经提供好了链表与队列的基本实现，但是由于例子中给出的BankSimulation实现有出入。

	// 这里给出可运行的思路
	// 1. 所有来银行办理业务的事件，都需要记录到EventList中，单位为Event，也就是说，每条记录都需要记录
	// 2. 有四个窗口，这里是使用队列，四个队列，单位为CustomerElemType
	// 3. 实例中，给出了两种情况，一、银行窗口还未开始，但是叫号系统以及就绪，那么需要先记录到队列中，需要加上等待时间

	// 如果你恰好需要实现本例子，如果有问题可以联系我：dengjili@outlook.com

	printf("\n");

	return 0;
}