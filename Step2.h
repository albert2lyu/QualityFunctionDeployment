#ifndef Step2_H
#define Step2_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include "Step2_1.h"
#include "Step2_2.h"
#include "Step2_3.h"
#include "Step2Data.h"
#include "Step1Data.h"

#include "Step3Data.h"
#include "Step4Data.h"
#include "Step5Data.h"
#include "Step6Data.h"
#include "Step7Data.h"
#include "Step8Data.h"
#include "Step9Data.h"
#include "Step10Data.h"
namespace Ui {
class Step2;
}

class Step2 : public QWidget
{
    Q_OBJECT

public:
    explicit Step2(QWidget *parent = nullptr);

    ~Step2();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
        void on_pushButton_4_clicked();
        void comboBox_activated(const QString &arg1);

private:
    Ui::Step2 *ui;
    Step2_1 *Step2_1_Page;//创建窗口页面指针
    Step2_2 *Step2_2_Page;
    Step2_3 *Step2_3_Page;
    Step1Data *Step1Data_Page;
    Step2Data *Step2Data_Page;
    Step3Data *Step3Data_Page;
    Step4Data *Step4Data_Page;
    Step5Data *Step5Data_Page;
    Step6Data *Step6Data_Page;
    Step7Data *Step7Data_Page;
    Step8Data *Step8Data_Page;

};

#endif // Step2_H
