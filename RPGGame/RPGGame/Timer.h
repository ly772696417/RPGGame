#pragma once

#include <Windows.h>

class CTimer
{
public:
	CTimer(void);
	~CTimer(void);

	//启动计数器;
	void restart();
	//停止计数器;
	float stop();
	//得到毫秒级别;
	float getTime_MS();
	//得到秒级别;
	float getTime_second();
	//得到时间（默认为秒级）;
	float getTime(){return getTime_second();}

public:
	enum TimerState
	{
		TIMER_RUNNING,
		TIMER_STOPPED
	};

	float m_Time;
	TimerState m_TimeState;
	LARGE_INTEGER	m_PerformanceCount;
};

