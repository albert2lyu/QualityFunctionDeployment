#include "Step8.h"
#include "ui_Step8.h"

Step8::Step8(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step8)
{
    ui->setupUi(this);
    Step8_1_Page = new Step8_1(this);//实例化窗口页面
    ui->stackedWidget->addWidget(Step8_1_Page);
    Step8Data_Page = new Step8Data(this);
    ui->stackedWidget_2->addWidget(Step8Data_Page);
//    setStyleSheet(QString::fromUtf8("border:1px solid black"));
}
void Step8::paintEvent(QPaintEvent *)
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
}
Step8::~Step8()
{

    delete ui;
}
void Step8::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(Step8_1_Page);
}

void Step8::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(Step8_1_Page);
}

void Step8::on_pushButton_3_clicked()
{
    ui->stackedWidget_2->setCurrentWidget(Step8Data_Page);
}
