#ifndef SENDTEXT_H
#define SENDTEXT_H

#include "netheader.h"

#include <QThread>
#include <QMutex>
#include <QQueue>

struct M
{
	QString str;
	MSG_TYPE type;

	M(QString s, MSG_TYPE e)
	{
		str = s;
		type = e;
	}
};

class SendText  : public QThread
{
	Q_OBJECT

public:
	SendText(QObject *par = NULL);
	~SendText();

public slots:
	void push_Text(MSG_TYPE, QString str = "");
	void stopImmediately();

private:
	QQueue<M> textqueue;
	QMutex textqueue_lock; // 队列锁
	QWaitCondition queue_waitCond;
	void run() override;
	QMutex m_lock;
	bool m_isCanRun;
};

#endif // !SENDTEXT_H
