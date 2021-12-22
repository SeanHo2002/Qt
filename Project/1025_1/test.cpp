#include "test.h"
#include <QtPrintSupport/qprinter.h>//列印視窗需要的函式庫
#include <QtPrintSupport/qpagesetupdialog.h>//列印視窗需要的函式庫
#include <QtPrintSupport/QPrintDialog>//列印視窗需要的函式庫
#include <QtPrintSupport/QPrintPreviewDialog>//列印視窗需要的函式庫
test::test(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout* gridLayout=new QGridLayout;
    displayTextEdit=new QTextEdit(QStringLiteral("Qt的標準通用對話盒"));
    colorPushBtn=new QPushButton(QStringLiteral("顏色對話盒"));
    errorPushBtn=new QPushButton(QStringLiteral("錯誤訊息盒"));
    filePushBtn=new QPushButton(QStringLiteral("檔案對話盒"));
    fontPushBtn=new QPushButton(QStringLiteral("字體對話盒"));
    inputPushBtn=new QPushButton(QStringLiteral("輸入對話盒"));
    pagePushBtn=new QPushButton(QStringLiteral("頁面設定對話盒"));
    progressPushBtn=new QPushButton(QStringLiteral("進度對話盒"));
    printPushBtn=new QPushButton(QStringLiteral("列印對話盒"));
    gridLayout->addWidget(colorPushBtn,0,0,1,1);
    gridLayout->addWidget(errorPushBtn,0,1,1,1);
    gridLayout->addWidget(filePushBtn,0,2,1,1);
    gridLayout->addWidget(fontPushBtn,1,0,1,1);
    gridLayout->addWidget(inputPushBtn,1,1,1,1  );
    gridLayout->addWidget(pagePushBtn,1,2,1,1);
    gridLayout->addWidget(progressPushBtn,2,0,1,1);
    gridLayout->addWidget(printPushBtn,2,1,1,1);
    gridLayout->addWidget(displayTextEdit,3,0,3,3);
    setLayout(gridLayout);
    setWindowTitle(QStringLiteral("內建對話盒展示"));
    resize(400,300);
    connect(colorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(errorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(filePushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(fontPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(inputPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(pagePushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(progressPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(printPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
}
void test:: doPushBtn(){
    QPushButton* btn=qobject_cast<QPushButton*>(sender());
    if(btn==colorPushBtn){
        QPalette palette=displayTextEdit->palette();
        const QColor& color=QColorDialog::getColor(palette.color(QPalette::Base),this,QStringLiteral("設定背景顏色"));
        if(color.isValid()){
            palette.setColor(QPalette::Base,color);
            displayTextEdit->setPalette((palette));
        }
    }
    if(btn==errorPushBtn){
        QErrorMessage box(this);
        box.setWindowTitle("錯誤訊息盒");
        box.showMessage(QStringLiteral("錯誤訊息1"));
        box.showMessage(QStringLiteral("錯誤訊息2"));
        box.showMessage(QStringLiteral("錯誤訊息3"));
        box.exec();
    }
    if(btn==filePushBtn){
        QString fileName=QFileDialog::getOpenFileName(this,QStringLiteral("打開檔案"),".",QStringLiteral("任何檔案(*.*);;文字檔(*.txt);;XML檔(*.xml)"));
        displayTextEdit->setText(fileName);
    }
    if(btn==fontPushBtn){
        bool ok;
        const QFont& font=QFontDialog::getFont(&ok,displayTextEdit->font(),this,QStringLiteral("字體對話盒"));
        if(ok)displayTextEdit->setFont(font);
    }
    if(btn==inputPushBtn){//點擊輸入對話盒
        bool ok;//儲存是否輸入成功
        QString text=QInputDialog::getText(this,QStringLiteral("輸入對話盒"),QStringLiteral("輸入文字"),QLineEdit::Normal,QDir::home().dirName(),&ok);
        //建立一字串變數儲存由對話盒回傳的輸入值，新增的對話盒的標頭名稱為"輸入對話盒"，裡面有一字串顯示"輸入文字"
        if(ok&&!text.isEmpty())displayTextEdit->setText(text);//如果輸入成功將主視窗的TextEdit裡的字設定成輸入值
    }
    if(btn==pagePushBtn){//點擊頁面設定對話盒
        QPrinter printer(QPrinter::HighResolution);
        //建立一QPrinter變數(高解析)
        QPageSetupDialog* dlg=new QPageSetupDialog(&printer,this);
        //建立一PageSetupDialog指標變數並設定記憶體位置
        dlg->setWindowTitle(QStringLiteral("頁面設定方塊"));
        //設定PageSetupDialog的標頭名稱為"頁面設定方塊"
        if(dlg->exec()==QDialog::Accepted){}
    }
    if(btn==progressPushBtn){//點擊進度對話盒
        QProgressDialog progress(QStringLiteral("正在複製檔案..."),QStringLiteral("取消"),0,1000000,this);
        //建立一QProgressDialog變數並設定顯示"正在複製檔案..."，新增一按鈕"取消"，設定其進度最大為1000000
        progress.setWindowModality(Qt::WindowModal);
        //設定其形態為Qt::WindowModal
        progress.setWindowTitle(QStringLiteral("進度對話方塊"));
        //設定其標頭名稱為"進度對話方塊"
        for(int x=0;x<1000000;x++){
            progress.setValue(x);//依x值設定其進度
            qApp->processEvents();
            if(progress.wasCanceled())break;//關閉視窗
            qDebug()<<x;
        }
        progress.setValue(1000000);//設定其進度為1000000
    }
    if(btn==printPushBtn){//點擊列印對話盒
        QPrinter printer(QPrinter::HighResolution);
        //建立一QPrinter變數(高解析)
        QPrintDialog dialog(&printer,this);
        //建立一QPrintDialog變數(高解析)
        if(dialog.exec()!=QDialog::Accepted)return;
    }

}
test::~test()
{
}

