#ifndef CLIENTTCP_H
#define CLIENTTCP_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class ClientTCP;
}

class ClientTCP : public QWidget
{
    Q_OBJECT

public:
    explicit ClientTCP(QWidget *parent = 0);
    ~ClientTCP();

private slots:
    void on_buttonConnect_clicked();

    void on_buttonWrite_clicked();

    void on_buttonClose_clicked();

private:
    Ui::ClientTCP *ui;
    QTcpSocket *tcpSocket; //通信套接字

};

#endif // CLIENTTCP_H
