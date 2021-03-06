#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

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
    void on_buttonStart_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QTimer *myTimer;

    int i;

};

#endif // WIDGET_H
