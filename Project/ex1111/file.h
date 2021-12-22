#ifndef FILE_H
#define FILE_H

#include <QWidget>
#include <QFileDialog>//檔案選取視窗要用
QT_BEGIN_NAMESPACE
namespace Ui { class file; }
QT_END_NAMESPACE

class file : public QWidget
{
    Q_OBJECT

public:
    file(QWidget *parent = nullptr);
    ~file();

private slots:
    void on_newPushButton_clicked();
    //建立當newPushButton被點擊時函示
    void on_outPushButton_clicked();
    //建立當outPushButton被點擊時函示
    void on_inPushButton_clicked();
    //建立當inPushButton被點擊時函示
private:
    Ui::file *ui;
};
#endif // FILE_H
