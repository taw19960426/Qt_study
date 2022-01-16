#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "mythread.h"

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
    void on_pushButton_clicked();

    void on_buttonClose1_clicked();

private:
    Ui::Widget *ui;

    QTimer myTimer;

    MyThread *myThread;


private:
    void delTimer();//定时器槽函数
    void myThreadDone();//线程结束处理槽函数
    void killMyThread();//窗口关闭 线程退出
};

#endif // WIDGET_H
