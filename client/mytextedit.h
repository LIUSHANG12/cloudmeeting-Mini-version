#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QCompleter>
#include <QStringList>
#include <QPair>
#include <QVector>

class Completer : public QCompleter
{
	Q_OBJECT
public:
	explicit Completer(QWidget* parent = nullptr);
};

class MyTextEdit  : public QWidget
{
	Q_OBJECT

public:
	MyTextEdit(QWidget *parent = nullptr);
	QString toPlainText();
	void setPlainText(QString);
	void setPlaceholderText(QString);
	void setCompleter(QStringList);
	~MyTextEdit();

private slots:
	void changeCompletion(QString);

public slots:
	void complete();

private:
	QPlainTextEdit* edit;
	Completer* completer;
	QVector<QPair<int, int>> ipspan;

	QString textUnderCursor();
	bool eventFilter(QObject*, QEvent*);
signals:
};

#endif // !MYTEXTEDIT_H
