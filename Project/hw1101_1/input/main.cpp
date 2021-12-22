#include "input.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    input w;
    w.show();
    return a.exec();
}
