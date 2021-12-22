#include "input.h"

input::input(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout* gridLayout=new QGridLayout;//建立QGridLayout指標變數並設定記憶體位置
    LineEdit=new QLineEdit();//設定記憶體位置
    SpinBox=new QSpinBox();//設定記憶體位置
    DoubleSpinBox=new QDoubleSpinBox();//設定記憶體位置
    Slider=new QSlider();//設定記憶體位置
    ScrollBar=new QScrollBar();//設定記憶體位置
    Slider->setOrientation(Qt::Horizontal);//設定記憶體位置並把Slider方向轉為橫向
    ScrollBar->setOrientation(Qt::Horizontal);//設定記憶體位置並把ScrollBar方向轉為橫向
    ComboBox=new QComboBox();//設定記憶體位置
    FontComboBox=new QFontComboBox();//設定記憶體位置
    DateEdit=new QDateEdit(QDate::currentDate(),this);//設定記憶體位置並設定初始顯示當下日期
    TimeEdit=new QTimeEdit(QTime::currentTime(),this);//設定記憶體位置並設定初始顯示當下時間
    DateTimeEdit=new QDateTimeEdit(QDateTime::currentDateTime(),this);//設定記憶體位置並設定初始顯示當下日期時間
    Calendar=new QCalendarWidget();//設定記憶體位置
    gridLayout->addWidget(LineEdit,0,0,1,1);//將LineEdit設定為gridLayout的0,0位置
    gridLayout->addWidget(SpinBox,1,0,1,1);//將SpinBox設定為gridLayout的1,0位置
    gridLayout->addWidget(DoubleSpinBox,2,0,1,1);//將DoubleSpinBox設定為gridLayout的2,0位置
    gridLayout->addWidget(Slider,3,0,1,1);//將Slider設定為gridLayout的3,0位置
    gridLayout->addWidget(ScrollBar,4,0,1,1);//將ScrollBar設定為gridLayout的4,0位置
    gridLayout->addWidget(ComboBox,5,0,1,1);//將ComboBox設定為gridLayout的5,0位置
    gridLayout->addWidget(FontComboBox,6,0,1,1);//將FontComboBox設定為gridLayout的6,0位置
    gridLayout->addWidget(DateEdit,7,0,1,1);//將DateEdit設定為gridLayout的7,0位置
    gridLayout->addWidget(TimeEdit,8,0,1,1);//將TimeEdit設定為gridLayout的8,0位置
    gridLayout->addWidget(DateTimeEdit,9,0,1,1);//將DateTimeEdit設定為gridLayout的9,0位置
    gridLayout->addWidget(Calendar,10,0,1,1);//將Calendar設定為gridLayout的10,0位置
    setLayout(gridLayout);//設定gridLayout
}

input::~input()
{
}

