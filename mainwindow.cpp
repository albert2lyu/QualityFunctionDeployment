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
       //ui->listWidget->insertItem(0,tr("OneForm_Page"));  //此处可以自己通过代码添加行，左边为行号，右边为名称
       //ui->listWidget->insertItem(1,tr("TwoForm_Page"));
       //ui->listWidget->insertItem(2,tr("ThreeForm_Page"));
       //ui->listWidget->insertItem(3,tr("FourForm_Page"));
       //ui->listWidget->insertItem(4,tr("FiveForm_Page"));
       //ui->listWidget->insertItem(5,tr("SixForm_Page"));
       //ui->listWidget->insertItem(6,tr("SevenForm_Page"));
       //ui->listWidget->insertItem(7,tr("EightForm_Page"));
       //ui->listWidget->insertItem(8,tr("NineForm_Page"));
       //ui->listWidget->insertItem(9,tr("TenForm_Page"));

       //QObject::connect(ui->listWidget,SIGNAL(currentRowChanged(int)),ui->listWidget,SLOT(on_listWidget_clicked()));//信号与槽



    OneForm_Page = new OneForm(this);//实例化窗口页面
    TwoForm_Page = new TwoForm(this);
    ThreeForm_Page = new ThreeForm(this);
    FourForm_Page = new FourForm(this);
    FiveForm_Page = new FiveForm(this);
    SixForm_Page = new SixForm(this);
    SevenForm_Page = new SevenForm(this);
    EightForm_Page = new EightForm(this);
    NineForm_Page = new NineForm(this);
    TenForm_Page = new TenForm(this);

    ui->stackedWidget->addWidget(OneForm_Page);
    ui->stackedWidget->addWidget(TwoForm_Page);
    ui->stackedWidget->addWidget(ThreeForm_Page);
    ui->stackedWidget->addWidget(FourForm_Page);
    ui->stackedWidget->addWidget(FiveForm_Page);
    ui->stackedWidget->addWidget(SixForm_Page);
    ui->stackedWidget->addWidget(SevenForm_Page);
    ui->stackedWidget->addWidget(EightForm_Page);
    ui->stackedWidget->addWidget(NineForm_Page);
    ui->stackedWidget->addWidget(TenForm_Page);
    //ui->stackedWidget->setCurrentWidget(OneForm_Page);
    setStyleSheet(QString::fromUtf8("border:1px solid black"));
}

    MainWindow::~MainWindow()
    {
        delete ui;
    }

//    void MainWindow::on_pushButton_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(OneForm_Page);
//    }

//    void MainWindow::on_pushButton_2_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(TwoForm_Page);
//    }
//    void MainWindow::on_pushButton_3_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(ThreeForm_Page);
//    }
//    void MainWindow::on_pushButton_4_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(FourForm_Page);
//    }
//    void MainWindow::on_pushButton_5_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(FiveForm_Page);
//    }
//    void MainWindow::on_pushButton_6_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(SixForm_Page);
//    }
//    void MainWindow::on_pushButton_7_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(SevenForm_Page);
//    }
//    void MainWindow::on_pushButton_8_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(EightForm_Page);
//    }
//    void MainWindow::on_pushButton_9_clicked()
//    {
//        ui->stackedWidget->setCurrentWidget(NineForm_Page);
   // }
    //void MainWindow::on_pushButton_10_clicked()
   // {
        //ui->stackedWidget->setCurrentWidget(TenForm_Page);
    //}

void MainWindow::on_listWidget_clicked()
{
    int row_listWidget=ui->listWidget->currentRow(); //currentRow()获取当前行号

    if((row_listWidget==0)) //点击第一或第四行切换到第一页
    {
        ui->stackedWidget->setCurrentWidget(OneForm_Page);//为堆栈窗体切换到当前索引
    }

    else if((row_listWidget==1))
    {
        ui->stackedWidget->setCurrentWidget(TwoForm_Page);
    }

    else if((row_listWidget==2))
    {
        ui->stackedWidget->setCurrentWidget(ThreeForm_Page);
    }
    else if((row_listWidget==3))
    {
        ui->stackedWidget->setCurrentWidget(FourForm_Page);
    }
    else if((row_listWidget==4))
    {
        ui->stackedWidget->setCurrentWidget(FiveForm_Page);
    }
    else if((row_listWidget==5))
    {
        ui->stackedWidget->setCurrentWidget(SixForm_Page);
    }
    else if((row_listWidget==6))
    {
        ui->stackedWidget->setCurrentWidget(SevenForm_Page);
    }
    else if((row_listWidget==7))
    {
        ui->stackedWidget->setCurrentWidget(EightForm_Page);
    }
    else if((row_listWidget==8))
    {
        ui->stackedWidget->setCurrentWidget(NineForm_Page);
    }
    else if((row_listWidget==9))
    {
        ui->stackedWidget->setCurrentWidget(TenForm_Page);
    }
    setStyleSheet(QString::fromUtf8("border:1px solid black"));
}

