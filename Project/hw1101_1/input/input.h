#ifndef INPUT_H
#define INPUT_H
#include <QDialog>
#include <QtWidgets>

class input : public QWidget
{
    Q_OBJECT
private:
    QLineEdit* LineEdit;//建立QLineEdit指標變數
    QSpinBox* SpinBox;//建立QSpinBox指標變數
    QDoubleSpinBox* DoubleSpinBox;//建立QDoubleSpinBox指標變數
    QSlider* Slider;//建立QSlider指標變數
    QScrollBar* ScrollBar;//建立QScrollBar指標變數
    QComboBox* ComboBox;//建立QComboBox指標變數
    QFontComboBox* FontComboBox;//建立QFontComboBox指標變數
    QDateEdit* DateEdit;//建立QDateEdit指標變數
    QTimeEdit* TimeEdit;//建立QTimeEdit指標變數
    QDateTimeEdit* DateTimeEdit;//建立QDateTimeEdit指標變數
    QCalendarWidget* Calendar;//建立QCalendarWidget指標變數
public:
    input(QWidget *parent = nullptr);
    ~input();
};
#endif // INPUT_H
