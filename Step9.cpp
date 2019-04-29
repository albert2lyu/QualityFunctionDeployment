#include "Step9.h"
#include "ui_Step9.h"

Step9::Step9(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step9)
{
    ui->setupUi(this);

    ui->stackedWidget->setVisible(true);
    ui->stackedWidget_2->setVisible(false);
  //  setStyleSheet(QString::fromUtf8("border:1px solid black"));
}

Step9::~Step9()
{
    delete ui;
}
//Step9_1_Page = new Step9_1(this);//实例化窗口页面
//ui->stackedWidget->addWidget(Step9_1_Page);
//Step9_2_Page = new Step9_2(this);//实例化窗口页面
//ui->stackedWidget->addWidget(Step9_2_Page);
//Step9_3_Page = new Step9_3(this);//实例化窗口页面
//ui->stackedWidget->addWidget(Step9_3_Page);
//Step9Data_Page = new Step9Data(this);
//ui->stackedWidget_2->addWidget(Step9Data_Page);
void Step9::on_pushButton_clicked()
{
    Step9_1_Page = new Step9_1(this);
    ui->stackedWidget->addWidget(Step9_1_Page);
    ui->stackedWidget->setCurrentWidget(Step9_1_Page);
     ui->stackedWidget->show();
}

void Step9::on_pushButton_2_clicked()
{Step9_2_Page = new Step9_2(this);
  ui->stackedWidget->addWidget(Step9_2_Page);
    ui->stackedWidget->setCurrentWidget(Step9_2_Page);
    ui->stackedWidget->show();
}

void Step9::on_pushButton_3_clicked()
{
  comboBox_activated(ui->comboBox->currentText());
}
void Step9::on_pushButton_4_clicked()
{
    Step9_3_Page = new Step9_3(this);
    ui->stackedWidget->addWidget(Step9_3_Page);
    ui->stackedWidget->setCurrentWidget(Step9_3_Page);
    ui->stackedWidget->show();
}
void Step9::on_pushButton_5_clicked()
{

    Step9_4_Page=new Step9_4(this);
    ui->stackedWidget->addWidget(Step9_4_Page);

    ui->stackedWidget->setCurrentWidget(Step9_4_Page);
    ui->stackedWidget->show();
}

void Step9::comboBox_activated(const QString &arg1)
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
    else if (arg1=="Step8")
    {
        Step8Data_Page = new Step8Data(this);
       ui->stackedWidget_2->addWidget(Step8Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step8Data_Page);
      ui->stackedWidget_2->show();
    }
    else
    {
        Step9Data_Page = new Step9Data(this);
       ui->stackedWidget_2->addWidget(Step9Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step9Data_Page);
      ui->stackedWidget_2->show();
    }

}
