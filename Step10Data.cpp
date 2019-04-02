#include "Step10Data.h"
#include "ui_Step10Data.h"

Step10Data::Step10Data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step10Data)
{
    ui->setupUi(this);
}

Step10Data::~Step10Data()
{
    delete ui;
}
