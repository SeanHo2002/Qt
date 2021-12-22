#include "calender.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    calender w;
    w.show();
    return a.exec();
}
