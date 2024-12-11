#include "widget.h"
#include "screen.h"

#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    QApplication a(argc, argv);
    Screen::init();

    Widget w;
    w.show();
    return a.exec();
}
