#include "calender.h"

calender::calender(QWidget *parent)
    : QWidget(parent)
{
    Calendar=new QCalendar();
    LineEdit=new QLineEdit(QStringLiteral("輸入密碼:"));
    SpinBox=new QSpinBox();
    DoubleSpinBox=new QDoubleSpinBox();
    Slider=new QSlider();
    Slider->setOrientation(Qt::Horizontal);//設定滑塊的橫豎
    ScrollBar=new QScrollBar();
    ScrollBar->setOrientation(Qt::Horizontal);//設定滑塊的橫豎
    ComboBox=new QComboBox();
    FontComboBox=new QFontComboBox();
    DateEdit=new QDateEdit(QDate::currentDate(),this);
    TimeEdit=new QTimeEdit(QTime::currentTime(),this);
    DateTimeEdit=new QDateTimeEdit(QDateTime::currentDateTime(),this);
    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(LineEdit,0,0,1,1);
    gridLayout->addWidget(SpinBox,1,0,1,1);
    gridLayout->addWidget(SpinBox,2,0,1,1);
    gridLayout->addWidget(DoubleSpinBox,3,0,1,1);
    gridLayout->addWidget(Slider,4,0,1,1  );
    gridLayout->addWidget(ScrollBar,5,0,1,1);
    gridLayout->addWidget(ComboBox,6,0,1,1);
    gridLayout->addWidget(FontComboBox,7,0,1,1);
    gridLayout->addWidget(DateEdit,8,0,1,1);
    gridLayout->addWidget(TimeEdit,9,0,1,1);
    gridLayout->addWidget(DateTimeEdit,10,0,1,1);
    setLayout(gridLayout);
    setWindowTitle(QStringLiteral("內建對話盒展示"));
}

calender::~calender()
{
}

