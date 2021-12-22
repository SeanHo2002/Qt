#include "tcpfileserver.h"

TcpFileServer::TcpFileServer(QWidget *parent)
    : QDialog(parent){
    totalBytes=0;
    byteReceived=0;
    fileNameSize=0;
    serverProgressBar=new QProgressBar;
    serverStatusLabel=new QLabel(tr("server ready"));
    startButton=new QPushButton(tr("Receive"));
    quitButton=new QPushButton(tr("Quit"));
    ButtonBox=new QDialogButtonBox;
    ButtonBox->addButton(startButton,QDialogButtonBox::ActionRole);
    ButtonBox->addButton(quitButton,QDialogButtonBox::RejectRole);
    QVBoxLayout *mainLayout=new QVBoxLayout;
    mainLayout->addWidget(serverProgressBar);
    mainLayout->addWidget(serverStatusLabel);
    mainLayout->addStretch(1);//彈簧
    mainLayout->addWidget(ButtonBox);
    setLayout(mainLayout);
    setWindowTitle(tr("ReceiveFile"));
    connect(startButton,SIGNAL(clicked()),this,SLOT(start()));
        connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(&tcpServer,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
    connect(&tcpServer,SIGNAL(acceptError(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
}

TcpFileServer::~TcpFileServer()
{
}
void TcpFileServer::start(){
    startButton->setEnabled(false);
    byteReceived=0;
    fileNameSize=0;
    while(!tcpServer.isListening()&&!tcpServer.listen(QHostAddress::AnyIPv4,16689)){
        QMessageBox::StandardButton ret=QMessageBox::critical(this,tr("loop"),tr("can't open the Server: %1").arg(tcpServer.errorString()),QMessageBox::Retry|QMessageBox::Cancel);
        if(ret==QMessageBox::Cancel)return;
    }
    serverStatusLabel->setText(tr("listening..."));
}
void TcpFileServer::acceptConnection(){
    tcpServerConnection=tcpServer.nextPendingConnection();
    connect(tcpServerConnection,SIGNAL(readyRead()),this,SLOT(updateServerProgress()));
    connect(tcpServerConnection,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    serverStatusLabel->setText(tr("accept connect"));
    tcpServer.close();
}
void TcpFileServer::updateServerProgress(){
    QDataStream in(tcpServerConnection);
    in.setVersion(QDataStream::Qt_4_6);
    if(byteReceived<=sizeof(qint64)*2){
        if((fileNameSize==0)&&(tcpServerConnection->bytesAvailable()>=sizeof(qint64)*2)){
            in>>totalBytes>>fileNameSize;
            byteReceived+=sizeof(qint64)*2;
        }
        if((fileNameSize!=0)&&(tcpServerConnection->bytesAvailable()>=fileNameSize)){
            in>>fileName;
            byteReceived+=fileNameSize;
            localFile=new QFile(fileName);
            if(!localFile->open(QFile::WriteOnly)){
                QMessageBox::warning(this,tr("application"),tr("can't read the file %1:\n%2").arg(fileName).arg(localFile->errorString()));
                return;
            }
        }
        else
            return;
    }
    if(byteReceived<totalBytes){
        byteReceived+=tcpServerConnection->bytesAvailable();
        inBlock=tcpServerConnection->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }
    serverProgressBar->setMaximum(totalBytes);
    serverProgressBar->setValue(byteReceived);
    qDebug()<<byteReceived;
    serverStatusLabel->setText(tr("receive %1 Bytes").arg(byteReceived));
    if(byteReceived==totalBytes){
        tcpServerConnection->close();
        startButton->setEnabled(true);
        localFile->fileName();
        localFile->close();
        start();
    }
}
void TcpFileServer::displayError(QAbstractSocket::SocketError socketError){
    if(socketError==QTcpSocket::RemoteHostClosedError)
        return;
    QMessageBox::information(this,tr("internet error"),tr("issue:%1").arg(tcpServerConnection->errorString()));
    tcpServerConnection->close();
    serverProgressBar->reset();
    serverStatusLabel->setText(tr("server ready"));
    startButton->setEnabled(true);
}
