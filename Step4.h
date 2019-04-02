#ifndef Step4_H
#define Step4_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include "Step4_1.h"
#include "Step4Data.h"
namespace Ui {
class Step4;
}

class Step4 : public QWidget
{
    Q_OBJECT

public:
    explicit Step4(QWidget *parent = 0);
         void paintEvent(QPaintEvent *);
    ~Step4();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
private:
    Ui::Step4 *ui;
    Step4_1 *Step4_1_Page;//创建窗口页面指针
 //   Step4_2 *Step4_2_Page;
    Step4Data *Step4Data_Page;
};

#endif // Step4_H
