#include "Step2_3.h"
#include "ui_Step2_3.h"
//#include "excelengine.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>
#include "sqlite.h"
#include "entity_step1.h"
#include "mingwwantc.h"
Step2_3::Step2_3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step2_3)
{
        qDebug()<<"Step2_3::ui";
        mingwwantcInitialize();
        ui->setupUi(this);
        Sqlite sqlite = * new Sqlite();
        sqlite.connect();
        vector<Entity_Step1> returnlist = sqlite.queryStep1Data();
        if( returnlist.size()!=0)
        {
            QStringList HStrList;
            for(int i=0;i<returnlist.size();i++)
            {
                QString valueIndexName = returnlist[i].valueIndexName;
                HStrList.push_back(valueIndexName);
            }
            int HlableCnt = HStrList.count();
            ui->qTableWidget->setRowCount(HlableCnt);//
            ui->qTableWidget->setColumnCount(HlableCnt);
            ui->qTableWidget->setHorizontalHeaderLabels(HStrList);//设置列标签
            ui->qTableWidget->setVerticalHeaderLabels(HStrList); //设置行标签
        }
        int RowNum = returnlist.size();
        int ColumnNum = returnlist.size();
        setWindowTitle(tr("TableWidget"));//设置对话框的标题
        ui->qTableWidget->setWindowTitle("QTableWidget");
        ui->qTableWidget->verticalHeader()->setVisible(true);//纵向表头可视化
        ui->qTableWidget->horizontalHeader()->setVisible(true);//横向表头可视化
        ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格选择方式：设置表格为整行选中
        ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
        ui->qTableWidget->setStyleSheet("selection-background-color:grey");//设置选中颜色：粉色
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
                ui->qTableWidget->item(rows,columns)->setBackgroundColor(QColor(255,255,255));//设置前景颜色
                ui->qTableWidget->item(rows,columns)->setTextColor(QColor(0,0,0));//设置文本颜色
                ui->qTableWidget->item(rows,columns)->setFont(QFont("Helvetica"));//设置字体为黑体
            }
        }
        ui->qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置水平滚动条
        ui->qTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置垂直滚动条
}

Step2_3::~Step2_3()
{
    delete ui;
}

void Step2_3::on_pushButton_clicked()
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

void Step2_3::on_pushButton_2_clicked()
{
    QTableWidgetItem * item = ui->qTableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->qTableWidget->removeRow(item->row());
}
//将表格数据写入文件
void Step2_3::on_pushButton_3_clicked()
{
    QExcelEngine excelEngine=*new QExcelEngine();

    QString filename="0";
    if(filename.isEmpty())
        return;
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
//将文件数据导入表格
void Step2_3::on_pushButton_4_clicked()
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
void Step2_3::on_pushButton_5_clicked()
{
    qDebug()<<"Step2_3::on_pushButton_5_clicked";
    QExcelEngine excelEngine = *new QExcelEngine();
    //清空表格之前的所有内容
    excelEngine.ClearAllData("");
    //打开数据库，并保存数据
    excelEngine.Step2SaveData2(ui->qTableWidget);
    QMessageBox::information(this, "excel提示", "保存成功");
    excelEngine.Close();

}


