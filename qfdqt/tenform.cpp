#include "tenform.h"
#include "ui_tenform.h"

TenForm::TenForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TenForm)
{
    ui->setupUi(this);
}

TenForm::~TenForm()
{
    delete ui;
}
