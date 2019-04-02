#include "Step7Data.h"
#include "ui_Step7Data.h"

Step7Data::Step7Data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step7Data)
{
    ui->setupUi(this);
}

Step7Data::~Step7Data()
{
    delete ui;
}
