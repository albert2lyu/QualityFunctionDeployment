#ifndef Step4_H
#define Step4_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include "Step4_1.h"
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
class Step4;
}

class Step4 : public QWidget
{
    Q_OBJECT

public:
    explicit Step4(QWidget *parent = 0);

    ~Step4();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void comboBox_activated(const QString &arg1);

private:
    Ui::Step4 *ui;
    Step4_1 *Step4_1_Page;//创建窗口页面指针
 //   Step4_2 *Step4_2_Page;
    Step1Data *Step1Data_Page;
    Step2Data *Step2Data_Page;
    Step3Data *Step3Data_Page;
    Step4Data *Step4Data_Page;
    Step5Data *Step5Data_Page;
    Step6Data *Step6Data_Page;
    Step7Data *Step7Data_Page;
    Step8Data *Step8Data_Page;

};

#endif // Step4_H
