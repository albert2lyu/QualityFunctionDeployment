#include "Step3.h"
#include "ui_Step3.h"

Step3::Step3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step3)
{
    ui->setupUi(this);




    ui->stackedWidget->setVisible(true);
    ui->stackedWidget_2->setVisible(false);

}


Step3::~Step3()
{
    delete ui;
}
void Step3::on_pushButton_clicked()
{
    Step3_1_Page=new Step3_1(this);   ui->stackedWidget->addWidget(Step3_1_Page);



    ui->stackedWidget->setCurrentWidget(Step3_1_Page);
     ui->stackedWidget->show();
}

void Step3::on_pushButton_2_clicked()
{
    Step3_2_Page=new Step3_2(this);ui->stackedWidget->addWidget(Step3_2_Page);

    ui->stackedWidget->setCurrentWidget(Step3_2_Page);
    ui->stackedWidget->show();
}

void Step3::on_pushButton_3_clicked()
{

 comboBox_activated(ui->comboBox->currentText());

}
void Step3::on_pushButton_4_clicked()
{

    Step3_3_Page=new Step3_3(this); ui->stackedWidget->addWidget(Step3_3_Page);

    ui->stackedWidget->setCurrentWidget(Step3_3_Page);
    ui->stackedWidget->show();
}
void Step3::on_pushButton_5_clicked()
{

    Step3_4_Page=new Step3_4(this); ui->stackedWidget->addWidget(Step3_4_Page);

    ui->stackedWidget->setCurrentWidget(Step3_4_Page);
    ui->stackedWidget->show();
}


void Step3::comboBox_activated(const QString &arg1)
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
    else
    {
        Step3Data_Page = new Step3Data(this);
       ui->stackedWidget_2->addWidget(Step3Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step3Data_Page);
      ui->stackedWidget_2->show();
    }

}
