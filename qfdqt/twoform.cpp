#include "twoform.h"
#include "ui_twoform.h"

TwoForm::TwoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TwoForm)
{
    ui->setupUi(this);
}

TwoForm::~TwoForm()
{
    delete ui;
}
