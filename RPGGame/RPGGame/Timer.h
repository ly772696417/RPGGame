#pragma once

#include <Windows.h>

class CTimer
{
public:
	CTimer(void);
	~CTimer(void);

	//����������;
	void restart();
	//ֹͣ������;
	float stop();
	//�õ����뼶��;
	float getTime_MS();
	//�õ��뼶��;
	float getTime_second();
	//�õ�ʱ�䣨Ĭ��Ϊ�뼶��;
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

