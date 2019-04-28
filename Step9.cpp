#include "Step9.h"
#include "ui_Step9.h"

Step9::Step9(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step9)
{
    ui->setupUi(this);

    ui->stackedWidget->setVisible(false);
    ui->stackedWidget_2->setVisible(false);
  //  setStyleSheet(QString::fromUtf8("border:1px solid black"));
}
void Step9::paintEvent(QPaintEvent *)
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
Step9::~Step9()
{
    delete ui;
}
//Step9_1_Page = new Step9_1(this);//实例化窗口页面
//ui->stackedWidget->addWidget(Step9_1_Page);
//Step9_2_Page = new Step9_2(this);//实例化窗口页面
//ui->stackedWidget->addWidget(Step9_2_Page);
//Step9_3_Page = new Step9_3(this);//实例化窗口页面
//ui->stackedWidget->addWidget(Step9_3_Page);
//Step9Data_Page = new Step9Data(this);
//ui->stackedWidget_2->addWidget(Step9Data_Page);
void Step9::on_pushButton_clicked()
{
    Step9_1_Page = new Step9_1(this);
    ui->stackedWidget->addWidget(Step9_1_Page);
    ui->stackedWidget->setCurrentWidget(Step9_1_Page);
     ui->stackedWidget->show();
}

void Step9::on_pushButton_2_clicked()
{Step9_2_Page = new Step9_2(this);
  ui->stackedWidget->addWidget(Step9_2_Page);
    ui->stackedWidget->setCurrentWidget(Step9_2_Page);
    ui->stackedWidget->show();
}

void Step9::on_pushButton_3_clicked()
{
    ui->stackedWidget_2->setCurrentWidget(Step9Data_Page);
    Step9Data_Page = new Step9Data(this);
    ui->stackedWidget_2->addWidget(Step9Data_Page);
    ui->stackedWidget_2->show();
}
void Step9::on_pushButton_4_clicked()
{
    Step9_3_Page = new Step9_3(this);
    ui->stackedWidget->addWidget(Step9_3_Page);
    ui->stackedWidget->setCurrentWidget(Step9_3_Page);
    ui->stackedWidget->show();
}
void Step9::on_pushButton_5_clicked()
{

    Step9_4_Page=new Step9_4(this);
    ui->stackedWidget->addWidget(Step9_4_Page);

    ui->stackedWidget->setCurrentWidget(Step9_4_Page);
    ui->stackedWidget->show();
}

void Step9::on_comboBox_activated(const QString &arg1)
{
    if(arg1=="Step1")
       { Step1Data_Page = new Step1Data(this);
       ui->stackedWidget_2->addWidget(Step1Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step1Data_Page);
      ui->stackedWidget_2->show();}
      else if (arg1=="Step2")
      {
          Step2Data_Page = new Step2Data(this);
         ui->stackedWidget_2->addWidget(Step2Data_Page);
        ui->stackedWidget_2->setCurrentWidget(Step2Data_Page);
        ui->stackedWidget_2->show();
      }
    else if (arg1=="Step3")
    {
        Step3Data_Page = new Step3Data(this);
       ui->stackedWidget_2->addWidget(Step3Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step3Data_Page);
      ui->stackedWidget_2->show();
    }
    else if (arg1=="Step4")
    {
        Step4Data_Page = new Step4Data(this);
       ui->stackedWidget_2->addWidget(Step4Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step4Data_Page);
      ui->stackedWidget_2->show();
    }
    else if (arg1=="Step5")
    {
        Step5Data_Page = new Step5Data(this);
       ui->stackedWidget_2->addWidget(Step5Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step5Data_Page);
      ui->stackedWidget_2->show();
    }
    else if (arg1=="Step6")
    {
        Step6Data_Page = new Step6Data(this);
       ui->stackedWidget_2->addWidget(Step6Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step6Data_Page);
      ui->stackedWidget_2->show();
    }
    else if (arg1=="Step7")
    {
        Step7Data_Page = new Step7Data(this);
       ui->stackedWidget_2->addWidget(Step7Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step7Data_Page);
      ui->stackedWidget_2->show();
    }
    else if (arg1=="Step8")
    {
        Step8Data_Page = new Step8Data(this);
       ui->stackedWidget_2->addWidget(Step8Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step8Data_Page);
      ui->stackedWidget_2->show();
    }
    else
    {
        Step9Data_Page = new Step9Data(this);
       ui->stackedWidget_2->addWidget(Step9Data_Page);
      ui->stackedWidget_2->setCurrentWidget(Step9Data_Page);
      ui->stackedWidget_2->show();
    }

}
