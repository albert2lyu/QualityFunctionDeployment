#include "Step2.h"
#include "ui_Step2.h"

Step2::Step2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step2)
{
    ui->setupUi(this);
}

Step2::~Step2()
{
    delete ui;
}
