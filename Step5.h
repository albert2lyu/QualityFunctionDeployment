#ifndef Step5_H
#define Step5_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include "Step5_1.h"
#include "Step5Data.h"
namespace Ui {
class Step5;
}

class Step5 : public QWidget
{
    Q_OBJECT

public:
    explicit Step5(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~Step5();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
private:
    Ui::Step5 *ui;
    Step5_1 *Step5_1_Page;//创建窗口页面指针

    Step5Data *Step5Data_Page;
};

#endif // Step5_H
