#ifndef RECVSOLVE_H
#define RECVSOLVE_H

#include "netheader.h"

#include <QThread>
#include <QMutex>
/*
 * 接收线程
 * 从接收队列拿取数据
 */

class RecvSolve  : public QThread
{
	Q_OBJECT

public:
	RecvSolve(QObject *par = NULL);
	~RecvSolve();
	void run() override;

signals:
	void datarecv(MESG*);

public slots:
	void stopImmediately();

private:
	QMutex m_lock;
	bool m_isCanRun;
};

#endif // !RECVSOLVE_H
