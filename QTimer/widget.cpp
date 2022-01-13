#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    i=0;

    myTimer=new QTimer(this);

    connect(myTimer,&QTimer::timeout,
            [=](){
                    i++;
                    ui->lcdNumber->display(i);
                }

            );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonStart_clicked()
{
    //启动定时器
    //时间间隔为100ms
    //每隔100ms,定时器myTimer自动触发timeout()
    //如果定时器没有激活，才启动
    if(!myTimer->isActive()){
        myTimer->start(100);
    }
}

void Widget::on_pushButton_2_clicked()
{
    if(true == myTimer->isActive())
        {
            myTimer->stop();
            i = 0;
        }
}
