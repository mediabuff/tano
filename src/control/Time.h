#ifndef TANO_TIME_H_
#define TANO_TIME_H_

#include <QTimer>
#include <QList>

#include "../recorder/Timer.h"

class Time : public QObject {
Q_OBJECT
public:
	Time();
	virtual ~Time();

	void addTimer(const Timer *t);
	void removeTimer(const Timer *t);

signals:
	void startTimer(const Timer*);
	void stopTimer(const Timer*);

private slots:
	void check();

private:
	QTimer *time;
	QList<const Timer*> timersList;
};

#endif // TANO_TIME_H_
