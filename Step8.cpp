#include "Step8.h"
#include "ui_Step8.h"

Step8::Step8(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step8)
{
    ui->setupUi(this);

    ui->stackedWidget->setVisible(true);
    ui->stackedWidget_2->setVisible(false);
//    setStyleSheet(QString::fromUtf8("border:1px solid black"));
}

Step8::~Step8()
{

    delete ui;
}
void Step8::on_pushButton_clicked()
{

    Step8_1_Page = new Step8_1(this);//实例化窗口页面
    ui->stackedWidget->addWidget(Step8_1_Page);

    ui->stackedWidget->setCurrentWidget(Step8_1_Page);

     ui->stackedWidget->show();
}

void Step8::on_pushButton_2_clicked()
{
    Step8_1_Page = new Step8_1(this);//实例化窗口页面
    ui->stackedWidget->addWidget(Step8_1_Page);
    ui->stackedWidget->setCurrentWidget(Step8_1_Page);

     ui->stackedWidget->show();
}

void Step8::on_pushButton_3_clicked()
{    comboBox_activated(ui->comboBox->currentText());

}

void Step8::comboBox_activated(const QString &arg1)
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
    else if (arg1=="Step7")
    {
        Step7Data_Page = new Step7Data(this);
       ui->stackedWidget_2->addWidget(Step7Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step7Data_Page);
      ui->stackedWidget_2->show();
    }
    else
    {
        Step8Data_Page = new Step8Data(this);
       ui->stackedWidget_2->addWidget(Step8Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step8Data_Page);
      ui->stackedWidget_2->show();
    }
}
