#ifndef Step9_H
#define Step9_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include "Step9_1.h"
#include "Step9_2.h"
#include "Step9_3.h"
#include "Step9Data.h"
namespace Ui {
class Step9;
}

class Step9 : public QWidget
{
    Q_OBJECT

public:
    explicit Step9(QWidget *parent = nullptr);
         void paintEvent(QPaintEvent *);
    ~Step9();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
        void on_pushButton_4_clicked();
private:
    Ui::Step9 *ui;
    Step9_1 *Step9_1_Page;//创建窗口页面指针
Step9_2 *Step9_2_Page;
Step9_3 *Step9_3_Page;
    Step9Data *Step9Data_Page;
};

#endif // Step9_H
