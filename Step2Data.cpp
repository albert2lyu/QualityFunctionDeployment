#include "Step2Data.h"
#include "ui_Step2Data.h"

Step2Data::Step2Data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step2Data)
{
    ui->setupUi(this);
}

Step2Data::~Step2Data()
{
    delete ui;
}
