#include "sixform.h"
#include "ui_sixform.h"

SixForm::SixForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SixForm)
{
    ui->setupUi(this);
}

SixForm::~SixForm()
{
    delete ui;
}
