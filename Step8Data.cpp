#include "Step8Data.h"
#include "ui_Step8Data.h"

Step8Data::Step8Data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step8Data)
{
    ui->setupUi(this);
}

Step8Data::~Step8Data()
{
    delete ui;
}
