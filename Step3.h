#ifndef Step3_H
#define Step3_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include "Step3_1.h"
#include "Step3_2.h"
#include "Step3data.h"
namespace Ui {
class Step3;
}

class Step3 : public QWidget
{
    Q_OBJECT

public:
    explicit Step3(QWidget *parent = 0);
     void paintEvent(QPaintEvent *);
    ~Step3();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
private:
    Ui::Step3 *ui;
    Step3_1 *Step3_1_Page;//创建窗口页面指针
    Step3_2 *Step3_2_Page;
    Step3Data *Step3Data_Page;
};

#endif // Step3_H
