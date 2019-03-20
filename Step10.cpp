#include "Step10.h"
#include "ui_Step10.h"

Step10::Step10(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step10)
{
    ui->setupUi(this);
}

Step10::~Step10()
{
    delete ui;
}
