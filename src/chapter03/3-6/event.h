#include "base.h"
#include "queue.h"

#ifndef _EVENT_H_
#define _EVENT_H_

typedef struct 
{
	// 事件发生时刻
	int occur_time;
	// 事件类型，0：到达事件，1：四个窗口离开
	int event_type;
} Event;

// 队列中的数据类型
typedef struct 
{
	// 到达时刻
	int arrival_time;
	// 办理时间
	int duration;
} CustomerElemType;

#endif