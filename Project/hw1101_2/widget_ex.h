#ifndef WIDGET_EX_H
#define WIDGET_EX_H

#include <QWidget>
#include <QDialog>
#include <QtWidgets>
class widget_ex : public QWidget
{
    Q_OBJECT
private:
    QSpinBox* spinBox;//建立QSpinBox指標變數
    QSlider* slider;//建立QSlider指標變數
public:
    widget_ex(QWidget *parent = nullptr);
    ~widget_ex();
private slots:
    void setValue();//建立setValue函式
};
#endif // WIDGET_EX_H
