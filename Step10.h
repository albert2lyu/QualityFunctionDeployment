#ifndef Step10_H
#define Step10_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include "Step10_1.h"
#include "Step10Data.h"
namespace Ui {
class Step10;
}

class Step10 : public QWidget
{
    Q_OBJECT

public:
    explicit Step10(QWidget *parent = nullptr);
         void paintEvent(QPaintEvent *);
    ~Step10();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
private:
    Ui::Step10 *ui;
    Step10_1 *Step10_1_Page;//创建窗口页面指针
    Step10Data *Step10Data_Page;
};

#endif // Step10_H
