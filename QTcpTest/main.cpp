#include "widget.h"
#include "clienttcp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    ClientTCP w2;
    w2.show();

    return a.exec();
}
