#include "Step6Data.h"
#include "ui_Step6Data.h"

Step6Data::Step6Data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step6Data)
{
    ui->setupUi(this);
}

Step6Data::~Step6Data()
{
    delete ui;
}
