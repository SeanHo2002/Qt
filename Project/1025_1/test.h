#ifndef TEST_H
#define TEST_H

#include <QDialog>
#include <QtWidgets>
class test : public QDialog
{
    Q_OBJECT

public:
    test(QWidget *parent = nullptr);
    ~test();
private:
    QTextEdit* displayTextEdit;
    QPushButton* colorPushBtn;
    QPushButton* errorPushBtn;
    QPushButton* filePushBtn;
    QPushButton* fontPushBtn;
    QPushButton* inputPushBtn;
    QPushButton* pagePushBtn;
    QPushButton* progressPushBtn;
    QPushButton* printPushBtn;
private slots:
    void doPushBtn();
};
#endif // TEST_H
