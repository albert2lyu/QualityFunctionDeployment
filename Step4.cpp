#include "Step4.h"
#include "ui_Step4.h"

Step4::Step4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step4)
{
    ui->setupUi(this);
    ui->stackedWidget->setVisible(true);
    ui->stackedWidget_2->setVisible(false);

}

Step4::~Step4()
{
    delete ui;
}
void Step4::on_pushButton_clicked()
{
    Step4_1_Page = new Step4_1(this);//实例化窗口页面
    ui->stackedWidget->addWidget(Step4_1_Page);
    ui->stackedWidget->setCurrentWidget(Step4_1_Page);

     ui->stackedWidget->show();
}

void Step4::on_pushButton_2_clicked()
{
    Step4_1_Page = new Step4_1(this);//实例化窗口页面
    ui->stackedWidget->addWidget(Step4_1_Page);

    ui->stackedWidget->setCurrentWidget(Step4_1_Page);

     ui->stackedWidget->show();
}

void Step4::on_pushButton_3_clicked()
{

 comboBox_activated(ui->comboBox->currentText());

}

void Step4::comboBox_activated(const QString &arg1)
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
    else
    {
        Step4Data_Page = new Step4Data(this);
       ui->stackedWidget_2->addWidget(Step4Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step4Data_Page);
      ui->stackedWidget_2->show();
    }
}
