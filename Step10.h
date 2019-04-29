#ifndef Step10_H
#define Step10_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include "Step10_1.h"
#include <QComboBox>
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
#include "Step2.h"
namespace Ui {
class Step10;
}

class Step10 : public QWidget
{
    Q_OBJECT

public:
    explicit Step10(QWidget *parent = nullptr);

    ~Step10();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();




    void comboBox_activated(const QString &arg1);

private:
    Ui::Step10 *ui;
    Step10_1 *Step10_1_Page;//创建窗口页面指针
    Step10Data *Step10Data_Page;
    Step2Data *Step2Data_Page;
    Step3Data *Step3Data_Page;
    Step4Data *Step4Data_Page;
    Step5Data *Step5Data_Page;
    Step6Data *Step6Data_Page;
    Step7Data *Step7Data_Page;
    Step8Data *Step8Data_Page;
    Step9Data *Step9Data_Page;
    Step1Data *Step1Data_Page;
};

#endif // Step10_H
