#pragma once

#include <QObject>
#include <QAudioInput>
#include <QIODevice>

class AudioInput  : public QObject
{
	Q_OBJECT

public:
	AudioInput(QObject *par = 0);
	~AudioInput();

public slots:
	void startCollect();
	void stopCollect();

private slots:
	void onreadyRead();
	void handleStateChanged(QAudio::State);
	QString errorString();
	void setVolumn(int);

signals:
	void audioinputerror(QString);

private:
	QAudioInput* audio;
	QIODevice* inputdevice;
	char* recvbuf;
};
