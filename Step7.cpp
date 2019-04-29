#include "Step7.h"
#include "ui_Step7.h"

Step7::Step7(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step7)
{
    ui->setupUi(this);
    ui->stackedWidget->setVisible(true);
    ui->stackedWidget_2->setVisible(false);


//    setStyleSheet(QString::fromUtf8("border:1px solid black"));
}

Step7::~Step7()
{
    delete ui;
}
void Step7::on_pushButton_clicked()
{
    Step7_1_Page = new Step7_1(this);
        ui->stackedWidget->addWidget(Step7_1_Page);
    ui->stackedWidget->setCurrentWidget(Step7_1_Page);
        ui->stackedWidget->show();
}

void Step7::on_pushButton_2_clicked()
{
    Step7_2_Page = new Step7_2(this);
        ui->stackedWidget->addWidget(Step7_2_Page);
    ui->stackedWidget->setCurrentWidget(Step7_2_Page);
        ui->stackedWidget->show();
}

void Step7::on_pushButton_3_clicked()
{
 comboBox_activated(ui->comboBox->currentText());
}

void Step7::comboBox_activated(const QString &arg1)
{
    if(arg1=="Step1")
       { Step1Data_Page = new Step1Data(this);
       ui->stackedWidget_2->addWidget(Step1Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step1Data_Page);
      ui->stackedWidget_2->show();}
      else if (arg1=="Step2")
      {
          Step2Data_Page = new Step2Data(this);
         ui->stackedWidget_2->addWidget(Step2Data_Page);
        ui->stackedWidget_2->setCurrentWidget(Step2Data_Page);
        ui->stackedWidget_2->show();
      }
    else if (arg1=="Step3")
    {
        Step3Data_Page = new Step3Data(this);
       ui->stackedWidget_2->addWidget(Step3Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step3Data_Page);
      ui->stackedWidget_2->show();
    }
    else if (arg1=="Step4")
    {
        Step4Data_Page = new Step4Data(this);
       ui->stackedWidget_2->addWidget(Step4Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step4Data_Page);
      ui->stackedWidget_2->show();
    }
    else if (arg1=="Step5")
    {
        Step5Data_Page = new Step5Data(this);
       ui->stackedWidget_2->addWidget(Step5Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step5Data_Page);
      ui->stackedWidget_2->show();
    }
    else if (arg1=="Step6")
    {
        Step6Data_Page = new Step6Data(this);
       ui->stackedWidget_2->addWidget(Step6Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step6Data_Page);
      ui->stackedWidget_2->show();
    }
    else
    {
        Step7Data_Page = new Step7Data(this);
       ui->stackedWidget_2->addWidget(Step7Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step7Data_Page);
      ui->stackedWidget_2->show();
    }
}
