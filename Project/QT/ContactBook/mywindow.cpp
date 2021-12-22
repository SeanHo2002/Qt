#include "mywindow.h"
#include "ui_mywindow.h"
#include <QFile>
#include <QDebug>
#include<QFileDialog>

//QString mFilename ="./exported.csv";//存檔的路徑
//int cou=0;
void Write(QString Filename,QString str) //QString str 寫的資料，QString Filenamet傳進去的檔案名稱
{
    QFile mFile(Filename);
    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug()<<"couldn't open file for output!";
        return ;
    }
    QTextStream out(&mFile);
    out << str;
    mFile.flush();
    mFile.close();
}

MyWindow::MyWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);//利用tableWidget產生空格，setColumnCount(4)設定此有4個變數
    QStringList colTitle;
    colTitle << QStringLiteral("學號")<<QStringLiteral("班級")<<QStringLiteral("姓名")<<QStringLiteral("電話");
    ui->tableWidget->setHorizontalHeaderLabels(colTitle);
}

MyWindow::~MyWindow()
{
    delete ui;
}


void MyWindow::on_pushButton_new_clicked()//on是自動產生的並且在這個物件被按下的時候，這個物件(槽函數)會自動執行
{
    QTableWidgetItem *inputRow1, *inputRow2, *inputRow3, *inputRow4;


    inputRow1 = new QTableWidgetItem(QString(ui->lineEdit_1->text()));//拿取使用者輸入的資料放在tables裡面
    inputRow2 = new QTableWidgetItem(QString(ui->lineEdit_2->text()));
    inputRow3 = new QTableWidgetItem(QString(ui->lineEdit_3->text()));
    inputRow4 = new QTableWidgetItem(QString(ui->lineEdit_4->text()));

    ui->tableWidget->insertRow(0); //在表單視窗元件新增一列 標號多少 從0開始 這裡放的是位置
    ui->tableWidget->setItem(0,0,inputRow1);//把tableWidget裡的東西放在指定的欄位裡
    ui->tableWidget->setItem(0,1,inputRow2);
    ui->tableWidget->setItem(0,2,inputRow3);
    ui->tableWidget->setItem(0,3,inputRow4);
}


void MyWindow::on_pushButton_exp_clicked()
{
   // QString countt=0;
    QString saveFile="";
    QString mFilename = QFileDialog::getSaveFileName(this,QString("Export filename"),".");//檔案存取

    for(int i=0;i<ui->tableWidget->rowCount();i++)//從第0列到最後一列
        {
        for(int j=0;j<ui->tableWidget->columnCount();j++)
            saveFile += ui->tableWidget->item(i,j)->text()+" ";
        saveFile+="\n";
      // cou+=1;
    }
    Write(mFilename,saveFile);
    qDebug()<<saveFile;
}




void MyWindow::on_pushButton_getin_clicked()
{
    QString fileName,i1,i2,i3,i4;
    fileName = QFileDialog::getOpenFileName(this,QStringLiteral("選擇檔案"), ".");
    QFile mFilename(fileName);

    if(!mFilename.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"couldn't open file for output!";
        return ;
    }
    QTextStream in(&mFilename);
    QTableWidgetItem *outputRow1, *outputRow2, *outputRow3, *outputRow4;



    while(!in.atEnd())//檔案內的東西讀到結束
    {

    in>>i1;in>>i2;in>>i3;in>>i4;

    outputRow1 = new QTableWidgetItem(i1);
    outputRow2 = new QTableWidgetItem(i2);
    outputRow3 = new QTableWidgetItem(i3);
    outputRow4 = new QTableWidgetItem(i4);

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,outputRow1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,outputRow2);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,outputRow3);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,outputRow4);
   // }

    }
    mFilename.close();

}

