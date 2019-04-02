#include "Step5Data.h"
#include "ui_Step5Data.h"

Step5Data::Step5Data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step5Data)
{
    ui->setupUi(this);
}

Step5Data::~Step5Data()
{
    delete ui;
}
