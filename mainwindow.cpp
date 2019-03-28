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
       //ui->listWidget->insertItem(0,tr("Step1_Page"));  //此处可以自己通过代码添加行，左边为行号，右边为名称
       //ui->listWidget->insertItem(1,tr("Step2_Page"));
       //ui->listWidget->insertItem(2,tr("Step3_Page"));
       //ui->listWidget->insertItem(3,tr("Step4_Page"));
       //ui->listWidget->insertItem(4,tr("Step5_Page"));
       //ui->listWidget->insertItem(5,tr("Step6_Page"));
       //ui->listWidget->insertItem(6,tr("Step7_Page"));
       //ui->listWidget->insertItem(7,tr("Step8_Page"));
       //ui->listWidget->insertItem(8,tr("Step9_Page"));
       //ui->listWidget->insertItem(9,tr("Step10_Page"));

       //QObject::connect(ui->listWidget,SIGNAL(currentRowChanged(int)),ui->listWidget,SLOT(on_listWidget_clicked()));//信号与槽
  //  ui->setupUi(this);
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
    Step1_Page = new Step1(this);//实例化窗口页面
    Step2_Page = new Step2(this);
    Step3_Page = new Step3(this);
    Step4_Page = new Step4(this);
    Step5_Page = new Step5(this);
    Step6_Page = new Step6(this);
    Step7_Page = new Step7(this);
    Step8_Page = new Step8(this);
    Step9_Page = new Step9(this);
    Step10_Page = new Step10(this);
    ui->stackedWidget->addWidget(Step1_Page);
    ui->stackedWidget->addWidget(Step2_Page);
    ui->stackedWidget->addWidget(Step3_Page);
    ui->stackedWidget->addWidget(Step4_Page);
    ui->stackedWidget->addWidget(Step5_Page);
    ui->stackedWidget->addWidget(Step6_Page);
    ui->stackedWidget->addWidget(Step7_Page);
    ui->stackedWidget->addWidget(Step8_Page);
    ui->stackedWidget->addWidget(Step9_Page);
    ui->stackedWidget->addWidget(Step10_Page);

    connect(navigationWidget, &QNavigationWidget::currentItemChanged, this, [=](const int &current){
        switch (current+1) {
        case 1:ui->stackedWidget->setCurrentWidget(Step1_Page);break;
        case 2:ui->stackedWidget->setCurrentWidget(Step2_Page);break;
        case 3:ui->stackedWidget->setCurrentWidget(Step3_Page);break;
        case 4:ui->stackedWidget->setCurrentWidget(Step4_Page);break;
        case 5:ui->stackedWidget->setCurrentWidget(Step5_Page);break;
        case 6:ui->stackedWidget->setCurrentWidget(Step6_Page);break;
        case 7:ui->stackedWidget->setCurrentWidget(Step7_Page);break;
        case 8:ui->stackedWidget->setCurrentWidget(Step8_Page);break;
        case 9:ui->stackedWidget->setCurrentWidget(Step9_Page);break;
        case 10:ui->stackedWidget->setCurrentWidget(Step10_Page);break;
        default:break;
        }
    });
}




  /*  //ui->stackedWidget->setCurrentWidget(Step1_Page);
    setStyleSheet(QString::fromUtf8("border:1px solid black"));
}
*/
    MainWindow::~MainWindow()
    {
        delete ui;
    }

//    void MainWindow::on_pushButton_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(Step1_Page);
//    }

//    void MainWindow::on_pushButton_2_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(Step2_Page);
//    }
//    void MainWindow::on_pushButton_3_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(Step3_Page);
//    }
//    void MainWindow::on_pushButton_4_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(Step4_Page);
//    }
//    void MainWindow::on_pushButton_5_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(Step5_Page);
//    }
//    void MainWindow::on_pushButton_6_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(Step6_Page);
//    }
//    void MainWindow::on_pushButton_7_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(Step7_Page);
//    }
//    void MainWindow::on_pushButton_8_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(Step8_Page);
//    }
//    void MainWindow::on_pushButton_9_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(Step9_Page);
   // }
    //void MainWindow::on_pushButton_10_clicked()
   // {
        //ui->stackedWidget->setCurrentWidget(Step10_Page);
    //}

/*void MainWindow::on_listWidget_clicked()
{
    int row_listWidget=ui->listWidget->currentRow(); //currentRow()获取当前行号

    if((row_listWidget==0)) //点击第一或第四行切换到第一页
    {
        ui->stackedWidget->setCurrentWidget(Step1_Page);//为堆栈窗体切换到当前索引
    }

    else if((row_listWidget==1))
    {
        ui->stackedWidget->setCurrentWidget(Step2_Page);
    }

    else if((row_listWidget==2))
    {
        ui->stackedWidget->setCurrentWidget(Step3_Page);
    }
    else if((row_listWidget==3))
    {
        ui->stackedWidget->setCurrentWidget(Step4_Page);
    }
    else if((row_listWidget==4))
    {
        ui->stackedWidget->setCurrentWidget(Step5_Page);
    }
    else if((row_listWidget==5))
    {
        ui->stackedWidget->setCurrentWidget(Step6_Page);
    }
    else if((row_listWidget==6))
    {
        ui->stackedWidget->setCurrentWidget(Step7_Page);
    }
    else if((row_listWidget==7))
    {
        ui->stackedWidget->setCurrentWidget(Step8_Page);
    }
    else if((row_listWidget==8))
    {
        ui->stackedWidget->setCurrentWidget(Step9_Page);
    }
    else if((row_listWidget==9))
    {
        ui->stackedWidget->setCurrentWidget(Step10_Page);
    }
    setStyleSheet(QString::fromUtf8("border:1px solid black"));
}
*/
