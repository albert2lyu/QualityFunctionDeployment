#ifndef Step1_H
#define Step1_H

#include <QWidget>
#include "Step1_1.h"
#include "Step1_2.h"
namespace Ui {
class Step1;
}

class Step1 : public QWidget
{
    Q_OBJECT

public:
    explicit Step1(QWidget *parent = 0);
    ~Step1();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
private:
    Ui::Step1 *ui;
    Step1_1 *Step1_1_Page;//创建窗口页面指针
    Step1_2 *Step1_2_Page;
};

#endif // Step1_H
