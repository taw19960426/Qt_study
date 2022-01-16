#include "mythread.h"
#include <QDebug>

MyThread::MyThread(QObject *parent) :
    QThread(parent)
{
    isStop=false;


}

void MyThread::run(){
    //线程处理函数
    //很复杂的数据处理
    //需要耗时5s
    //sleep(5);
    while (!isStop) {
        sleep(1);
        qDebug() << "子线程号：" << QThread::currentThread();

        //通过标志位来跳出循环
        if(isStop){
            break;
        }
    }

    //处理完以后发出结束信号
    emit delDone();
}

bool MyThread::getStopValue(){

    return isStop;
}

void MyThread::setIsStop(bool flag){
    isStop=flag;
}
