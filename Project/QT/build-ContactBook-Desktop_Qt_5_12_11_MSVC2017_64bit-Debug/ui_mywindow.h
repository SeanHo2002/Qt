/********************************************************************************
** Form generated from reading UI file 'mywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWINDOW_H
#define UI_MYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QFormLayout *formLayout;
    QLabel *label_1;
    QLineEdit *lineEdit_1;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_new;
    QPushButton *pushButton_exp;
    QPushButton *pushButton_getin;

    void setupUi(QWidget *MyWindow)
    {
        if (MyWindow->objectName().isEmpty())
            MyWindow->setObjectName(QString::fromUtf8("MyWindow"));
        MyWindow->resize(800, 600);
        verticalLayout = new QVBoxLayout(MyWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(MyWindow);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_1 = new QLabel(MyWindow);
        label_1->setObjectName(QString::fromUtf8("label_1"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_1);

        lineEdit_1 = new QLineEdit(MyWindow);
        lineEdit_1->setObjectName(QString::fromUtf8("lineEdit_1"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_1);

        label_2 = new QLabel(MyWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(MyWindow);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_3 = new QLabel(MyWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_3 = new QLineEdit(MyWindow);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_4 = new QLabel(MyWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEdit_4 = new QLineEdit(MyWindow);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_4);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_new = new QPushButton(MyWindow);
        pushButton_new->setObjectName(QString::fromUtf8("pushButton_new"));

        horizontalLayout->addWidget(pushButton_new);

        pushButton_exp = new QPushButton(MyWindow);
        pushButton_exp->setObjectName(QString::fromUtf8("pushButton_exp"));

        horizontalLayout->addWidget(pushButton_exp);

        pushButton_getin = new QPushButton(MyWindow);
        pushButton_getin->setObjectName(QString::fromUtf8("pushButton_getin"));

        horizontalLayout->addWidget(pushButton_getin);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MyWindow);

        QMetaObject::connectSlotsByName(MyWindow);
    } // setupUi

    void retranslateUi(QWidget *MyWindow)
    {
        MyWindow->setWindowTitle(QApplication::translate("MyWindow", "MyWindow", nullptr));
        label_1->setText(QApplication::translate("MyWindow", "\345\255\270\350\231\237\357\274\232", nullptr));
        label_2->setText(QApplication::translate("MyWindow", "\347\217\255\347\264\232\357\274\232", nullptr));
        label_3->setText(QApplication::translate("MyWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_4->setText(QApplication::translate("MyWindow", "\351\233\273\350\251\261\357\274\232", nullptr));
        pushButton_new->setText(QApplication::translate("MyWindow", "\346\226\260\345\242\236", nullptr));
        pushButton_exp->setText(QApplication::translate("MyWindow", "\345\214\257\345\207\272", nullptr));
        pushButton_getin->setText(QApplication::translate("MyWindow", "\345\214\257\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWindow: public Ui_MyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWINDOW_H
