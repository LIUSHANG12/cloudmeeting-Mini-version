﻿#include "netheader.h"
#include "logqueue.h"
#include <QDebug>
#include <time.h>

QUEUE_DATA<MESG> queue_send; // 发送的消息队列
QUEUE_DATA<MESG> queue_recv; // 接收的消息队列
QUEUE_DATA<MESG> audio_recv; // 接收音频的消息队列

LogQueue* logqueue = nullptr;

void log_print(const char* filename, const char* funcname, int line, const char* fmt, ...)
{
	Log* log = (Log*)malloc(sizeof(Log));
	if (log == nullptr)
	{
		qDebug() << "malloc log fail";
	}
	else
	{
		memset(log, 0, sizeof(Log));
		log->ptr = (char*)malloc(1 * KB);
		if (log->ptr == nullptr)
		{
			free(log);
			qDebug() << "malloc log.ptr fail";
			return;
		}
		else
		{
			memset(log->ptr, 0, 1 * KB);
			time_t t = time(NULL);
			int pos = 0;
			int m = strftime(log->ptr + pos, KB - 2 - pos, "%F %H:%M:%S", localtime(&t));
			pos += m;

			m = snprintf(log->ptr + pos, KB - 2 - pos, "%s:%s::%d>>>", filename, funcname, line);
			pos += m;

			va_list ap;
			va_start(ap, fmt);
			m = _vsnprintf(log->ptr + pos, KB - 2 - pos, fmt, ap);
			pos += m;
			va_end(ap);
			strcat_s(log->ptr + pos, KB - pos, "\n");
			log->len = strlen(log->ptr);
			logqueue->pushLog(log);
		}
	}
}