#include "Step1.h"
#include "ui_Step1.h"

Step1::Step1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step1)
{
    ui->setupUi(this);

    Step1_1_Page = new Step1_1(this);//实例化窗口页面
    Step1_2_Page = new Step1_2(this);
    ui->stackedWidget->addWidget(Step1_1_Page);
    ui->stackedWidget->addWidget(Step1_2_Page);
    //ui->stackedWidget->setCurrentWidget(Step1_1_Page);
    setStyleSheet(QString::fromUtf8("border:1px solid black"));
}

Step1::~Step1()
{
    delete ui;
}
void Step1::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(Step1_1_Page);
}

void Step1::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(Step1_2_Page);
}

