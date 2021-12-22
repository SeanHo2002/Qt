#ifndef CALENDER_H
#define CALENDER_H

#include <QDialog>
#include <QtWidgets>

class calender : public QWidget
{
    Q_OBJECT

public:
    calender(QWidget *parent = nullptr);
    ~calender();
private:
    QCalendar* Calendar;
    QLineEdit* LineEdit;
    QSpinBox* SpinBox;
    QDoubleSpinBox* DoubleSpinBox;
    QSlider* Slider;
    QScrollBar* ScrollBar;
    QComboBox* ComboBox;
    QFontComboBox* FontComboBox;
    QDateEdit* DateEdit;
    QTimeEdit* TimeEdit;
    QDateTimeEdit* DateTimeEdit;
};
#endif // CALENDER_H
