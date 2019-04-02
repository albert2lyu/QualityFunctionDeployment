#include "Step3Data.h"
#include "ui_Step3Data.h"

Step3Data::Step3Data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step3Data)
{
    ui->setupUi(this);
}

Step3Data::~Step3Data()
{
    delete ui;
}
