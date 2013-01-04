#include "Timer.h"

CTimer::CTimer(void)
{
	restart();
}

CTimer::~CTimer(void)
{
}

void CTimer::restart(){
	m_TimeState = TIMER_RUNNING;
	m_Time = 0;
	QueryPerformanceCounter(&m_PerformanceCount);
}

float CTimer::stop(){
	m_TimeState = TIMER_STOPPED;
	LARGE_INTEGER pcount;
	QueryPerformanceCounter(&pcount);

	LARGE_INTEGER counter_frequency;
	QueryPerformanceFrequency(&counter_frequency);

	LARGE_INTEGER count_diff;
	count_diff.QuadPart = pcount.QuadPart - m_PerformanceCount.QuadPart;
	float time_diff = (float) count_diff.QuadPart / (float) counter_frequency.QuadPart;

	m_Time += time_diff;

	return m_Time;
}

float CTimer::getTime_MS(){
	return getTime_second()*1000.0f;
}

float CTimer::getTime_second(){
	if (TIMER_RUNNING == m_TimeState)
	{
		LARGE_INTEGER	new_counter;
		QueryPerformanceCounter(&new_counter);

		LARGE_INTEGER	counter_frequency;
		QueryPerformanceFrequency(&counter_frequency);

		float time = (float)((new_counter.QuadPart-m_PerformanceCount.QuadPart)/counter_frequency.QuadPart);

		return time;
	}
}