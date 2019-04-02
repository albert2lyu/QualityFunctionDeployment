#include "Step9Data.h"
#include "ui_Step9Data.h"

Step9Data::Step9Data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step9Data)
{
    ui->setupUi(this);
}

Step9Data::~Step9Data()
{
    delete ui;
}
