#include "widget.h"
#include "ui_widget.h"
#include <QThread>

#include <QDebug>
#define cout qDebug() << "[" << __FILE__ <<":" << __LINE__ << "]"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    myThread=new MyThread(this);//线程创建

    //通过set函数设置标志位 默认为假
    myThread->setIsStop(false);

    //get获取私有成员
    bool ans=myThread->getStopValue();
    cout<<ans;
    //cout<<myThread->isStop;//直接获取不到


    connect(&myTimer,&QTimer::timeout,this,&Widget::delTimer);

    //线程任务结束后返回delDone信号，关闭定时器
    connect(myThread,&MyThread::delDone,this,&Widget::myThreadDone);

    //关闭主窗口时线程退出
    //当按窗口右上角x时，窗口触发destroyed()
    connect(this,&Widget::destroyed,this,&Widget::killMyThread);

}

void Widget::killMyThread(){
    //关闭主窗口，让线程结束任务
    myThread->setIsStop(true);
    //停止线程
    myThread->quit();
    //等待线程处理完手头动作
    myThread->wait();
    cout<<"关闭主窗口，线程资源回收";
}

void Widget::delTimer(){
    static int i = 0;

    ui->lcdNumber->display(i);
    i++;
}

void Widget::myThreadDone(){

    //关闭定时器
    cout<<"线程处理结束，关闭定时器";
    myTimer.stop();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //如果定时器没有激活，才启动
    if(!myTimer.isActive()){
          myTimer.start(20);
      }

    if(myThread->isRunning()){
        return;
    }

//    //需要处理复杂的任务
//    QThread::sleep(5);

//    myTimer.stop();

    //启动线程
    myThread->start();
}


void Widget::on_buttonClose1_clicked()
{
    if(!myThread->isRunning()){
        return;
    }
    //cout<<"555555555";
    //通过标志位结束线程死循环，让线程发出delDone()信号
    myThread->setIsStop(true);
    Widget::myThreadDone();
}
