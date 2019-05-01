#ifndef Step6_H
#define Step6_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include "Step6_1.h"
#include "Step6_2.h"
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
#include"Step6Help.h"
namespace Ui {
class Step6;
}

class Step6 : public QWidget
{
    Q_OBJECT

public:
    explicit Step6(QWidget *parent = nullptr);

    ~Step6();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void comboBox_activated(const QString &arg1);
 void on_helpButton_clicked();
private:
    Ui::Step6 *ui;
    Step6_1 *Step6_1_Page;//创建窗口页面指针
Step6_2 *Step6_2_Page;
Step1Data *Step1Data_Page;
Step2Data *Step2Data_Page;
Step3Data *Step3Data_Page;
Step4Data *Step4Data_Page;
Step5Data *Step5Data_Page;
Step6Data *Step6Data_Page;
Step7Data *Step7Data_Page;
Step8Data *Step8Data_Page;

};

#endif // Step6_H
