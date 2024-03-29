#include "Step3_1.h"
#include "ui_Step3_1.h"
#include "excelengine.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>
#include "sqlite.h"
#include "entity_step2.h"
#include "Step3.h"
#include "ui_Step3.h"
#include"mainwindow.h"
Step3_1::Step3_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step3_1)
{
        ui->setupUi(this);
        qDebug()<<"Step3_1:ui";

        ui->qTableWidget->verticalHeader()->setVisible(false);//纵向表头可视化
        ui->qTableWidget->horizontalHeader()->setVisible(true);//横向表头可视化
        Sqlite sqlite;
        sqlite.connect();
        vector<Entity_Step2>returnList = sqlite.queryStep2Data();
        int tableColumn =returnList.size();
        int RowNum=tableColumn;
        int ColumnNum=2;
        qDebug()<<"Step3_1::tableColumn"<<tableColumn;
        //先把table的内容清空
        QStringList header;
        header<<"价值期望名称"<<"相对重要评级";
        ui->qTableWidget->setColumnCount(2);//设置列数
        ui->qTableWidget->setRowCount(tableColumn);//设置行数
        ui->qTableWidget->setHorizontalHeaderLabels(header);
        for(int i =0;i<returnList.size();i++)
        {
            QString vExpectation = returnList[i].valueExpectation;
            ui->qTableWidget->setItem(i,0,new QTableWidgetItem(vExpectation));
            double retuC =returnList[i].relativeImportanceRating.toDouble();
            ui->qTableWidget->setItem(i,1,new QTableWidgetItem(QString::number(retuC,'d',3)));
        }
        qDebug()<<"Step3_1:ui";
        ui->qTableWidget->setWindowTitle("QTableWidget");
        ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格选择方式：设置表格为整行选中
        ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
        ui->qTableWidget->setStyleSheet("selection-background-color:grey");//设置选中颜色：粉色
     //   setStyleSheet(QString::fromUtf8("border:1px solid black"));
        for(int rows=0;rows<RowNum;rows++)
        {
            for(int columns=0;columns<ColumnNum;columns++)
            {
                ui->qTableWidget->setColumnWidth(columns,306/ColumnNum);//hangkuan
                ui->qTableWidget->setRowHeight(rows,227/RowNum);//列宽
                ui->qTableWidget->item(rows,columns)->setTextAlignment(Qt::AlignCenter);//居中显示
                ui->qTableWidget->item(rows,columns)->setBackgroundColor(QColor(255,255,255));//设置前景颜色
                ui->qTableWidget->item(rows,columns)->setTextColor(QColor(0,0,0));//设置文本颜色
                ui->qTableWidget->item(rows,columns)->setFont(QFont("Helvetica"));//设置字体为黑体
            }
        }
        ui->qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置水平滚动条
        ui->qTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置垂直滚动条


    }

Step3_1::~Step3_1()
{
    delete ui;
}

void Step3_1::on_pushButton_clicked()
{
    int cols=ui->qTableWidget->columnCount();
    int rows=ui->qTableWidget->rowCount();
    qDebug()<<rows;
    ui->qTableWidget->insertRow(rows);
    for(int i=0;i<cols;i++)
    {
        ui->qTableWidget->setItem(rows,i,new QTableWidgetItem(""));
    }
    ui->qTableWidget->selectRow(rows);
}

void Step3_1::on_pushButton_2_clicked()
{
    QTableWidgetItem * item = ui->qTableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->qTableWidget->removeRow(item->row());
}
//将表格数据写入文件
void Step3_1::on_pushButton_3_clicked()
{
     QExcelEngine excelEngine=*new QExcelEngine();

    QString filename="0";// = QFileDialog::getSaveFileName(this, tr("Save as..."), "../datafile", tr("EXCEL files (*.xls *.xlsx);;HTML-Files (*.txt);;"));
    if(filename.isEmpty())
        return;

    bool b = excelEngine.Open2(filename, 1, false); //flase为不显示窗体
    if(b == false)
    {
        QMessageBox::information(this, "excel提示", "文件打开失败");
        return;
    }

    excelEngine.ClearAllData(" ");
    excelEngine.Close();
    //打开数据库，并保存数据
    excelEngine.Open(filename, 1, false);
    excelEngine.SaveDataFrTable(ui->qTableWidget);
    excelEngine.Close();

    QMessageBox::information(this, "excel提示", "导出成功");
}
//将文件数据导入表格
void Step3_1::on_pushButton_4_clicked()
{
    QMessageBox::StandardButton rb = QMessageBox::information(this, "warning", "从excel文件中导入数据将会覆盖之前所有内容，\n确定导入吗？",
                             QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    if(rb == QMessageBox::Yes)
    {
        //从Excel中将表格导入到TableWidget
       QExcelEngine excelEngine=*new QExcelEngine();

       QString m_fileName = QFileDialog::getOpenFileName(this, tr("select file"), "../datafile/", tr("*.xls *.xlsx"));
        if(m_fileName.isEmpty())
            return;

        bool b = excelEngine.Open(m_fileName, 1, false); //flase为不显示窗体
        if(b == false)
        {
            QMessageBox::information(this, "excel提示", "文件打开失败");
            return;
        }
        excelEngine.ReadDataToTable(ui->qTableWidget);
        excelEngine.Close();
   QMessageBox::information(this, "excel提示", "导入成功");
}

}


void Step3_1::on_pushButton_5_clicked()
{

   QExcelEngine excelEngine=*new QExcelEngine();

  //清空表格之前的所有内容
  excelEngine.ClearAllData(" ");
  excelEngine.Close();
  //打开数据库，并保存数据


  excelEngine.Close();

  QMessageBox::information(this, "excel提示", "保存成功");

}

