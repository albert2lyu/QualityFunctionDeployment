#include "eightform.h"
#include "ui_eightform.h"

EightForm::EightForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EightForm)
{
    ui->setupUi(this);
}

EightForm::~EightForm()
{
    delete ui;
}
