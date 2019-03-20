#include "threeform.h"
#include "ui_threeform.h"

ThreeForm::ThreeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ThreeForm)
{
    ui->setupUi(this);
}

ThreeForm::~ThreeForm()
{
    delete ui;
}
