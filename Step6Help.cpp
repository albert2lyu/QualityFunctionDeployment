#include "Step6Help.h"
#include "ui_Step6Help.h"

Step6Help::Step6Help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Step6Help)
{
    ui->setupUi(this);
}

Step6Help::~Step6Help()
{
    delete ui;
}
