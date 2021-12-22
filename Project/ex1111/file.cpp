#include "file.h"
#include "ui_file.h"
#include <QFile>
#include <QDebug>
QString fileName="myfile.txt";//定義匯出檔案位置及檔名
void Write(QString FileName,QString str){//自定義匯出檔案函式
    QFile mFile(FileName);//檔案存取類別QFile
    if(!mFile.open(QFile::WriteOnly|QFile::Text)){//打開檔案(唯寫)如果檔案沒打開
        qDebug()<<"could not open file";//顯示錯誤
        return;//結束函式
    }
    QTextStream out(&mFile);
    out<<str;//將內容輸出至檔案
    mFile.flush();//更新檔案
    mFile.close();//關閉檔案
}
file::file(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::file)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);//設定tableWidget的Column為4行
    QStringList colTitle;//創一整數列表(像陣列)用來儲存tableWidget的行名稱
    colTitle<<QStringLiteral("ID")<<QStringLiteral("Class")<<QStringLiteral("Name")<<QStringLiteral("PhoneNumber");
    //定義tableWidget的行名稱
    ui->tableWidget->setHorizontalHeaderLabels(colTitle);
    //設定tableWidget的行名稱
}

file::~file()
{
    delete ui;
}


void file::on_newPushButton_clicked()
{
    QTableWidgetItem *ID,*input_class,*name,*phone;
    //創4個TableWidgetItem用來儲存輸入值
    ID=new QTableWidgetItem(QString(ui->IDLineEdit->text()));
    //定義ID為輸入值
    input_class=new QTableWidgetItem(QString(ui->classLineEdit->text()));
    //定義input_class為輸入值
    name=new QTableWidgetItem(QString(ui->nameLineEdit->text()));
    //定義name為輸入值
    phone=new QTableWidgetItem(QString(ui->phoneLineEdit->text()));
    //定義phone為輸入值
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    //tableWidget新增一列，列的編號為原始列+1
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,ID);
    //設定tableWidget新增一列的值為ID
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,input_class);
    //設定tableWidget新增一列的值為input_class
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,name);
    //設定tableWidget新增一列的值為name
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,phone);
    //設定tableWidget新增一列的值為phone
}


void file::on_outPushButton_clicked()
{
    QString saveFile="";//創一字串儲存輸出值
    for(int x=0;x<ui->tableWidget->rowCount();x++){//依序讀取tableWidget列的值新增到saveFile作為輸出
        for(int y=0;y<ui->tableWidget->columnCount();y++){
            if(y==ui->tableWidget->columnCount()-1)
                saveFile+=ui->tableWidget->item(x,y)->text();
            else
                saveFile+=ui->tableWidget->item(x,y)->text()+",";
        }
        saveFile+="\n";
    }
    Write(fileName,saveFile);//將saveFile輸出至檔案
}


void file::on_inPushButton_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this,QStringLiteral("打開檔案"),".",QStringLiteral("任何檔案(*.*);;文字檔(*.txt);;XML檔(*.xml)"));
    //創一字串用來存取從選取檔案式窗輸出的檔案位置
    QFile mFile(fileName);//檔案存取類別QFile
    if(!mFile.open(QFile::ReadOnly|QFile::Text)){//打開檔案(唯讀)如果檔案沒打開
        qDebug()<<"could not open file";//顯示錯誤
        return;//結束函式
    }
    QString test;//暫存輸入值
    QTextStream in(&mFile);//輸入檔案
    while(!in.atEnd()){//一行一行將檔案內容輸入至list
        test=in.readLine();//將"此行"讀入test
        QStringList list = test.split(",");//將test用","分割並存入list
        QTableWidgetItem *ID,*input_class,*name,*phone;//創4個TableWidgetItem用來儲存輸入值
        ID=new QTableWidgetItem(list[0]);
        //定義ID為list的第1項
        input_class=new QTableWidgetItem(list[1]);
        //定義input_class為list的第2項
        name=new QTableWidgetItem(list[2]);
        //定義name為list的第3項
        phone=new QTableWidgetItem(list[3]);
        //定義phone為list的第4項
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        //tableWidget新增一列，列的編號為原始列+1
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,ID);
        //設定tableWidget新增一列的值為ID
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,input_class);
        //設定tableWidget新增一列的值為input_class
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,name);
        //設定tableWidget新增一列的值為name
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,phone);
        //設定tableWidget新增一列的值為phone
    }
    mFile.flush();//更新檔案
    mFile.close();//關閉檔案
}

