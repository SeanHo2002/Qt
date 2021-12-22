#include "widget_ex.h"

widget_ex::widget_ex(QWidget *parent)
    : QWidget(parent)
{
    QWidget *window = new QWidget;//建立QWidget指標變數並設定記憶體位置
    QHBoxLayout *layout = new QHBoxLayout;//建立QHBoxLayout指標變數並設定記憶體位置
    spinBox=new QSpinBox();//設定記憶體位置
    slider=new QSlider();//設定記憶體位置
    window->setWindowTitle("輸入年紀");//設定window變數(視窗)的視窗名子
    slider->setOrientation(Qt::Horizontal);//設定記憶體位置並把Slider方向轉為橫向
    layout->addWidget(spinBox);//將spinBox新增到layout裡
    layout->addWidget(slider);//將slider新增到layout裡
    window->setLayout(layout);//將window的版型設定成layout
    window->show();//將window顯示出來
    connect(spinBox,SIGNAL(valueChanged(int)),this,SLOT(setValue()));
    //當spinBox數值變動時，執行setValue()
    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(setValue()));
    //當slider被捲動動時，執行setValue()
}
void widget_ex:: setValue(){
    this->spinBox->setValue(this->slider->value());
    //將spinBox的值設定成slider的值
    this->slider->setValue(this->spinBox->value());
    //將slider的值設定成spinBox的值
}
widget_ex::~widget_ex()
{
}

