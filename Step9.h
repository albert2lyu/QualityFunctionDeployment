#ifndef Step9_H
#define Step9_H

#include <QWidget>
#include<QPainter>
#include<QPen>
#include "Step9_1.h"
#include "Step9_2.h"
#include "Step9_3.h"
#include "Step9_4.h"
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
        void on_pushButton_5_clicked();
        void on_comboBox_activated(const QString &arg1);

private:
    Ui::Step9 *ui;
    Step9_1 *Step9_1_Page;//创建窗口页面指针
    Step9_2 *Step9_2_Page;
    Step9_3 *Step9_3_Page;
    Step9_4 *Step9_4_Page;
    Step9Data *Step9Data_Page;

    Step10Data *Step10Data_Page;
    Step1Data *Step1Data_Page;
    Step2Data *Step2Data_Page;
    Step3Data *Step3Data_Page;
    Step4Data *Step4Data_Page;
    Step5Data *Step5Data_Page;
    Step6Data *Step6Data_Page;
    Step7Data *Step7Data_Page;
    Step8Data *Step8Data_Page;


};

#endif // Step9_H
