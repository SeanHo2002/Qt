#include "widget_ex.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    widget_ex w;
    //w.show();取消顯示空白視窗
    return a.exec();
}
