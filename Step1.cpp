#include "Step1.h"
#include "ui_Step1.h"
#include<QFileDialog>
#include<QDebug>
#include "initialize_db.h"
#include <QtSql>
#include <sqlite.h>

Step1::Step1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step1)
{
    ui->setupUi(this);
    ui->stackedWidget->setVisible(false);
    ui->stackedWidget_2->setVisible(false);
}
void Step1::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::TextAntialiasing, true) ;
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(QPen(Qt::black,2,Qt::SolidLine));
    int left=0;
    int up=0;
    int width=721;
    int height=480;
    width=width-2*left;
    height=height-2*up;
    painter.drawRect(left,height/3,width-2*left,height/3);
    painter.drawRect(width*2/7,up+height/9,width*3/7,height*8/9-2*up);
    painter.drawLine(QPoint(width*2/7,up+height/9),QPoint(width/2,up));
    painter.drawLine(QPoint(width*5/7,up+height/9),QPoint(width/2,up));
    painter.drawLine(QPoint(width*2/7,up+height*2/9),QPoint(width*5/7,up+height*2/9));
    painter.drawLine(QPoint(width*2/7,up+height*8/9),QPoint(width*5/7,up+height*8/9));
    painter.drawLine(QPoint(width*2/7,up+height*7/9),QPoint(width*5/7,up+height*7/9));
    painter.drawLine(QPoint(width*1/7+left,height/3),QPoint(width*1/7+left,height*2/3));
   // painter.drawLine(QPoint(left+height*5/3+width/2,up),QPoint(left+height/3*5+width,up+height));
    QFont font;
    font.setFamily("微软雅黑");
    font.setPointSize(9);
    // font.setBold(true);
    painter.setFont(font);
  //  painter.drawText(QPoint(width*7/14-5,height/18+5),"Step6");
    painter.drawText(QPoint(width*6/14-5,height*3/36+5),"Step6 确定相关性矩阵");
    painter.drawText(QPoint(width*5/14+5,height/6+5),"Step5 识别关于全局质量参数的约束");
    painter.drawText(QPoint(width*11/28+5,height*5/18+5),"Step4 生成全局质量参数");
    painter.drawText(QPoint(width*17/56+5,height*9/18+5),"Step7 确定价值指标与全局质量参数间的定量关系");
    painter.drawText(QPoint(width*5/14+5,height*13/18+5),"Step8 初步确定全局质量参数的初始评级");
    painter.drawText(QPoint(width*17/56+5,height*15/18+5),"Step9 根据竞争性分析确定全局质量参数的最终评级");
    painter.drawText(QPoint(width*5/14+5,height*17/18+5),"Step10 生成全局质量参数的配置方案");
    painter.drawText(QPoint(37,height*7/18+45),"Step1");
    painter.drawText(QPoint(9,height*7/18+60),"确定利益相关者");
    painter.drawText(QPoint(12,height*7/18+75),"收集价值期望");
    painter.drawText(QPoint(37+width/7,height*7/18+45),"Step2");
    painter.drawText(QPoint(9+width/7,height*7/18+60),"确定价值指标的");
    painter.drawText(QPoint(9+width/7,height*7/18+75),"相对重要性评级");
    painter.drawText(QPoint(37+width*11/14,height*7/18+45),"Step3");
    painter.drawText(QPoint(width*11/14-16,height*7/18+60),"基于竞争性分析确定价值");
    painter.drawText(QPoint(width*11/14-10,height*7/18+75),"指标的最终重要性评级");
    painter.drawText(QPoint(width*11/14-10,height*7/18+75),"指标的最终重要性评级");

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
