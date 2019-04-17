#include "Step3data.h"
#include "ui_Step3Data.h"
#include "Step3_1.h"
#include<QPixmapCache>

Step3Data::Step3Data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step3Data)
{
        ui->setupUi(this);
        int RowNum=10;
        int ColumnNum=4;
        setWindowTitle(tr("TableWidget"));//设置对话框的标题
        ui->qTableWidget->setColumnCount(ColumnNum);//设置列数
        ui->qTableWidget->setRowCount(RowNum);//设置行数
        ui->qTableWidget->setWindowTitle("QTableWidget");
        QStringList m_Header;
        m_Header<<QString("价值期望名称")<<QString("价值期望符号")<<QString("符号")<<QString("期望值");
        ui->qTableWidget->setHorizontalHeaderLabels(m_Header);//添加横向表头
        ui->qTableWidget->verticalHeader()->setVisible(false);//纵向表头可视化
        ui->qTableWidget->horizontalHeader()->setVisible(true);//横向表头可视化
        ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格选择方式：设置表格为整行选中
        ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
        ui->qTableWidget->setStyleSheet("selection-background-color:green");//设置选中颜色：粉色
        setStyleSheet(QString::fromUtf8("border:1px solid black"));

        for(int rows=0;rows<RowNum;rows++)
        {
            for(int columns=0;columns<ColumnNum;columns++)
            {
                if(columns==0)
                {
                    ui->qTableWidget->setItem(rows,columns,new QTableWidgetItem(""));
                }
                else if(columns==1)
                {
                    ui->qTableWidget->setItem(rows,columns,new QTableWidgetItem(""));
                }
                else if(columns==2)
                {
                    ui->qTableWidget->setItem(rows,columns,new QTableWidgetItem(""));
                }
                else
                {
                    ui->qTableWidget->setItem(rows,columns,new QTableWidgetItem(""));
                }
            }
        }
        for(int rows=0;rows<RowNum;rows++)
        {
            for(int columns=0;columns<ColumnNum;columns++)
            {
                ui->qTableWidget->setColumnWidth(columns,705/ColumnNum);//hangkuan
                ui->qTableWidget->setRowHeight(rows,335/RowNum);//列宽
                ui->qTableWidget->item(rows,columns)->setTextAlignment(Qt::AlignCenter);//居中显示
                ui->qTableWidget->item(rows,columns)->setBackgroundColor(QColor(85,170,255));//设置前景颜色
                ui->qTableWidget->item(rows,columns)->setTextColor(QColor(0,0,0));//设置文本颜色
                ui->qTableWidget->item(rows,columns)->setFont(QFont("Helvetica"));//设置字体为黑体
            }
        }
        ui->qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置水平滚动条
        ui->qTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置垂直滚动条
        QStringList HStrList;
        HStrList.push_back(QString("指标序号"));
        HStrList.push_back(QString("价值指标"));
        HStrList.push_back(QString("关系符号"));
        HStrList.push_back(QString("期望值"));
        int HlableCnt = HStrList.count();
        ui->qTableWidget->setRowCount(RowNum);//
        ui->qTableWidget->setColumnCount(HlableCnt);
        ui->qTableWidget->setHorizontalHeaderLabels(HStrList);
        QComboBox *comBox = new QComboBox();
        comBox->addItem("");
        comBox->addItem("");
}

Step3Data::~Step3Data()
{
    delete ui;
}
void Step3Data::on_pushButton_clicked(){


    qDebug()<<"Step2Data:: on_pushButton_clicked";
    QExcelEngine excelEngine=*new QExcelEngine();
    excelEngine.Step2QueryData1(ui->qTableWidget);
    excelEngine.Close();

}
