#include "base.h"
#include "queue.h"

#ifndef _EVENT_H_
#define _EVENT_H_

typedef struct 
{
	// �¼�����ʱ��
	int occur_time;
	// �¼����ͣ�0�������¼���1���ĸ������뿪
	int event_type;
} Event;

// �����е���������
typedef struct 
{
	// ����ʱ��
	int arrival_time;
	// ����ʱ��
	int duration;
} CustomerElemType;

#endif