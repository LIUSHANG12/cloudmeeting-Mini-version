#ifndef PARTNER_H
#define PARTNER_H

#include <QLabel>

class Partner  : public QLabel
{
	Q_OBJECT

public:
	Partner(QWidget *parent = nullptr, quint32 = 0);
	void setpic(QImage img);
	~Partner();

signals:
	void sendip(quint32); // 发送ip

private:
	quint32 ip;

	void mousePressEvent(QMouseEvent* ev) override;
	int w;
};

#endif // !PARTNER_H
