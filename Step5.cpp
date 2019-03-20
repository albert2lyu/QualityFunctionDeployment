#include "Step5.h"
#include "ui_Step5.h"

Step5::Step5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step5)
{
    ui->setupUi(this);
    setStyleSheet(QString::fromUtf8("border:1px solid black"));
}
void Step5::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::TextAntialiasing, true) ;
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(QPen(Qt::black,2,Qt::SolidLine));
    int left=70;
    int up=90;
    int width=200;
    int height=45;
    painter.drawRect(left,up+90,width+width/2+width/4,height*2);
    painter.drawRect(left+height/3*5,up+height,width,height*2+3*height);
    painter.drawLine(QPoint(left+height/3*5,up+height*2+height*2+height),QPoint(left+height/3*5+width,up+height*2+height*2+height));
    painter.drawLine(QPoint(left+height*5/3,up+height),QPoint(left+height*5/3+width/2,up));
    painter.drawLine(QPoint(left+height*5/3+width/2,up),QPoint(left+height/3*5+width,up+height));
    QFont font;
    font.setFamily("微软雅黑");
    font.setPointSize(14);
    // font.setBold(true);
    painter.setFont(font);

    painter.drawText(left+135,up+45-5,"自相关性");
    painter.drawText(left+115,up+80-5,"全局质量参数");
    painter.drawText(left+130-5,up+145-5,"相关性矩阵");
    painter.drawText(left+105-5,up+210-5,"质量参数的重要度");
    painter.drawText(left+95-5,up+251-5,"质量参数的配置方案");
    painter.drawText(left+290-5,up+126-5,"价值期");
    painter.drawText(left+290-5,up+146-5,"望重要");
    painter.drawText(left+310-5,up+166-5,"度");
    font.setPointSize(18);
    painter.setFont(font);
    painter.drawText(left+50,up-20,"Step5：我也不知道要干啥");
}
Step5::~Step5()
{
    delete ui;
}
