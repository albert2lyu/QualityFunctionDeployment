#include "Step2_1.h"
#include "ui_Step2_1.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
Step2_1::Step2_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step2_1)
{
    //int n;//n为1中传递的数据
    ui->setupUi(this);
    setWindowTitle(tr("TableWidget"));//设置对话框的标题
    ui->setupUi(this);
    int RowNum=5;
    int ColumnNum=RowNum;
    setWindowTitle(tr("TableWidget"));
    ui->qTableWidget->setColumnCount(ColumnNum);
    ui->qTableWidget->setRowCount(RowNum);
    ui->qTableWidget->setWindowTitle("QTableWidget");
    QStringList m_Header;
    m_Header<<QString("参数名称")<<QString("参数类型(连续or离散)")<<QString("参数范围");//<<QString("改进可能性")<<QString("价值指标关键度");
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);
    ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->qTableWidget->setStyleSheet("selection-background-color:black");
    for(int rows=0;rows<RowNum;rows++)
     {
         for(int columns=0;columns<ColumnNum;columns++)
         {
                 ui->qTableWidget->setItem(rows,columns,new QTableWidgetItem(""));
                ui->qTableWidget->setColumnWidth(columns,465/RowNum);
                  ui->qTableWidget->setRowHeight(rows,335/ColumnNum);
                 ui->qTableWidget->item(rows,columns)->setTextAlignment(Qt::AlignCenter);
                 ui->qTableWidget->item(rows,columns)->setBackgroundColor(QColor(255,255,255));
                 ui->qTableWidget->item(rows,columns)->setTextColor(QColor(0,0,0));
                 ui->qTableWidget->item(rows,columns)->setFont(QFont("微软雅黑"));
         }
     }

    ui->qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->qTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    }


Step2_1::~Step2_1()
{
    delete ui;
}
//void Step2_1::on_pushButton_clicked(){}
//void Step2_1::on_pushButton_2_clicked(){}
//void Step2_1::on_pushButton_3_clicked(){}
//void Step2_1::on_pushButton_4_clicked(){}
//void Step2_1::on_pushButton_5_clicked(){}
