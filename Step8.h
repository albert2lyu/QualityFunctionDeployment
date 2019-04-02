#ifndef Step8_H
#define Step8_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include "Step8_1.h"
#include "Step8_2.h"
#include "Step8data.h"
namespace Ui {
class Step8;
}

class Step8 : public QWidget
{
    Q_OBJECT

public:
    explicit Step8(QWidget *parent = 0);
         void paintEvent(QPaintEvent *);
    ~Step8();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
private:
    Ui::Step8 *ui;
    Step8_1 *Step8_1_Page;//创建窗口页面指针
    Step8_2 *Step8_2_Page;
    Step8Data *Step8Data_Page;
};

#endif // Step8_H
