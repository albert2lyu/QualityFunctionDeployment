#include "Step5.h"
#include "ui_Step5.h"

Step5::Step5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step5)
{
    ui->setupUi(this);

    ui->stackedWidget->setVisible(true);
    ui->stackedWidget_2->setVisible(false);
}

Step5::~Step5()
{
    delete ui;
}
void Step5::on_pushButton_clicked()
{
    Step5_1_Page = new Step5_1(this);//实例化窗口页面
    ui->stackedWidget->addWidget(Step5_1_Page);

    ui->stackedWidget->setCurrentWidget(Step5_1_Page);
    ui->stackedWidget->show();
}

void Step5::on_pushButton_2_clicked()
{  Step5_1_Page = new Step5_1(this);//实例化窗口页面
    ui->stackedWidget->addWidget(Step5_1_Page);

    ui->stackedWidget->setCurrentWidget(Step5_1_Page);
     ui->stackedWidget->show();
}

void Step5::on_pushButton_3_clicked()
{
 comboBox_activated(ui->comboBox->currentText());
}

void Step5::comboBox_activated(const QString &arg1)
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
    else
    {
        Step5Data_Page = new Step5Data(this);
       ui->stackedWidget_2->addWidget(Step5Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step5Data_Page);
      ui->stackedWidget_2->show();
    }

}
