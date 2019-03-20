#include "fiveform.h"
#include "ui_fiveform.h"

FiveForm::FiveForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FiveForm)
{
    ui->setupUi(this);
}

FiveForm::~FiveForm()
{
    delete ui;
}
