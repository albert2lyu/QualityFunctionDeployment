#include "oneform.h"
#include "ui_oneform.h"

OneForm::OneForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OneForm)
{
    ui->setupUi(this);

    TableOneForm_Page = new TableOneForm(this);//实例化窗口页面
    TableTwoForm_Page = new TableTwoForm(this);
    ui->stackedWidget->addWidget(TableOneForm_Page);
    ui->stackedWidget->addWidget(TableTwoForm_Page);
    //ui->stackedWidget->setCurrentWidget(TableOneForm_Page);
    setStyleSheet(QString::fromUtf8("border:3px solid black"));
}

OneForm::~OneForm()
{
    delete ui;
}
void OneForm::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(TableOneForm_Page);
}

void OneForm::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(TableTwoForm_Page);
}

