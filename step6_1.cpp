#include "Step6_1.h"
#include "ui_Step6_1.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>
#include "sqlite.h"
#include "entity_step5.h"

Step6_1::Step6_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step6_1)
{
    ui->setupUi(this);
    ui->qTableWidget->setWindowTitle("QTableWidget");
    ui->qTableWidget->verticalHeader()->setVisible(true);//纵向表头可视化
    ui->qTableWidget->horizontalHeader()->setVisible(true);//横向表头可视化
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格选择方式：设置表格为整行选中
    ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
    ui->qTableWidget->setStyleSheet("selection-background-color:grey");//设置选中颜色：粉色
    ui->qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置水平滚动条
    ui->qTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置垂直滚动条


    Sqlite sqlite;
    sqlite.connect();
    vector<Entity_Step5>returnList = sqlite.queryStep5Data();
    int RowNum = returnList.size();
    qDebug()<<"Step5_1::ui::RowNum::"<<RowNum;
    //设置列标签
    QStringList HStrList;
    for(int i =0;i<RowNum;i++)
    {
        QString qualityParameterName = returnList[i].qualityParameterName;
        HStrList.push_back(qualityParameterName);
    }
    int HlableCnt = HStrList.count();
    ui->qTableWidget->setRowCount(RowNum);//
    ui->qTableWidget->setColumnCount(HlableCnt);
    ui->qTableWidget->setHorizontalHeaderLabels(HStrList);
}

Step6_1::~Step6_1()
{
    delete ui;
}

void Step6_1::on_pushButton_clicked()
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

void Step6_1::on_pushButton_2_clicked()
{
    QTableWidgetItem * item = ui->qTableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->qTableWidget->removeRow(item->row());
}
//将表格数据写入文件
void Step6_1::on_pushButton_3_clicked()
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
    excelEngine.Open(filename, 1, false);
    excelEngine.SaveDataFrTable(ui->qTableWidget);
    excelEngine.Close();

    QMessageBox::information(this, "excel提示", "导出成功");
}
//将文件数据导入表格
void Step6_1::on_pushButton_4_clicked()
{
    QMessageBox::StandardButton rb = QMessageBox::information(this, "warning", "从excel文件中导入数据将会覆盖之前所有内容，\n确定导入吗？",
                                                              QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    if(rb == QMessageBox::Yes)
    {
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


void Step6_1::on_pushButton_5_clicked()
{
    QExcelEngine excelEngine=*new QExcelEngine();
    excelEngine.ClearAllData(" ");
    excelEngine.Step6_1SaveData(ui->qTableWidget);
    excelEngine.Close();
    QMessageBox::information(this, "excel提示", "保存成功");

}



