#include "Step1_2.h"
#include "ui_Step1_2.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
Step1_2::Step1_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step1_2)
    {

    }


Step1_2::~Step1_2()
{
    delete ui;
}
