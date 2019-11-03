#include <stdio.h>
#include <stdlib.h>
#include "link.h"
#include "event.h"

// �¼�����
EventList ev;
// �¼�
Event en;
// �ͻ�����
LinkQueue q[5];
// �ͻ���¼
CustomerElemType customer;
// �ۼƿͻ�����ʱ�䣬�ͻ���
int totaltime, totalcustomernum;

// ���¼�a�ķ���ʱ��<��=��>�¼�b�ķ���ʱ�̷ֱ𷵻�-1��0��1
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
	// �����鱾�ϵ�����ֻ��˼�룬ʵ�ʴ����ǲ������еģ����Ա����Ӳ�ʵ��
	// �����Ѿ��ṩ������������еĻ���ʵ�֣��������������и�����BankSimulationʵ���г��롣

	// ������������е�˼·
	// 1. ���������а���ҵ����¼�������Ҫ��¼��EventList�У���λΪEvent��Ҳ����˵��ÿ����¼����Ҫ��¼
	// 2. ���ĸ����ڣ�������ʹ�ö��У��ĸ����У���λΪCustomerElemType
	// 3. ʵ���У����������������һ�����д��ڻ�δ��ʼ�����ǽк�ϵͳ�Լ���������ô��Ҫ�ȼ�¼�������У���Ҫ���ϵȴ�ʱ��

	// �����ǡ����Ҫʵ�ֱ����ӣ���������������ϵ�ң�dengjili@outlook.com

	printf("\n");

	return 0;
}