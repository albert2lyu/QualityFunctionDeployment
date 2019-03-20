#include "Step9.h"
#include "ui_Step9.h"

Step9::Step9(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step9)
{
    ui->setupUi(this);
}

Step9::~Step9()
{
    delete ui;
}
