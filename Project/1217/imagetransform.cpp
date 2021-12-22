#include "imagetransform.h"
#include <QPixmap>
ImageTransform::ImageTransform(QWidget *parent)
    : QWidget(parent){
    setWindowTitle(tr("ImageTransform"));
    mainLayout=new QHBoxLayout(this);
    leftLayout=new QVBoxLayout(this);
    mirrorGroup=new QGroupBox(tr("Mirror"),this);//鏡射
    groupLayout=new QVBoxLayout(mirrorGroup);
    hCheckBox=new QCheckBox(tr("Horizontal"),mirrorGroup);//水平
    vCheckBox=new QCheckBox(tr("Vertical"),mirrorGroup);//垂直
    mirrorButton=new QPushButton(QStringLiteral("Run"),mirrorGroup);//執行
    hCheckBox->setGeometry(QRect(13,28,87,19));
    vCheckBox->setGeometry(QRect(13,54,87,19));
    mirrorButton->setGeometry(QRect(13,80,93,28));
    groupLayout->addWidget(hCheckBox);
    groupLayout->addWidget(vCheckBox);
    groupLayout->addWidget(mirrorButton);
    leftLayout->addWidget(mirrorGroup);
    rotateDial=new QDial(this);
    rotateDial->setNotchesVisible(true);
    vSpacer=new QSpacerItem(20,58,QSizePolicy::Minimum,QSizePolicy::Expanding);
    leftLayout->addWidget(rotateDial);
    leftLayout->addItem(vSpacer);
    mainLayout->addLayout(leftLayout);
    inWin=new QLabel(this);
    inWin->setScaledContents(true);
    QPixmap *initPixmap=new QPixmap(300,200);
    initPixmap->fill(QColor(255,255,255));
    inWin->setPixmap(*initPixmap);
    inWin->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    if(srcImg.isNull()){
        QPixmap *initPixmap=new QPixmap(300,200);
        initPixmap->fill(QColor(255,255,255));
        inWin->setPixmap(*initPixmap);
    }
    mainLayout->addWidget(inWin);
    connect(mirrorButton,SIGNAL(clicked()),this,SLOT(mirrorImage()));
    connect(rotateDial,SIGNAL(valueChanged()),this,SLOT(rotatedImage()));
}

ImageTransform::~ImageTransform(){
}
void ImageTransform::mirroredImgae(){
    bool H,V;
    if(srcImg.isNull())
        return;
    H=hCheckBox->isChecked();
    V=vCheckBox->isChecked();
    dstImg=srcImg.mirrored(H,V);
    inWin->setPixmap(QPixmap::fromImage(dstImg));
    srcImg=dstImg;
}
void ImageTransform::rotatedImage(){
    QTransform tran;
    int angle;
    if(srcImg.isNull())
        return;
    angle=rotateDial->value();
    tran.rotate(angle);
    dstImg=srcImg.transformed(tran);
    inWin->setPixmap(QPixmap::fromImage(dstImg));
}


