#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //为了防止段错误
    tcpServer = NULL;
    tcpSocket = NULL;

    setWindowTitle("服务端(端口:8888)");

    //监听套接字，指定父对象，让其自动回收空间
    tcpServer = new QTcpServer(this);

    tcpServer->listen(QHostAddress::Any,8888);

    connect(tcpServer,&QTcpServer::newConnection,
            [=](){
        //取出建立好连接的套接字
        tcpSocket=tcpServer->nextPendingConnection();

        //获取对方的IP和端口
        QString ip=tcpSocket->peerAddress().toString();
        qint16 port =tcpSocket->peerPort();
        QString ipDate=QString("ip=%1 port=%2").arg(ip).arg(port);

        ui->showEdit->setText(ipDate);

        //从通信套接字中取出内容
        connect(tcpSocket,&QTcpSocket::readyRead,
                [=](){
                        QByteArray array=tcpSocket->readAll();
                        ui->showEdit->append(array);
                    }

                );
    }

    );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonSend_clicked()
{
    if(NULL == tcpSocket)
    {
        return;
    }

    //获取编辑区内容
    QString str=ui->sendEdit->toPlainText();
    //给对方发送数据， 使用套接字是tcpSocket
    tcpSocket->write(str.toUtf8().data());
}

void Widget::on_buttonClose_clicked()
{
    if(NULL == tcpSocket)
    {
        return;
    }

        //主动和客户端端口连接
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
        tcpSocket = NULL;
}
