#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include "netheader.h"

#include <QThread>
#include <QTcpSocket>
#include <QMutex>
#ifndef MB
#define MB (1024 * 1024)
#endif // !MB

typedef unsigned char uchar;

class MyTcpSocket  : public QThread
{
	Q_OBJECT

public:
	MyTcpSocket(QObject *par = NULL);
	~MyTcpSocket();
	bool connectToServer(QString, QString, QIODevice::OpenModeFlag);
	QString errorString();
	void disconnectFromHost();
	quint32 getlocalip();

private slots:
	bool connectServer(QString, QString, QIODevice::OpenModeFlag);
	void sendData(MESG*);
	void closeSocket();

public slots:
	void recvFromSocket();
	void stopImmediately();
	void errorDetect(QAbstractSocket::SocketError error);

signals:
	void socketerror(QAbstractSocket::SocketError);
	void sendTextOver();

private:
	void run() override;
	qint64 readn(char*, quint64, int);
	QTcpSocket* _socktcp;
	QThread* _sockThread;
	uchar* sendbuf;
	uchar* recvbuf;
	quint64 hasrecvive;

	QMutex m_lock;
	volatile bool m_isCanRun;
};

#endif // !MYTCPSOCKET_H
