#include "Step2.h"
#include "ui_Step2.h"

Step2::Step2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step2)
{
    ui->setupUi(this);
    //setStyleSheet(QString::fromUtf8("border:1px solid black"));

    //setStyleSheet(QString::fromUtf8("border:1px solid black"));
    ui->stackedWidget->setVisible(true);
     ui->stackedWidget_2->setVisible(true);

}

Step2::~Step2()
{
    delete ui;
}


void Step2::on_pushButton_clicked()
{
    Step2_1_Page=new Step2_1(this);

    ui->stackedWidget->addWidget(Step2_1_Page);

    ui->stackedWidget->setCurrentWidget(Step2_1_Page);
    ui->stackedWidget->show();
}

void Step2::on_pushButton_2_clicked()
{
    Step2_3_Page=new Step2_3(this); ui->stackedWidget->addWidget(Step2_3_Page);

    ui->stackedWidget->setCurrentWidget(Step2_3_Page);
    ui->stackedWidget->show();
}

void Step2::on_pushButton_3_clicked()
{

   comboBox_activated(ui->comboBox->currentText());
}

void Step2::on_pushButton_4_clicked()
{
    Step2_3_Page=new Step2_3(this);
    ui->stackedWidget->addWidget(Step2_3_Page);
    ui->stackedWidget->setCurrentWidget(Step2_3_Page);
    ui->stackedWidget->show();
}

void Step2::comboBox_activated(const QString &arg1)
{
    if(arg1=="Step1")
       { Step1Data_Page = new Step1Data(this);
       ui->stackedWidget_2->addWidget(Step1Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step1Data_Page);
      ui->stackedWidget_2->show();}
      else
      {
          Step2Data_Page = new Step2Data(this);
         ui->stackedWidget_2->addWidget(Step2Data_Page);
        ui->stackedWidget_2->setCurrentWidget(Step2Data_Page);
        ui->stackedWidget_2->show();
      }

}
