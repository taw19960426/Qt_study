#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //打印Qt支持的数据库驱动
    qDebug() << QSqlDatabase::drivers();

    //添加MySql数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("127.0.0.1"); //数据库服务器IP
    db.setUserName("root"); //数据库用户名
    db.setPassword("qaz12580"); //密码
    db.setDatabaseName("info"); //使用哪个数据库

    //打开数据库
    if( !db.open() ) //数据库打开失败
    {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }

    //创建表
    QSqlQuery query;
//    query.exec("create table student(id int primary key auto_increment, name varchar(255), age int, score int);");

//    //插入
//    //query.exec("insert into student(id, name, age, score) values(1, 'xiaoMing', 18, 59);");

//    //批量插入
//    //oracle风格
//    //占位符 ： + 自定义名字
//    query.prepare("insert into student(name, age, score) values(:name, :age, :score)");
//    //给字段设置内容 list
//    QVariantList nameList;
//    nameList << "xiaod" << "xiaoe" << "xiaof";
//    QVariantList ageList;
//    ageList << 13 << 16 << 45;
//    QVariantList scoreList;
//    scoreList << 85 << 16 << 66;
//    //给字段绑定
//    query.bindValue(":name",nameList);
//    query.bindValue(":age",ageList);
//    query.bindValue(":score",scoreList);

//    //执行预处理命令
//    if(!query.execBatch()){
//        qDebug() << query.lastError();
//    }

    //遍历数据库
    query.exec("select * from student");
    while(query.next()){
        //一行一行遍历
        qDebug() << query.value(0).toInt()
                 << query.value(1).toString()
                 << query.value("age").toInt()
                 << query.value("score").toInt();
    }


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonDel_clicked()
{
    //获取编辑器内容
    QString name=ui->lineEdit->text();
    QString del=QString("delete from student where name = '%1';").arg(name);

    //开启一个事务
    QSqlDatabase::database().transaction();
    QSqlQuery query;
    query.exec(del);
}

void Widget::on_buttonQueDing_clicked()
{
    //确定删除
    QSqlDatabase::database().commit();
}

void Widget::on_buttonQuXiao_clicked()
{
    //撤销删除
    QSqlDatabase::database().rollback();
}
