#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer> //监听套接字
#include <QTcpSocket> //通信套接字

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_buttonSend_clicked();

    void on_buttonClose_clicked();

private:
    Ui::Widget *ui;
    QTcpServer *tcpServer; //监听套接字
    QTcpSocket *tcpSocket; //通信套接字
};

#endif // WIDGET_H
