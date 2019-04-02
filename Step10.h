#ifndef Step10_H
#define Step10_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include "Step10_1.h"
#include "Step10_2.h"
#include "Step10data.h"
namespace Ui {
class Step10;
}

class Step10 : public QWidget
{
    Q_OBJECT

public:
    explicit Step10(QWidget *parent = 0);
         void paintEvent(QPaintEvent *);
    ~Step10();

private:
    Ui::Step10 *ui;
    Step10_1 *Step10_1_Page;//创建窗口页面指针
    Step10_2 *Step10_2_Page;
    Step10Data *Step10Data_Page;
};

#endif // Step10_H
