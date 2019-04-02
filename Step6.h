#ifndef Step6_H
#define Step6_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include "Step6_1.h"
#include "Step6Data.h"
namespace Ui {
class Step6;
}

class Step6 : public QWidget
{
    Q_OBJECT

public:
    explicit Step6(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~Step6();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
private:
    Ui::Step6 *ui;
    Step6_1 *Step6_1_Page;//创建窗口页面指针

    Step6Data *Step6Data_Page;
};

#endif // Step6_H
