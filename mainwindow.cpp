#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QBrush>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStackedWidget>
#include<sqlite.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStackedWidget *stackedWidget=new QStackedWidget(this);
    navigationWidget = new QNavigationWidget;
  // navigationWidget->setFixedWidth(navigationWidget->width());
    navigationWidget->setRowHeight(40);
    navigationWidget->addItem("Step1");
    navigationWidget->addItem("Step2");
    navigationWidget->addItem("Step3");
    navigationWidget->addItem("Step4");
    navigationWidget->addItem("Step5");
    navigationWidget->addItem("Step6");
    navigationWidget->addItem("Step7");
    navigationWidget->addItem("Step8");
    navigationWidget->addItem("Step9");
    navigationWidget->addItem("Step10");
    ui->horizontalLayout_2->addWidget(navigationWidget);
    ui->horizontalLayout_2->addWidget(stackedWidget);
    ui->horizontalLayout_2->setMargin(0);
    ui->horizontalLayout_2->setStretch(1,8);


    connect(navigationWidget, &QNavigationWidget::currentItemChanged, this, [=](const int &current){
        switch (current+1) {
        case 1:{Step1_Page = new Step1(this);stackedWidget->addWidget(Step1_Page);stackedWidget->setCurrentWidget(Step1_Page);break;};
        case 2:{Step2_Page = new Step2(this);stackedWidget->addWidget(Step2_Page);stackedWidget->setCurrentWidget(Step2_Page);break;};
        case 3:{Step3_Page = new Step3(this);stackedWidget->addWidget(Step3_Page);stackedWidget->setCurrentWidget(Step3_Page);break;};
        case 4:{Step4_Page = new Step4(this);stackedWidget->addWidget(Step4_Page);stackedWidget->setCurrentWidget(Step4_Page);break;};
        case 5:{Step5_Page = new Step5(this);stackedWidget->addWidget(Step5_Page);stackedWidget->setCurrentWidget(Step5_Page);break;};
        case 6:{Step6_Page = new Step6(this);stackedWidget->addWidget(Step6_Page);stackedWidget->setCurrentWidget(Step6_Page);break;};
        case 7:{Step7_Page = new Step7(this);stackedWidget->addWidget(Step7_Page);stackedWidget->setCurrentWidget(Step7_Page);break;};
        case 8:{Step8_Page = new Step8(this);stackedWidget->addWidget(Step8_Page);stackedWidget->setCurrentWidget(Step8_Page);break;};
        case 9:{Step9_Page = new Step9(this);stackedWidget->addWidget(Step9_Page);stackedWidget->setCurrentWidget(Step9_Page);break;};
        case 10:{Step10_Page = new Step10(this);stackedWidget->addWidget(Step10_Page);stackedWidget->setCurrentWidget(Step10_Page);break;};
        default:break;
        }
    });
}
    MainWindow::~MainWindow()
    {
        delete ui;
    }

    void MainWindow::resizeEvent(QResizeEvent *event)
    {
        //QWidget::resizeEvent(event);
//  mainWidget->resize(frameGeometry().size());
    }


