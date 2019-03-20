#include "tablethreeform.h"
#include "ui_tablethreeform.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
TableThreeForm::TableThreeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableThreeForm)
{
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
    m_Header<<QString("价值期望名称")<<QString("当前位次")<<QString("期望位次")<<QString("改进可能性")<<QString("价值指标关键度");
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


TableThreeForm::~TableThreeForm()
{
    delete ui;
}
void TableThreeForm::on_pushButton_clicked(){}
void TableThreeForm::on_pushButton_2_clicked(){}
void TableThreeForm::on_pushButton_3_clicked(){}
void TableThreeForm::on_pushButton_4_clicked(){}
void TableThreeForm::on_pushButton_5_clicked(){}
