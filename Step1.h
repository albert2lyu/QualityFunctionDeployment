#ifndef Step1_H
#define Step1_H

#include <QWidget>
#include "Step1_1.h"
#include "Step1_2.h"
#include "step1data.h"
#include<QPainter>
#include<QPen>
namespace Ui {
class Step1;
}

class Step1 : public QWidget
{
    Q_OBJECT

public:
    explicit Step1(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~Step1();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
private:
    Ui::Step1 *ui;
    Step1_1 *Step1_1_Page;//创建窗口页面指针
    Step1_2 *Step1_2_Page;
    Step1Data *Step1Data_Page;
};

#endif // Step1_H
