#include "fourform.h"
#include "ui_fourform.h"

FourForm::FourForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FourForm)
{
    ui->setupUi(this);
}

FourForm::~FourForm()
{
    delete ui;
}
