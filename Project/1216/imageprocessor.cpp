#include "imageprocessor.h"
#include <QHBoxLayout>
#include <QMenuBar>
#include <QFileDialog>
#include <QDebug>
#pragma execution_character_set("utf-8")
ImageProcessor::ImageProcessor(QWidget *parent)
    : QMainWindow(parent){
    setWindowTitle(QStringLiteral("ImageProcessor"));
    central=new QWidget();
    QHBoxLayout *mainLayout=new QHBoxLayout(central);
    imgWin=new QLabel();
    result=new QLabel();
    QPixmap *initPixmap=new QPixmap(300,200);
    initPixmap->fill(QColor(0,0,255));
    imgWin->resize(300,200);
    imgWin->setScaledContents(true);
    imgWin->setPixmap(*initPixmap);//把畫面(QPixmap)貼在顯示器上(QLabel)
    mainLayout->addWidget(imgWin);
    setCentralWidget(central);
    createActions();
    createMenu();
    createToolBars();
}

ImageProcessor::~ImageProcessor(){
}
void ImageProcessor::createActions(){
    enlargeAction=new QAction(QStringLiteral("EnlargeImage&B"),this);
    enlargeAction->setShortcut(tr("Ctrl+B"));
    connect(enlargeAction,SIGNAL(triggered()),this,SLOT(setImageSizeBig()));

    narrowAction=new QAction(QStringLiteral("NarrowImage&S"),this);
    narrowAction->setShortcut(tr("Ctrl+S"));
    connect(narrowAction,SIGNAL(triggered()),this,SLOT(setImageSizeSmall()));

    openFileActon=new QAction(QStringLiteral("OpenFile&O"),this);
    openFileActon->setShortcut(tr("Ctrl+O"));
    openFileActon->setStatusTip(QStringLiteral("OpenImageFile"));
    connect(openFileActon,SIGNAL(triggered()),this,SLOT(showOpenFile()));

    exitAction=new QAction(QStringLiteral("Exit&Q"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(QStringLiteral("Quit Application"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));

}
void ImageProcessor::setImageSizeBig(){
    img.load(filename);
    result->setPixmap(QPixmap::fromImage(img.scaled(img.width()*2,img.height()*2)));
    result->setWindowTitle("BiggerImg");
    result->setScaledContents(true);
    result->show();
}
void ImageProcessor::setImageSizeSmall(){
    img.load(filename);
    result->setPixmap(QPixmap::fromImage(img.scaled(img.width()/2,img.height()/2)));
    result->setWindowTitle("SmallerImg");
    result->setScaledContents(true);
    result->show();
}
void ImageProcessor::createMenu(){
    fileMenu=menuBar()->addMenu(QStringLiteral("File&F"));
    fileMenu->addAction(openFileActon);
    fileMenu->addAction(exitAction);
}
void ImageProcessor::createToolBars(){
    fileTool=addToolBar("file");
    fileTool->addAction(openFileActon);
    fileTool=addToolBar("resize");
    fileTool->addAction(enlargeAction);
    fileTool->addAction(narrowAction);
}
void ImageProcessor::loadFile(QString filename){
    qDebug()<<QString("file name:%1").arg(filename);
    QByteArray ba=filename.toLatin1();
    printf("FN:%s\n",(char *)ba.data());
    img.load(filename);
    imgWin->setPixmap(QPixmap::fromImage(img));
}
void ImageProcessor::showOpenFile(){
    filename=QFileDialog::getOpenFileName(this,QStringLiteral("OpenImage"),tr("."),"png(*.png);;Jpeg(*.jpg);;bmp(*.bmp)");
    if(!filename.isEmpty()){
        loadFile(filename);
        /*if(img.isNull())
            loadFile(filename);
        else{
            ImageProcessor *newIPWin=new ImageProcessor();
            newIPWin->loadFile(filename);
            newIPWin->show();
        }*/
    }
}

