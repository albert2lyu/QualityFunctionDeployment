#ifndef Step7_H
#define Step7_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include "Step7_1.h"
#include "Step7_2.h"
#include "Step1Data.h"
#include "Step2Data.h"
#include "Step3Data.h"
#include "Step4Data.h"
#include "Step5Data.h"
#include "Step6Data.h"
#include "Step7Data.h"
#include "Step8Data.h"
#include "Step9Data.h"
#include "Step10Data.h"
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
    void on_comboBox_activated(const QString &arg1);

private:
    Ui::Step7 *ui;
    Step7_1 *Step7_1_Page;//创建窗口页面指针
    Step7_2 *Step7_2_Page;
    Step1Data *Step1Data_Page;
    Step2Data *Step2Data_Page;
    Step3Data *Step3Data_Page;
    Step4Data *Step4Data_Page;
    Step5Data *Step5Data_Page;
    Step6Data *Step6Data_Page;
    Step7Data *Step7Data_Page;
    Step8Data *Step8Data_Page;

};

#endif // Step7_H
