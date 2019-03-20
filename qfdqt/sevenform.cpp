#include "sevenform.h"
#include "ui_sevenform.h"

SevenForm::SevenForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SevenForm)
{
    ui->setupUi(this);
}

SevenForm::~SevenForm()
{
    delete ui;
}
