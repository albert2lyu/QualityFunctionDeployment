#include "Step4Data.h"
#include "ui_Step4Data.h"

Step4Data::Step4Data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step4Data)
{
    ui->setupUi(this);
}

Step4Data::~Step4Data()
{
    delete ui;
}
