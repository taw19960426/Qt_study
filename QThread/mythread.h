#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);

public:
    //get set函数必须公有public
    bool getStopValue();
    //通过set函数设置标志位 默认为假
    void setIsStop(bool flag=false);

private:
    //QThread的虚函数
    //线程处理函数
    //不能直接调用，通过start()间接调用
    void run();

    bool isStop;

signals:
    void delDone();

public slots:

};

#endif // MYTHREAD_H
