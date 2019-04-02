#ifndef Step2_H
#define Step2_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include "Step2_1.h"
#include "Step2_2.h"
#include "Step2data.h"
namespace Ui {
class Step2;
}

class Step2 : public QWidget
{
    Q_OBJECT

public:
    explicit Step2(QWidget *parent = 0);
         void paintEvent(QPaintEvent *);
    ~Step2();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
private:
    Ui::Step2 *ui;
    Step2_1 *Step2_1_Page;//创建窗口页面指针
    Step2_2 *Step2_2_Page;
    Step2Data *Step2Data_Page;
};

#endif // Step2_H
