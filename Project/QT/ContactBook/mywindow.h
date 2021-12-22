#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MyWindow; }
QT_END_NAMESPACE

class MyWindow : public QWidget
{
    Q_OBJECT

public:
    MyWindow(QWidget *parent = nullptr);
    ~MyWindow();

private slots:
    void on_pushButton_new_clicked();

    void on_pushButton_exp_clicked();

    void on_pushButton_getin_clicked();

private:
    Ui::MyWindow *ui;
};
#endif // MYWINDOW_H
