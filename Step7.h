#ifndef Step7_H
#define Step7_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include "Step7_1.h"
#include "Step7_2.h"
#include "Step7Data.h"
namespace Ui {
class Step7;
}

class Step7 : public QWidget
{
    Q_OBJECT

public:
    explicit Step7(QWidget *parent = nullptr);
         void paintEvent(QPaintEvent *);
    ~Step7();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
private:
    Ui::Step7 *ui;
    Step7_1 *Step7_1_Page;//创建窗口页面指针
    Step7_2 *Step7_2_Page;
    Step7Data *Step7Data_Page;
};

#endif // Step7_H
