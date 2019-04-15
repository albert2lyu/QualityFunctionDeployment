#include "Step3_3.h"
#include "ui_Step3_3.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
#include "sqlite.h"
#include <QString>
#include "excelengine.h"
#include "matlabfunction.h"
Step3_3::Step3_3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step3_3)
{
    ui->setupUi(this);
    setWindowTitle(tr("TableWidget"));
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);
    ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->qTableWidget->setStyleSheet("selection-background-color:grey");

    Sqlite sqlite;
    sqlite.connect();
    vector<Entity_Step2>returnList = sqlite.queryStep2Data();
    int tableColumn = returnList.size()+1;
    int RowNum = 1;
    QStringList  HStrList;
    HStrList<<"利益相关者";
    for(int i =0;i<returnList.size();i++)
    {
        QString vExpectation = returnList[i].valueExpectation;
        qDebug()<<"Step3_2::vExpectation"<<vExpectation;
        HStrList.push_back(vExpectation);
    }
    ui->qTableWidget->setRowCount(RowNum);
    ui->qTableWidget->setColumnCount(tableColumn);
    ui->qTableWidget->setHorizontalHeaderLabels(HStrList);
    ui->qTableWidget->setWindowTitle("QTableWidget");
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);
    ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->qTableWidget->setStyleSheet("selection-background-color:grey");
    ui->qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->qTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->qTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}


Step3_3::~Step3_3()
{
    delete ui;
}

void Step3_3::on_pushButton_clicked()
{
    int cols=ui->qTableWidget->columnCount();
    int rows=ui->qTableWidget->rowCount();
    ui->qTableWidget->insertRow(rows);
    for(int i=0;i<cols;i++)
    {
        ui->qTableWidget->setItem(rows,i,new QTableWidgetItem(""));
    }
    ui->qTableWidget->selectRow(rows);
}
void Step3_3::on_pushButton_2_clicked()
{
    qDebug()<<"on_pushButton_2_clicked";
    QTableWidgetItem * item = ui->qTableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->qTableWidget->removeRow(item->row());
}
void Step3_3::on_pushButton_3_clicked()
{
    qDebug()<<"on_pushButton_3_clicked";
    QExcelEngine excelEngine=*new QExcelEngine();

    QString filename="0";// = QFileDialog::getSaveFileName(this, tr("Save as..."), "../datafile", tr("EXCEL files (*.xls *.xlsx);;HTML-Files (*.txt);;"));
    if(filename.isEmpty())
        return;
   // QFile::copy("/1.xlsx", filename);

    bool b = excelEngine.Open2(filename, 1, false); //flase为不显示窗体
    if(b == false)
    {
        QMessageBox::information(this, "excel提示", "文件打开失败");
        return;
    }

    //清空表格之前的所有内容
    excelEngine.ClearAllData(" ");
    excelEngine.Close();
    //打开数据库，并保存数据
    excelEngine.Open(filename, 1, false);
    excelEngine.SaveDataFrTable(ui->qTableWidget);
    excelEngine.Close();

    QMessageBox::information(this, "excel提示", "导出成功");
}
void Step3_3::on_pushButton_4_clicked(){}
void Step3_3::on_pushButton_5_clicked()
{
    qDebug()<<"Step3_3::on_pushButton_5_clicked";
    QExcelEngine excelEngine = *new QExcelEngine();

    excelEngine.ClearAllData("");

    excelEngine.Step3_3SaveData(ui->qTableWidget);


    MatlabFunction matlabFunction = *new MatlabFunction();
    matlabFunction.mlfStep3(ui->qTableWidget);

    QMessageBox::information(this, "end", "end");
    excelEngine.Close();
}
