#include "TimerEvents.h"
#include <QTimerEvent>

TimerEvents& TimerEvents::Instance()
{
	static TimerEvents singleton;
	return singleton;
}

void TimerEvents::timerEvent(QTimerEvent* event)
{
	if (event->timerId() == m_timer1Hz.timerId())
		emit timeout1Hz();
	if (event->timerId() == m_timer10Hz.timerId())
		emit timeout10Hz();
	if (event->timerId() == m_timer20Hz.timerId())
		emit timeout20Hz();
}

void TimerEvents::startTimers()
{
	m_timer1Hz.start(1000, this);
	m_timer10Hz.start(100, this);
	m_timer20Hz.start(20, this);
}

void TimerEvents::stopTimers()
{
	m_timer1Hz.stop();
	m_timer10Hz.stop();
	m_timer20Hz.stop();
}
