#include "tcpfilesender.h"

TcpFileSender::TcpFileSender(QWidget *parent)
    : QDialog(parent){
    loadSize=1024*4;
    totalBytes=0;
    bytesWritten=0;
    bytesToWrite=0;
    clientProgressBar=new QProgressBar;
    clientStatusLabel=new QLabel(tr("client ready"));
    startButton=new QPushButton(tr("Start"));
    quitButton=new QPushButton(tr("Quit"));
    openButton=new QPushButton(tr("OpenFile"));

    startButton->setEnabled(false);
    ButtonBox=new QDialogButtonBox;
    ButtonBox->addButton(startButton,QDialogButtonBox::ActionRole);
    ButtonBox->addButton(openButton,QDialogButtonBox::ActionRole);
    ButtonBox->addButton(quitButton,QDialogButtonBox::RejectRole);
    QVBoxLayout *mainLayout=new QVBoxLayout;
    mainLayout->addWidget(clientProgressBar);
    mainLayout->addWidget(clientStatusLabel);
    mainLayout->addStretch(1);//彈簧
    mainLayout->addSpacing(10);//相隔距離
    mainLayout->addWidget(ButtonBox);
    setLayout(mainLayout);
    setWindowTitle(tr("SendFile"));
    connect(openButton,SIGNAL(clicked()),this,SLOT(openFile()));
    connect(startButton,SIGNAL(clicked()),this,SLOT(start()));
    connect(&tcpClient,SIGNAL(connected()),this,SLOT(startTransfer()));
    connect(&tcpClient,SIGNAL(bytesWritten(qint64)),this,SLOT(updateClientProgress(qint64)));
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
}

TcpFileSender::~TcpFileSender(){
}
void TcpFileSender::start(){
    startButton->setEnabled(false);
    bytesWritten=0;
    clientStatusLabel->setText(tr("connecting..."));
    tcpClient.connectToHost(QHostAddress::LocalHost,16689);
}
void TcpFileSender::startTransfer(){
    localFile=new QFile(fileName);
    if(!localFile->open(QFile::ReadOnly)){
        QMessageBox::warning(this,tr("application"),tr("can't load %1:\n%2").arg(fileName).arg(localFile->errorString()));
        return;
    }
    totalBytes=localFile->size();
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    sendOut.setVersion((QDataStream::Qt_4_6));
    QString currentFile=fileName.right(fileName.size()-fileName.lastIndexOf("/")-1);
    sendOut<<qint64(0)<<qint64(0)<<currentFile;
    totalBytes+=outBlock.size();
    sendOut.device()->seek(0);
    sendOut<<totalBytes<<qint64((outBlock.size()-sizeof(qint64)*2));
    bytesToWrite=totalBytes-tcpClient.write(outBlock);
    clientStatusLabel->setText(tr("connected"));
    qDebug()<<currentFile<<totalBytes;
    outBlock.resize(0);

}
void TcpFileSender::updateClientProgress(qint64 numBytes){
    bytesWritten+=(int)numBytes;
    if(bytesToWrite>0){
        outBlock=localFile->read(qMin(bytesToWrite,loadSize));
        bytesToWrite-=(int)tcpClient.write(outBlock);
        outBlock.resize(0);
    }
    else
        localFile->close();
    clientProgressBar->setMaximum(totalBytes);
    clientProgressBar->setValue(bytesWritten);
    clientStatusLabel->setText(tr("send %1 Bytes").arg(bytesWritten));
}
void TcpFileSender::openFile(){
    fileName=QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())startButton->setEnabled(true);
}
