#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QBrush>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainWidget = new QWidget;
    rightWidget = new QWidget;
    rightLayout = new QVBoxLayout(rightWidget);
    mainLayout = new QHBoxLayout(mainWidget);
    navigationWidget = new QNavigationWidget;
    rightWidget->setFixedWidth(1620 - navigationWidget->width());
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
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->addWidget(navigationWidget);
    mainLayout->addWidget(rightWidget);
    rightLayout->addWidget(ui->stackedWidget);
    setCentralWidget(mainWidget);


    connect(navigationWidget, &QNavigationWidget::currentItemChanged, this, [=](const int &current){
        switch (current+1) {
        case 1:{Step1_Page = new Step1(this);ui->stackedWidget->addWidget(Step1_Page);ui->stackedWidget->setCurrentWidget(Step1_Page);break;};
        case 2:{Step2_Page = new Step2(this);ui->stackedWidget->addWidget(Step2_Page);ui->stackedWidget->setCurrentWidget(Step2_Page);break;};
        case 3:{Step3_Page = new Step3(this);ui->stackedWidget->addWidget(Step3_Page);ui->stackedWidget->setCurrentWidget(Step3_Page);break;};
        case 4:{Step4_Page = new Step4(this);ui->stackedWidget->addWidget(Step4_Page);ui->stackedWidget->setCurrentWidget(Step4_Page);break;};
        case 5:{Step5_Page = new Step5(this);ui->stackedWidget->addWidget(Step5_Page);ui->stackedWidget->setCurrentWidget(Step5_Page);break;};
        case 6:{Step6_Page = new Step6(this);ui->stackedWidget->addWidget(Step6_Page);ui->stackedWidget->setCurrentWidget(Step6_Page);break;};
        case 7:{Step7_Page = new Step7(this);ui->stackedWidget->addWidget(Step7_Page);ui->stackedWidget->setCurrentWidget(Step7_Page);break;};
        case 8:{Step8_Page = new Step8(this);ui->stackedWidget->addWidget(Step8_Page);ui->stackedWidget->setCurrentWidget(Step8_Page);break;};
        case 9:{Step9_Page = new Step9(this);ui->stackedWidget->addWidget(Step9_Page);ui->stackedWidget->setCurrentWidget(Step9_Page);break;};
        case 10:{Step10_Page = new Step10(this);ui->stackedWidget->addWidget(Step10_Page);ui->stackedWidget->setCurrentWidget(Step10_Page);break;};
        default:break;
        }
    });
}
    MainWindow::~MainWindow()
    {
        delete ui;
    }

