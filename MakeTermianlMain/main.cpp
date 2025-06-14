#include <QApplication>
#include "TerminalWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TerminalWindow w;
    w.show();
    return a.exec();
}
