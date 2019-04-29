#include "Step1.h"
#include "ui_Step1.h"
#include<QFileDialog>
#include<QDebug>
#include <QtSql>
#include <sqlite.h>

Step1::Step1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step1)
{
    ui->setupUi(this);
    ui->stackedWidget->setVisible(true);
    ui->stackedWidget_2->setVisible(true);
    Step1_1_Page = new Step1_1(this);
    ui->stackedWidget->addWidget(Step1_1_Page);
    ui->stackedWidget->setCurrentWidget(Step1_1_Page);
    ui->stackedWidget->show();
}

Step1::~Step1()
{
    delete ui;
}
void Step1::on_pushButton_clicked()
{
    Step1_1_Page = new Step1_1(this);
    ui->stackedWidget->addWidget(Step1_1_Page);
    ui->stackedWidget->setCurrentWidget(Step1_1_Page);
    ui->stackedWidget->show();
}

void Step1::on_pushButton_2_clicked()
{
    Step1_2_Page = new Step1_2(this);
    ui->stackedWidget->addWidget(Step1_2_Page);
    ui->stackedWidget->setCurrentWidget(Step1_2_Page);
    ui->stackedWidget->show();
    Initialize_DB initialize_DB;
    initialize_DB.Initialize_QFD("ssss");

}

void Step1::on_pushButton_3_clicked()
{
    Step1Data_Page = new Step1Data(this);
    ui->stackedWidget_2->addWidget(Step1Data_Page);
    ui->stackedWidget_2->setCurrentWidget(Step1Data_Page);
    ui->stackedWidget_2->show();

}

void Step1::on_pushButton_4_clicked()
{
    qDebug()<<"Step1::on_pushButton_4_clicked";
    QFileDialog *fileDialog = new QFileDialog(this);
    //定义文件对话框标题
    fileDialog->setWindowTitle(tr("打开图片"));
    //设置默认文件路径
    fileDialog->setDirectory(".");
    //设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    //打印所有选择的文件的路径
    QStringList fileNames;
    if(fileDialog->exec())
    {
        fileNames = fileDialog->selectedFiles();
    }
    QString chooseFileNames =fileNames.at(0);
    qDebug()<<chooseFileNames<<endl;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/QT_workplace/build-QualityFunctionDeployment-Desktop_Qt_5_12_2_MinGW_64_bit-Debug/xxxxx.db");
    if(!db.open())
    {
        qDebug()<<"connect false";
    }

}
void Step1::on_pushButton_5_clicked()
{
    Initialize_DB initialize_DB;
    initialize_DB.exportDatabase("ssss");
}
