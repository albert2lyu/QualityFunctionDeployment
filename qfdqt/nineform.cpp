#include "nineform.h"
#include "ui_nineform.h"

NineForm::NineForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NineForm)
{
    ui->setupUi(this);
}

NineForm::~NineForm()
{
    delete ui;
}
