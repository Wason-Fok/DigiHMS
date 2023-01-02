#pragma once

#include <QObject>
#include <QBasicTimer>

class TimerEvents  : public QObject
{
	Q_OBJECT

public:
	static TimerEvents& Instance();

protected:
	void timerEvent(QTimerEvent* event) override;

private:
	TimerEvents() {};
	TimerEvents(TimerEvents&&) = delete;
	TimerEvents(const TimerEvents&) = delete;
	TimerEvents& operator=(TimerEvents&&) = delete;
	TimerEvents& operator=(const TimerEvents&) = delete;

signals:
	void timeout1Hz();
	void timeout10Hz();
	void timeout20Hz();

public slots:
	void startTimers();
	void stopTimers();

private:
	QBasicTimer m_timer1Hz;
	QBasicTimer m_timer10Hz;
	QBasicTimer m_timer20Hz;

};
